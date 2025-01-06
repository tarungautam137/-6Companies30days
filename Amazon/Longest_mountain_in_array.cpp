# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {

        int n = arr.size(), start = n, maxi = 0;

        for (int i = 0; i <= n - 3; i++) {
            if (arr[i] < arr[i + 1]) {
                start = i;
                break;
            }
        }
        while (start <= n - 3) {

            int j = start + 1;

            while (j < n - 1 && arr[j] < arr[j + 1])
                j++;

            if (j == n - 1)
                break;

            if (arr[j] == arr[j + 1]) {

                while (j < n - 1 && arr[j + 1] <= arr[j])
                    j++;
                start = j;
            } else {

                while (j < n - 1 && arr[j + 1] < arr[j])
                    j++;
                maxi = max(maxi, j - start + 1);

                while (j < n - 1 && arr[j + 1] <= arr[j])
                    j++;
                start = j;
            }
        }
        return maxi;
    }
};