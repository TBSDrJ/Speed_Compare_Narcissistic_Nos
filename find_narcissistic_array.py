from array import array
from time import time

def main():
    start = time()
    digits = array('i', [0, 0, 0, 0, 0, 0, 0, 0, 0, 0])
    start = time()
    chars = 0
    for i in range(10000000):
        n = i
        for j in range(10):
            digits[j] = n % 10
            n //= 10
            if n == 0:
                dg_sz = j + 1
                break
        narcissism_sum = 0
        for j in range(dg_sz):
            narcissism_sum += digits[j] ** dg_sz
        if i == narcissism_sum:
            print(i, end = " ", flush = True)
            chars += dg_sz + 1
            if chars > 70:
                print()
                chars = 0
    print()
    print("Secs to complete: ", time() - start)




if __name__ == "__main__":
    main()