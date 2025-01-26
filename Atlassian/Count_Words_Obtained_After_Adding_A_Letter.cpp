# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        
        unordered_map<string,int> target;
        for(string& s:targetWords) {

            sort(s.begin(),s.end());
            target[s]++;
        }
        unordered_map<string,int> mp;

        for(string& s:startWords){

            for(int i=0;i<26;i++){

                string t=s;

                char ch=char(i+97);
                t.push_back(ch);

                sort(t.begin(),t.end());

                if(target.find(t)!=target.end()) mp[t]++;
            }
        }
        int count=0;
        for(string& s:targetWords){

            if(mp.find(s)!=mp.end()) count++;
        }
        return count;
    }
};