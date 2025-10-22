#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fcfs(int requests[], int n, int head)
{
    int total_movement = 0;
    int current = head;

    printf("FCFS Disk Scheduling:\n");
    printf("Sequence: %d", head);

    for (int i = 0; i < n; i++)
    {
        total_movement += abs(requests[i] - current);
        current = requests[i];
        printf(" -> %d", current);
    }

    printf("\nTotal head movement: %d\n\n", total_movement);
    return total_movement;
}

int scan(int requests[], int n, int head, int disk_size, int direction)
{
    int total_movement = 0;
    int current = head;
    int sorted_requests[100];
    int left[100], right[100];
    int left_count = 0, right_count = 0;

    for (int i = 0; i < n; i++)
    {
        sorted_requests[i] = requests[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (sorted_requests[j] > sorted_requests[j + 1])
            {
                int temp = sorted_requests[j];
                sorted_requests[j] = sorted_requests[j + 1];
                sorted_requests[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (sorted_requests[i] < head)
        {
            left[left_count++] = sorted_requests[i];
        }
        else if (sorted_requests[i] > head)
        {
            right[right_count++] = sorted_requests[i];
        }
    }

    printf("SCAN Disk Scheduling:\n");
    printf("Sequence: %d", head);

    if (direction == 1)
    {
        for (int i = 0; i < right_count; i++)
        {
            total_movement += abs(right[i] - current);
            current = right[i];
            printf(" -> %d", current);
        }

        if (right_count > 0)
        {
            total_movement += abs(disk_size - 1 - current);
            current = disk_size - 1;
            printf(" -> %d", current);
        }

        for (int i = left_count - 1; i >= 0; i--)
        {
            total_movement += abs(left[i] - current);
            current = left[i];
            printf(" -> %d", current);
        }
    }
    else
    {
        for (int i = left_count - 1; i >= 0; i--)
        {
            total_movement += abs(left[i] - current);
            current = left[i];
            printf(" -> %d", current);
        }

        if (left_count > 0)
        {
            total_movement += abs(0 - current);
            current = 0;
            printf(" -> %d", current);
        }

        for (int i = 0; i < right_count; i++)
        {
            total_movement += abs(right[i] - current);
            current = right[i];
            printf(" -> %d", current);
        }
    }

    printf("\nTotal head movement: %d\n\n", total_movement);
    return total_movement;
}

int cscan(int requests[], int n, int head, int disk_size, int direction)
{
    int total_movement = 0;
    int current = head;
    int sorted_requests[100];
    int left[100], right[100];
    int left_count = 0, right_count = 0;

    for (int i = 0; i < n; i++)
    {
        sorted_requests[i] = requests[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (sorted_requests[j] > sorted_requests[j + 1])
            {
                int temp = sorted_requests[j];
                sorted_requests[j] = sorted_requests[j + 1];
                sorted_requests[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (sorted_requests[i] < head)
        {
            left[left_count++] = sorted_requests[i];
        }
        else if (sorted_requests[i] > head)
        {
            right[right_count++] = sorted_requests[i];
        }
    }

    printf("C-SCAN Disk Scheduling:\n");
    printf("Sequence: %d", head);

    if (direction == 1)
    {
        for (int i = 0; i < right_count; i++)
        {
            total_movement += abs(right[i] - current);
            current = right[i];
            printf(" -> %d", current);
        }

        if (right_count > 0)
        {
            total_movement += abs(disk_size - 1 - current) + abs(disk_size - 1 - 0);
            current = 0;
            printf(" -> %d -> %d", disk_size - 1, current);
        }

        for (int i = 0; i < left_count; i++)
        {
            total_movement += abs(left[i] - current);
            current = left[i];
            printf(" -> %d", current);
        }
    }
    else
    {
        for (int i = left_count - 1; i >= 0; i--)
        {
            total_movement += abs(left[i] - current);
            current = left[i];
            printf(" -> %d", current);
        }
        if (left_count > 0)
        {
            total_movement += abs(0 - current) + abs(disk_size - 1 - 0);
            current = disk_size - 1;
            printf(" -> %d -> %d", 0, current);
        }
        for (int i = right_count - 1; i >= 0; i--)
        {
            total_movement += abs(right[i] - current);
            current = right[i];
            printf(" -> %d", current);
        }
    }
    printf("\nTotal head movement: %d\n\n", total_movement);
    return total_movement;
}

int main()
{
    int n, head, disk_size, direction;
    int requests[100];
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &requests[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    printf("Enter the disk size: ");
    scanf("%d", &disk_size);
    printf("Enter the direction (0 for left, 1 for right): ");
    scanf("%d", &direction);
    fcfs(requests, n, head);
    scan(requests, n, head, disk_size, direction);
    cscan(requests, n, head, disk_size, direction);
    return 0;
}