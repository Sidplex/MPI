from mpi4py import MPI

comm = MPI.COMM_WORLD

rank = comm.Get_rank()


if rank == 0:
    msg = '6'
    comm.send(msg,dest=1)
    p = comm.recv()
    print("Rank ", rank," : ",p)

elif rank == 1:
    msg1 = '7'
    comm.send(msg1,dest=2)
    q = comm.recv()
    print("Rank ", rank," : ",q)

elif rank == 2:
    msg2 = '8'
    comm.send(msg2,dest=3)
    r = comm.recv()
    print("Rank ", rank," : ",r)

elif rank == 3:
    msg3 = '9'
    comm.send(msg3,dest=0)
    s = comm.recv()
    print("Rank ", rank," : ",s)
