import numpy as np

v1 = np.arange(0,6)
arr = [ 2, 3 ]
v2 = np.reshape(v1, arr)

# v3 = np.dot(v2, v2)
v4 = np.multiply(v2, v2)

print(v2)
print(v4)

v5 = np.arange(0,9)
v6 = np.reshape(v5, [3,3])

v7 = np.dot(v6,v6)

print(v6)
print(v7)
print(v7)
print(v7)