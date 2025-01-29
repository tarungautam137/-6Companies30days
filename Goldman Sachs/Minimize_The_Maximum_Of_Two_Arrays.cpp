#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int maxi, int d1, int d2, int uc1, int uc2) {

        int db1 = maxi / d1, db2 = maxi / d2, dbb = 0;

        int lc = lcm(d1, d2);

        // lcm may overflow
        if (lc % d1 == 0 && lc % d2 == 0) dbb = maxi / lc;

        int nb1 = maxi - db1, nb2 = maxi - db2, nbany = maxi - (db1 + db2 - dbb);

        if (nb1 < uc1) return false;

        int tf2 = db2 - dbb;

        int tfnb2 = max(0, uc1 - tf2);

        nb2 = nb2 - tfnb2;

        if (nb2 >= uc2) return true;

        return false;
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1,int uniqueCnt2) {

        long long low = 2, high = INT_MAX, ans = 0;

        while (low <= high) {

            long long mid = (low + high) / 2;

            if (check(mid, divisor1, divisor2, uniqueCnt1, uniqueCnt2)) {

                ans = mid;
                high = mid - 1;
            } 
            else low = mid + 1;
        }
        return (int)ans;
    }
};