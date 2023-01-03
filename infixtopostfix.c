#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct stack{
    char data;
    struct stack* next;
}*top,*head,*newnode,*temp;
#define size 1000
char infix[size],postfix[size];
int charindex;
typedef struct stack stack;
void push(char x){
    newnode=(stack*)malloc(sizeof(stack));
    newnode->data=x;
    newnode->next=NULL;
    if(top==NULL){
        top=newnode;
        head=newnode;
    }
    else{
        newnode->next=top;
        top=newnode;
    }
}
void pop(){
    if(top==NULL)
        printf("Stack is empty");
    else{
        temp=top;
        top=top->next;
        temp->next=NULL;
    }
}
int precedence(char x){
    if(x=='(')
        return 0;
    else if(x=='+'||x=='-')
        return 1;
    else if(x=='*'||x=='/')
        return 2;
    else if(x=='^')
        return 3;
    return 0;
}
void infixTOpostfix(char var){
    if(isalnum(var)){
        postfix[charindex]=var;
        charindex++;
    }
    else if(var=='('){
        char a='(';
        push(a);
    }
    else if(var==')'){
        while(top->data!='('){
            postfix[charindex]=top->data;
            charindex++;
            pop();
        }
        pop();
    }
    else{
        while(precedence(top->data)>=precedence(var)){
            postfix[charindex]=top->data;
            charindex++;
            pop();
        }
        push(var);
    }
}
int main(){
    charindex=0;
    printf("Enter the string:");
    gets(infix);
    char a='(';
    push(a);
    strcat(infix,")");
    int length=strlen(infix);
    for(int i=0;i<length;i++){
        infixTOpostfix(infix[i]);
    }
    printf("\nPostfix expression is:");
    puts(postfix);
}
