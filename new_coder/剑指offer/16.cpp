#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;



struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
         
        if(pHead==NULL) return NULL;
         
        ListNode* p=pHead;
        ListNode* pReverseHead=NULL;
        ListNode* q=NULL;
         
        while(p!=NULL){
            ListNode* r=p->next;
             
            if(r==NULL)
                pReverseHead=p;
  
            p->next=q;
            q=p;
            p=r;
        }
        return pReverseHead;
    }
};

void print(ListNode* p){
	while(p){
		cout << p->val<<endl;
		p=p->next;
	}
}
int main(){
	ListNode *p,*q;
	q=p=new ListNode(1);
	p->next=new ListNode(2);
	p=p->next;
	p->next=new ListNode(3);
	p=p->next;
	p->next=new ListNode(4);
	p=p->next;
	p->next=new ListNode(5);
	
	print(q);
	
	Solution s;
	p=s.ReverseList(q);
	
	
	print(p);
	
	return 0;
}
