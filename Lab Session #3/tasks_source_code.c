#include <time.h>
#include <stdio.h>
#include<dos.h>

#define MAX 100

struct TASK
{
    int taskId;
    char taskTitle[MAX];
    int taskDuration; // in seconds
    int status;       // 0: idle 1: scheduled 3: completed
}

struct TASK task_arr[10];                // holds tasks
int available_tasks = 10;                // idle tasks that cn be scheduled
struct TASK task_queue[10];              // scheduled tasks
int rear = -1, front = -1, curr_max = 5; // curr max after tasks are completed
int slots = 5;                           // slots in queue

void schedule_task();
void run_task();
void display_tasks();

int main(int argc, char const *argv[])
{

    FILE *fptr;
    if ((fptr = fopen("tasks.txt", "r")) == NULL)
    {
        printf("File could not be opened\n");
        exit(1);
    }
    for (int i = 0; i <= 10; i++)
        fscanf(fptr, "%d %s %d %d", &task_arr[i].taskId, task_arr[i].taskTitle, &task_arr[i].taskDuration, &task_arr[i].status);
    while (1)
    {
        int choice;
        printf("Enter the choice: ");
        printf("1.Schedule\n2.Run\n3.Display\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            schedule_task();
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
        }
    }
    return 0;
}

int isFull()
{
    if (rear == curr_max - 1)
        return 1;
    return 0;
}

int isEmpty()
{
    if (front == -1 || front == rear + 1)
        return 1;
    return 0;
}

void schedule_task(int id)
{
    if (isFull() || available_tasks == 0)
    {
        printf("No more tasks can be scheduled\n");
        return;
    }
    printf("Here are the available tasks to be scheduled\n");
    for (int i = 0; i < 10; i++)
    {
        if (task_arr[i].status == 0)
            printf("Id: %d, Title: %s\n", task_arr[i].taskId, task_arr[i].taskTitle);
    }
    int id, n;
    printf("Enter the number of tasks to be scheduled\n");
    scanf("%d", &n);
    if (n > available_tasks || n > slots)
    {
        if (n > slots)
        {
            n = slots;
            break;
        }
        printf("There are only %d tasks to be scheduled\n", available_tasks);
        n = available_tasks;
    }

    for (int i = 1; i <= n; i++)
    {
        printf("Enter the id of the task to be scheduled: ");
        scanf("%d", &id);
        for (int i = 0; i < 10; i++)
        {
            if (id == task_arr[i].taskId)
            {
                if (task_arr[i].status != 0)
                {
                    printf("That task can't be scheduled\n");
                    return;
                }
                else
                {
                    if (rear == -1)
                        front = 0;
                    rear++, curr_max++;
                    task_queue[rear].taskId = task_arr[i].taskId;
                    task_queue[rear].taskTitle = task_arr[i].taskTitle;
                    task_queue[rear].taskDuration = task_arr[i].taskDuration;
                    task_queue[rear].status = 1;
                    task_arr[i].status = 1;
                    printf("Task has been scheduled succesfully!\nAvailable slots: %d\n", --slots);
                    return;
                }
            }
        }
    }
}

void run_task()
{
    if (isEmpty())
    {
        printf("No tasks have been scheduled\nSchedule one!\n");
        schedule_task();
    }
    while (!isEmpty())
    {
        
    }
}