
Лабораторна робота №14. Структуровані типи даних.

Загальне завдання: 
1) З розділу "Індивідуальні завдання комплексної роботи" взяти прикладну галузь стосовно номеру варіанту за попередньо-визначеною формулою.
2) Створити структуру, що відображає "базовий клас".
3) Розробити функції, які
->читають дані з файлу;
->записують дані у файл;
->виводить масив елементів на екран;
->№1 з категорії "Методи для роботи з колекцією;
2) Продемонструвати роботу розроблених методів за допомогою модульних тестів.
    Наводжу ступень покриття коду модульними тестами:
LLVM_PROFILE_FILE="dist/test.profraw" ./dist/test.bin
Running suite(s): Programing

Have insurance: 0
Experience: 10
Company: Google
Worker name: Anna Diakova
Email: annadkva07@gmail.com
Characteristics: cool,cool

100%: Checks: 2, Failures: 0, Errors: 0
test/test.c:26:P:lab14:test_read_from_file:0: Passed
test/test.c:61:P:lab14:test_write_to_file:0: Passed
llvm-profdata merge -sparse dist/test.profraw -o dist/test.profdata
llvm-cov report dist/test.bin -instr-profile=dist/test.profdata src/*.c
Filename                                               Regions    Missed Regions     Cover   Functions  Missed Functions  Executed       Lines      Missed Lines     Cover
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/home/turtlee_/programming-Diakova/lab14/src/lib.c          17                 9    47.06%           4                 2    50.00%          42                21    50.00%
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
TOTAL                                                       17                 9    47.06%           4                 2    50.00%          42                21    50.00%
llvm-cov show dist/test.bin -instr-profile=dist/test.profdata src/*.c --format html > dist/coverage.html

Висновок: під час виконання цієї лабораторної роботи я закріпила навички реалізації структурованих типів даних, а також покращила свої навички написання програм мовою С.
