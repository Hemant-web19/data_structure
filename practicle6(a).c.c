#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char operator_stack[MAX];
char operand_stack[MAX];
int operator_top = -1;
int operand_top = -1;

void pop_operator() {
    if (operator_top == -1) {
        printf("Operator stack underflow\n");
    } else {
        operator_top--;
    }
}

void push_operator(char c) {
    if (operator_top == MAX - 1) {
        printf("Operator stack overflow\n");
    } else {
        operator_stack[++operator_top] = c;
    }
}

int is_operator_precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '(') {
        return 0; 
    }
    return -1; 
}

int is_operand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

void exp_reverse(char *ptr) {
    int length = strlen(ptr);
    char temp;
    for (int i = 0; i < length / 2; i++) {
        temp = ptr[i];
        ptr[i] = ptr[length - 1 - i];
        ptr[length - 1 - i] = temp;
    }
    for (int i = 0; i < length; i++) {
        if (ptr[i] == '(') {
            ptr[i] = ')';
        } else if (ptr[i] == ')') {
            ptr[i] = '(';
        }
    }
}

void process_operator(char op, char *output, int *output_index) {
    while (operator_top != -1 && is_operator_precedence(op) <= is_operator_precedence(operator_stack[operator_top])) {
        output[(*output_index)++] = operator_stack[operator_top];
        pop_operator();
    }
    push_operator(op);
}

void infix_to_prefix(char *infix, char *prefix) {
    exp_reverse(infix); // Reverse infix expression

    int output_index = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        if (is_operand(infix[i])) {
            prefix[output_index++] = infix[i];
        } else if (infix[i] == ')') {
            push_operator(infix[i]);
        } else if (infix[i] == '(') {
            while (operator_top != -1 && operator_stack[operator_top] != ')') {
                prefix[output_index++] = operator_stack[operator_top];
                pop_operator();
            }
            pop_operator(); // Pop the ')'
        } else if (is_operator_precedence(infix[i]) >= 0) {
            process_operator(infix[i], prefix, &output_index);
        }
    }

    // Pop remaining operators
    while (operator_top != -1) {
        prefix[output_index++] = operator_stack[operator_top];
        pop_operator();
    }
    
    prefix[output_index] = '\0'; // Null-terminate the output
    exp_reverse(prefix); // Reverse the output to get prefix
}

int main() {
    char infix[100];
    char prefix[100];
    
    printf("Enter the expression: ");
    fgets(infix, sizeof(infix), stdin);
    
    // Remove newline character if present
    infix[strcspn(infix, "\n")] = 0;

    infix_to_prefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
