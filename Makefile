# ============================================================
#  Makefile — CMP1001 Lab: Arrays in C++
#
#  For Linux / macOS / MSYS2 terminal.
#  Windows (Command Prompt / PowerShell) users: use build.bat
#
#  ONE test binary (test_all) compiled from tests/test_all.cpp.
#  Grading runs each section tag independently for partial credit.
#
#  Targets
#  ───────
#    make              build lab + test_all
#    make lab          build student program only
#    make test_all     build test binary only
#    make grade_s1     Section 1  — Warm-up             (10 pts)
#    make grade_s2     Section 2  — Core Concepts       (10 pts)
#    make grade_3b     Exercise 3-B — Statistics        (15 pts)
#    make grade_3c     Exercise 3-C — Linear Search     (15 pts)
#    make grade_3e     Exercise 3-E — Bubble Sort       (20 pts)
#    make grade_ch     Section 4  — Challenges          (30 pts)
#    make grade_all    run every section in sequence
#    make clean        remove all generated files
# ============================================================

# ── Windows / Scoop fix ──────────────────────────────────────
# Scoop's make.exe uses cmd.exe by default and loses PATH.
# These two lines fix it: point make at sh.exe from git, and
# ensure Scoop's shims (where g++ lives) are on the PATH.
ifeq ($(OS),Windows_NT)
    # Scoop installs git's sh.exe here — works for all Scoop users
    SHELL := $(USERPROFILE)/scoop/apps/git/current/bin/sh.exe
    # Also add gcc and mingw bin dirs to PATH so g++ is found
    PATH  := $(USERPROFILE)/scoop/apps/gcc/current/bin:$(USERPROFILE)/scoop/apps/mingw/current/bin:$(USERPROFILE)/scoop/shims:$(PATH)
    export PATH
    RUN   := ./
    RM    := rm -f
else
    RUN   := ./
    RM    := rm -f
endif

CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.

CATCH_SRC = catch_amalgamated.cpp
CATCH_OBJ = catch_amalgamated.o
TEST_SRC  = test_all.cpp
TEST_BIN  = test_all

.PHONY: all lab grade_s1 grade_s2 grade_3b grade_3c grade_3e grade_ch grade_all clean

# ── Default ──────────────────────────────────────────────────
all: lab $(TEST_BIN)

# ── Student lab executable ───────────────────────────────────
lab: MainProgram.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
	@echo ">>> Built: lab"

# ── Catch2 object (compiled once, ~30 sec) ───────────────────
$(CATCH_OBJ): $(CATCH_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo ">>> Compiled Catch2"

# ── Single test binary ───────────────────────────────────────
$(TEST_BIN): $(TEST_SRC) $(CATCH_OBJ)
	$(CXX) $(CXXFLAGS) $< $(CATCH_OBJ) -o $@
	@echo ">>> Built: $(TEST_BIN)"

# ── Per-section grading ──────────────────────────────────────
grade_s1: $(TEST_BIN)
	@echo "=============================================="
	@echo "  SECTION 1 -- Warm-up                 10 pts"
	@echo "=============================================="
	$(RUN)$(TEST_BIN) "[section1]" --reporter compact

grade_s2: $(TEST_BIN)
	@echo "=============================================="
	@echo "  SECTION 2 -- Core Concepts           10 pts"
	@echo "=============================================="
	$(RUN)$(TEST_BIN) "[section2]" --reporter compact

grade_3b: $(TEST_BIN)
	@echo "=============================================="
	@echo "  EXERCISE 3-B -- Statistics           15 pts"
	@echo "=============================================="
	$(RUN)$(TEST_BIN) "[section3b]" --reporter compact

grade_3c: $(TEST_BIN)
	@echo "=============================================="
	@echo "  EXERCISE 3-C -- Linear Search        15 pts"
	@echo "=============================================="
	$(RUN)$(TEST_BIN) "[section3c]" --reporter compact

grade_3e: $(TEST_BIN)
	@echo "=============================================="
	@echo "  EXERCISE 3-E -- Bubble Sort          20 pts"
	@echo "=============================================="
	$(RUN)$(TEST_BIN) "[section3e]" --reporter compact

grade_ch: $(TEST_BIN)
	@echo "=============================================="
	@echo "  SECTION 4  -- Challenges             30 pts"
	@echo "=============================================="
	$(RUN)$(TEST_BIN) "[section4]" --reporter compact

grade_all: $(TEST_BIN)
	@echo "############################################"
	@echo "  CMP1001 -- FULL GRADING RUN"
	@echo "############################################"
	-$(MAKE) --no-print-directory grade_s1
	-$(MAKE) --no-print-directory grade_s2
	-$(MAKE) --no-print-directory grade_3b
	-$(MAKE) --no-print-directory grade_3c
	-$(MAKE) --no-print-directory grade_3e
	-$(MAKE) --no-print-directory grade_ch
	@echo "############################################"
	@echo "  GRADING COMPLETE"
	@echo "############################################"

# ── Clean ────────────────────────────────────────────────────
clean:
	$(RM) lab $(TEST_BIN) $(CATCH_OBJ)
	@echo ">>> Clean complete"