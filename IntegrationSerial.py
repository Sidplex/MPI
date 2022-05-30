import matplotlib.pyplot as plt
import time

a = float(input("Enter Value for upper limit: \n"))
b = float(input("Enter vale for lower limit: \n"))
n = int(input("Enter number of trapezoids to form: \n"))

num1 = int(a)
num2 = int(b)
begin = time.time()
def fx(x):
    return x*x

height = (b-a)/n
integral = (fx(a) + fx(b))/2.0
x = a
for i in range(1,n):
    x += height
    integral += fx(x)


integral *= height
end = time.time()
totaltime = end - begin
print(" With n = %d trapezoids, our estimate \n" %(n))
print("of the integral from %f to %f = %0.8f\n" %(a,b,integral))
print("Total runtime of the program is %f" %(totaltime))

xcords = range(num1,num2)
ycords = [x*x for x in xcords]
plt.plot(xcords,ycords)
plt.show()
