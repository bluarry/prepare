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
    ListNode* Merge(ListNode *p, ListNode *q)
    {
    	if(p==NULL) return q;
    	if(q==NULL) return p;
    	
    	ListNode *ans=NULL;
    	
    	if(p->val < q->val){
    		ans =p;
    		ans->next=Merge(p->next,q);
		}else{
			ans=q;
			ans->next=Merge(p,q->next);
		}
		return ans;
    }
};

void cr(ListNode* p){

	p->next=new ListNode(3);
	p=p->next;
	p->next=new ListNode(4);
	p=p->next;
	p->next=new ListNode(5);
	p=p->next;
	p->next=new ListNode(6);
}
void cr2(ListNode* p){

	p->next=new ListNode(2);
	p=p->next;
	p->next=new ListNode(3);
	p=p->next;
	p->next=new ListNode(4);
	p=p->next;
	p->next=new ListNode(5);
}
void print(ListNode* p){
	while(p){
		cout << p->val<<endl;
		p=p->next;
	}
}

int main(){
	
	ListNode *p,*q;
	p=new ListNode(1);
	q=new ListNode(1);

	cr(p);
	cr(q);
	Solution s;
	ListNode *aa=s.Merge(p,q);
	print(aa);
	
	
	return 0;
}
