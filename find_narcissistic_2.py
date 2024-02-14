# from time import time

def main():
    
    # start = time()
    # out_str = ""
    chars = 0
    for i in range(1, 10000000):
        digs = [int(k) for k in str(i)]
        sz = len(digs)
        narcissism_sum = 0
        for j in range(sz):
            narcissism_sum += digs[j]**sz
        if i == narcissism_sum:
            print(i, end = " ", flush = True)
            # out_str += str(i) + " "
            chars += sz + 1
        if chars > 70:
            print("", flush = True)
            # out_str s+= "\n"
            chars = 0
    print()
    # print(f"Secs to run: {time() - start:.4f}")
    # with open('narcissistic_nos_python.txt', 'w') as fout:
    #     print(f"{out_str}", file = fout)
    #     print(f"Secs to run: {time() - start:.4f}", file = fout)

if __name__ == "__main__":
    main()