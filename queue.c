#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int *item;
    int f,r,size;
};
typedef struct queue queue_t;
int qinsert(queue_t*,int);
int qdelete(queue_t*);
void display(queue_t*);
void init(queue_t*);
int main()
{
    queue_t q;
    int ch,k,x;
    init(&q);
    while(1)
    {
        display(&q);
        printf("\n1..insert");
        printf("\n2..delete");
        printf("\n3..display");
        printf("\n4..eixt");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("enter the value..\n");
                scanf("%d",&x);
                k=qinsert(&q,x);
                if(k>0)
                    printf("Element inserted successfully\n");
                break;
            case 2:
                k=qdelete(&q);
                printf("element deleted =%d\n",k);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);

        }
    }
}
void init(queue_t* ptr_q)
{
    printf("enter the size of the queue..\n");
    scanf("%d",&ptr_q->size);
    ptr_q->item=(int*)malloc(ptr_q->size*(sizeof(int)));
    ptr_q->f=ptr_q->r=-1;
}
int qinsert(queue_t *ptr_q,int x)
{
    if(ptr_q->r==ptr_q->size-1)
    {
        printf("queue is full..cannot insert");
        return 0;
    }
    ptr_q->r++;
    ptr_q->item[ptr_q->r]=x;
    if(ptr_q->f==-1)
        ptr_q->f=0;
    return 1;

}
int qdelete(queue_t *ptr_q)
{
    int x;
    if(ptr_q->f==-1)
    {
        printf("queue empty..cannot delete\n");
        return 0;
    }
    x=ptr_q->item[ptr_q->f];
    if(ptr_q->f==ptr_q->r){
        ptr_q->f=ptr_q->r=-1;
    }
    else{
        ptr_q->f++;
    }
    return x;
}
void display(queue_t *ptr_q)
{
    int i;
    if(ptr_q->f==-1)
        printf("empty queue..\n");
    else
        for(i=ptr_q->f;i<=ptr_q->r;i++)
        printf("%d ",ptr_q->item[i]);
}
