rows = int(input("Enter the Number of rows  for the first matrix: " ))
column = int(input("Enter the Number of Columns for the first matrix: "))

print("Enter the elements of First Matrix:")
matrix_a= [[int(input()) for i in range(column)] for i in range(rows)]

print("First Matrix is: ")
for n in matrix_a:
    print(n)
column_b = int(input("Enter the Number of Columns for the second matrix: "))

print("Enter the elements of Second Matrix:")

matrix_b= [[int(input()) for i in range(column_b)] for i in range(column)]
for n in matrix_b:
    print(n)
    
result=[[0 for i in range(column_b)] for i in range(rows)]

for i in range(len(matrix_a)):
    for j in range(len(matrix_b[0])):
        for k in range(len(matrix_b)):
            result [i][j]+=matrix_a[i][k]*matrix_b[k][j]
print("\n A X B is: ")
for r in result:
    print(r)