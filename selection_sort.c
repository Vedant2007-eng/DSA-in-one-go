#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, maxIndex, temp;

    for(i = 0; i < n-1; i++){
        maxIndex = i;

        for(j = i+1; j < n; j++){
            if(arr[j]> arr[maxIndex]){
                maxIndex = j;
            }
        }
        if(maxIndex != i){
            int temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }
}
int main(){
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i=0; i<n; i++) {
        scanf("%d",&arr[i]);
    }

    selectionSort(arr,n);

    for(int i = 0; i<n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");

    return 0;
}
