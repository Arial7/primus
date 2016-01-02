# what is primus?
primus is a small benchmarking or CPU heating application. It just calculates prime numbers on multiple (or a single) threads. Use it with the `time` command in front to measure the time it took to calculate.
## Installation
```bash
git clone https://github.com/Arial7/primus
cd primus
make
```
I put different optimization levels directly into the Makefile. Just run
```bash
make O2
```
for example.
<br>
<b>ATTENTION!</b>: O3 does wierd things, for me it just removes the whole number calculation. The program instantly finishes, it does nothing at all.

## Usage
The default usage is:
### Benchmarking
```bash
time ./primus <maximumNumber> <numberOfThreads>
```
where `<maximumNumber>` is the maximum number to calculate to. I typically use 1.000.000 (without the dots please).

`<numberOfThreads>` is pretty self-explanatory, it is the count of threads to calculate on. On multi-core systems, using more threads is better, as the first threads finish earlier than the last threads. So on my octa-core I typically use 32 threads. To get accurate results. Also, the bigger the number you want to calculate to, the more cores you should use.
### CPU heating
```bash
./primus heat [numberOfThreads]
```
Primus will just calculate primes until you stop it with `^C`.

`[numberOfThreads]` is optional, as primus will try to find out how many cores you have.
