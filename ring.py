from mpi4py import MPI

comm = MPI.COMM_WORLD
rank=comm.rank
size=comm.size

shared=(rank)

comm.send(shared,dest=(rank+1)%size)
data=comm.recv(source=(rank-1)%size)
print ('Rank:',rank)
print ('Recieved:',data,'which came from rank:',(rank-1)%size)