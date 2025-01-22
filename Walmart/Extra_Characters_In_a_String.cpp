# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // SAME AS WORD BREAK , F(IND) GIVES MIN EXTRA CHARACTERS IN A STRING S FROM INDEX IND TO N-1.
    int f(int ind,string& s,vector<string>& words,vector<int>& dp){

        int n=s.size();

        if(ind==n) return 0;

        if(dp[ind]!=-1) return dp[ind];

        int mini=INT_MAX;

        for(string word:words){

            int len=word.size();

            if(ind+len>n) continue;

            bool flag1=true;
            for(int i=ind;i<ind+len;i++){

                if(s[i]!=word[i-ind]) {

                    flag1=false;
                    break;
                }
            }

            if(flag1){

                mini=min(mini,f(ind+len,s,words,dp));
            }
        }

        return dp[ind]=min(1+f(ind+1,s,words,dp),mini);

    }
    int minExtraChar(string s, vector<string>& words) {

        vector<int> dp(s.size(),-1);
        
        return f(0,s,words,dp);
    }
};