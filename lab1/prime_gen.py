#This file reads in N and generates all primes up to and including N

n = int(input())


# this program is O(n^2), not very good but it works
def prime_gen(n):
    primes = []
    for i in range(2, n+1):
        isPrime = True
        for j in range(len(primes)):
            if i%primes[j] == 0:
                isPrime = False
        if isPrime:
            primes.append(i)
    return primes

primes = prime_gen(n)
print(primes)

