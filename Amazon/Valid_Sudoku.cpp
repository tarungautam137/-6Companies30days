# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int lr = 0, ur = 2;
        while (lr <= 6) {

            int lc = 0, uc = 2;

            while (lc <= 6) {

                unordered_map<char, int> m;

                for (int i = lr; i <= ur; i++) {

                    for (int j = lc; j <= uc; j++) {

                        if (m[board[i][j]])
                            return false;
                        else if (board[i][j] != '.')
                            m[board[i][j]]++;
                    }
                }
                lc += 3;
                uc += 3;
            }
            lr += 3;
            ur += 3;
        }

        for (int i = 0; i < 9; i++) {

            unordered_map<char, int> m;

            for (int j = 0; j < 9; j++) {

                if (m[board[i][j]])
                    return false;
                else if (board[i][j] != '.')
                    m[board[i][j]]++;
            }
        }

        for (int i = 0; i < 9; i++) {

            unordered_map<char, int> m;

            for (int j = 0; j < 9; j++) {

                if (m[board[j][i]])
                    return false;
                else if (board[j][i] != '.')
                    m[board[j][i]]++;
            }
        }
        
        return true;
    }
};