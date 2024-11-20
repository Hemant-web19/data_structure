#include <stdio.h>
#include <string.h>
#define MAX 100

char stack_operator[MAX];
int top = -1;

int is_operand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int is_operator_pre(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else {
        return 0; 
    }
}

void push_operator(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        top++;
        stack_operator[top] = c;
    }
}

void pop_operator_print() {
    if (top != -1) {
        printf("%c", stack_operator[top]);
        top--;
    }
}

void in_postfix(char str[], int length) {
    for (int i = 0; i < length; i++) {
        if (is_operand(str[i])) {
            printf("%c", str[i]);  
        } else if (str[i] == '(') {
            push_operator(str[i]); 
        } else if (str[i] == ')') {
            while (top != -1 && stack_operator[top] != '(') {
                pop_operator_print();
            }
            top--; // Pop '('
        } else if (is_operator_pre(str[i])) {
            while (top != -1 && is_operator_pre(stack_operator[top]) >= is_operator_pre(str[i])) {
                pop_operator_print();
            }
            push_operator(str[i]); 
        } else {
            printf("Invalid input\n");
        }
    }
    
    while (top != -1) {
        pop_operator_print();
    }
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

void in_prefix(char str[], int length) {
    // Reverse the infix expression
    exp_reverse(str);

    // Reset the stack for prefix conversion
    top = -1;

    // Process the reversed expression
    for (int i = 0; i < length; i++) {
        if (is_operand(str[i])) {
            printf("%c", str[i]);
        } else if (str[i] == '(') {
            push_operator(str[i]); 
        } else if (str[i] == ')') {
            while (top != -1 && stack_operator[top] != '(') {
                pop_operator_print();
            }
            top--; // Pop '('
        } else if (is_operator_pre(str[i])) {
            while (top != -1 && is_operator_pre(stack_operator[top]) > is_operator_pre(str[i])) {
                pop_operator_print();
            }
            push_operator(str[i]);
        } else {
            printf("Invalid input\n");
        }
    }
    
    while (top != -1) {
        pop_operator_print();
    }
    
    // Reverse the result for prefix
    printf("\n");
}

int main() {
    char str[100];
    
    printf("Enter the infix expression: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; 

    int length = strlen(str);
    
    printf("Postfix expression: ");
    in_postfix(str, length);
    
    printf("\nPrefix expression: ");
    in_prefix(str, length);
    printf("\n");

    return 0;
}
