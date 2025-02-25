import ctypes
import math

def main():
    fn_lib = ctypes.CDLL("find_narcissistic.so")

    fn_lib.check_narcissistic.argtypes = [ctypes.c_int32]
    fn_lib.check_narcissistic.restype = ctypes.c_bool

    for n in range(10000000):
        if fn_lib.check_narcissistic(n):
            print(n, end=" ")
    print()

if __name__ == "__main__":
    main()