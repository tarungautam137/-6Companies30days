#include<bits/stdc++.h>
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
    pair<bool,vector<int>> f(TreeNode* root,int& maxi){

        if(root==NULL) return {true,{0,-1000000,1000000}};

        auto pl=f(root->left,maxi);
        auto pr=f(root->right,maxi);

        bool flag=false;
        int sum=0,minim=0,maxim=0;

        if(pl.first && pr.first && root->val>pl.second[1] && root->val<pr.second[2]) {

            flag=true;

            sum=pl.second[0]+pr.second[0]+root->val;
            maxi=max(maxi,sum);

            maxim=pr.second[1];
            if(maxim==-1000000) maxim=root->val;

            minim=pl.second[2];
            if(minim==1000000) minim=root->val;

            return {flag,{sum,maxim,minim}};
        }
        return {flag,{sum,maxim,minim}};
    }
    int maxSumBST(TreeNode* root) {
        
        int maxi=0;

        auto p=f(root,maxi);

        return maxi;
    }
};