#include<stdio.h>
void main() {
    int flag = 0, n, arr[100], i;
    int key;
    int pos = -1;
    scanf("%d",&n);

    for(i = 0; i < n; i++){
        scanf("%d",&key);
    }
    scanf("%d",&key);{
        for(i = 0; i < n; i++)
            if(arr[i] == key){
                flag = 1;
                pos = i;
                break;
            }
    }
    if (flag == 1){
        printf("found at position %d\n", pos);
    }
    else{
        printf("%d not found\n", key);
    }
}
