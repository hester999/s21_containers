# Компиляторы
CC = clang++ ## variant for school mac
CC1 = g++

# Флаги компиляции
CFLAGS = -Wall -Wextra -Werror -std=c++17 -Wno-deprecated-declarations -Wno-sign-compare

# Пути к библиотекам Google Test
GTEST_DIR = /opt/homebrew/opt/googletest
INCLUDES = -I$(GTEST_DIR)/include
LIBS = -L$(GTEST_DIR)/lib -lgtest -lgtest_main -pthread

# Флаги для покрытия кода
GCOVFLAGS = -fprofile-arcs -ftest-coverage

# Путь к исполняемому файлу и тестам
BUILD_PATH = ./
EXE = test
TEST_SRC = qtests/s21_test*.c*

# Правило по умолчанию
all: clean test

test: clean
	$(CC1) $(CFLAGS) $(INCLUDES) $(TEST_SRC) $(LIBS) -o $(EXE) -pthread
	./$(EXE)

style:
	@find s21_containers \( -name "*.c*" -or -name "*.h" \) -exec clang-format --style=google -i {} +
	@find qtests \( -name "*.c*" -or -name "*.h" \) -exec clang-format --style=google -i {} +
	@echo "All C++ source files and headers formatted with Google style."

rebuild:
	make all

clean:
	rm -rf *.o *.g* *.info *.out report *.a $(EXE) *.log gcov* *.dSYM

valgrind: clean
	$(CC1) $(CFLAGS) $(INCLUDES) $(TEST_SRC) $(LIBS) -o $(EXE) -pthread
	valgrind --tool=memcheck --leak-check=yes ./$(EXE)

gcov_report: clean
	$(CC1) $(CFLAGS) $(GCOVFLAGS) $(INCLUDES) -c $(TEST_SRC)
	$(CC1) $(CFLAGS) $(GCOVFLAGS) *.o $(LIBS) -o $(EXE) -pthread
	./$(EXE)
	lcov --no-external -t "test" -o test.info -c -d . --ignore-errors inconsistent
	genhtml -o report test.info
	open report/index.html
