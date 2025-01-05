# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int ind,vector<int>& needs,vector<int>& price,vector<vector<int>>& special,vector<int>& zero,map<pair<int,vector<int>>,int>& mp){

        int n=needs.size();

        if(needs==zero) return 0;

        if(ind<0){

            int cost=0;
            for(int i=0;i<n;i++) cost+=(needs[i]*price[i]);
            return cost;
        }
        if(mp[{ind,needs}]) return mp[{ind,needs}];

        int take=INT_MAX,nottake=INT_MAX;

        bool flag=true;

        for(int i=0;i<n;i++){
            if(special[ind][i]>needs[i]){
                flag=false;
                break;
            }
        }

        if(flag) {
            for(int i=0;i<n;i++) needs[i]-=special[ind][i];
            take=f(ind,needs,price,special,zero,mp)+special[ind][n];
            for(int i=0;i<n;i++) needs[i]+=special[ind][i];
        } 

        nottake=f(ind-1,needs,price,special,zero,mp);

        return mp[{ind,needs}]= min(take,nottake);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        
        int m=special.size(),n=price.size();
        vector<int> zero(n,0);

        map<pair<int,vector<int>>,int> mp;

        return f(m-1,needs,price,special,zero,mp);
    }
};