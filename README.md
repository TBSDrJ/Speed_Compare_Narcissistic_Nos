# Narcissistic Numbers

This is another repository with the goal of comparing speeds of executing an algorithm across different languages and settings.  I tried, as much as possible, to make the implementation of the algorithm the same from one language to another.

A _Narcissistic Number_ is defined as a number where the sum of the digits, each raised to the power of the number of digits, is equal to itself.  So, for example:

$$153: 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153\ \text{is narcissistic}$$

$$172: 1^3 + 7^3 + 2^3 = 1 + 343 + 8 = 352\ \text{is not narcissistic}$$

They're not useful in any way that I know of, they're just an easy target for a computational test, and an amusing numerical pattern.  I suppose that they are, in some sense, inspired by perfect numbers (which are equal to the sum of their own proper divisors, e.g. 6 = 1 + 2 + 3).

# Test Assumptions

In all of the tests, I am calculating time/memory using a Macbook Pro with an M1 Max processor running the following at command-line:

```/usr/bin/time -l program```

Each is run 3 times, I take the average of the three.  The time value reported here is only the 'user' value, excluding the 'system' time.  The 'RAM' value reported is the 'peak memory footprint.'  I'm using kB = 1000 bytes and mB = 1000000 bytes.

I'm checking all of the integers less than 1000 for these tests.

I'm compiling C and C++ code using the 2011 standard (`--std=c11` `--std=c++11`).  I am running with multiple optimization flags on compile, see the table for details.

I wrote all the code last year without using `git` (shame), so I'll be uploading it all in one big dump.  For each test, I am calculating all of the narcissistic numbers up to 10,000,000.

## Results

|Setup                 |Time     |RAM     |
|:--------------------:|:-------:|:------:|
|C, no flags           | sec| kB  |
|C, -O1 flag           | sec| kB  |
|C, -O2 flag           | sec| kB  |
|C, -Ofast flag        | sec| kB  |
|C++, no flags         | sec| kB  |
|C++, -O1 flag         | sec| kB  |
|C++, -O2 flag         | sec| kB  |
|C++, -Ofast flag      | sec| kB  |
|Pypy 3.10             | sec| mB|
|Java                  | sec| mB|
|C, int, no flags      | sec| kB  |
|C, int, -O1 flag      | sec| kB  |
|C, int, -O2 flag      | sec| kB  |
|C, int, -Ofast flag   | sec| kB  |
|C++, int, no flags    | sec| kB  |
|C++, int, -O1 flag    | sec| kB  |
|C++, int, -O2 flag    | sec| kB  |
|C++, int, -Ofast flag | sec| kB  |
|Fortran 90, no flags  | sec| mB|
|Fortran 90, -O1 flag  | sec| mB|
|Fortran 90, -O2 flag  | sec| mB|
|Fortran 90,-Ofast flag| sec| mB|
|F90, int, no flags    | sec| mB|
|F90, subr, no flags   | sec| mB|
|F90, subr, -Ofast flag| sec| mB|
|JS in Firefox         | sec|?       |
|JS in Chrome          | sec|?       |
|JS in Safari          | sec|?       |
|Python, with 3.9      | sec| mB|
|Python, with 3.10     | sec| mB|
|Python, with 3.11     | sec| mB|
