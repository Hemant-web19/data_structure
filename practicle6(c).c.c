#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 100 
char stack_operand[MAX];
int top = -1;

void push(char c ){
    if (top == MAX - 1){
        printf(" stack overflow \n ");}
    else{
        top = top + 1 ;
        stack_operand[top] = c ;
    }
}
char  pop (char str []){
    if(top == -1){
        printf("stack underflow \n ");}
    else{
        return stack_operand[top--];
       
    }
}
int is_operator( char c ){
    if( c == '+' || c ==  '-' || c == '/' || c== '*'){
        return 1 ;}
    else {
        return 0;
    }
}
int evaluate_post( char str[], int length){
    int result  = 0 ;
    
    for( int i =0 ;i <length ;i++ ){
        if (isspace(str[i])) {
            continue;
        }
        else if (isdigit(str[i])){
                push(str[i]);
            }
        else if (  is_operator(str[i])){
            int num2 = pop(stack_operand) - '0';
            int num1 = pop(stack_operand) - '0';
            
            switch (str[i]) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':

                    result = num1 / num2;
                    break;
                default:
                    printf("Invalid operator.\n");}
            
            

            push( result +'0' );
            }
        else{
            printf(" invalid input \n");
            }
    }
    return result ;
    }


int main (){
    char str[MAX];
    printf("Enter the expression ");
    
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = 0;
    int length = strlen(str);
    for(int i =0 ; i<length ; i++){
        
    }

    
    int result = evaluate_post(str , length );
    printf(" result :  %d ", result);

    return 0; 
     
}