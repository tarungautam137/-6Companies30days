# include <bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string s = "";
        if (root == NULL)
            return s;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            if (node != NULL) {

                s += to_string(node->val) + ".";

                TreeNode* l = node->left;
                TreeNode* r = node->right;

                q.push(l);
                q.push(r);
            } else
                s += "+.";
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if (data == "")
            return NULL;

        queue<TreeNode*> q;

        string s;
        int j = 0, n = data.size();

        while (data[j] != '.') {
            s.push_back(data[j]);
            j++;
        }
        j++;

        TreeNode* node = new TreeNode(stoi(s));
        q.push(node);

        while (!q.empty() && j < n) {

            TreeNode* curr = q.front();
            q.pop();

            string l;

            while (data[j] != '.') {
                l.push_back(data[j]);
                j++;
            }
            j++;

            if (l != "+") {

                TreeNode* le = new TreeNode(stoi(l));
                q.push(le);
                curr->left = le;
            } else
                curr->left = NULL;

            string r;

            while (data[j] != '.') {
                r.push_back(data[j]);
                j++;
            }
            j++;

            if (r != "+") {

                TreeNode* re = new TreeNode(stoi(r));
                q.push(re);
                curr->right = re;
            } else
                curr->right = NULL;
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));