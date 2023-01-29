#include<stdio.h>
void SelectionSort(int arr[] ,int size){
    for(int i = 0 ; i < size ; i++){
        for(int j = i+1 ; j < size ; j++){
            //6 3 4 2 5
            if(arr[j] < arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
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
    SelectionSort(arr , size);
    for(int i = 0 ; i < size ; i++){
        printf("%d\t",arr[i]);
    }

return 0;
}