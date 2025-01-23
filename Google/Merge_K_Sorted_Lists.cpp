# include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        vector<vector<int>> v;

        for (auto& it : lists) {

            vector<int> temp;

            auto ptr = it;
            while (ptr != NULL) {

                temp.push_back(ptr->val);
                ptr = ptr->next;
            }
            v.push_back(temp);
        }
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        for (int i = 0; i < v.size(); i++) {

            if (v[i].size())
                pq.push({v[i][0], {i, 0}});
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while (!pq.empty()) {

            auto p = pq.top();
            pq.pop();

            int val = p.first, r = p.second.first, c = p.second.second;

            if (c + 1 < v[r].size())
                pq.push({v[r][c + 1], {r, c + 1}});

            ListNode* node = new ListNode(val);
            curr->next = node;
            curr = node;
        }
        return dummy->next;
    }
};