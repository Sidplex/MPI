from mpi4py import MPI
import numpy as np
import random

comm = MPI.COMM_WORLD
size = comm.size
rank = comm.Get_rank()


a = np.random.randint(10, size=(20, 20))
if rank == 0:
    b = np.random.randint(10, size=(20, 20))
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

    if rank == 0:
    
        result = np.vstack(data)
        print(result)
