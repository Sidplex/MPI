#define N 16
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
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
    double time1, time2, duration, global;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(rank == 0){
        

        printf("enter the number of row =");    
        scanf("%d",&row);    
        printf("enter the number of column =");    
        scanf("%d",&col);    

        srand(time(NULL));
        for(i=0;i<row;i++) {
            for(j=0;j<col;j++){
                a[i][j] = rand() % 10;
            }
        }

        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                b[i][j] = rand() % 10;
            }
        }
    }
    MPI_Barrier(MPI_COMM_WORLD);
    time1 = MPI_Wtime();
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

    MPI_Allgather(cc, N*N/size, MPI_INT, c, N*N/size, MPI_INT, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);

    time2 = MPI_Wtime();
    duration = time2 - time1;
    MPI_Reduce(&duration,&global,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
    if(rank == 0) {
        printf("Global runtime is %f\n",global);
    }
    printf("Runtime at %d is %f \n", rank,duration);       
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
