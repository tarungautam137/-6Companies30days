# include<bits/stdc++.h>
using namespace std;

    // Function to calculate the number of ways to reach the destination from the start point
    // with the given x-steps. The flag variable is used to determine whether the current step
    // is a step up (1) or a step down (0).

    // The function uses a map to store the intermediate states and their corresponding counts
    // to avoid redundant calculations.

class Solution {
public:
    int f(int start, int dest, int x, int flag,
          map<pair<int, pair<int, int>>, int>& mp) {

        if (start - dest >= 2)
            return 0;
        // ALWAYS USE MP.FIND(X) INSTEAD OF MP[X] TO CHECK IF A STATE EXISTS IN A MAP OR NOT.
        if (mp.find({start, {x, flag}}) != mp.end())
            return mp[{start, {x, flag}}];

        int ways = 0;
        if (flag)
            ways =
                f(start - 1, dest, x, 0, mp) + f(start + x, dest, 2 * x, 1, mp);
        else
            ways = f(start + x, dest, 2 * x, 1, mp);

        if (start == dest)
            return mp[{start, {x, flag}}] = ways + 1;

        return mp[{start, {x, flag}}] = ways;
    }
    int waysToReachStair(int k) {

        map<pair<int, pair<int, int>>, int> m;
        return f(1, k, 1, 1, m);
    }
};