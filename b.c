#include <stdlib.h>
#include <stdio.h>
#define MAX 10

int count = 0;

struct Stack {
    struct Stack_Array *array;
    int top;
};

typedef struct Stack_Array {
    char letter;
    int priority;
} Stack_Array;

typedef struct Stack stack;

void create_null_stack(stack *s) {
    s->top = -1;
}

int is_full_stack(stack *s) {
    if(s->top == MAX - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int is_empty_stack(stack *s) {
    if(s->top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

void push(stack *s, char new_letter, int new_number) {
    if(is_full_stack(s)) {
        printf("Stack is full.");
    }
    else {
        s->top++;
        s->array[s->top].letter = new_letter;
        s->array[s->top].priority = new_number;
    }
    count++;
}

void pop(stack *s) {
    if(is_empty_stack(s)) {
        printf("\nStack is empty.\n");
    }
    else {
        printf("%c is deleted.", s->array[s->top].letter);
        s->top--;
    }
    count--;
    printf("\n");
}

void print_stack(stack *s) {
    printf("Stack is: ");
    for( int i = 0; i < count; i++) {
        printf("%c", s->array[i].letter); 
        printf("%d ", s->array[i].priority);
    }
    printf("\n");
}

void queue(stack *s, stack *temp, int size) {
    for( int i = 0; i < size; i++) {
        for( int j = i + 1; j < size ; j++) {
            if(s->array[i].priority < s->array[j].priority) {
                temp->array[1] = s->array[j];
                s->array[j] = s->array[i];

                s->array[i] = temp->array[1];
            }
        }
    }
}



int main(void) {

    char letter_array[] = "EOYUUCOST";
    int priority_array[] = {99, 46, 6, 65, 15, 58, 9, 32, 72};
    int size = sizeof(letter_array)/sizeof(letter_array[0]);

    stack *s = (stack*)malloc(sizeof(stack));
    s->array = (Stack_Array*)malloc(size * sizeof(stack));

    create_null_stack(s);

    stack *temp = (stack*)malloc(sizeof(stack));
    temp->array = (Stack_Array*)malloc(1 * sizeof(stack));

    
    for( int i = 0; i < size; i++) {
    push(s, letter_array[i], priority_array[i]);
    }
    print_stack(s);

    queue(s, temp, size);
    for( int i = 0; i < size; ++i) {
        printf("%c ", s->array[i].letter);
    }
    printf("\n");
    /* for( int i = 0; i < size + 1; i++) {
    pop(s);
    }

    print_stack(s); */

    return 0;
}