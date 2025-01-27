# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // SAME AS LEETCODE 2572-COUNT THE NO. OF SQUARE FREE SUBSETS. 
    // BIT MASKING is used to solve problems involving subsets and combinations.

    int mod = 1e9 + 7;
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    int power(int x, int y) {

        if (y == 0)
            return 1;
        if (y == 1)
            return x;

        long long f = x, s = y - 1;

        while (s--) {

            f = (f * x) % mod;
        }
        return (int)(f % mod);
    }

    int check(int mask, int num) {

        for (int i = 0; i < 10; i++) {

            int p = primes[i], x = (1 << i);

            if (num % p == 0) {

                num = num / p;
                if (mask & x)
                    return 0;
                if (num % p == 0)
                    return 0;

                mask = mask | x;
            }
        }
        return mask;
    }
    long long count(vector<int>& v, unordered_map<int, int>& m, int mask,
                    int ind) {

        int n = v.size();
        if (ind == n) {

            if (mask)
                return 1;
            return 0;
        }

        long long nottake = count(v, m, mask, ind + 1), take = 0;

        int newmask = check(mask, v[ind]);
        if (newmask != 0) {

            take = (m[v[ind]] * count(v, m, newmask, ind + 1)) % mod;
        }

        return (take + nottake) % mod;
    }

    int numberOfGoodSubsets(vector<int>& nums) {

        unordered_map<int, int> m;

        for (int x : nums)
            m[x]++;

        vector<int> v;
        for (auto& it : m) {

            if (it.first != 1)
                v.push_back(it.first);
        }

        int first = power(2, m[1]) - 1;

        long long second = count(v, m, 0, 0);

        return (second +
                (int)(((long long)first * (long long)second) % mod)) %
               mod;
    }
};