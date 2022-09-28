#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASK 5
#define TOTAL_TASKS 10

struct TASK
{
    int TaskID;
    char TaskTitle[100];
    int duration;
    int status; // 0 for idle, 1 for queued and 2 for completed
};

void delay(int time){
    int time_ms=1000*time;
    clock_t start = clock();
    while(clock()<start+time_ms){
        printf(". ");
    }
    printf("\n");
}

void display(struct TASK []);
void schedule(struct TASK[], struct TASK[]);
void run(struct TASK [], struct TASK []);
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
    if ((f = fopen("tasks.txt", "r")) == NULL)
    {
        printf("The file could not be opened\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 10; i++)
    {
        fscanf(f, "%d %s %d %d", tasks[i].TaskID, tasks[i].TaskTitle, tasks[i].duration, tasks[i].status);
    }
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
            run();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(EXIT_SUCCESS);
        default:
            printf("Invalid i/p\n");
            break;
        }
    }
    return 0;
}

int isFull()
{
    rear == MAX - 1 ? return 1 : return 0;
}

int isEmpty()
{
    if (front == -1 || front == rear + 1)
        return 1;
    return 0;
}

void schedule(struct TASK task_arr[], struct TASK queue[])
{
    if (isFull())
    {
        int maxwait = 0;
        for (int i = 0; i < currentMax; i++)
            maxwait += queue[i].duration;
        printf("Please wait. Min wating time: %d seconds\nMax waiting time: %d seconds\n", task_arr[rear].duration, maxwait);
        return;
    }

    printf("Enter the task ID: ");
    int ID;
    scanf("%d", &ID);
    for (int i = 0; i < 10; i++)
    {
        if (ID == task_arr[i].TaskID)
        {
            if (task_arr[i].status != 0)
            {
                printf("Task cannot be scheduled\nReason: ");
                switch (task_arr[i].status)
                {
                case 1:
                    printf("Task already Scheduled\n");
                    return;
                case 2:
                    printf("Task Completed\n");
                default:
                    return;
                }
                return;
            }
            if (front == -1)
                front = 0;
            rear += 1;
            queue[rear].duration=task_arr[i].duration;
            queue[rear].TaskTitle=task_arr[i].TaskTitle;
            queue[rear].TaskID=task_arr[i].TaskID;
            queue[rear].status=task_arr[i].status;
            task_arr[i].TaskID=1;
            printf("Task successfully scheduled\n");
            return;
        }
    }
    printf("Task not found\n");
    return;
}

void run(struct TASK queue[], struct TASK task_arr[]){
    printf("Running Task: %s\n", queue[rear].TaskTitle);
    delay(queue[rear].duration);
    front=front+1;
    currentMax+=1;
    for(int i=0;i<10;i++){
        if(queue[rear].TaskID==task_arr[i].TaskID){
            task_arr[i].status=2;
        }
    }
    printf("Task completed!\n");
}

void display(struct TASK queue[]){
    if(isEmpty()){
        printf("No tasks scheduled!\n");
        return;
    }
    printf("Tasks scheduled are\n");
    for(int i=front;i<=rear;i++){
        printf("ID: %d\nTitle: %s\n", queue[i].TaskID, queue[i].TaskTitle);
    }
}
