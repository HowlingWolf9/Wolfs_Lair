#include <stdio.h>
#include <stdlib.h>
void display(int k)
{
    printf("\t");
    for (int i = 0; i < k; i++)
        printf("\t");
    printf("    +\n");
}

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

    //Sort Requests
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
    
    printf("k = %d\n", k);

    printf("|0\t|");
    for (i = 0; i < n; i++)
    {
        if (i == k)
            printf("%d\t|", head);
        printf("%d\t|", req[i]);
    }
    printf("%d\t|\n", t_size);
    display(k);

    if (!dir)
    {   
        
        while(k > 0)
        {
            k--;
            seek_time += abs(req[k] - head);
            head = req[k];
            display(k);
        }

        seek_time += head - 0;
        head = 0; 
        printf("    +\n");
        k = k_initial + 1;
        display(k);
        while(k < n)
        {
            seek_time += abs(req[k] -head);
            head = req[k];
            k++;
            display(k);
        }
    }
    else
    {
        while(k < n)
        {
            seek_time += abs(req[k] - head);
            head = req[k];
            k++;
            display(k);
        }

        seek_time += t_size - head;
        head = t_size;
        for (i = 0; i < n + 2; i++)
            printf("\t");
        printf("    +\n");
        k = k_initial;
        while(k > 0)
        {
            k--;
            seek_time += abs(req[k] - head);
            head = req[k];
            display(k);
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
k = 2
|0      |10     |40     |45     |50     |65     |75     |90     |135    |170    |179    |
                            +
                    +
            +
    +
                                    +
                                            +
                                                    +
                                                            +
                                                                    +
                                                                            +
SEEK TIME: 215

OUTPUT: RIGHT
Enter the track size: 180
Enter No.of Requests: 8
Enter the requests: 75 90 40 135 50 170 65 10
Enter Initial Head Position: 45
Enter the Direction of Scan (0 = Left, 1 = Right): 1
k = 2
|0      |10     |40     |45     |50     |65     |75     |90     |135    |170    |179    |
                            +
                                    +
                                            +
                                                    +
                                                            +
                                                                    +
                                                                            +
                                                                                    +
                    +
            +
SEEK TIME: 303
*/