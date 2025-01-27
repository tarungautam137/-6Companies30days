# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        int count=0;

        for(int i=0;i<arr1.size();i++){

            int c=0;
            for(int j=0;j<arr2.size();j++){

                if(abs(arr1[i]-arr2[j])>d) c++;
            }
            if(c==arr2.size()) count++;
        }

        return count;
    }
};