# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int h=0,v=0,ph=hBars[0],pv=vBars[0],count=0;

        for(int i=1;i<hBars.size();i++){

            if(hBars[i]==ph+1) count++;

            else {

                h=max(h,count);
                count=0;
            }
            ph=hBars[i];
        }

        h=max(h,count);
        count=0;

        for(int i=1;i<vBars.size();i++){

            if(vBars[i]==pv+1) count++; 
            
            else{

                v=max(v,count);
                count=0;
            }
            pv=vBars[i];
        }
        v=max(v,count);
        
        int side=min(h+1,v+1)+1;

        return side*side;
    }
};