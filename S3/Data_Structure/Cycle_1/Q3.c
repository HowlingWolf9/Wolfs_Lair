/*
Experiment: 3

AIM: Represent Sparse Matrices using arrays and read two sparse matrices. Write functions to perform addition of two sparse matrices and Transpose of a Sparse Matrix.

ALGORITHM: main()
Step 01: START
Step 02: Read the sparse matrix 1 using readSparseMatrix() by passing matrix a
Step 03: Read the sparse matrix 2 using readSparseMatrix() by passing matrix b
Step 04: Add the sparse matrices using addSparseMatrices() by passing matrix a and b
Step 05: Display the sparse matrix using displaySparseMatrix() by passing matrix c
Step 06: Find transpose of sparse matrix 2 using transposeSparseMatrix() by passing b as the source matrix d as the target
Step 07: Display the sparse matrix using displaySparseMatrix() by passing matrix d
Step 08: STOP

ALGORITHM: readSparseMatrix(int mat[][3])
Step 01: START
Step 02: Read the number of rows, columns and non-zero elements of the sparse matrix as the first line of sparse matrix
Step 03: Initialize i = 0 and repeat steps 04 to 05 until i <= mat[0][2]
Step 04:      Read the elements of the sparse matrix as row, column and value of the non-zero element
Step 05:      Increment i by 1
Step 06: STOP

ALGORITHM: displaySparseMatrix(int mat[][3])
Step 01: START
Step 02: IF mat[0][2] == 0
Step 03:     Print the message "Empty matrix"
Step 04: ELSE
Step 05:     Initialize i = 0 and repeat steps 06 to 07 until i <= mat[0][2]
Step 06:          Print the elements of the sparse matrix as row, column and value of the non-zero element
Step 07:          Increment i by 1
Step 08: ENDIF
Step 09: STOP

ALGORITHM: addSparseMatrices(int a[][3], int b[][3])
Step 01: START
Step 02: IF (a[0][0] != b[0][0] || a[0][1] != b[0][1])
Step 03:    Print the message "Addition not possible"
Step 04:    STOP
Step 05: ELSE
Step 06:    Initialize i = 1, j = 1 and k = 1
Step 07:    Set c[0][0] = a[0][0], c[0][1] = a[0][1]
Step 08:    WHILE (i <= a[0][2] && j <= b[0][2]) repeat steps 09 to 26
Step 09:        IF (a[i][0] < b[j][0])
Step 10:            Set c[k][0] = a[i][0], c[k][1] = a[i][1], c[k][2] = a[i][2]
Step 11:            Increment i, k by 1
Step 12:        ELSE IF (b[j][0] < a[i][0])
Step 13:            Set c[k][0] = b[j][0], c[k][1] = b[j][1], c[k][2] = b[j][2]
Step 14:            Increment j, k by 1
Step 15:        ELSE
Step 16:            IF (a[i][1] < b[j][1])
Step 17:                Set c[k][0] = a[i][0], c[k][1] = a[i][1], c[k][2] = a[i][2]
Step 18:                Increment i, k by 1
Step 19:            ELSE IF (b[j][1] < a[i][1])
Step 20:                Set c[k][0] = b[j][0], c[k][1] = b[j][1], c[k][2] = b[j][2]
Step 21:                Increment j, k by 1
Step 22:            ELSE
Step 23:                Set c[k][0] = a[i][0], c[k][1] = a[i][1], c[k][2] = a[i][2] + b[j][2]
Step 24:                Increment i, j, k by 1
Step 25:            ENDIF
Step 26:        ENDIF
Step 27:    WHILE (i <= a[0][2]) repeat steps 28 to 29
Step 28:        Set c[k][0] = a[i][0], c[k][1] = a[i][1], c[k][2] = a[i][2]
Step 29:        Increment i, k by 1
Step 30:    WHILE (j <= b[0][2]) repeat steps 31 to 32
Step 31:        Set c[k][0] = b[j][0], c[k][1] = b[j][1], c[k][2] = b[j][2]
Step 32:        Increment j, k by 1
Step 33:    Set c[0][2] = k - 1
Step 34: ENDIF
Step 35: STOP

ALGORITHM: transposeSparseMatrix(int smat[][3], int tmat[][3])
Step 01: START
Step 02: Set tmat[0][0] = smat[0][0], tmat[0][1] = smat[0][1], tmat[0][2] = smat[0][2]
Step 03: Initialize i = 1
Step 04: WHILE (i <= smat[0][2]) repeat steps 05 to 06
Step 05:    Set tmat[i][0] = smat[i][1], tmat[i][1] = smat[i][0], tmat[i][2] = smat[i][2]
Step 06:    Increment i by 1
Step 07: STOP
*/
// CODE:
#include <stdio.h>
#define SIZE 25

int a[SIZE][3], b[SIZE][3], c[SIZE][3], d[SIZE][3];
void readSparseMatrix(int mat[][3])
{
    scanf("%d %d %d", &mat[0][0], &mat[0][1], &mat[0][2]);
    for (int i = 1; i <= mat[0][2]; i++)
        scanf("%d %d %d", &mat[i][0], &mat[i][1], &mat[i][2]);
}

void displaySparseMatrix(int mat[][3])
{
    if (mat[0][2] == 0)
        printf("Empty matrix\n");
    else
        for (int i = 0; i <= mat[0][2]; i++)
            printf("%d %d %d\n", mat[i][0], mat[i][1], mat[i][2]);
}
void addSparseMatrices(int a[][3], int b[][3])
{
    if ((a[0][0] != b[0][0]) || (a[0][1] != b[0][1]))
    {
        printf("Addition not possible\n");
        return;
    }
    else
    {
        int i = 1, j = 1, k = 1;
        c[0][0] = a[0][0];
        c[0][1] = a[0][1];
        while (i <= (a[0][2]) && j <= (b[0][2]))
        {
            if (a[i][0] < b[j][0])
            {
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = a[i][2];
                i++;
                k++;
            }
            else if (b[j][0] < a[i][0])
            {
                c[k][0] = b[j][0];
                c[k][1] = b[j][1];
                c[k][2] = b[j][2];
                j++;
                k++;
            }
            else
            {
                if (a[i][1] < b[j][1])
                {
                    c[k][0] = a[i][0];
                    c[k][1] = a[i][1];
                    c[k][2] = a[i][2];
                    i++;
                    k++;
                }
                else if (b[j][1] < a[i][1])
                {
                    c[k][0] = b[j][0];
                    c[k][1] = b[j][1];
                    c[k][2] = b[j][2];
                    j++;
                    k++;
                }
                else
                {
                    c[k][0] = a[i][0];
                    c[k][1] = a[i][1];
                    c[k][2] = a[i][2] + b[j][2];
                    i++;
                    j++;
                    k++;
                }
            }
        }
        while (i <= (a[0][2]))
        {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++;
            k++;
        }
        while (j <= (b[0][2]))
        {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            j++;
            k++;
        }
        c[0][2] = k - 1;
    }
}

void transposeSparseMatrix(int smat[][3], int tmat[][3])
{
    tmat[0][0] = smat[0][0];
    tmat[0][1] = smat[0][1];
    tmat[0][2] = smat[0][2];
    int i = 1;
    while (i <= (smat[0][2]))
    {
        tmat[i][0] = smat[i][1];
        tmat[i][1] = smat[i][0];
        tmat[i][2] = smat[i][2];
        i++;
    }
}
void main()
{
    printf("Enter sparse matrix 1:\n");
    readSparseMatrix(a);
    printf("\nEnter sparse matrix 2:\n");
    readSparseMatrix(b);
    addSparseMatrices(a, b);
    printf("\nAddition of sparse matrices:\n");
    displaySparseMatrix(c);
    printf("\nTranspose of sparse matrix 2:\n");
    transposeSparseMatrix(b,d);
    displaySparseMatrix(d);
}

/*
OUTPUT:
Enter  sparse matrix 1:
3 3 4 
0 1 4
0 2 5
1 2 4
2 2 5

Enter  sparse matrix 2:
3 3 3
0 1 5
1 2 8
2 0 4

Addition of sparse matrices:
3 3 5
0 1 9
0 2 5
1 2 12
2 0 4
2 2 5

Transpose of sparse matrix:
3 3 3
0 2 4
1 0 5
2 1 8
*/