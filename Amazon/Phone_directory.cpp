# include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // BRUTE FORCE.
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> ans;
        vector<string> contacts;
        
        map<string,int> m;
        
        for(int i=0;i<n;i++) {
            
            string na=contact[i];
            
           m[na]++;
        }
        
        sort(contacts.begin(),contacts.end());
        
        string prefix="";
        
        for(int i=0;i<s.size();i++){
            
            prefix.push_back(s[i]);
            
            vector<string> temp;
            
            for(auto it=m.begin();it!=m.end();it++){
                
                auto p=*it;
                string name=p.first;
                
                int cs=name.size(),ps=prefix.size(),k=0;
                
                while(k<cs && k<ps){
                    
                    if(prefix[k]==name[k]) k++;
                    else break;
                }
                
                if(k==ps) temp.push_back(name);
            }
            
            if(temp.size()>0) ans.push_back(temp);
            
            else{
                
                while(i<s.size()){
                    
                    ans.push_back({"0"});
                    i++;
                }
            }
        }
        
        return ans;
    }
};