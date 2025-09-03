#include <stdio.h>
#include <stdlib.h>
int qinsert(int,int*,int*,int*,int);
int qdelete(int *,int *,int *);
void display(int *,int,int);
int main()
{
    int *q;
    int ch,k,x;
    int f,r,size;
    f=r=-1;
    printf("enter the size of the queue..\n");
    scanf("%d",&size);
    q=(int*)malloc(sizeof(int)*size);
    while(1)
    {
        display(q,f,r);
        printf("\n1..insert");
        printf("\n2..delete");
        printf("\n3..display");
        printf("\n4..exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("enter the value..");
                scanf("%d",&x);
                k=qinsert(x,q,&f,&r,size);
                if(k>0)
                    printf("element inserted successfully\n");
                break;
            case 2:
                k=qdelete(q,&f,&r);
                if(k>0)
                    printf("element deleted=%d\n",k);
                break;
            case 3:
                display(q,f,r);
                break;
            case 4:
                exit(0);
        }
    }
}
int qinsert(int x,int *q,int *f,int *r,int size){
    if(*r==size-1){
        printf("queue full.. cannot insert..\n");
        return 0;
    }
    (*r)++;
    q[*r]=x;
    if(*f==-1)
        *f=0;
    return 1;
}
int qdelete(int *q,int *f,int *r)
{
    int x;
    if(*f==-1)
    {
        printf("empty queue..\n");
        return -1;
    }
    x=q[*f];
    if(*f==*r)//only one element
        *f=*r=-1;
    else
        (*f)++;
    return x;
}
void display(int *q,int f,int r)
{
    int i;
    if(f==-1)
        printf("queue is empty..\n");
    else{
        for(i=f;i<=r;i++)
            printf("%d ",q[i]);
    }
    printf("\n");
}
