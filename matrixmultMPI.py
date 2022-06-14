from mpi4py import MPI
import mpi4py
import numpy as np

comm = MPI.COMM_WORLD
size = comm.size
rank = comm.Get_rank()
time1 = mpi4py.MPI.Wtime()


a = np.random.randint(10, size=(100, 100))
if rank == 0:
    b = np.random.randint(10, size=(100, 100))
    print(b)
else:
    b = None

b = comm.bcast(b, root=0)

c = np.dot(a, b)

if size == 1:
    
    result = np.dot(a, b)

else:
    
    if rank == 0:
        
        a_row = a.shape[0]
    
        if a_row >= size:
            
            split = np.array_split(a, size, axis=0)
            
    else:
        
        split = None
        
    split = comm.scatter(split, root=0)
    
    split = np.dot(split, b)
    
    data = comm.gather(split, root=0)

time2 = mpi4py.MPI.Wtime()
duration = time2 - time1
totaltime = comm.reduce(duration,op = MPI.SUM, root = 0)
print("Runtime at %d is %f" %(rank,duration))

if rank == 0:

    result = np.vstack(data)
    print(result)
    print(totaltime)
