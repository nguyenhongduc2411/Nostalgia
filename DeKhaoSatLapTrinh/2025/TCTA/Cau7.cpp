#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6;
vector<bool> isPrime(MAX + 1, true);
vector<int> primes;

void sieve()
{
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i <= MAX; i++) {
        if (!isPrime[i])
            continue;

        for (ll j = i * i; j <= MAX; j += i) {
            isPrime[j] = false;
        }
    }
}

// bool checkPrime(ll n)
// {
//     if (n < 2)
//         return false;

//     for (ll j = 2; j * j <= n; j++) {
//         if (n % j == 0) {
//             return false;
//         }
//     }
//     return true;
// }

// Utility function to do modular exponentiation.
// It returns (x^y) % p
int power(int x, unsigned int y, int p)
{
    int res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
                // equal to p
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

// This function is called for all k trials. It returns
// false if n is composite and returns true if n is
// probably prime.
// d is an odd number such that  d*2 = n-1
// for some r >= 1
bool millerTest(int d, int n)
{
    // Pick a random number in [2..n-2]
    // Corner cases make sure that n > 4
    int a = 2 + rand() % (n - 4);

    // Compute a^d % n
    int x = power(a, d, n);

    if (x == 1  || x == n-1)
       return true;

    // Keep squaring x while one of the following doesn't
    // happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)      return false;
        if (x == n-1)    return true;
    }

    // Return composite
    return false;
}

// It returns false if n is composite and returns true if n
// is probably prime.  k is an input parameter that determines
// accuracy level. Higher value of k indicates more accuracy.
bool checkPrime(int n, int k=5)
{
    // Corner cases
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;

    // Find r such that n = 2^d * r + 1 for some r >= 1
    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    // Iterate given number of 'k' times
    for (int i = 0; i < k; i++)
         if (!millerTest(d, n))
              return false;

    return true;
}

// 78497 * log3(n)

void solve()
{
    ll n;
    cin >> n;

    for (ll u : primes) {
        if (n % u == 0) {
            ll v = n / u;
            if (u < v && checkPrime(v)) {
                cout << u << " " << v << "\n";   
                break;
            }
        }
    }
}

int main()
{
    // sieve();

    for (int i = 3; i <= MAX; i++) {
        if (checkPrime(i)) {
            primes.push_back(i);
        }
    }
    // cout << primes.size() << "\n";

    // for (int i = 0; i <= 30; i++) {
    //     cout << i << ": " << isPrime[i] << "\n";
    // }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}