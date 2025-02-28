# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {

        int m = board.size(), n = board[0].size(), count = 0;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'X') {

                    if (!((i >= 1 && board[i - 1][j] == 'X') ||
                          (j >= 1 && board[i][j - 1] == 'X')))
                    count++;
                }
            }
        }

        return count;
    }
};