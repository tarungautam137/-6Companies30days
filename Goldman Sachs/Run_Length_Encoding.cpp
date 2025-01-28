# include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string encode(string s) {
        
        int n=s.size();
        string ans="";
        
        int i=0,j=1;
        
        while(j<n){
            
            while(s[i]==s[j] && j<n) j++;
            
            ans.push_back(s[i]);
            string t=to_string(j-i);
            ans+=t;
            
            i=j;
            j++;
        }
        if(i==n-1) {
            
            ans.push_back(s[i]);
            ans.push_back('1');
        } 
        return ans;
    }
};