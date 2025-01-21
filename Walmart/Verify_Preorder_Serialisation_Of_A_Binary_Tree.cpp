# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {

        vector<string> v;

        string s = "";
        for (char c : preorder) {

            if (c != ',')
                s.push_back(c);
            else {

                v.push_back(s);
                s = "";
            }
        }
        v.push_back(s);
        cout << v.size();
        stack<string> st;

        for (int i = 0; i < v.size(); i++) {

            string t = v[i];

            if (st.empty() || t != "#")
                st.push(t);
            else {

                while (!st.empty() && st.top() == "#") {

                    st.pop();
                    if (st.empty())
                        return false;
                    st.pop();
                }

                st.push("#");
            }
        }
        if (st.size() == 1 && st.top() == "#")
            return true;

        return false;
    }
};