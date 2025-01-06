# include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        
        map<pair<int,int>,int> m;
        vector<int> ans;
        
        for(int i=0;i<k;i++) m[{arr[i],i}]++;
        
        int i=0,j=k-1,n=arr.size();
        
        while(j<n){
            auto it=m.end();
            it--;
            auto p=*it;
            
            ans.push_back(p.first.first);
            
            j++;
            if(j<n) m[{arr[j],j}]++;
            
            m.erase({arr[i],i});
            i++;
        }
        return ans;
    }
};