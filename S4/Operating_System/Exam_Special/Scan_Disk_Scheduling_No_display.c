#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, head, t_size, dir, i, j, temp, k = 0, k_initial = 0, seek_time = 0;

    printf("Enter the track size: ");
    scanf("%d", &t_size);
    t_size--;

    printf("Enter No.of Requests: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter the requests: ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter Initial Head Position: ");
    scanf("%d", &head);

    printf("Enter the Direction of Scan (0 = Left, 1 = Right): ");
    scanf("%d", &dir);

    for (i = 0; i < n; i++)
        for (j = 0; j < n - i - 1; j++)
            if (req[j] > req[j + 1])
            {
                temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }

    while (head > req[k])
        k++;
    k_initial = k;

    if (!dir)
    {   
        
        while(k > 0)
        {
            k--;
            seek_time += abs(req[k] - head);
            head = req[k];
        }
        seek_time += head - 0;
        head = 0; 
        k = k_initial + 1;
        while(k < n)
        {
            seek_time += abs(req[k] -head);
            head = req[k];
            k++;
        }
    }
    else
    {
        while(k < n)
        {
            seek_time += abs(req[k] - head);
            head = req[k];
            k++;
        }
        seek_time += t_size - head;
        head = t_size;
        k = k_initial;
        while(k > 0)
        {
            k--;
            seek_time += abs(req[k] - head);
            head = req[k];
        }
    }
    printf("SEEK TIME: %d\n", seek_time);
}

/*
OUTPUT: LEFT
Enter the track size: 180
Enter No.of Requests: 8
Enter the requests: 75 90 40 135 50 170 65 10          
Enter Initial Head Position: 45
Enter the Direction of Scan (0 = Left, 1 = Right): 0

OUTPUT: RIGHT
Enter the track size: 180
Enter No.of Requests: 8
Enter the requests: 75 90 40 135 50 170 65 10
Enter Initial Head Position: 45
Enter the Direction of Scan (0 = Left, 1 = Right): 1
SEEK TIME: 303
*/