#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};
class Solution1 {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==NULL || pHead2==NULL) return NULL;
        stack<ListNode*> s1,s2;
        while(pHead1){
            s1.push(pHead1);
            cout <<s1.top()->val <<endl;
            pHead1=pHead1->next;
        }
        while(pHead2){
            s2.push(pHead2);
            cout <<s2.top()->val <<endl;
            pHead2=pHead2->next;
        }
        ListNode* ans=NULL;
        while(!s1.empty()&& !s2.empty() &&s1.top()==s2.top()){
            ans=s1.top();
            s1.pop();
            s2.pop();
        }
        return ans;
    }
};

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==NULL || pHead2==NULL) return NULL;
        ListNode *p=pHead1,*q=pHead2;
        int len1=0,len2=0;
        while(p){
            len1++;
            p=p->next;
        }
        while(q){
            len2++;
            q=q->next;
        }

        if(len1<len2){
            int t=len2-len1;
            while(t>0){
                pHead2=pHead2->next;
                t--;
            }
           
        }else{
            int t=len1-len2;
            while(t>0){
                pHead1=pHead1->next;
                t--;
            }
             
        }

        while(pHead1!=NULL && pHead2!=NULL && pHead1->next!=pHead2->next){
            pHead1=pHead1->next;
            pHead2=pHead2->next;
        }
        ListNode *ans=NULL;
        if(pHead1==pHead2){
            ans=pHead1;
        }else if(pHead1->next!=NULL){
            ans=pHead1->next;
        }else if(pHead2->next!=NULL){
            ans=pHead2->next;
        }
        return ans;
    }
};

void v(ListNode* &p){
    p=new ListNode(1);
    ListNode *q=p;
    q->next=new ListNode(2);
    q=q->next;
    q->next=new ListNode(3);
    q=q->next;
    q->next=new ListNode(4);
    q=q->next;
    q->next=new ListNode(5);
}

int main(){
    ListNode *p=NULL;
    v(p);
    Solution s;
    ListNode* q=s.FindFirstCommonNode(p,p);
    while(q){
        cout << q->val << " ";
        q=q->next;
    }cout << endl;


    return 0;
}