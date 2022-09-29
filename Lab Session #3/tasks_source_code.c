#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct TASK
{
    int TaskID;
    char TaskTitle[100];
    int duration;
    int status; // 0 for idle, 1 for queued and 2 for completed
};

void delay(int time);
void display(struct TASK queue[]);
void schedule(struct TASK tasks[], struct TASK queue[]);
void run(struct TASK[], struct TASK[]);
int isFull();
int isEmpty();

int currentMax = 5;
int front = -1, rear = -1;

int main(int argc, char const *argv[])
{
    struct TASK tasks[10];
    int currentMAX = 5;
    struct TASK task_arr[currentMAX];

    FILE *f;
    if ((f = fopen("tasks.txt", "r+")) == NULL)
    {
        printf("The file could not be opened\n");
        exit(1);
    }
    for (int i = 0; i < 10; i++)
        fscanf(f, "%d %s %d %d", &tasks[i].TaskID, tasks[i].TaskTitle, &tasks[i].duration, &tasks[i].status);
    fclose(f);

    while (1)
    {
        printf("Select the task operation\n1.Schedule\n2.Run the tasks\n3.Display\n4.Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            schedule(tasks, task_arr);
            break;
        case 2:
            run(task_arr, tasks);
            break;
        case 3:
            display(task_arr);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid i/p\n");
            break;
        }
    }
    return 0;
}

void delay(int time)
{
    int time_ms = 1000 * time;
    clock_t start = clock();
    while (clock() < start + time_ms)
    {
    }
}

int isFull()
{
    if (rear == currentMax - 1)
        return 1;
    return 0;
}

int isEmpty()
{
    if (front == -1 || front == rear + 1)
        return 1;
    return 0;
}

void schedule(struct TASK task[], struct TASK queue[])
{
    if (isFull())
    {
        int maxwait = 0;
        for (int i = 0; i < currentMax; i++)
            maxwait += queue[i].duration;
        printf("Please wait. Min wating time: %d seconds\nMax waiting time: %d seconds\n", task[rear].duration, maxwait);
        return;
    }

    printf("Enter the task ID: ");
    int ID;
    scanf("%d", &ID);
    for (int i = 0; i < 10; i++)
    {
        if (ID == task[i].TaskID)
        {
            if (task[i].status != 0)
            {
                printf("Task cannot be scheduled\nReason: ");
                switch (task[i].status)
                {
                case 1:
                    printf("Task already Scheduled\n");
                    return;
                case 2:
                    printf("Task Completed\n");
                default:
                    return;
                }
            }
            if (front == -1)
                front = 0;
            rear += 1;
            queue[rear].duration = task[i].duration;
            queue[rear].TaskID = task[i].TaskID;
            task[i].status = 1;
            queue[rear].status = task[i].status;
            strcpy(queue[rear].TaskTitle, task[i].TaskTitle);
            printf("Task successfully scheduled\n");
            return;
        }
    }
    printf("Task not found\n");
    return;
}

void run(struct TASK queue[], struct TASK task[])
{
    printf("Running Task: %s\n", queue[front].TaskTitle);
    for (int i = 0; i < 5; i++)
    {
        printf(".");
        delay(1);
    }
    delay(queue[front].duration);
    front = front + 1;
    currentMax += 1;
    for (int i = 0; i < 10; i++)
    {
        if (queue[front].TaskID == task[i].TaskID)
        {
            task[i].status = 2;
        }
    }
    for (int i = 0; i <= 10000; i++)
    {
        printf("\rIn progress %d", i / 100);
    }
    printf("\nTask completed!\n");
}

void display(struct TASK queue[])
{
    if (isEmpty())
    {
        printf("No tasks scheduled!\n");
        return;
    }
    printf("Tasks scheduled are\n");
    for (int i = front; i <= rear; i++)
    {
        printf("ID: %d\nTitle: %s\n", queue[i].TaskID, queue[i].TaskTitle);
    }
    printf("\n");
}
