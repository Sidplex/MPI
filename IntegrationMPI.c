#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int main(int argc, char** argv){
    int my_rank;
    int size;
    float a ;
    float b ;
    int n ;
    float h;
    float local_a;
    float local_b;
    int local_n;
    float integral;
    float total;
    int source;
    int dest = 0;
    int tag = 0;
    MPI_Status status;

    printf("Enter a, b and n \n");
    scanf("%f %f %d", &a, &b, &n);

    float Trap(float local_a, float local_b, int local_n, float h);

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    MPI_Comm_size(MPI_COMM_WORLD, &size);

    h = (b-a)/n;
    
    local_n = n/size;

    local_a = a + my_rank * local_n * h;

    local_b = (local_a + local_n) * h;

    integral = Trap(local_a, local_b, local_n, h);

    if (my_rank == 0){
        total = integral;
        for (source = 1; source < size; source++){
            MPI_Recv(&integral, 1, MPI_FLOAT, source, tag, MPI_COMM_WORLD, &status);
            total += integral;
        }
    }
    else {
        MPI_Send(&integral, 1, MPI_FLOAT, dest, tag, MPI_COMM_WORLD); 
    }
    if (my_rank == 0){
        printf("With n = %d trapezoids, our estimate \n", n);

        printf("of the integral from %f to %f = %0.8f\n",a,b,total);
    
    }    
    MPI_Finalize();
 
}

float Trap(float local_a, float local_b, int local_n, float h){
    float integral;
    float x;
    int i;

    float f(float x);
    integral = (f(local_a) + f(local_b))/2.0;
    x = local_a;
    for (int i = 1; i <= local_n-1; i++){
        x += h;
        integral += f(x);
    }
    integral *= h;

}

float f(float x){
    return x*x;
}
