import math
import numpy as np

print(f'{1}: {0}')

key, val = [], []
key.append(1)
val.append(0)

def check(x):
    num = math.factorial(5 * i)
    res = 0
    k = 10
    while num % k == 0:
        k *= 10
        res += 1
    return res


for i in range(1, 5000):
    res = check(i)
    key.append(i*5)
    val.append(res)
    np.savetxt("key.txt", key)
    np.savetxt("val.txt", val)
