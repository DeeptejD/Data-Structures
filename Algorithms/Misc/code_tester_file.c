// // /* C program for Merge Sort */
// // #include <stdio.h>
// // #include <stdlib.h>

// // // Merges two subarrays of arr[].
// // // First subarray is arr[l..m]
// // // Second subarray is arr[m+1..r]
// // void merge(int arr[], int l, int m, int r)
// // {
// //     int i, j, k;
// //     int n1 = m - l + 1;
// //     int n2 = r - m;

// //     /* create temp arrays */
// //     int L[n1], R[n2];

// //     /* Copy data to temp arrays L[] and R[] */
// //     for (i = 0; i < n1; i++)
// //         L[i] = arr[l + i];
// //     for (j = 0; j < n2; j++)
// //         R[j] = arr[m + 1 + j];

// //     /* Merge the temp arrays back into arr[l..r]*/
// //     i = 0; // Initial index of first subarray
// //     j = 0; // Initial index of second subarray
// //     k = l; // Initial index of merged subarray
// //     while (i < n1 && j < n2)
// //     {
// //         if (L[i] <= R[j])
// //         {
// //             arr[k] = L[i];
// //             i++;
// //         }
// //         else
// //         {
// //             arr[k] = R[j];
// //             j++;
// //         }
// //         k++;
// //     }

// //     /* Copy the remaining elements of L[], if there
// //     are any */
// //     while (i < n1)
// //     {
// //         arr[k] = L[i];
// //         i++;
// //         k++;
// //     }

// //     /* Copy the remaining elements of R[], if there
// //     are any */
// //     while (j < n2)
// //     {
// //         arr[k] = R[j];
// //         j++;
// //         k++;
// //     }
// // }

// // /* l is for left index and r is right index of the
// // sub-array of arr to be sorted */
// // void mergeSort(int arr[], int l, int r)
// // {
// //     if (l < r)
// //     {
// //         // Same as (l+r)/2, but avoids overflow for
// //         // large l and h
// //         int m = l + (r - l) / 2;

// //         // Sort first and second halves
// //         mergeSort(arr, l, m);
// //         mergeSort(arr, m + 1, r);

// //         merge(arr, l, m, r);
// //     }
// // }

// // /* UTILITY FUNCTIONS */
// // /* Function to print an array */
// // void printArray(int A[], int size)
// // {
// //     int i;
// //     for (i = 0; i < size; i++)
// //         printf("%d ", A[i]);
// //     printf("\n");
// // }

// // int main(int argc, char const *argv[])
// // {
// //     int n;
// //     printf("Enter number of elements: ");
// //     scanf("%d", &n);
// //     int arr[n];
// //     printf("Insert elements\n");
// //     for (int i = 0; i < n; i++)
// //         scanf("%d", &arr[i]);
// //     printArray(arr, n);
// //     printf("Sorted array: ");
// //     mergeSort(arr, 0, n - 1);
// //     printArray(arr, n);
// //     return 0;
// // }

// // Code to generate a random word in c
// // #include <stdio.h>
// // #include <stdlib.h>
// // #include <time.h>

// // int main()
// // {
// //     srand(time(0));
// //     int n = rand() % 10 + 1;
// //     char word[n];
// //     for (int i = 0; i < n; i++)
// //     {
// //         word[i] = rand() % 26 + 97;
// //     }
// //     word[n] = '\0';
// //     printf("%s", word);
// //     return 0;
// // }

// // flappy bird game
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <conio.h>
// #include <windows.h>
// #include <stdbool.h>

// #define WIDTH 20
// #define HEIGHT 20

// int x, y, fruitX, fruitY, score;
// int tailX[100], tailY[100];
// int nTail;
// bool gameOver;

// void setup()
// {
//     gameOver = false;
//     x = WIDTH / 2;
//     y = HEIGHT / 2;
// label1:
//     fruitX = rand() % WIDTH;
//     if (fruitX == 0)
//         goto label1;
// label2:
//     fruitY = rand() % HEIGHT;
//     if (fruitY == 0)
//         goto label2;
//     score = 0;
// }

// void draw()
// {
//     system("cls");
//     for (int i = 0; i < WIDTH + 2; i++)
//         printf("#");
//     printf("");
//     for (int i = 0; i < HEIGHT; i++)
//     {
//         for (int j = 0; j < WIDTH; j++)
//         {
//             if (j == 0)
//                 printf("#");
//             if (i == y && j == x)
//                 printf("O");
//             else if (i == fruitY && j == fruitX)
//                 printf("F");
//             else
//             {
//                 bool print = false;
//                 for (int k = 0; k < nTail; k++)
//                 {
//                     if (tailX[k] == j && tailY[k] == i)
//                     {
//                         printf("o");
//                         print = true;
//                     }
//                 }
//                 if (!print)
//                     printf(" ");
//             }
//             if (j == WIDTH - 1)
//                 printf("#");
//         }
//         printf("");
//     }
//     for (int i = 0; i < WIDTH + 2; i++)
//         printf("#");
//     printf("");
//     printf("Score: %d", score);
// }

// void input()
// {
//     if (kbhit())
//     {
//         switch (getch())
//         {
//         case 'a':
//             x--;
//             break;
//         case 'd':
//             x++;
//             break;
//         case 'w':
//             y--;
//             break;
//         case 's':
//             y++;
//             break;
//         case 'x':
//             gameOver = true;
//             break;
//         }
//     }
// }

// void logic()
// {
//     int prevX = tailX[0];
//     int prevY = tailY[0];
//     int prev2X, prev2Y;
//     tailX[0] = x;
//     tailY[0] = y;
//     for (int i = 1; i < nTail; i++)
//     {
//         prev2X = tailX[i];
//         prev2Y = tailY[i];
//         tailX[i] = prevX;
//         tailY[i] = prevY;
//         prevX = prev2X;
//         prevY = prev2Y;
//     }
//     if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
//         gameOver = true;
//     for (int i = 0; i < nTail; i++)
//     {
//         if (tailX[i] == x && tailY[i] == y)
//             gameOver = true;
//     }
//     if (x == fruitX && y == fruitY)
//     {
//     label3:
//         fruitX = rand() % WIDTH;
//         if (fruitX == 0)
//             goto label3;
//     label4:
//         fruitY = rand() % HEIGHT;
//         if (fruitY == 0)
//             goto label4;
//         score += 10;
//         nTail++;
//     }
// }

// int main()
// {
//     char c;
//     int m, n;
//     printf("Enter the size of the game: ");
//     scanf("%d %d", &m, &n);
//     system("cls");
//     printf("Press any key to start the game");
//     getch();
//     system("cls");
//     // WIDTH = m;
//     // HEIGHT = n;
//     setup();
//     while (!gameOver)
//     {
//         draw();
//         input();
//         logic();
//         Sleep(10);
//     }
//     return 0;
// }
