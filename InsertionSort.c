#include<stdio.h>
void InsertionSort(int arr[] ,int size){
     for(int i = 1 ; i <= size ; i++){
        int temp = arr[i];
        int j = i - 1;
        while(temp < arr[j] && j >= 0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
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
    InsertionSort(arr , size);
    for(int i = 0 ; i < size ; i++){
        printf("%d\t",arr[i]);
    }

return 0;
}