# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        
        int n=aliceValues.size();
        vector<pair<int,int>> v;

        for(int i=0;i<n;i++){

            int s=aliceValues[i]+bobValues[i];
            v.push_back({s,i});
        }
        sort(v.begin(),v.end());

        int a=0,b=0;

        bool flag=true;
        for(int i=n-1;i>=0;i--){

            auto p=v[i];

            int ind=p.second;

            if(flag){

                a+=aliceValues[ind];
                flag=!flag;
            }
            else{

                b+=bobValues[ind];
                flag=!flag;
            }
        }
        
        if(a>b) return 1;
        else if(a==b) return 0;
        return -1;
    }
};