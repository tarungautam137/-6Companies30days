# include<bits/stdc++.h>
using namespace std;


  // This is the MountainArray's API interface.
  // You should not implement it, or speculate about its implementation
class MountainArray {
    public:
      int get(int index);
      int length();
};

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int n=mountainArr.length(),low=0,high=n-1,peak=1,curr,prev,next;
        
        while(low<=high){

            int mid=(low+high)/2;

            if(mid==0) mid=1;
            else if(mid==n-1) mid=n-2;

            curr=mountainArr.get(mid);
            prev=mountainArr.get(mid-1);
            next=mountainArr.get(mid+1);

            if(curr>prev && curr>next){
                peak=mid;
                break;
            }
            else if(curr>prev && curr<next) low=mid+1;
            else high=mid-1;
        }
        if(curr==target) return peak;
        
        low=0;high=peak-1;

        while(low<=high){

            int mid=(low+high)/2;

            curr=mountainArr.get(mid);

            if(curr==target) return mid;
            else if(curr>target) high=mid-1;
            else low=mid+1;
        }

        low=peak+1;high=n-1;

        while(low<=high){

            int mid=(low+high)/2;

            curr=mountainArr.get(mid);

            if(curr==target) return mid;
            else if(curr<target) high=mid-1;
            else low=mid+1;
        }

        return -1;
    }
};