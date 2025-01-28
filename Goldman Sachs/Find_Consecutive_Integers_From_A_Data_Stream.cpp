# include<bits/stdc++.h>
using namespace std;

class DataStream {
public:
    // CAN BE SOLVED WITH QUEUE ALSO 
    
    vector<int> stream;
    unordered_map<int, int> mp;
    int val, K, i;

    DataStream(int value, int k) {

        val = value;
        K = k;
        i = 0;
    }

    bool consec(int num) {

        stream.push_back(num);
        mp[num]++;

        int n = stream.size();

        if (n < K) return false;
        else if (n == K) {

            if (mp[val] == K) return true;
            return false;
        }

        mp[stream[i]]--;
        i++;

        if (mp[val] == K) return true;
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */