// ============================================================
//  Lab Title  : Arrays in C++ — Declare, Fill, Process, Analyze
//  Course     : CMP1001 – Introduction to Programming (C++)
//  Duration   : 60 minutes
//  Topic      : Arrays (1-D): declaration, initialization, traversal,
//               searching, sorting, and basic statistics
// ------------------------------------------------------------
//  Description:
//    In this lab you will practise every essential array skill:
//    allocating fixed-size arrays, reading and writing elements
//    with loops, computing statistics (sum, average, min, max),
//    linear search, and a simple bubble-sort.  A small challenge
//    at the end asks you to reverse an array in-place and remove
//    duplicates without using the STL.
//
//  Instructions to Students:
//    1. Work through each section in order.
//    2. Every // TODO: comment is a place where YOU must write code.
//    3. Do NOT delete the TODO comments — leave them above your code.
//    4. Compile often:   g++ MainProgram.cpp -o lab && ./lab
//    5. Your program must compile (even partially) before you submit.
//    6. When you are done, submit ONLY this file.
// ============================================================

#include <iostream>
using namespace std;

// ============================================================
//  SECTION 1 — Warm-up  (≈ 5–10 min)
//  Goal: recall variables, cin/cout, and basic loops.
// ============================================================

// Exercise 1-A
// Print the numbers 1 through 10 on one line separated by spaces.
void warmup_printNumbers()
{
    cout << "\n--- Warm-up 1-A: Print 1 to 10 ---\n";
    for (int i = 1; i < 10; ++i) {
        std::cout << i << " ";
    }
    std::cout << 10 << std::endl;
}

// Exercise 1-B
// Ask the user to enter 5 integers and print their sum.
void warmup_sumFive()
{
    cout << "\n--- Warm-up 1-B: Sum of 5 numbers ---\n";
    int sum = 0;
    // TODO: declare an integer variable 'num'
    int num;
    // TODO: loop 5 times: read num with cin, then add it to sum
    for (int i = 0; i < 5; ++i) {
        std::cin >> num;
        sum += num;
    }
    // TODO: print sum
    std::cout << "Sum: " << sum << std::endl;
}

// ============================================================
//  SECTION 2 — Core Concepts  (≈ 10–15 min)
//
//  KEY FACTS ABOUT ARRAYS
//  ─────────────────────
//  • An array stores MULTIPLE values of the SAME type.
//  • Syntax:   type name[SIZE];          // uninitialized
//              type name[SIZE] = {v0, v1, ...};  // initialized
//  • Index starts at 0 → last valid index is SIZE-1.
//  • Access:   name[index]
//
//  Example already written for you — READ it, then do the TODOs.
// ============================================================

void concepts_demo()
{
    cout << "\n--- Section 2: Core Concepts Demo ---\n";

    // --- GIVEN EXAMPLE (do not modify) ---
    int scores[5] = {90, 75, 88, 62, 95};

    cout << "Scores: ";
    for (int i = 0; i < 5; i++)
    {
        cout << scores[i];
        if (i < 4) cout << ", ";
    }
    cout << "\n";
    // First element
    cout << "First score : " << scores[0] << "\n";
    // Last element
    cout << "Last score  : " << scores[4] << "\n";

    // --- YOUR TURN ---

    // TODO 2-A: declare an integer array called 'temps' of size 7
    //           and initialize it with: 22, 19, 25, 30, 28, 17, 21
    int temps[7] = {22, 19, 25, 30, 28, 17, 21};

    // TODO 2-B: print all elements of 'temps' using a for-loop
    cout << "Temperatures: \n";
    // your loop here
    for (int temp : temps) {
        std::cout << temp << "\n";
    }

    cout << "\n";

    // TODO 2-C: change the 4th element (index 3) of 'temps' to 35
    //           then print it to verify
    temps[3] = 35;

    cout << "Temperatures (change the 4th element (index 3) of 'temps' to 35): \n";
    // your loop here
    for (int temp : temps) {
        std::cout << temp << "\n";
    }

    cout << "\n";
}

// ============================================================
//  SECTION 3 — Guided Exercises  (≈ 25–30 min)
//  Increasing difficulty — read each description carefully.
// ============================================================

// ----------------------------------------------------------
// Exercise 3-A  |  Fill an array from user input
// ----------------------------------------------------------
// Ask the user how many grades they want to enter (between 1
// and 20).  Store them in an array, then print them back.
// ----------------------------------------------------------
void exercise_fillArray()
{
    cout << "\n--- Exercise 3-A: Fill array from input ---\n";

    const int MAX = 20;
    int grades[MAX];
    int n = 0;

    // TODO: ask the user to enter n (1 ≤ n ≤ 20)
    //       keep asking until n is in range
    do {
        std::cout << "Enter an integer in range [1, 20]: ";
        std::cin >> n;
    } while (n < 1 && n > 20);

    // TODO: loop n times and read each grade into grades[i]
    for (int i = 0; i < n; ++i) {
        std::cin >> grades[i];
    }

    // TODO: print all n grades on one line
    cout << "You entered: ";
    // your loop here
    for (int i = 0; i < n; ++i) {
        std::cout << grades[i] << " ";
    }
    cout << "\n";
}

// ----------------------------------------------------------
// Exercise 3-B  |  Sum, Average, Minimum, Maximum
// ----------------------------------------------------------
// Given the array below, compute and print:
//   • the sum of all elements
//   • the average (as a double)
//   • the minimum value
//   • the maximum value
// Do NOT use any library functions — write the logic yourself.
// ----------------------------------------------------------
void exercise_statistics()
{
    cout << "\n--- Exercise 3-B: Statistics ---\n";

    int data[8] = {34, 67, 23, 89, 12, 55, 78, 45};
    int size = 8;

    // TODO: compute the sum using a loop
    int sum = 0;
    // your loop here
    for (int num: data) {
        sum += num;
    }

    // TODO: compute the average (cast to double)
    double avg = 0.0;
    // your calculation here
    avg = sum / (double)size;

    // TODO: find minimum — start with data[0] and update in a loop
    int minVal = data[0];
    // your loop here
    for (int i = 1; i < size; ++i) {
        if (data[i] < minVal) minVal = data[i];
    }

    // TODO: find maximum — start with data[0] and update in a loop
    int maxVal = data[0];
    // your loop here
    for (int i = 1; i < size; ++i) {
        if (data[i] > maxVal) maxVal = data[i];
    }

    cout << "Sum     : " << sum    << "\n";
    cout << "Average : " << avg    << "\n";
    cout << "Minimum : " << minVal << "\n";
    cout << "Maximum : " << maxVal << "\n";
}

// ----------------------------------------------------------
// Exercise 3-C  |  Linear Search
// ----------------------------------------------------------
// Write a function that searches for a target value in an
// array.  It should return the INDEX of the first match, or
// -1 if the value is not found.
//
// Then in exercise_search(), call it with different targets
// and print whether each was found (and at which index).
// ----------------------------------------------------------

// TODO: implement linearSearch
//   Parameters: int arr[], int size, int target
//   Return    : int  (index of target, or -1)
int linearSearch(int arr[], int size, int target)
{
    int res = -1;
    // TODO: loop through arr; if arr[i] == target return i
    // TODO: if you finish the loop without finding it, return -1
    for (int i = 0; i < size; ++i) {
        if (target == arr[i]) { res = i; break; }
    }
    return res; // replace this placeholder
}

void exercise_search()
{
    cout << "\n--- Exercise 3-C: Linear Search ---\n";

    int values[10] = {5, 12, 8, 3, 27, 19, 6, 44, 31, 7};

    // TODO: call linearSearch for target = 27 and print the result
    //       e.g.  "27 found at index 4"  or  "27 not found"
    int i_27 = linearSearch(values, sizeof(values), 27);

    // TODO: call linearSearch for target = 99 and print the result
    int i_99 = linearSearch(values, sizeof(values), 99);

    std::cout << "27 ";
    if (i_27 == -1) std::cout << "not found\n";
    else std::cout << "found at index " << i_27;

    std::cout << "99 ";
    if (i_99 == -1) std::cout << "not found\n";
    else std::cout << "found at index " << i_99;
}

// ----------------------------------------------------------
// Exercise 3-D  |  Count occurrences
// ----------------------------------------------------------
// Given a sentence encoded as an array of characters (a char
// array), count how many times the letter 'a' or 'A' appears.
//
// Hint: use a for-loop and compare each element to 'a' and 'A'
// ----------------------------------------------------------
void exercise_countChar()
{
    cout << "\n--- Exercise 3-D: Count characters ---\n";

    char text[] = "Abracadabra is a famous magic phrase";
    int  len    = 36;   // number of characters (do not change)

    // TODO: declare a counter, loop over text[0..len-1],
    //       increment when you find 'a' or 'A'

    int count = 0;
    // your loop here
    for (char c : text) {
        if (c == 'a' || c == 'A') count++;
    }

    cout << "Letter 'a'/'A' appears " << count << " times.\n";
}

// ----------------------------------------------------------
// Exercise 3-E  |  Bubble Sort (ascending)
// ----------------------------------------------------------
// Implement bubble sort on the array below, then print the
// sorted result.
//
// Algorithm reminder:
//   for each pass p from 0 to size-2:
//     for each index i from 0 to size-2-p:
//       if arr[i] > arr[i+1]:  swap them
// ----------------------------------------------------------
void exercise_bubbleSort()
{
    cout << "\n--- Exercise 3-E: Bubble Sort ---\n";

    int arr[9] = {64, 34, 25, 12, 22, 11, 90, 45, 7};
    int size   = 9;

    // TODO: implement the two-loop bubble sort described above
    //       use a temporary variable for the swap
    int tmp;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i; j < size - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    // TODO: print the sorted array
    cout << "Sorted: ";
    // your loop here
    for (int num : arr) {
        std::cout << num << " ";
    }
    cout << "\n";
}

// ============================================================
//  SECTION 4 — Challenge  (≈ 10 min)
//  These problems are harder and slightly open-ended.
//  Even a partial solution earns partial credit.
// ============================================================

// ----------------------------------------------------------
// Challenge A  |  Reverse an array IN-PLACE
// ----------------------------------------------------------
// Reverse the elements of the array WITHOUT creating a second
// array.  Use only one temporary variable and a single loop.
//
// After reversing, print the result.
// Example input : {1, 2, 3, 4, 5}
// Expected output: 5 4 3 2 1
// ----------------------------------------------------------
void challenge_reverse()
{
    cout << "\n--- Challenge A: Reverse In-Place ---\n";

    int arr[7] = {10, 20, 30, 40, 50, 60, 70};
    int size   = 7;

    // TODO: use a loop that swaps arr[i] with arr[size-1-i]
    //       stop when i reaches the midpoint (size/2)
    int tmp;
    for (int i = 0, j = size - 1; i < size / 2; i++, j--) {
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    cout << "Reversed: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// ----------------------------------------------------------
// Challenge B  |  Remove duplicates (no STL)
// ----------------------------------------------------------
// Given the array below, create a NEW array that contains only
// the UNIQUE values (first occurrence wins), preserving order.
// Print the unique values and how many there are.
//
// Hint: for each element, check if it already appeared earlier
//       in the array before deciding to keep it.
//
// Input : {4, 7, 2, 4, 9, 7, 3, 2, 8, 4}
// Output: 4 7 2 9 3 8   (6 unique values)
// ----------------------------------------------------------
void challenge_removeDuplicates()
{
    cout << "\n--- Challenge B: Remove Duplicates ---\n";

    int original[10] = {4, 7, 2, 4, 9, 7, 3, 2, 8, 4};
    int origSize     = 10;

    int unique[10];   // result array (max same size as original)
    int uniqueCount  = 0;

    // TODO: loop through original[]; for each element check
    //       whether it already exists in unique[0..uniqueCount-1]
    //       if NOT found, add it to unique[] and increment uniqueCount
    unique[uniqueCount++] = original[0];
    for (int i = 1; i < origSize; ++i) {
        if (linearSearch(original, origSize, original[i]) == i)
            unique[uniqueCount++] = original[i];
    }

    cout << "Unique values (" << uniqueCount << "): ";
    for (int i = 0; i < uniqueCount; i++)
        cout << unique[i] << " ";
    cout << "\n";
}

// ============================================================
//  main — calls every section in order
// ============================================================
int main()
{
    cout << "========================================\n";
    cout << "  CMP1001 Lab — Arrays in C++\n";
    cout << "========================================\n";

    // Section 1
    warmup_printNumbers();
    warmup_sumFive();

    // Section 2
    concepts_demo();

    // Section 3
    exercise_fillArray();
    exercise_statistics();
    exercise_search();
    exercise_countChar();
    exercise_bubbleSort();

    // Section 4
    challenge_reverse();
    challenge_removeDuplicates();

    cout << "\n========================================\n";
    cout << "  Lab complete — good work!\n";
    cout << "========================================\n";

    return 0;
}
