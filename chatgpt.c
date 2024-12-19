#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 500

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Funzioni per gestire gli stack
bool is_empty(Stack *stack) {
    return stack->top == -1;
}

bool is_full(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int value) {
    if (!is_full(stack)) {
        stack->data[++stack->top] = value;
    }
}

int pop(Stack *stack) {
    if (!is_empty(stack)) {
        return stack->data[stack->top--];
    }
    return -1; // Indicatore di stack vuoto
}

int peek(Stack *stack) {
    if (!is_empty(stack)) {
        return stack->data[stack->top];
    }
    return -1;
}

// Mosse disponibili
void sa(Stack *a) {
    if (a->top > 0) {
        int temp = a->data[a->top];
        a->data[a->top] = a->data[a->top - 1];
        a->data[a->top - 1] = temp;
    }
	printf("sa\n");
}

void sb(Stack *b) {
    if (b->top > 0) {
        int temp = b->data[b->top];
        b->data[b->top] = b->data[b->top - 1];
        b->data[b->top - 1] = temp;
    }
	printf("sb\n");
}

void ss(Stack *a, Stack *b) {
    sa(a);
    sb(b);
	printf("ss\n");
}

void pa(Stack *a, Stack *b) {
    if (!is_empty(b)) {
        push(a, pop(b));
    }
	printf("pa\n");
}

void pb(Stack *a, Stack *b) {
    if (!is_empty(a)) {
        push(b, pop(a));
    }
	printf("pb\n");
}

void ra(Stack *a) {
    if (a->top > 0) {
        int temp = pop(a);
        for (int i = a->top; i >= 0; i--) {
            a->data[i + 1] = a->data[i];
        }
        a->data[0] = temp;
        a->top++;
    }
	printf("ra\n");
}

void rb(Stack *b) {
    if (b->top > 0) {
        int temp = pop(b);
        for (int i = b->top; i >= 0; i--) {
            b->data[i + 1] = b->data[i];
        }
        b->data[0] = temp;
        b->top++;
    }
	printf("rb\n");
}

void rr(Stack *a, Stack *b) {
    ra(a);
    rb(b);
	printf("rr\n");
}

void rra(Stack *a) {
    if (a->top > 0) {
        int temp = a->data[0];
        for (int i = 0; i < a->top; i++) {
            a->data[i] = a->data[i + 1];
        }
        a->data[a->top] = temp;
    }
	printf("rra\n");
}

void rrb(Stack *b) {
    if (b->top > 0) {
        int temp = b->data[0];
        for (int i = 0; i < b->top; i++) {
            b->data[i] = b->data[i + 1];
        }
        b->data[b->top] = temp;
    }
	printf("rrb\n");
}

void rrr(Stack *a, Stack *b) {
    rra(a);
    rrb(b);
	printf("rrr\n");
}

// Algoritmo Radix Sort
void radix_sort(Stack *a, Stack *b, int size) {
    int max_bits = 0;
    int max_num = size - 1;

    // Calcola il numero di bit necessari
    while ((max_num >> max_bits) != 0) {
        max_bits++;
    }

    for (int bit = 0; bit < max_bits; bit++) {
        for (int i = 0; i < size; i++) {
            int num = peek(a);
            if (((num >> bit) & 1) == 0) {
                pb(a, b);
            } else {
                ra(a);
            }
        }
        while (!is_empty(b)) {
            pa(a, b);
        }
    }
}

int main(int argc, char *argv[]) {
    Stack a = {.top = -1};
    Stack b = {.top = -1};

    if (argc < 2) {
        fprintf(stderr, "Usage: %s num1 num2 ...\n", argv[0]);
        return 1;
    }

    // Riempie lo stack a con gli argomenti forniti
    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]);
        push(&a, num);
    }

    // Ordina lo stack
    radix_sort(&a, &b, argc - 1);

    /* // Stampa lo stack ordinato
    while (!is_empty(&a)) {
        printf("%d\n", pop(&a));
    } */

    return 0;
}