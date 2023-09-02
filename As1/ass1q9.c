#include<stdio.h>
#include<stdlib.h>

int main(){
        int n,m,i,j;
        printf("Enter dimension of array: ");
        scanf("%d %d", &n, &m);
        int a[m*n];
        printf("Enter element of array:\n");
        for(i=0; i<n; i++){
                for(j=0; j<m; j++){
                        scanf("%d" , &a[i*m+j]);
                }
        }
        printf("Entered elements are:\n");
        for(i=0; i<n; i++){
                for(j=0; j<m; j++){
                        printf("%d " , a[i*m+j]);
                }
                printf("\n");
        }

        return 0;
}
