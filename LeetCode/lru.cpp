
/*------------------------------------------------------------------------------------------
Author: JugheadJones13
Site: 	
Date: 2020 Oct 13 06:05:01 PM	

--------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    struct node{
        int val;
        struct node * next;
        struct node * prev;
        node(){
            val = -1;
            next = NULL;
            prev = NULL;
        }
    };
    vector<struct node*>* nodes;
    struct node* head;
    struct node* tail;
    int cap;
    int used;
    LRUCache(int capacity) {
        nodes = new vector<struct node*> (3001,NULL);
        head = new struct node();
        tail = new struct node();
        head->val = -2;
        tail->val = -3;
        head->next = tail;
        tail->prev = head;
        used = 0;
        cap = capacity;
    }
    
    int get(int key) {
        int ans = -1;
        if (nodes->at(key) == NULL || nodes->at(key)->val == -1){
            return -1;
        }
        else{
            ans = nodes->at(key)->val;
            struct node* t1 = nodes->at(key);
            struct node* t0 = t1->prev;
            struct node* t2 = t1->next;
            t0->next = t2;
            t2->prev = t0;
            t1->prev = head;
            t1->next = head->next;
            head->next = t1;
            t1->next->prev = t1;
        }
        return ans;
    }
    
    void put(int key, int value) {
        struct node* t1 = nodes->at(key);
        if (t1 == NULL) {
            nodes->at(key) = new struct node();
            t1 = nodes->at(key);
        }
        if (t1->val != -1){
            t1->val = value;
            struct node* t0 = t1->prev;
            struct node* t2 = t1->next;
            t0->next = t2;
            t2->prev = t0;
            t1->prev = head;
            t1->next = head->next;
            head->next = t1;
            t1->next->prev = t1;
        }
        else{
            if (cap - used > 0){
                t1->val = value;
                t1->prev = head;
                t1->next = head->next;
                head->next = t1;
                t1->next->prev = t1;
                used++;
            }
            else{
                struct node* last = tail->prev;
                tail->prev = last->prev;
                last->prev->next = tail;
                last->val = -1;
                last->prev = NULL;
                last->next = NULL;
                t1->val = value;
                t1->prev = head;
                t1->next = head->next;
                head->next = t1;
                t1->next->prev = t1;
            }
        }
    }
    
    void prlist(){
        struct node* curr = head;
        while (curr){
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << '\n';
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
	LRUCache* obj = new LRUCache(3);
	obj->put(1,1);
	obj->put(2,2);
	obj->put(3,3);
	obj->put(4,4);
	cout << obj->get(4) << endl;
	cout << obj->get(3) << endl;
	cout << obj->get(2) << endl;
	cout << obj->get(1) << endl;
	obj->put(5,5);
	cout << obj->get(1) << endl;
	cout << obj->get(2) << endl;
	cout << obj->get(3) << endl;
	cout << obj->get(4) << endl;
	cout << obj->get(5) << endl;
	return 0;
}

