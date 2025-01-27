# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long Power(long long x, long long y) {

        int mod = 1e9 + 7;

        long long num = 1;
        while (y) {

            if (y % 2)
                num = (num * x) % mod;

            x = ((x % mod) * (x % mod)) % mod;
            y = y / 2;
        }
        return num;
    }
    int minNonZeroProduct(int p) {

        int mod = 1e9 + 7;
        
        long long t = 1;
        long long maxi = (t << p) - 1;

        long long z = Power(maxi - 1, maxi / 2);

        return int(((maxi % mod) * (z % mod)) % mod);
    }
};