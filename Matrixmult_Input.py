r1=int(input("Enter number of Rows of Matrix A: "))
c1=int(input("Enter number of Columns of Matrix A: "))
A=[[0 for i in range(c1)] for j in range(r1)] 
print("Enter Matrix Elements of A:")
for i in range(r1):
    for j in range(c1):
        x=int(input())
        A[i][j]=x
r2=int(input("Enter number of Rows of Matrix B: "))
c2=int(input("Enter number of Columns of Matrix B: "))
B=[[0 for i in range(c2)] for j in range(r2)] 
print("Enter Matrix Elements of B:")
for i in range(r2):
    for j in range(c2):
        x=int(input())
        B[i][j]=x
if(c1==r2): 
    P=[[0 for i in range(c2)] for j in range(r1)]
    for i in range(len(A)):
        for j in range(c2):
            for k in range(len(B)):
                P[i][j]=P[i][j]+(A[i][k]*B[k][j])
    print("Product of Matrices A and B: ")
    for i in range(r1):
        for j in range(c2):
            print(P[i][j],end=" ")
        print()
else:
    print("Matrix Multiplication is not possible.")
