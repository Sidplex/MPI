## ***For Installation of MPI on Ubuntu***

(For C Program)

1. sudo apt-get install libopenmpi-dev
2. sudo apt-get install openmpi-bin

- Compiling the program

mpicc -o hello_world hello_world.c

- Running the program

mpirun -np 4 ./hello_world

(For Python Program)

1. sudo apt-get install python3
2. sudo apt install python3-pip
3. sudo pip3 install mpi4py 

-Running the program

mpiexec -n 4 python3 hello_world.py

## ***For Installation of MPI on Windows***

We need Cygwin for both C and Python MPI programs

(For C Program)
1. On Cygwin Terminal install all mpi/gcc packages shown below. 

![image](https://user-images.githubusercontent.com/74717951/169682786-02dc1085-5b2e-4b12-a2d7-9c4d5690a214.png)

2. Compiling and running the program is same as we do in Ubuntu.

(For Python program)

1. On Cygwin Terminal, Python is installed by default.
2. Compiling and running the program is same as we do in Ubuntu.
