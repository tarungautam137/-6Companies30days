# include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convertToTitle(int num) {

        vector<int> v;

        while (num != 0) {

            int x = num % 26;

            if (x == 0)
                x = 26;
            v.push_back(x);

            if (num % 26 == 0)
                num = (num / 26) - 1;
            else
                num = num / 26;
        }

        string s;
        for (int x : v) {
            char c = char(x + 64);
            s.push_back(c);
        }

        reverse(s.begin(), s.end());
        return s;
    }
};