#define N 4
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "mpi.h"


void print_results(char *prompt, int a[N][N]);

int main(int argc, char *argv[])
{
    int i, j, k, rank, size, tag = 99, sum = 0;
    int a[N][N];
    int b[N][N];
    int c[N][N];
    int aa[N],cc[N];
    int row,col;
    int dest = 0;
    int source;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(rank == 0){

      printf("enter the number of row =");    
      scanf("%d",&row);    
      printf("enter the number of column =");    
      scanf("%d",&col);    

      printf("enter the first matrix elements =\n"); 

      for(i=0;i<row;i++) {
          for(j=0;j<col;j++){
              scanf("%d", &a[i][j]);
          }
      }

      printf("enter the second matrix elements =\n");
      for(i=0;i<row;i++){
          for(j=0;j<col;j++){
              scanf("%d", &b[i][j]);
          }
      }
    }

    MPI_Scatter(a, N*N/size, MPI_INT, aa, N*N/size, MPI_INT,0,MPI_COMM_WORLD);

    MPI_Bcast(b, N*N, MPI_INT, 0, MPI_COMM_WORLD);

    MPI_Barrier(MPI_COMM_WORLD);

          for (i = 0; i < N; i++)
            {
                    for (j = 0; j < N; j++)
                    {
                            sum = sum + aa[j] * b[j][i];               
                    }
                    cc[i] = sum;
                    sum = 0;
            }

    MPI_Gather(cc, N*N/size, MPI_INT, c, N*N/size, MPI_INT, 0, MPI_COMM_WORLD);

    MPI_Barrier(MPI_COMM_WORLD);        
    MPI_Finalize();
    if (rank == 0)                      
      print_results("C = ", c);
}

void print_results(char *prompt, int a[N][N])
{
    int i, j;

    printf ("\n\n%s\n", prompt);
    for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                    printf(" %d", a[i][j]);
            }
            printf ("\n");
    }
    printf ("\n\n");
}
