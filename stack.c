#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int st[MAX], top = -1;

void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);

int main(int argc, char *argv[]) {
    int option, val;

    do {
        printf("\n******MAIN MENU*****");
        printf("\n 1) PUSH");
        printf("\n 2) POP");
        printf("\n 3) PEEK");
        printf("\n 4) DISPLAY");
        printf("\n 5) EXIT");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nEnter the number to be pushed on stack: ");
                scanf("%d", &val);
                push(st, val);
                break;

            case 2:
                val = pop(st);
                if (val != -1) {
                    printf("\nThe value popped from stack is: %d", val);
                }
                break;

            case 3:
                val = peek(st);
                if (val != -1) {
                    printf("\nThe value stored at the top of the stack is: %d", val);
                }
                break;

            case 4:
                display(st);
                break;

            case 5:
                printf("\nExiting from the program...\n");
                break;

            default:
                printf("\nInvalid option, please try again.\n");
                break;
        }
    } while (option != 5);

    return 0;
}

void push(int st[], int val) {
    if (top == MAX - 1) {
        printf("\nStack overflow");
    } else {
        top++;
        st[top] = val;
    }
}

int pop(int st[]) {
    int val;
    if (top == -1) {
        printf("\nStack underflow");
        return -1;
    } else {
        val = st[top];
        top--;
        return val;
    }
}

void display(int st[]) {
    int i;
    if (top == -1) {
        printf("\nStack is empty");
    } else {
        printf("\nStack elements are:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", st[i]);
        }
    }
}

int peek(int st[]) {
    if (top == -1) {
        printf("\nStack is empty");
        return -1;
    } else {
        return st[top];
    }
}
