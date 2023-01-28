#include<stdio.h>
#include<stdlib.h>
#define size 5
int stack[size];
int top = -1;
void push(int data){
    if(top == size - 1){
        printf("Overflow\n");
        return;
    }
    top++;
    stack[top] = data;
    printf("%d is pushed in stack\n",data);
}

void pop(){
    if(top == -1){
        printf("Underflow\n");
        return;
    }
    printf("%d is deleted",stack[top]);
    top--;
}

void display(){
    printf("stack is : \n");
    for(int i = top ; i >= 0 ; i--){
        printf("%d\t",stack[i]);
    }
}

void peek(){
    if(top==-1){
        printf("empty\n");
    }
    else printf("%d\n" , stack[top]);
}
int main()
{
    int ch;
    int data;
    while(1){
        printf("Enter your choice:\n");
        printf("Enter 1 to push element\n 2 to pop\n 3 to Display\n 4 to peek\n 5 to exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter Data to push : ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                printf("\n");
                break;
            case 4:
                peek();
                break;
            case 5:
                printf("Program ended!");
                exit(1);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

return 0;
}