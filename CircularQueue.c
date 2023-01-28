#include<stdio.h>
#include<stdlib.h>
#define size 3
int CQ[size];
int front = -1;
int rear = -1;
void enqueue(){
    int data;
    printf("Enter data : ");
    scanf("%d",&data);
    if(front == 0 && rear == size-1 || front == rear+1){
        printf("Overflow\n");
        return;
    }
    else if(rear == size - 1){
        rear = (rear+1)%size;
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
    }
    else{
        rear++;
    }
    CQ[rear] = data;
    printf("Data is pushed!\n");

}

void Dequeue(){
    if(front == -1 && rear == -1){
        printf("Underflow\n");
    }
    else if(front == rear && front != -1){
        front = rear = -1;
    }
    if(front == size - 1){
        front = (front+1)%size;
    }
    else{
        front++;
    }
}

void display(){
    if(front < rear){
        for(int i = front ; i <= rear ; i++){
            printf("%d\t",CQ[i]);
        }
    }
    else if(front > rear){
        for(int i = front ; i < size ; i++){
            printf("%d\t",CQ[i]);
        }
        for(int i = 0 ; i <= rear ; i++){
            printf("%d\t",CQ[i]);
        }
    }
}
int main()
{
    int ch;
    while(1){
        printf("Enter 1 to enqueue element\t 2 to Dequeue \t 3 to Display \t 4 to exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                enqueue();
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                display();
                printf("\n");
                break;
            case 4:
                exit(1);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

return 0;
}