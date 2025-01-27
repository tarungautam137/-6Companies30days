# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCollisions(string directions) {

        stack<char> st;
        int i = 0, n = directions.size(), count = 0;

        while (i < n) {

            char curr = directions[i];

            if (curr == 'L') {

                if (!st.empty()) {

                    if (st.top() == 'S')
                        count++;
                    else {

                        count += 2;
                        curr = 'S';
                        st.pop();
                    }
                }
            }
            if (curr == 'S') {

                while (!st.empty() && st.top() == 'R') {

                    count++;
                    st.pop();
                }
                st.push('S');
            }
            if (curr == 'R') {

                st.push(curr);
            }

            i++;
        }
        return count;
    }
};