# include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:

    void f(TreeNode* root,string str,vector<string>& v){

        if(root==NULL) return;

        if(root->left==NULL&&root->right==NULL){

            v.push_back(str);
            return;
        }

        str.push_back('L');
        f(root->left,str,v);

        str.pop_back();

        str.push_back('R');
        f(root->right,str,v);
    }
    int countPairs(TreeNode* root, int distance) {

        vector<string> v;

        string str;

        f(root,str,v);

        int count=0;

        for(int i=0;i<v.size()-1;i++){

            for(int j=i+1;j<v.size();j++){

             int s=v[i].size(),t=v[j].size(),d=0;

             for(int k=0;k<t;k++){

                if(v[i][k]!=v[j][k]){

                    d=(s-k)+(t-k);

                    if(d<=distance) count++;
                    
                    break;
                }
             }
            }
        }
       
        return count;
    }
};