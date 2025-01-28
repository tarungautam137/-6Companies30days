# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // OBSERVATION IS VERY IMPORTANT
    // O(1) FROM O(3*N^3)
    int longestString(int x, int y, int z) {

        if (x == y)
            return 2 * (x + y + z);

        int mini = min(x, y);
        return 2 * ((2 * mini) + 1 + z);
    }
};