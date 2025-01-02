# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {

        int m = img.size(), n = img[0].size();

        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<int> v = {-1, 0, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int sum = 0, count = 0;

                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {

                        int nr = i + v[k];
                        int nc = j + v[l];

                        if (nr < m && nr >= 0 && nc < n && nc >= 0) {
                            sum += img[nr][nc];
                            count++;
                        }
                    }
                }
                sum = sum / count;
                ans[i][j] = sum;
            }
        }
        return ans;
    }
};