# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // RABIN-KARP!!!!!!
    vector<string> findRepeatedDnaSequences(string s) {

        unordered_map<char, int> m;
        m['A'] = 1;
        m['C'] = 2;
        m['G'] = 3;
        m['T'] = 4;

        vector<char> v(5, 'A');
        v[1] = 'A';
        v[2] = 'C';
        v[3] = 'G';
        v[4] = 'T';

        vector<string> ans;

        int n = s.size();
        if (n < 10)
            return ans;

        long long num = 0, x = 1e9;

        for (int i = 0; i <= 9; i++) {

            num += (m[s[i]] * x);
            x = x / 10;
        }

        unordered_map<long long, int> m2;
        int i = 0, j = 9;

        while (j < n) {
            m2[num]++;
            j++;
            if (j < n) {
                num = num - (m[s[i]] * 1e9);
                num = num * 10;
                num += m[s[j]];
                i++;
            }
        }

        for (auto it : m2) {

            if (it.second >= 2) {

                string t;
                x = 1e9;
                auto number = it.first;

                while (x != 0) {

                    auto digit = number / x;
                    number = number % x;
                    x = x / 10;
                    t.push_back(v[digit]);
                }
                ans.push_back(t);
            }
        }
        cout << m2.size();
        return ans;
    }
};