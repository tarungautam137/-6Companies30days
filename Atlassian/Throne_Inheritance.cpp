# include <bits/stdc++.h>
using namespace std;

class ThroneInheritance {
public:

    unordered_map<string,vector<string>> mp;
    unordered_map<string,int> dead;

    string king;

    void dfs(string& king,vector<string>& ans){

        if(dead.find(king)==dead.end()) ans.push_back(king);

        for(string& child:mp[king]){

            dfs(child,ans);
        }
    }

    ThroneInheritance(string kingName) {
        
        king=kingName;
    }
    
    void birth(string parentName, string childName) {
        
        mp[parentName].push_back(childName);
    }
    
    void death(string name) {
        
        dead[name]++;
    }
    
    vector<string> getInheritanceOrder() {
        
        vector<string> ans;

        dfs(king,ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */