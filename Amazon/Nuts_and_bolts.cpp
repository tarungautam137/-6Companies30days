#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    
    void matchPairs(int n, char nuts[], char bolts[]) {
    
    vector<int> nu,b;
    
    for(int i=0;i<n;i++) nu.push_back(nuts[i]);
    for(int i=0;i<n;i++) b.push_back(bolts[i]);
    
    sort(nu.begin(),nu.end());
    sort(b.begin(),b.end());
    
    for(int i=0;i<n;i++) nuts[i]=nu[i];
    for(int i=0;i<n;i++) bolts[i]=b[i];
    }
};