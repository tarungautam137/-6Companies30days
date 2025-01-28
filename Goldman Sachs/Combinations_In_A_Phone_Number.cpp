# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(int ind, string& digits, string& s, vector<string>& ans,
           vector<vector<char>>& v) {

        if (ind == digits.size()) {

            ans.push_back(s);
            return;
        }

        int curr = int(digits[ind] - '0');

        for (char c : v[curr]) {

            s.push_back(c);
            f(ind + 1, digits, s, ans, v);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {

        vector<vector<char>> v(10);

        v[2] = {'a', 'b', 'c'};
        v[3] = {'d', 'e', 'f'};
        v[4] = {'g', 'h', 'i'};
        v[5] = {'j', 'k', 'l'};
        v[6] = {'m', 'n', 'o'};
        v[7] = {'p', 'q', 'r', 's'};
        v[8] = {'t', 'u', 'v'};
        v[9] = {'w', 'x', 'y', 'z'};

        vector<string> ans;

        if (digits.size() == 0)
            return ans;

        string s = "";
        f(0, digits, s, ans, v);

        return ans;
    }
};