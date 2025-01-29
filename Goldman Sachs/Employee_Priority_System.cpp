#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {

        unordered_map<string, vector<int>> mp;

        for (auto& it : access_times) {

            string time = it[1], hour, minutes;

            hour.push_back(time[0]);
            hour.push_back(time[1]);

            minutes.push_back(time[2]);
            minutes.push_back(time[3]);

            int t = (stoi(hour) * 60) + stoi(minutes);

            mp[it[0]].push_back(t);
        }

        vector<string> ans;

        for (auto& it : mp) {

            auto v = it.second;

            sort(v.begin(), v.end());

            int n = v.size();
            for (int start = 0; start < (n - 2); start++) {

                if (v[start + 1] - v[start] < 60 && v[start + 2] - v[start] < 60) {

                    ans.push_back(it.first);
                    break;
                }
            }
        }
        return ans;
    }
};