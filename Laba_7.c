#include <stdio.h>
#include <limits.h>

#define MAX_ROWS 2000
#define MAX_COLS 2000

int N, M;
char l[MAX_ROWS][MAX_COLS];
int L[MAX_ROWS][MAX_COLS];
int Nc = 1;
int queue1[MAX_ROWS * MAX_COLS][2],
queue2[MAX_ROWS * MAX_COLS][2];
int queue1_size = 0, queue2_size = 0;

void push (int row, int col, int value, int queue)
{
    if (queue == 1)
    {
        queue1[queue1_size][0] = row;
        queue1[queue1_size][1] = col;
        L[row][col] = value;
        queue1_size++;
    }
    else
    {
        queue2[queue2_size][0] = row;
        queue2[queue2_size][1] = col;
        queue2_size++;
    }
}

void pop (int *row, int *col, int queue)
{
    if (queue == 1)
    {
        *row = queue1[queue1_size - 1][0];
        *col = queue1[queue1_size - 1][1];
        queue1_size--;
    }
    else
    {
        *row = queue2[queue2_size - 1][0];
        *col = queue2[queue2_size - 1][1];
        queue2_size--;
    }
}

int main()
{
    FILE *file = fopen("Labirint.txt", "r");
    
    fscanf(file, "%d %d\n", &N, &M);
    
    for (int i = 0; i < N; i++)
    {
        fgets(l[i], MAX_COLS, file);
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (l[i][j] == '*')
            {
                L[i][j] = 1;
            }
            else
            {
                L[i][j] = INT_MAX;
            }
        }
    }
    
    push (0, 0, 0, 1);
    
    while (queue1_size > 0)
    {
        int row, col;
        pop(&row, &col, 1);
        
        if (row + 1 < N && L[row + 1][col] > Nc)
        {
            push (row + 1, col, Nc, 2);
        }
        if (row - 1 >= 0 && L[row - 1][col] > Nc)
        {
            push (row - 1, col, Nc, 2);
        }
        if (col + 1 < M && L[row][col + 1] > Nc)
        {
            push (row, col + 1, Nc, 2);
        }
        if (col - 1 >= 0 && L[row][col - 1] > Nc)
        {
            push (row, col - 1, Nc, 2);
        }
        
        if (queue1_size == 0)
        {
            Nc++;
            int(*temp)[2] = queue1;
            queue1 = queue2;
            queue2 = temp;
            queue1_size = queue2_size;
            queue2_size = 0;
    }
}

if (L[N - 1][M - 1] ==INT_MAX)
{
    printf("No path found!\n");
}
else
{
    printf("Minimum number of moves:%d\n", L[N - 1][M - 1]);
    printf("Path:\n");
    int row = N - 1;
    int col = M - 1;
    printf("(%d, %d)\n", row, col);
    int current = L[row][col];
    while (current > 0)
    {
        if (row + 1 < N && L[row + 1][col] == current - 1)
        {
            row++;
        }
        else if (row - 1 >= 0 && L[row - 1][col] == current - 1)
        {
            row--;
        }
        else if (col + 1 < M && L[row][col + 1] == current - 1)
        {
            col++;
        }
        else if (col - 1 >= 0 && L[row][col - 1] == current - 1)
        {
            col--;
        }
        printf("(%d, %d)\n", row, col);
        current--;
    }
}

fclose (file);
return 0;
}
