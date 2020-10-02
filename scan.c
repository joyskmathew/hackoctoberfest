#include<stdio.h>
#include<stdlib.h>

#define LOW 0
#define HIGH 199

void main(){
    int q[10],head,n,max,temp,sum,i,j,loc;
    
    printf("Enter the size of the queue: ");
    scanf("%d",&n);

    printf("Enter the head: ");
    scanf("%d",&head);

    printf("Enter the queue elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&q[i]);
    }

    q[n]=head;
    n++;

    for(i=0; i<n;i++){
    for(j=i; j<n; j++){
      if(q[i]>q[j]){
        temp = q[i];
        q[i] = q[j];
        q[j] = temp;
      }
    }
  }

  max = q[n-1];

  for(i=0; i<n; i++){
    if(head == q[i]){
      loc = i;
      break;
    }
  }
    printf("\n\nThe disk sequence is: \n");
  if(abs(head-LOW) <= abs(head-HIGH)){

      for(j=loc; j>=0; j--){
        printf("%d --> ",q[j]);
      }
      for(j=loc+1; j<n; j++){
        printf("%d --> ",q[j]);
      }

      } else {

      for(int j=loc+1; j<n; j++){
          printf("%d --> ",q[j]);
      }
      for(int j=loc; j>=0; j--){
          printf("%d --> ",q[j]);
      }
  }

  sum  = head + max;
  printf("\n\nTotal seek time: %d", sum);
  float avg=sum/(float)n;
  printf("\nAverage seek time: %f",avg);

}