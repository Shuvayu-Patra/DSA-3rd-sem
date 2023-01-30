#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node*head = NULL;
//struct node *tail = NULL;
void InsertAtBeginning(){
    int data;
    printf("Enter Data : \n");
    scanf("%d",&data);
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(head == NULL){
        temp -> data = data;
        head = temp;
        temp -> next = NULL;
        return;
    }
    else if(head != NULL){
        temp -> next = head;
        head = temp;
        temp -> data = data;
        return;
    }

}
void InsertAtPos(){
    int pos;
    printf("Enter The Position : \n");
    scanf("%d",&pos);
    if(pos == 1){
        InsertAtBeginning();
        return;
    }
    int data;
    printf("enter Data : ");
    scanf("%d",&data);
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    struct node * curr = head;
    int i = 1;
    while(i < pos - 1){
        curr = curr -> next;
        i++;
    }
        temp -> next = curr -> next;
        curr -> next = temp;
        temp -> data = data;

}
void InsertAtEnd(){
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    int data;
    printf("Enter Data : ");
    scanf("%d",&data);
    if(head == NULL){
        temp -> next = NULL;
        head = temp;
        temp -> data = data;
    }
    else{
        struct node * curr = head;
        while(curr -> next != NULL){
            curr = curr -> next;
        }
        temp -> next = NULL;
        curr -> next = temp;
        temp -> data = data; 
    }

}

void DeleteFromBeginning(){
    struct node * curr = head;
    head = curr -> next;
    curr -> next = NULL;
    printf("%d is deleted" , curr -> data);
    free(curr);
}

void DeleteFromPosition(){
    int pos;
    printf("Enter Position : ");
    scanf("%d",&pos);
        if(pos == 1){
        DeleteFromBeginning();
        return;
    }
    int i = 1;
    struct node * curr = head;
    struct node * pre  = NULL;
    while(i < pos){
        pre = curr;
        curr = curr -> next;
        i++;
    }
    pre -> next  = curr -> next;
    curr -> next = NULL;
    printf("%d is deleted", curr -> data);
    free(curr);
}
void DeleteFromEnd(){
    struct node * curr = head;
    struct node * pre  = NULL;
    while(curr -> next != NULL){
        pre = curr;
        curr = curr -> next;
    }
    pre -> next  = curr -> next;
    curr -> next = NULL;
    printf("%d is deleted", curr -> data);
    free(curr);
}

void Reverse(){
    struct node * prev = NULL;
    struct node * curr = head;
    struct node * forward = NULL;
    while(curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
    return;
}
void Display(){
    struct node * temp = head;
    while(temp != NULL){
        printf("%d -> ",temp -> data);
        temp = temp -> next;
    }
    printf("X \n");
}
int main()
{
    int ch;
    while(1){
        printf("Enter Your choice: \n");
        printf("Enter 1 to insert at beginning\n");        
        printf("Enter 2 to insert at Given Position\n");        
        printf("Enter 3 to insert at end\n");
        printf("Enter 4 to Delete from Beginning\n");
        printf("Enter 5 to Delete from position\n");
        printf("Enter 6 to Delete from end\n");
        printf("Enter 7 to Reverse the list\n");
        printf("Enter 8 to Display\n");        
        printf("Enter 9 to Exit\n"); 


        scanf("%d",&ch);
        switch(ch){
            case 1:
                InsertAtBeginning();
                break;
            case 2:
                InsertAtPos();
                break;
            case 3:
                InsertAtEnd ();
                break;
            case 4:
                DeleteFromBeginning();
                break;
            case 5:
                DeleteFromPosition();
                break;
            case 6:
                DeleteFromEnd();
                break;
            case 7:
                Reverse();
                break;
            case 8:
                Display ();
                break;
            case 9:
                exit(1);
            default:
                printf("Invalid Choice!\n");
                break;
        }       

        
   }
return 0;
}