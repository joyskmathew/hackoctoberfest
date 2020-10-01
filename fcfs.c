#include<stdio.h>
#include<stdlib.h>

void main(){
    
    int q[10],n,head,seek=0,diff,i;
    float avg;

    printf("Enter the size of the queue: ");
    scanf("%d",&n);

    printf("Enter the queue elements: ");
    for(i=1;i<=n;i++){
        scanf("%d",&q[i]);
    }

    printf("Enter the head element: ");
    scanf("%d",&head);

    q[0]=head;

    printf("\nFROM\tTO\tSEEK");
    for(i=0;i<=n-1;i++){
        diff = abs(q[i]-q[i+1]);
        seek += diff;
        printf("\n%d\t%d\t%d",q[i],q[i+1],diff);
    }

    printf("\nThe total seek time: %d",seek);
    avg=seek/(float)n;
    printf("\nThe average seek time: %f",avg);
}