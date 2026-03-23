<<<<<<< HEAD
#include<stdio.h>
int main(){
    int n,pos;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    scanf("%d",&pos);
    if(pos<1||pos>n){
        printf("ERROR Position!\n");
        return 1;
    }
    for(int i=pos-1;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    for(int i=0;i<n-1;i++){
        printf("%d ",arr[i]);
        
    }
printf("\n");
    return 0;

=======
#include<stdio.h>
int main(){
    int n,pos;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    scanf("%d",&pos);
    if(pos<1||pos>n){
        printf("ERROR Position!\n");
        return 1;
    }
    for(int i=pos-1;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    for(int i=0;i<n-1;i++){
        printf("%d ",arr[i]);
        
    }
printf("\n");
    return 0;

>>>>>>> 5835556b807c3604a065f6dac259e93d7a0287cf
}