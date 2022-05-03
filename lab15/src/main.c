/**
 * @mainpage
 * Лабораторна робота №15. Динамічні масиви.
 * # Загальне завдання
 * На базі попередньо розробленого функціоналу сформувати динамічний масив
 * елементів розробленої структури.
 *
 * Розробити функції, які 1) виводять вміст списку на екран, 2) додавання об'єкта у кінець списку, 3)
 * видаляє об'єкт зі списку за індексом, 4) №1 з категорії "Методи для роботи з
 * колекцією".
 *
 * @author Diakova A.
 * @date 03-may-2022
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи функцій print_on_screen, does_not_have_insurance,
 * add_worker, free_struct.
 *
 * @author Diakova A.
 * @date 03-may-2022
 * @version 1.0
 */
 
#include "list.h"
#include "entity.h"

int main(void) {
  int amount_of_workers = 0;
  printf("Будь ласка, для початку роботи введіть кількість робітників: ");
  scanf("%d", &amount_of_workers);

  struct worker *array = (struct worker *)malloc(amount_of_workers * sizeof(struct worker));
  for( int i = 0; i < amount_of_workers; i++) {
    (array + i)->company = (char*)malloc(16 * sizeof(char));
    (array + i)->details.first_name = (char*)malloc(16 * sizeof(char));
    (array + i)->details.last_name = (char*)malloc(16 * sizeof(char));
    (array + i)->details.email = (char*)malloc(16 * sizeof(char));
    (array + i)->characteristics = (char*)malloc(16 * sizeof(char));
  }

  printf("Будь ласка, заповніть поля нижче: \n");
  int count = 1;
  for( int i = 0; i < amount_of_workers; i++) {
    printf("Досвід роботи робітника №%d: ", count);
    scanf("%d", &((array + i)->experience));
    printf("\nЧи має робітник №%d страхування: ", count);
    scanf("%d", &((array + i)->have_insurance));
    printf("\nКомпанія, у якій працює робітник №%d: ", count);
    scanf("%s", (array + i)->company);
    printf("\nІм'я робітника №%d: ", count);
    scanf("%s", (array + i)->details.first_name);
    printf("\nПрізвище робітника №%d: ", count);
    scanf("%s", (array + i)->details.last_name);
    printf("\nПошта робітника №%d для контакту: ", count);
    scanf("%s", (array + i)->details.email);
    printf("\nХарактеристика робітника: ");
    scanf("%s", (array + i)->characteristics);
    count++;
    printf("\n");
  }
  
  print_on_screen(array, amount_of_workers);
  does_not_have_insurance(array, amount_of_workers);

  int new_amount_of_workers = amount_of_workers + 1;

  struct worker *new_array = (struct worker *)malloc(new_amount_of_workers * sizeof(struct worker));

  add_worker(array, new_array, new_amount_of_workers);

  free(array);

  print_on_screen(new_array, new_amount_of_workers);
  printf("Будь ласка, оберіть номер робітника, інформація про котрого буде видалена: ");
  int index = 0;
  scanf("%d", &index);
  if(index > new_amount_of_workers) {
    printf("Значення некоректне. Спробуйте ще!");
    scanf("%d", &index);
  }
  printf("Будь ласка, введіть елемент, що бажаєте видалити зі структури: ");
  int temp = 0;
  printf("1 - Досвід, 2 - Страхування, 3 - Компанія, 4 - Прізвище та ім'я, 5 - Пошта, 6 - Характеристика ");
  scanf("%d", &temp);
  free_struct(new_array, new_amount_of_workers, index - 1, temp);
  print_on_screen(new_array, new_amount_of_workers);

  free(new_array);

  return 0;
}