CC = $(CLANG_PREFIX)clang
LAB_OPTS = -I./src src/lib.c
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla $(LAB_OPTS)
V_FLAGS=--tool=memcheck --leak-check=full --show-reachable=yes --undef-value-errors=yes --track-origins=no --child-silent-after-fork=no --trace-children=no --error-exitcode=1

all:	
	make clean prep compile check
clean:
	rm -rf dist
prep:
	mkdir dist
compile: main.bin test.bin

main.bin: src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@

test.bin: test/test.c
	$(CC) $(C_OPTS) $< $(ARCH) -o ./dist/$@ -lcheck -lm -lrt -lpthread -lsubunit
test: clean prep compile
	./dist/test.bin
run: clean prep compile
	./dist/main.bin
doxygen:
	doxygen Doxyfile
check:
	clang-format --verbose -dry-run --Werror src/* test/*
	cppcheck --enable=all --inconclusive --addon=cert --error-exitcode=1  -v --suppress=unreadVariable:*/main.c --suppress=knownConditionTrueFalse:*/main.c --suppress=missingIncludeSystem  --check-config --suppress=*:*/test.c  --suppress=unmatchedSuppression:*/main.c .

# TODO: clang-tidy; scan-build
