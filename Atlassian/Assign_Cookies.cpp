# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size(),m=s.size(),count=0;
        
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        for(int i=0,j=0;j<m && i<n;){
            if(s[j]>=g[i]){
                count++;
                i++;j++;
            }
            else{
                j++;
            }
        }
        return count;
    }
};