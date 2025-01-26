# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // RABIN-KARP WILL WORK.
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        
        long long ha=0,hb=0,num=1;

        int i=a.size()-1;

        while(i>=0){

            ha+=(num*(int(a[i]-'a')+1));
            num*=10;
            i--;
        }

        i=b.size()-1;num=1;

        while(i>=0){

            hb+=(num*(int(b[i]-'a')+1));
            num*=10;
            i--;
        }

        i=a.size()-1;num=1;
        long long sum=0;

        while(i<s.size() && i>=0){

            sum+=(num*(int(s[i]-'a')+1));
            num*=10;
            i--;
        }
        num=num/10;

        int ind=a.size()-1,start=0;
        vector<int> ai,bi;
 
        while(ind<s.size()){

            if(sum==ha) {

                string t="";
                for(int k=start;k<=ind;k++) t.push_back(s[k]);
                if(t==a) ai.push_back(start);
            }

            ind++;
            if(ind<s.size()){

                sum=sum-(num*(int(s[start]-'a')+1));

                sum*=10;
                sum+=int(s[ind]-'a')+1;
                start++;
            }
        }

        i=b.size()-1;num=1;sum=0;

        while(i<s.size() && i>=0){

            sum+=(num*(int(s[i]-'a')+1));
            num*=10;
            i--;
        }
        num=num/10;
        ind=b.size()-1;start=0;

        while(ind<s.size()){

            if(sum==hb) {

                string t="";
                for(int k=start;k<=ind;k++) t.push_back(s[k]);
                if(t==b) bi.push_back(start);                
            }

            ind++;
            if(ind<s.size()){

                sum=sum-(num*(int(s[start]-'a')+1));
                sum*=10;
                sum+=int(s[ind]-'a')+1;
                start++;
            }
        }

        vector<int> ans;
        if(ai.size()==0 || bi.size()==0) return ans;

        for(int x:ai){

            int ind1=lower_bound(bi.begin(),bi.end(),x-k)-bi.begin();
            int ind2=upper_bound(bi.begin(),bi.end(),x+k)-bi.begin()-1;

            if(ind1>=bi.size() || ind2<0) continue;

            if(ind1<=ind2) ans.push_back(x);
        }  
        
        return ans;  
    }
};