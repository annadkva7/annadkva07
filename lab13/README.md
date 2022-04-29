
Лабораторна робота №13. Взаємодія з файлами.

Загальне завдання: 
1) Виконати одне завдання з пулу завдань на свій розсуд згідно її складності, використовуючи зчитування інформації з вхідного файлу, а також запис відповіді у
результуючий файл.
2) Продемонструвати роботу розроблених методів за допомогою модульних тестів.
    Наводжу ступень покриття коду модульними тестами:
LLVM_PROFILE_FILE="dist/test.profraw" ./dist/test.bin
Running suite(s): Programing
.
├─ dist
├─ ..
├─ test
├─ README.md
├─ assets
├─ Makefile
├─ Doxyfile
├─ src
├─ 100%: Checks: 1, Failures: 0, Errors: 0
test/test.c:24:P:lab13:test_read_from_file:0: Passed
llvm-profdata merge -sparse dist/test.profraw -o dist/test.profdata
llvm-cov report dist/test.bin -instr-profile=dist/test.profdata src/*.c
Filename                                               Regions    Missed Regions     Cover   Functions  Missed Functions  Executed       Lines      Missed Lines     Cover
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/home/turtlee_/programming-Diakova/lab13/src/lib.c           4                 1    75.00%           2                 1    50.00%          14                 4    71.43%
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
TOTAL                                                        4                 1    75.00%           2                 1    50.00%          14                 4    71.43%
llvm-cov show dist/test.bin -instr-profile=dist/test.profdata src/*.c --format html > dist/coverage.html

Висновок: під час виконання цієї лабораторної роботи я закріпила навички взаємодії з файлами, а також покращила свої навички написання програм мовою С.

