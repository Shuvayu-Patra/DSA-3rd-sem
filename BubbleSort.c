#include<stdio.h>
void BubbleSort(int arr[] , int size){
    for(int i = 0; i < size ; i++){
        for(int j = 0 ; j < size-i-1 ; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
} 
int main()
{
    
    int size;
    printf("Enter The Size : ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the elements : ");
    for(int i = 0 ; i < size ; i++){
        scanf("%d",&arr[i]);
    }
    printf("Ater Sort : ");
    BubbleSort(arr , size);
    for(int i = 0 ; i < size ; i++){
        printf("%d\t",arr[i]);
    }
return 0;
}