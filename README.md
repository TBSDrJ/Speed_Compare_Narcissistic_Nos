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

I'm compiling C and C++ code using the 2011 standard (`--std=c11` `--std=c++11`).  I am running with multiple optimization flags on compile, see the table for details.

I wrote all the code last year without using `git` (shame), so I'll be uploading it all in one big dump.  For each test, I am calculating all of the narcissistic numbers up to 10,000,000.

## Results

In order of speed:

|Setup                 |Time     |RAM     |
|:--------------------:|:-------:|:------:|
|C, -Ofast flag        |0.227 sec|935 kB  |
|C++, -Ofast flag      |0.230 sec|951 kB  |
|Fortran 90,-Ofast flag|0.327 sec|1.038 mB|
|Fortran 90, no flags  |0.463 sec|1.033 mB|
|Pypy 3.10 w/array     |0.567 sec|20.37 mB|
|C, no flags           |0.660 sec|940 kB  |
|C++, no flags         |0.780 sec|951 kB  |
|Pypy 3.10             |0.853 sec|23.56 mB|
|JS in Safari          |0.969 sec|?       |
|JS in Firefox         |1.117 sec|?       |
|JS in Chrome          |4.272 sec|?       |
|Python, with 3.11     |8.040 sec|5.741 mB|
|Java                  |9.273 sec|5.673 mB|
|Python, with 3.10     |21.38 sec|5.244 mB|
|Python, with 3.9      |22.42 sec|4.228 mB|

+ I have a memory of Fortran being faster than C last year, I'm not sure what changed.