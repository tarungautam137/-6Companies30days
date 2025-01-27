# include <bits/stdc++.h>
using namespace std;

// HASHMAP AND DOUBLY-LINKED LIST
class LRUCache {
public:
    class Node {
    public:
        int K, V;
        Node* prev;
        Node* next;

        Node(int k, int val) {

            K = k;
            V = val;
            prev = NULL;
            next = NULL;
        }
    };

    int cap;
    unordered_map<int, Node*> mp;

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    LRUCache(int capacity) {

        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void add(Node* newnode) {

        Node* temp = head->next;

        head->next = newnode;
        newnode->prev = head;

        newnode->next = temp;
        temp->prev = newnode;
    }

    void del(Node* node) {

        Node* pn = node->prev;
        Node* nn = node->next;

        pn->next = nn;
        nn->prev = pn;
    }
    int get(int key) {

        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];
            int ans = node->V;

            mp.erase(key);
            del(node);

            add(node);
            mp[key] = head->next;

            return ans;
        }
        return -1;
    }

    void put(int key, int value) {

        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            node->V = value;

            mp.erase(key);
            del(node);

            add(node);
            mp[key] = head->next;
        } else {

            if (mp.size() == cap) {

                Node* node = tail->prev;

                int k = node->K;
                mp.erase(k);

                del(node);
            }
            Node* newnode = new Node(key, value);
            add(newnode);
            mp[key] = head->next;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */