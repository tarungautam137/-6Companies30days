# include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:

    vector<int> v;
    int k;

    priority_queue<int, vector<int>, greater<int>> heap;

    KthLargest(int x, vector<int>& nums) {

        k = x;
        v = nums;

        for (int i : v) {

            if (heap.size() < k) {
                
                heap.push(i);
            } else {

                int t = heap.top();

                if (i >= t) {

                    heap.pop();
                    heap.push(i);
                }
            }
        }
    }

    int add(int val) {

        int n = heap.size();

        if (n < k) {
            heap.push(val);
        } else {

            if (heap.top() < val) {

                heap.pop();
                heap.push(val);
            }
        }
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */