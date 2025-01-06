# include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};
class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        
        vector<int> v;
        
        while(head!=NULL){
            v.push_back(head->data);
            head=head->next;
        }
        
        vector<int> nums;
        int i=0,ss=v.size();
        
        while(i<ss){
            
            int y=m;
            
            while(y--){
                nums.push_back(v[i]);
                i++;
                if(i>=ss) break;
            }
            
            i+=n;
        }
        Node* Head=new Node(nums[0]);
        Node* curr=Head;
        
        for(int j=1;j<nums.size();j++){
            
            Node* newnode= new Node(nums[j]);
            curr->next=newnode;
            curr=newnode;
        }
        return Head;
    }
};