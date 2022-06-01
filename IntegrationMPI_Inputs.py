from mpi4py import MPI

def fx(x):
    return x*x

def Trap(local_a , local_b, local_n, h):
    integral = (fx(local_a) + fx(local_b))/2.0
    x = local_a
    for i in range(1,int(local_n)):
        x += h
        integral += fx(x)
    integral *= h
    return integral


comm = MPI.COMM_WORLD
rank=comm.rank
size=comm.size
a = 0
b = 0
n = 0
source = 1
dest = 0

if rank == 0:

    a = int(input("Enter Upper Limit \n"))
    b = int(input("Enter Lower Limit \n"))
    n = int(input("Enter number of trapezoids \n"))
    for i in range(1,size):
        dest += 1
        comm.send(a, dest, tag = 0)
        comm.send(b, dest, tag = 1)
        comm.send(n, dest, tag = 2)

else:
    comm.recv(a, source, tag = 0)
    comm.recv(b, source, tag = 1)
    comm.recv(n, source, tag = 2)


h = (b-a)/n
local_n = n/size
local_a = a + rank * local_n * h
local_b = (local_a + local_n) * h

integral = Trap(local_a, local_b, local_n, h)

if rank == 0:
    total = integral
    while (source < size):
        source += 1
        comm.recv(integral,source,tag = 0)
        total = total + integral
else:
    comm.send(integral, dest = 0, tag = 0)

if rank == 0:
    print(" With n = %d trapezoids, our estimate \n" %(n))
    print("of the integral from %f to %f = %0.8f\n" %(a,b,total))

