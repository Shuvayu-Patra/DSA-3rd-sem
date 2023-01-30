#include <stdio.h>
void Merge(int arr[], int s, int mid, int e)
{
    int left = mid - s + 1;
    int right = e - mid;
    int arr1[left], arr2[right];
    for (int i = 0; i < left; i++)
    {
        arr1[i] = arr[s + i];
    }
    for (int i = 0; i < right; i++)
    {
        arr2[i] = arr[mid + i + 1];
    }
    int temp[left + right];
    int i = 0, j = 0, k = 0;
    while (i < left && j < right)
    {
        if (arr1[i] < arr2[j])
        {
            temp[k++] = arr1[i++];
        }
        else
        {
            temp[k++] = arr2[j++];
        }
    }
    while (i < left)
    {
        temp[k++] = arr1[i++];
    }

    while (j < right)
    {
        temp[k++] = arr2[j++];
    }

    for (int i = 0, k = s; i < sizeof(temp) / sizeof(temp[0]); i++, k++)
    {
        arr[k] = temp[i];
    }
}
void MergeSort(int arr[], int s, int e)
{
    //      if(s > e){
    //     return;
    // }
    // int mid = s + (e - s)/2;
    // MergeSort(arr , s , mid - 1);
    // MergeSort(arr , mid , e);
    // //merge
    // Merge(arr , s , mid , e);

    if (s < e)
    {
        int mid = s + (e - s) / 2;
        MergeSort(arr, s, mid);
        MergeSort(arr, mid + 1, e);
        // merge
        Merge(arr, s, mid, e);
    }
}
int main()
{
    int size;
    printf("Enter The Size : ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Ater Sort : ");
    MergeSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}