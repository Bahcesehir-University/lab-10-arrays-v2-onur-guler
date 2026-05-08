// ============================================================
//  Test File : tests/test_all.cpp
//  Course    : CMP1001 – Introduction to Programming (C++)
//  Lab       : Arrays in C++
//
//  ALL test cases live in this ONE file.
//  Each section is tagged so the Makefile can run them
//  independently for partial grading:
//
//    Tag              Points   make target
//    [section1]         10     grade_s1
//    [section2]         10     grade_s2
//    [section3b]        15     grade_3b
//    [section3c]        15     grade_3c
//    [section3e]        20     grade_3e
//    [section4]         30     grade_ch
//    ─────────────────────────────────────
//    Total             100
// ============================================================

#include "catch_amalgamated.hpp"
#include <string>
#include <cmath>
using namespace std;

// ============================================================
//  Implementations under test
//  (mirrors what students write — used by all sections)
// ============================================================

// ── Section 1 helpers ────────────────────────────────────────

string buildNumberSequence(int n)
{
    string result;
    for (int i = 1; i <= n; i++)
    {
        if (i > 1) result += " ";
        result += to_string(i);
    }
    return result;
}

int sumArray(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

// ── Section 2 helpers ────────────────────────────────────────

void initTemps(int temps[], int size)
{
    int init[7] = {22, 19, 25, 30, 28, 17, 21};
    for (int i = 0; i < size; i++)
        temps[i] = init[i];
}

string arrayToString(int arr[], int size)
{
    string s;
    for (int i = 0; i < size; i++)
    {
        if (i > 0) s += " ";
        s += to_string(arr[i]);
    }
    return s;
}

// ── Section 3 helpers ────────────────────────────────────────

int computeSum(int arr[], int size)
{
    int s = 0;
    for (int i = 0; i < size; i++) s += arr[i];
    return s;
}

double computeAverage(int arr[], int size)
{
    if (size == 0) return 0.0;
    return static_cast<double>(computeSum(arr, size)) / size;
}

int computeMin(int arr[], int size)
{
    int m = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] < m) m = arr[i];
    return m;
}

int computeMax(int arr[], int size)
{
    int m = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > m) m = arr[i];
    return m;
}

int linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == target) return i;
    return -1;
}

void bubbleSort(int arr[], int size)
{
    for (int pass = 0; pass < size - 1; pass++)
        for (int i = 0; i < size - 1 - pass; i++)
            if (arr[i] > arr[i + 1])
            {
                int tmp    = arr[i];
                arr[i]     = arr[i + 1];
                arr[i + 1] = tmp;
            }
}

bool isSortedAscending(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1]) return false;
    return true;
}

// ── Section 4 helpers ────────────────────────────────────────

void reverseInPlace(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int tmp        = arr[i];
        arr[i]         = arr[size - 1 - i];
        arr[size-1-i]  = tmp;
    }
}

int removeDuplicates(int original[], int origSize,
                     int unique[],   int /*maxSize*/)
{
    int count = 0;
    for (int i = 0; i < origSize; i++)
    {
        bool found = false;
        for (int j = 0; j < count; j++)
            if (unique[j] == original[i]) { found = true; break; }
        if (!found)
            unique[count++] = original[i];
    }
    return count;
}

// ============================================================
//  SECTION 1 — Warm-up                               [10 pts]
// ============================================================

TEST_CASE("1-A: Number sequence 1 to 10", "[section1]")
{
    SECTION("Full sequence is correct")
    {
        REQUIRE(buildNumberSequence(10) == "1 2 3 4 5 6 7 8 9 10");
    }
    SECTION("Starts at 1")
    {
        REQUIRE(buildNumberSequence(10).substr(0, 1) == "1");
    }
    SECTION("Ends at 10")
    {
        string s = buildNumberSequence(10);
        REQUIRE(s.substr(s.size() - 2) == "10");
    }
    SECTION("Contains exactly 9 spaces (10 numbers)")
    {
        string s = buildNumberSequence(10);
        int spaces = 0;
        for (char c : s) if (c == ' ') spaces++;
        REQUIRE(spaces == 9);
    }
}

TEST_CASE("1-B: Sum of five integers", "[section1]")
{
    SECTION("Sum of {1,2,3,4,5} = 15")
    {
        int a[] = {1, 2, 3, 4, 5};
        REQUIRE(sumArray(a, 5) == 15);
    }
    SECTION("Sum of {10,20,30,40,50} = 150")
    {
        int a[] = {10, 20, 30, 40, 50};
        REQUIRE(sumArray(a, 5) == 150);
    }
    SECTION("Sum of all zeros = 0")
    {
        int a[] = {0, 0, 0, 0, 0};
        REQUIRE(sumArray(a, 5) == 0);
    }
    SECTION("Sum with negatives")
    {
        int a[] = {-5, 10, -3, 8, -2};
        REQUIRE(sumArray(a, 5) == 8);
    }
    SECTION("Single element")
    {
        int a[] = {42};
        REQUIRE(sumArray(a, 1) == 42);
    }
}

// ============================================================
//  SECTION 2 — Core Concepts                         [10 pts]
// ============================================================

TEST_CASE("2-A: temps array initialization", "[section2]")
{
    int temps[7];
    initTemps(temps, 7);

    SECTION("All 7 values are correct")
    {
        int expected[7] = {22, 19, 25, 30, 28, 17, 21};
        for (int i = 0; i < 7; i++)
            REQUIRE(temps[i] == expected[i]);
    }
    SECTION("First element is 22") { REQUIRE(temps[0] == 22); }
    SECTION("Last element is 21")  { REQUIRE(temps[6] == 21); }
    SECTION("Middle element [3] = 30") { REQUIRE(temps[3] == 30); }
}

TEST_CASE("2-B: Traverse and print temps", "[section2]")
{
    int temps[7];
    initTemps(temps, 7);
    string result = arrayToString(temps, 7);

    SECTION("Output is non-empty")     { REQUIRE(!result.empty()); }
    SECTION("Full output string correct")
    {
        REQUIRE(result == "22 19 25 30 28 17 21");
    }
    SECTION("Contains 17")  { REQUIRE(result.find("17") != string::npos); }
    SECTION("Contains 21")  { REQUIRE(result.find("21") != string::npos); }
}

TEST_CASE("2-C: Update element at index 3", "[section2]")
{
    int temps[7];
    initTemps(temps, 7);
    temps[3] = 35;   // student action

    SECTION("Index 3 is now 35") { REQUIRE(temps[3] == 35); }
    SECTION("Other elements unchanged")
    {
        REQUIRE(temps[0] == 22);
        REQUIRE(temps[1] == 19);
        REQUIRE(temps[2] == 25);
        REQUIRE(temps[4] == 28);
        REQUIRE(temps[5] == 17);
        REQUIRE(temps[6] == 21);
    }
}

// ============================================================
//  EXERCISE 3-B — Statistics                         [15 pts]
// ============================================================

TEST_CASE("3-B: Sum calculation", "[section3b]")
{
    SECTION("Lab dataset {34,67,23,89,12,55,78,45} = 403")
    {
        int d[] = {34, 67, 23, 89, 12, 55, 78, 45};
        REQUIRE(computeSum(d, 8) == 403);
    }
    SECTION("All zeros")
    {
        int d[] = {0, 0, 0, 0};
        REQUIRE(computeSum(d, 4) == 0);
    }
    SECTION("Single element")
    {
        int d[] = {99};
        REQUIRE(computeSum(d, 1) == 99);
    }
    SECTION("Negatives cancel")
    {
        int d[] = {-10, -20, 30};
        REQUIRE(computeSum(d, 3) == 0);
    }
    SECTION("Large values")
    {
        int d[] = {1000, 2000, 3000};
        REQUIRE(computeSum(d, 3) == 6000);
    }
}

TEST_CASE("3-B: Average calculation", "[section3b]")
{
    SECTION("Lab dataset average ≈ 50.375")
    {
        int d[] = {34, 67, 23, 89, 12, 55, 78, 45};
        REQUIRE(fabs(computeAverage(d, 8) - 50.375) < 0.001);
    }
    SECTION("{2,4,6,8} average = 5.0")
    {
        int d[] = {2, 4, 6, 8};
        REQUIRE(computeAverage(d, 4) == Catch::Approx(5.0));
    }
    SECTION("Uses double — not integer truncation ({1,2} → 1.5)")
    {
        int d[] = {1, 2};
        REQUIRE(computeAverage(d, 2) == Catch::Approx(1.5));
    }
    SECTION("Single element average")
    {
        int d[] = {7};
        REQUIRE(computeAverage(d, 1) == Catch::Approx(7.0));
    }
}

TEST_CASE("3-B: Minimum value", "[section3b]")
{
    SECTION("Lab dataset min = 12")
    {
        int d[] = {34, 67, 23, 89, 12, 55, 78, 45};
        REQUIRE(computeMin(d, 8) == 12);
    }
    SECTION("Min at first position")
    {
        int d[] = {1, 5, 9, 3};
        REQUIRE(computeMin(d, 4) == 1);
    }
    SECTION("Min at last position")
    {
        int d[] = {9, 7, 5, 2};
        REQUIRE(computeMin(d, 4) == 2);
    }
    SECTION("Negative minimum")
    {
        int d[] = {3, -5, 8, -2};
        REQUIRE(computeMin(d, 4) == -5);
    }
}

TEST_CASE("3-B: Maximum value", "[section3b]")
{
    SECTION("Lab dataset max = 89")
    {
        int d[] = {34, 67, 23, 89, 12, 55, 78, 45};
        REQUIRE(computeMax(d, 8) == 89);
    }
    SECTION("Max at first position")
    {
        int d[] = {100, 5, 9, 3};
        REQUIRE(computeMax(d, 4) == 100);
    }
    SECTION("Max at last position")
    {
        int d[] = {1, 7, 5, 99};
        REQUIRE(computeMax(d, 4) == 99);
    }
    SECTION("Max among negatives")
    {
        int d[] = {-10, -2, -7};
        REQUIRE(computeMax(d, 3) == -2);
    }
}

// ============================================================
//  EXERCISE 3-C — Linear Search                      [15 pts]
// ============================================================

TEST_CASE("3-C: Linear search — found", "[section3c]")
{
    int values[10] = {5, 12, 8, 3, 27, 19, 6, 44, 31, 7};

    SECTION("27 found at index 4")  { REQUIRE(linearSearch(values, 10, 27) == 4); }
    SECTION("5 found at index 0 (first)") { REQUIRE(linearSearch(values, 10, 5) == 0); }
    SECTION("7 found at index 9 (last)")  { REQUIRE(linearSearch(values, 10, 7) == 9); }
    SECTION("19 found at index 5")  { REQUIRE(linearSearch(values, 10, 19) == 5); }
    SECTION("44 found at index 7")  { REQUIRE(linearSearch(values, 10, 44) == 7); }
}

TEST_CASE("3-C: Linear search — not found", "[section3c]")
{
    int values[10] = {5, 12, 8, 3, 27, 19, 6, 44, 31, 7};

    SECTION("99 not found → -1")  { REQUIRE(linearSearch(values, 10, 99) == -1); }
    SECTION("0 not found → -1")   { REQUIRE(linearSearch(values, 10,  0) == -1); }
    SECTION("-1 not found → -1")  { REQUIRE(linearSearch(values, 10, -1) == -1); }
}

TEST_CASE("3-C: Linear search — first occurrence & edge cases", "[section3c]")
{
    SECTION("Returns first index when duplicates exist")
    {
        int arr[] = {3, 7, 3, 9, 3};
        REQUIRE(linearSearch(arr, 5, 3) == 0);
    }
    SECTION("Finds unique element among duplicates")
    {
        int arr[] = {1, 1, 2, 1, 1};
        REQUIRE(linearSearch(arr, 5, 2) == 2);
    }
    SECTION("Array of size 1, found")
    {
        int arr[] = {42};
        REQUIRE(linearSearch(arr, 1, 42) == 0);
    }
    SECTION("Array of size 1, not found")
    {
        int arr[] = {42};
        REQUIRE(linearSearch(arr, 1, 7) == -1);
    }
}

// ============================================================
//  EXERCISE 3-E — Bubble Sort                        [20 pts]
// ============================================================

TEST_CASE("3-E: Bubble sort — lab dataset", "[section3e]")
{
    int arr[9] = {64, 34, 25, 12, 22, 11, 90, 45, 7};
    bubbleSort(arr, 9);

    SECTION("Array is sorted ascending") { REQUIRE(isSortedAscending(arr, 9)); }
    SECTION("Smallest = 7")  { REQUIRE(arr[0] == 7);  }
    SECTION("Largest  = 90") { REQUIRE(arr[8] == 90); }
    SECTION("Exact sorted sequence: 7 11 12 22 25 34 45 64 90")
    {
        int expected[9] = {7, 11, 12, 22, 25, 34, 45, 64, 90};
        for (int i = 0; i < 9; i++)
            REQUIRE(arr[i] == expected[i]);
    }
}

TEST_CASE("3-E: Bubble sort — already sorted", "[section3e]")
{
    int arr[] = {1, 2, 3, 4, 5};
    bubbleSort(arr, 5);

    SECTION("Stays sorted") { REQUIRE(isSortedAscending(arr, 5)); }
    SECTION("Values unchanged")
    {
        int expected[] = {1, 2, 3, 4, 5};
        for (int i = 0; i < 5; i++) REQUIRE(arr[i] == expected[i]);
    }
}

TEST_CASE("3-E: Bubble sort — reverse-order input", "[section3e]")
{
    int arr[] = {5, 4, 3, 2, 1};
    bubbleSort(arr, 5);

    SECTION("Correctly sorted")
    {
        int expected[] = {1, 2, 3, 4, 5};
        for (int i = 0; i < 5; i++) REQUIRE(arr[i] == expected[i]);
    }
}

TEST_CASE("3-E: Bubble sort — duplicates", "[section3e]")
{
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    bubbleSort(arr, 9);

    SECTION("Sorted with duplicates") { REQUIRE(isSortedAscending(arr, 9)); }
    SECTION("First = 1") { REQUIRE(arr[0] == 1); }
    SECTION("Last  = 9") { REQUIRE(arr[8] == 9); }
}

TEST_CASE("3-E: Bubble sort — edge cases", "[section3e]")
{
    SECTION("Single element unchanged")
    {
        int arr[] = {42};
        bubbleSort(arr, 1);
        REQUIRE(arr[0] == 42);
    }
    SECTION("Two elements — swap needed")
    {
        int arr[] = {9, 2};
        bubbleSort(arr, 2);
        REQUIRE(arr[0] == 2);
        REQUIRE(arr[1] == 9);
    }
    SECTION("Two elements — already in order")
    {
        int arr[] = {1, 8};
        bubbleSort(arr, 2);
        REQUIRE(arr[0] == 1);
        REQUIRE(arr[1] == 8);
    }
}

// ============================================================
//  SECTION 4 — Challenges                            [30 pts]
//  Challenge A: Reverse in-place      (15 pts)
//  Challenge B: Remove duplicates     (15 pts)
// ============================================================

// ── Challenge A ───────────────────────────────────────────────

TEST_CASE("Challenge A: Reverse — lab dataset", "[section4]")
{
    int arr[7] = {10, 20, 30, 40, 50, 60, 70};
    reverseInPlace(arr, 7);

    SECTION("First element becomes 70") { REQUIRE(arr[0] == 70); }
    SECTION("Last element becomes 10")  { REQUIRE(arr[6] == 10); }
    SECTION("Full reversed sequence")
    {
        int expected[] = {70, 60, 50, 40, 30, 20, 10};
        for (int i = 0; i < 7; i++) REQUIRE(arr[i] == expected[i]);
    }
}

TEST_CASE("Challenge A: Reverse — even-length array", "[section4]")
{
    int arr[] = {1, 2, 3, 4};
    reverseInPlace(arr, 4);
    SECTION("Reversed correctly")
    {
        int expected[] = {4, 3, 2, 1};
        for (int i = 0; i < 4; i++) REQUIRE(arr[i] == expected[i]);
    }
}

TEST_CASE("Challenge A: Reverse — edge cases", "[section4]")
{
    SECTION("Single element unchanged")
    {
        int arr[] = {99};
        reverseInPlace(arr, 1);
        REQUIRE(arr[0] == 99);
    }
    SECTION("Two elements swapped")
    {
        int arr[] = {5, 8};
        reverseInPlace(arr, 2);
        REQUIRE(arr[0] == 8);
        REQUIRE(arr[1] == 5);
    }
    SECTION("Palindrome array unchanged")
    {
        int arr[]  = {1, 2, 3, 2, 1};
        int copy[] = {1, 2, 3, 2, 1};
        reverseInPlace(arr, 5);
        for (int i = 0; i < 5; i++) REQUIRE(arr[i] == copy[i]);
    }
}

TEST_CASE("Challenge A: Reverse — no elements lost", "[section4]")
{
    int arr[]  = {3, 1, 4, 1, 5, 9, 2, 6};
    int orig[] = {3, 1, 4, 1, 5, 9, 2, 6};
    reverseInPlace(arr, 8);
    SECTION("Each position equals its mirror in the original")
    {
        for (int i = 0; i < 8; i++)
            REQUIRE(arr[i] == orig[7 - i]);
    }
}

// ── Challenge B ───────────────────────────────────────────────

TEST_CASE("Challenge B: Remove duplicates — lab dataset", "[section4]")
{
    int original[] = {4, 7, 2, 4, 9, 7, 3, 2, 8, 4};
    int unique[10];
    int count = removeDuplicates(original, 10, unique, 10);

    SECTION("6 unique values")              { REQUIRE(count == 6); }
    SECTION("Correct order: 4 7 2 9 3 8")
    {
        int expected[] = {4, 7, 2, 9, 3, 8};
        for (int i = 0; i < 6; i++) REQUIRE(unique[i] == expected[i]);
    }
}

TEST_CASE("Challenge B: Remove duplicates — no duplicates present", "[section4]")
{
    int original[] = {1, 2, 3, 4, 5};
    int unique[5];
    int count = removeDuplicates(original, 5, unique, 5);

    SECTION("All 5 kept")         { REQUIRE(count == 5); }
    SECTION("Order preserved")
    {
        for (int i = 0; i < 5; i++) REQUIRE(unique[i] == original[i]);
    }
}

TEST_CASE("Challenge B: Remove duplicates — all same", "[section4]")
{
    int original[] = {7, 7, 7, 7};
    int unique[4];
    int count = removeDuplicates(original, 4, unique, 4);

    SECTION("Count = 1")    { REQUIRE(count == 1); }
    SECTION("Value = 7")    { REQUIRE(unique[0] == 7); }
}

TEST_CASE("Challenge B: Remove duplicates — first occurrence wins", "[section4]")
{
    int original[] = {5, 3, 5, 1};
    int unique[4];
    int count = removeDuplicates(original, 4, unique, 4);

    SECTION("3 unique values")  { REQUIRE(count == 3); }
    SECTION("Order: 5 3 1")
    {
        REQUIRE(unique[0] == 5);
        REQUIRE(unique[1] == 3);
        REQUIRE(unique[2] == 1);
    }
}

TEST_CASE("Challenge B: Remove duplicates — single element", "[section4]")
{
    int original[] = {42};
    int unique[1];
    int count = removeDuplicates(original, 1, unique, 1);

    SECTION("Count = 1")  { REQUIRE(count == 1); }
    SECTION("Value = 42") { REQUIRE(unique[0] == 42); }
}
