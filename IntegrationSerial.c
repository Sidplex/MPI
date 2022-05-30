#include <stdio.h>
#include <math.h>
#include <time.h>

int main(){
    float integral;
    float a,b;
    int n;
    float h;
    float x;
    clock_t start,end;
    double cpu_time_used;


    float f(float x);
    printf("Enter a, b and n \n");
    scanf("%f %f %d", &a, &b, &n);
    start = clock();

    h = (b-a)/n;
    integral = (f(a) + f(b))/2.0;
    x = a;
    for( int i = 1; i <= n-1; i++){
        x += h;
        integral += f(x);
    }
    integral *= h;
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf(" With n = %d trapezoids, our estimate \n", n);
    printf("of the integral form %f to %f = %f\n", a, b, integral);
    printf("Program took %f seconds to execute \n", cpu_time_used);

}

float f(float x){ 
    return x*x;
}
