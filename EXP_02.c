#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char item) {
    if (top >= SIZE - 1) {
        printf("\nStack Overflow.");
    } else {
        top = top + 1;
        stack[top] = item;
    }
}

char pop() {
    char item;
    if (top < 0) {
        printf("Stack underflow: invalid infix expression");
        exit(1);
    } else {
        item = stack[top];
        top = top - 1;
        return item;
    }
}

int is_operator(char symbol) {
    return (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-');
}

int precedence(char symbol) {
    if (symbol == '^') {
        return 3;
    } else if (symbol == '*' || symbol == '/') {
        return 2;
    } else if (symbol == '+' || symbol == '-') {
        return 1;
    } else {
        return 0;
    }
}

void infixToPostfix(char infix_exp[], char postfix_exp[]) {
    int i = 0, j = 0;
    char item, x;
    
    strcat(infix_exp, ")");
    push('(');
    
    item = infix_exp[i];
    
    while (item != '\0') {
        if (item == '(') {
            push(item);
        } else if (isdigit(item) || isalpha(item)) {
            postfix_exp[j++] = item;
        } else if (is_operator(item)) {
            x = pop();
            while (is_operator(x) && precedence(x) >= precedence(item)) {
                postfix_exp[j++] = x;
                x = pop();
            }
            push(x);
            push(item);
        } else if (item == ')') {
            x = pop();
            while (x != '(') {
                postfix_exp[j++] = x;
                x = pop();
            }
        } else {
            printf("\nInvalid infix Expression.\n");
            exit(1);
        }
        i++;
        item = infix_exp[i];
    }
    
    if (top > 0) {
        printf("\nInvalid infix Expression.\n");
        exit(1);
    }
    
    postfix_exp[j] = '\0';
}

int main() {
    char infix[SIZE], postfix[SIZE];
    
    printf("\nEnter Infix expression : ");
    fgets(infix, SIZE, stdin);
    infix[strcspn(infix, "\n")] = '\0';
    
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: ");
    puts(postfix);
    
    return 0;
}
