/*leetcode 23 :
Merge k sorted linked lists and return it as one sorted list.
Analyze and describe its complexity.*/

#include<iostream>
#include<vector>
using namespace std;


struct ListNode {       //node
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


bool operator >(ListNode x,ListNode y){
    return (x.val)>(y.val);
}
bool operator <(ListNode x,ListNode y){
    return (x.val)<(y.val);
}

template <class T>       //heap
class Heap{
public:
    Heap(int n):size(0),maxsize(n+1){
        heap = new T[n+1];
    }

    void insert(const T& ele){
        heap[size] = ele;
        shiftup(size);
        size++;

    }
    T del(){
        auto res = heap[0];
        heap[0] = heap[size-1];
        size--;
        shiftdown(0);
        return res;
    }
    int _size(){
        return size;
    }
private:
    void shiftdown(int n){

        while(2*n+1<size){
            int l = 2*n+1;
            int r = 2*n+2;
            int temp = n;
            if(heap[temp][0]>heap[l][0])
                temp = l;
            if(r<size&&heap[temp][0]>heap[r][0])
                temp = r;
            if(temp != n){
                auto k = heap[n];
                heap[n] = heap[temp];
                heap[temp] = k;
                n = temp;
            }
            else break;
        }
    }
    void shiftup(int n){
        int pre = (n-1)/2;
        while(pre>=0){
            if(heap[pre][0]>heap[n][0]){
                auto k = heap[n];
                heap[n] = heap[pre];
                heap[pre] = k;
                n = pre;
                pre = (n-1)/2;
            }
            else break;
        }
    }
    T *heap;
    int size;
    int maxsize;
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        Heap<ListNode*> H(lists.size());

        ListNode* head =  new ListNode(0);
        ListNode* cur = head;
        for(auto i:lists){
            H.insert(i);
        }
        while(H._size()){
            ListNode * temp = H.del();
            cur->next = temp;
            cur = cur->next;
            if(temp->next!= nullptr){
                H.insert(temp->next);
            }
            cur->next = nullptr;
        }
        return head->next;
    }

};
