# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        
        long long sum=mass;

        sort(asteroids.begin(),asteroids.end());
        
        for(int x:asteroids){

            if(sum>=x) sum+=x;
            else return false;
        }
        return true;
    }
};