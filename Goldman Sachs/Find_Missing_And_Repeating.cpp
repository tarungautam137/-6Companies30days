# include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        
        unordered_map<int,int> mp;
        
        for(int x:arr) mp[x]++;
        
        vector<int> ans(2);
        
        for(int i=1;i<=arr.size();i++){
            
            if(mp.find(i)==mp.end()) ans[1]=i;
            else if(mp[i]==2) ans[0]=i;
        }
        return ans;
    }
};