# include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    unordered_map<int, vector<int>> m;
    vector<int> v;
    int totalIntegerPoints = 0;

    Solution(vector<vector<int>>& rects) {
        for (auto rect : rects) {

            int numberOfIntegerPoints =
                (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            totalIntegerPoints += numberOfIntegerPoints;
            v.push_back(totalIntegerPoints);
            m[totalIntegerPoints] = rect;
        }
    }

    vector<int> pick() {
        int number = rand() % totalIntegerPoints;
        // upper bound will be used because in case of lower bound the no. of
        // points increases for first rectangle and decreases for last
        // rectangle.
        int ind = upper_bound(v.begin(), v.end(), number) - v.begin();

        int totalIntegerPoints = v[ind];
        auto v = m[totalIntegerPoints];

        int x = v[0] + (rand() % (v[2] - v[0] + 1));
        int y = v[1] + (rand() % (v[3] - v[1] + 1));

        return {x, y};
    }
};