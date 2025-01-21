# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {

        int n = ages.size(), count = 0;

        sort(ages.begin(), ages.end());

        for (int i = 0; i < n; i++) {

            int x = (ages[i] / 2) + 7;

            int ind1 = upper_bound(ages.begin(), ages.end(), x) - ages.begin();

            int ind2 =
                upper_bound(ages.begin(), ages.end(), ages[i]) - ages.begin();
            ind2--;

            if (ind1 <= i)
                count += (ind2 - ind1);
        }
        return count;
    }
};