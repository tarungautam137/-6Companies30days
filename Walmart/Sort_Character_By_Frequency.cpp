#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> mp;

        for (string t : words)
            mp[t]++;

        map<int, vector<string>> m;

        vector<string> v;

        for (auto& it : mp) {

            m[it.second].push_back(it.first);
        }

        auto it = m.end();
        it--;

        while (v.size() < k) {

            auto temp = (*it).second;
            sort(temp.begin(), temp.end());

            int i = 0;
            
            while (v.size() < k && i < temp.size()) {
                v.push_back(temp[i]);
                i++;
            }
            it--;
        }
        return v;
    }
};