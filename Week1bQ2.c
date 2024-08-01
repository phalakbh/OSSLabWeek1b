#include <stdio.h>
int main()
{
    int r, c;
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);
    if (r==0 || c==0) 
    {
        printf("Please enter the correct dimensions!");
    }
    else
    {
        int arr[100][100];
        int transpose[100][100];
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                printf("Enter the element at row %d, column %d: ", i,j);
                scanf("%d", &arr[i][j]);
            }
        }
        for (int i = 0; i < r; ++i) 
        {
            for (int j = 0; j < c; ++j) 
            {
                transpose[j][i] = arr[i][j];
            }
        }
        printf("Transposed matrix:\n");
        for (int i = 0; i < c; ++i) 
        {
            for (int j = 0; j < r; ++j) 
            {
                printf("%d ", transpose[i][j]);
            }
            printf("\n");
        }

    }
    return 0;
}