#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemStack{
    char string[61];
    struct elemStack *next;
};
typedef struct elemStack ElemStack;

struct stack{
    ElemStack *top;

};
typedef struct stack Stack;

void iniStack(Stack *stack){
    stack->top = NULL;
}

int voidStack(Stack *stack){
    return (stack->top == NULL);
}
void releaseStack(Stack *stack){
    if(voidStack(stack)){
        printf("!");
    }
    else{
    ElemStack *aux;
    while(stack->top !=NULL){
        aux = stack->top;
        stack->top = stack->top->next;
        printf("@");
        free(aux);
    }
    }
}
void push(Stack *stack, const char string[61]){
    ElemStack *aux;
    aux = (ElemStack *) malloc(sizeof(ElemStack));
    strcpy(aux->string, string);
    aux->next = stack->top;
    stack->top = aux;
}
void pop(Stack *stack){
    ElemStack *aux = stack->top;
    stack->top = stack->top->next;
    free(aux);

}

int main(){
    Stack site;
    iniStack(&site);
    while(1){
        char string[61]; scanf("%s",string);
        if(!strcmp(string,"B")){
            if(voidStack(&site)){
                printf("Vazio\n");
            }
            else{
            printf("%s\n",site.top->string);
            pop(&site);}
        }
        else if(!strcmp(string,"E")){
            releaseStack(&site);
            break;
        }
        else{
            push(&site, string);
        }
    }
    printf("\n");

    return 0;
}
