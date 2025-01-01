# include <bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int findTheWinner(int n, int k) {

        int ans = 0, i = 1, count = 1;
        vector<int> v(n, 0);

        while (ans < n - 1) {

            if (count == k) {
                v[i % n] = 1;
                ans++;
                count = 0;
            } else {
                i++;
                if (v[i % n] == 0)
                    count++;
            }
        }
        for (int j = 1; j < n; j++) {
            if (v[j] == 0)
                return j;
        }
        return n;
    }
};