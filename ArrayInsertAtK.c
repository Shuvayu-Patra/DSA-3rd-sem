#include<stdio.h>
void InsertAtK(int arr[], int size){
    int pos , data;
    label:
    printf("Enter the position: ");
    scanf("%d", &pos);
    if(pos > size || pos < 0){
        printf("Invalid Choice!\n");
        goto label;
    }
    else{
        printf("Enter the data : ");
        scanf("%d",&data);
        for(int i = size -1 ; i >= pos - 1 ; i--){
            arr[i+1] = arr[i];
        }
        arr[pos - 1 ] = data;
    }

}
int main()
{
    int size;
    printf("Enter The Size : ");
    scanf("%d",&size);
    int arr[size+1];
    printf("Enter the elements : ");
    for(int i = 0 ; i < size ; i++){
        scanf("%d",&arr[i]);
    }
    InsertAtK(arr,size);
    for(int i = 0 ; i <= size ; i++){
        printf("%d\t",arr[i]);
    }

return 0;
}