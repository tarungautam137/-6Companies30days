# include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    string printMinNumberForPattern(string S){
       
       stack<int> st;
       string ans="";
       
       int n=S.size();
       
       for(int i=1;i<=(n+1);i++){
           
           if(S[i-1]=='D') st.push(i);
           
           if(i==n+1 || S[i-1]=='I'){
               
                ans.push_back(char(i+'0'));
               while(!st.empty()){
                   
                   int x=st.top();
                   st.pop();
                   
                   ans.push_back(char(x+'0'));
               }
              
           }
       }
       return ans;
    }
};