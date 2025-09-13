#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* link;
};
typedef struct node node_t;
struct stack{
    node_t* top;
};
typedef struct stack stack_t;
void display(stack_t*);
void destroy(stack_t*);
int push(stack_t*,int);
int pop(stack_t*);
int peek(stack_t*);
void init(stack_t*);
int main(){
    int ch,k,x,key;
    stack_t stk;
    init(&stk);
    while(1){
        display(&stk);
        printf("\n1..push");
        printf("\n2..pop");
        printf("\n3..display");
        printf("\n4..peek");
        printf("\n5..destroy");
        printf("\n6..exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("enter the element\n");
            scanf("%d",&key);
            k=push(&stk,key);
            if(k>0){
                printf("element pushed succesfully\n");
            }
            break;
            case 2:
            k=pop(&stk);
            if(k>0){
                printf("element poped is %d\n",k);
            }
            break;
            case 3:
            display(&stk);
            break;
            case 4:
            k=peek(&stk);
            if(k!=-1){
                printf("top element is %d\n",k);
            }
            break;
            case 5:
            destroy(&stk);
            printf("destroyed successfully\n");
            break;
            case 6:
            exit(0);
        }
    }
}
void display(stack_t* ptr_stk){
    node_t* pres;
    if(ptr_stk->top==NULL){
        printf("stack is empty\n");
        return;
    }
    pres=ptr_stk->top;
    while(pres!=NULL){
        printf("%d->",pres->data);
        pres=pres->link;
    }
    printf("NULL\n");
}
void destroy(stack_t* ptr_stk)
{
    node_t *pres,*temp;
    if(ptr_stk->top==NULL){
        printf("list is empty\n");
        return;
    }
    pres=ptr_stk->top;
    while(pres!=NULL){
        temp=pres;
        pres=pres->link;
        free(temp);
    }
    ptr_stk->top=NULL;
}
int push(stack_t* ptr_stk,int key)
{
    node_t* temp=(node_t*)malloc(sizeof(node_t));
    temp->data=key;
    temp->link=ptr_stk->top;
    ptr_stk->top=temp;
}
int pop(stack_t* ptr_stk){
    node_t* pres;
    if(ptr_stk->top==NULL){
        printf("stack is empty\n");
        return 0;
    }
    pres=ptr_stk->top;
    int x=pres->data;
    ptr_stk->top=pres->link;
    free(pres);
    return x;
}
int peek(stack_t* ptr_stk){
    node_t* pres;
    if(ptr_stk->top==NULL){
        printf("stack is empty\n");
        return -1;
    }
    pres=ptr_stk->top;
    int x=pres->data;
    return x;
}
void init(stack_t* ptr_stk){
    ptr_stk->top=NULL;
}
