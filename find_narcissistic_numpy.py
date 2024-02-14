import numpy as np
from time import time
from math import log10

def main():
    start = time()
    chars = 0
    d = np.zeros((10), dtype=np.uint64)
    for i in range(10):
        d[i] = i
    col0 = np.tile(d, 10000)
    col1 = np.tile(np.repeat(d,10), 1000)
    col2 = np.tile(np.repeat(d,100), 100)
    col3 = np.tile(np.repeat(d,1000), 10)
    col4 = np.repeat(d,10000)
    digits = np.column_stack((col0, col1, col2, col3, col4))
    for j in range(10):
        col6 = np.repeat(np.array([j], dtype=np.uint64), 100000)
        for i in range(10):
            col5 = np.repeat(np.array([i], dtype=np.uint64), 100000)
            digits_tmp = np.copy(digits)
            digits_tmp = np.hstack((digits_tmp, np.transpose([col5]), np.transpose([col6])))
            if i == 0 and j == 0:
                digits_tmp[10:99] = digits_tmp[10:99]**2
                digits_tmp[100:999] = digits_tmp[100:999]**3
                digits_tmp[1000:9999] = digits_tmp[1000:9999]**4
                digits_tmp[10000:99999]= digits_tmp[10000:99999]**5
            else:
                digits_tmp = digits_tmp**(5 + bool(i) + bool(j))
            for k in range(100000):
                if k + 100000*i + 1000000*j == np.sum(digits_tmp[k]):
                    if k > 0:
                        print(k + 100000*i+ 1000000*j, end=" ", flush=True)
                        chars += int(log10(k)) + bool(i) + bool(j) + 2
                    if chars > 70:
                        chars = 0
                        print()
    print()
    print(time() - start)
    



if __name__ == "__main__":
    main()