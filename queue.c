#include<stdio.h>
#include<stdlib.h>
#define size 10
int queue[size];
int front = -1;
int rear = -1;
void enqueue(int data){
    if(rear == size-1){
        printf("Overflow\n");
        return;
    }
    else if(front==-1 && rear==-1){
        front = rear = 0;
    }
    else{
        rear++;
    }
    queue[rear]=data;
    printf("Data is pushed in queue!\n\n");
}
void Dequeue(){
    if(front == -1 && rear == -1){
        printf("Underflow\n");
        return;
    }
    else if(front == rear && front!=-1){
        front = rear = -1;
        return;
    }
    printf("%d is deleted\n\n",queue[front]);
    front++;
}
void display(){
    if (front==-1){
        printf("Queue empty\n");
        return;
    }
    else{
    for(int i=front;i<=rear;i++){
        printf("%d",queue[i]);
     }
    }
}
void peek(){
    if(front == rear == -1){
        printf("underflow\n");
    }
    else printf("%d\n" , queue[front]);
}
int main()
{
    int ch;
    int data;
    while(1){
        printf("Enter 1 to enqueue element\t 2 to Dequeue \t 3 to Display \t 4 to peek \t 5 to exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter Data to push : \n");
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                display();
                printf("\n");
                break;
            case 4:
                peek();
                break;
            case 5:
                exit(1);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

return 0;
}