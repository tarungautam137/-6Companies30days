# include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
  right(right) {}
 };
 
class Solution {
public:
    void createAdjacencyList(unordered_map<int, vector<int>>& adj,
                             TreeNode* root) {

        TreeNode* l = root->left;
        TreeNode* r = root->right;

        if (l != NULL) {

            adj[root->val].push_back(l->val);
            adj[l->val].push_back(root->val);

            createAdjacencyList(adj, l);
        }
        if (r != NULL) {

            adj[root->val].push_back(r->val);
            adj[r->val].push_back(root->val);

            createAdjacencyList(adj, r);
        }
    }
    int amountOfTime(TreeNode* root, int start) {

        unordered_map<int, vector<int>> adj;
        createAdjacencyList(adj, root);

        unordered_map<int, int> vis;

        queue<pair<int, int>> q;

        q.push({start, 0});
        vis[start]++;

        int mt = 0;
        while (!q.empty()) {

            auto p = q.front();
            q.pop();

            int node = p.first, t = p.second;
            mt = max(mt, t);

            for (int nebor : adj[node]) {

                if (!vis[nebor]) {

                    q.push({nebor, t + 1});
                    vis[nebor]++;
                }
            }
        }
        return mt;
    }
};