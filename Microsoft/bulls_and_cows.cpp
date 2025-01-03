# include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> ms;
        unordered_map<char, int> mg;

        int x = 0, y = 0;

        for (int i = 0; i < secret.size(); i++) {

            if (secret[i] == guess[i])
                x++;
            else {
                ms[secret[i]]++;
                mg[guess[i]]++;
            }
        }
        for (auto it : ms) {
            y += min(it.second, mg[it.first]);
        }
        string ans = to_string(x) + "A" + to_string(y) + "B";
        return ans;
    }
};