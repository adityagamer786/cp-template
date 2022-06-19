vi SieveOfEratosthenes(int n)
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
 
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    int ma = 0;
    vi primes;
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.pb(p);
    return primes;
}