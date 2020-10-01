#include <stdio.h>
#include <stdlib.h>

#define HIGH 199
#define LOW 0

void main()
{
    int q[20], n, head, i, j, seek = 0, diff, max, temp, q1[20], q2[20], temp1 = 0, temp2 = 0;
    float avg;

    printf("Enter the size of the queue: ");
    scanf("%d", &n);

    printf("Enter the head position: ");
    scanf("%d", &head);

    printf("Enter the queue elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        if (temp >= head)
        {
            q1[temp1] = temp;
            temp1++;
        }
        else
        {
            q2[temp2] = temp;
            temp2++;
        }
    }

    for (i = 0; i < temp1 - 1; i++)
    {
        for (j = i + 1; j < temp1; j++)
        {
            if (q1[i] > q1[j])
            {
                temp = q1[i];
                q1[i] = q1[j];
                q1[j] = temp;
            }
        }
    }

    for (i = 0; i < temp2 - 1; i++)
    {
        for (j = i + 1; j < temp2; j++)
        {
            if (q2[i] > q2[j])
            {
                temp = q2[i];
                q2[i] = q2[j];
                q2[j] = temp;
            }
        }
    }

    if (abs(head - LOW) >= abs(head - HIGH))
    {

        for (i = 1, j = 0; j < temp1; i++, j++)
        {
            q[i] = q1[j];
        }

        q[i] = HIGH;
        q[i + 1] = 0;

        for (i = temp1 + 3, j = 0; j < temp2; i++, j++)
        {
            q[i] = q2[j];
        }
    }
    else
    {

        for (i = 1, j = temp2 - 1; j >= 0; i++, j--)
        {
            q[i] = q2[j];
        }

        q[i] = LOW;
        q[i + 1] = HIGH;

        for (i = temp2 + 3, j = temp1 - 1; j >= 0; i++, j--)
        {
            q[i] = q1[j];
        }
    }

    q[0] = head;

    printf("\nFROM\tTO\tSEEK");
    for (i = 0; i <= n; i++)
    {
        diff = abs(q[i + 1] - q[i]);
        seek += diff;
        printf("\n%d\t%d\t%d", q[i], q[i + 1], diff);
    }
    
    seek=seek-HIGH;
    
    printf("\nThe total seek time: %d", seek);
    avg = seek / (float)n;
    printf("\nThe average seek time: %f", avg);
    
}