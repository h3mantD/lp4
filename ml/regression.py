import matplotlib.pyplot as plt

import numpy as np
import pandas as pd
dataset = pd.read_csv('two.csv')

X = dataset['x']
Y = dataset['y']

x,y = list(X), list(Y)

xy = []
for i in range(0, len(x)):
  xy.append(x[i]*y[i])

x2 = []
for i in x:
  x2.append(i*i)

y2 = []
for i in y:
  y2.append(i*i)


sum_x = sum(x)
sum_y = sum(y)
sum_xy = sum(xy)
sum_x2 = sum(x2)
sum_y2 = sum(y2)

print(f"sum x : {sum_x, sum_y, sum_x2, sum_y2, sum_xy} ")

a = (len(x)*sum_xy-sum_x*sum_y)/(len(x)*sum_x2-sum_x*sum_x)
print(a)
b = (sum_y*sum_x2-sum_x*sum_xy)/(len(x)*sum_x2-sum_x*sum_x)
print(b)


ip=4

op = a*ip + b
print(f'*** y for {X} is {Y}')

plt.scatter(X,Y,color='black')
plt.plot(X,Y,color='blue',linewidth=3)
plt.xticks(())
plt.yticks(())
plt.show()