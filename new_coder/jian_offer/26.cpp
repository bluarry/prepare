#include <bits/stdc++.h>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution1 {
public:
    unordered_map<RandomListNode*,RandomListNode*> mp;
    RandomListNode* Clone(RandomListNode* pHead)
    {
        mp.clear();
        RandomListNode *qHead=pHead,*tHead=NULL,*pre=NULL;
        while(qHead){
            RandomListNode* n=new RandomListNode(qHead->label);
            if(tHead==NULL){
                tHead=n;               
            }else{
                pre->next=n;                
            }
            mp[qHead]=n;
            pre=n;
            qHead=qHead->next;
        }
        qHead=pHead;
        pre=tHead;
        while(qHead){
            if(qHead->random){
                RandomListNode *v=mp[qHead->random];
                pre->random=v;   
            }
            pre=pre->next;
            qHead=qHead->next;
        }
        return tHead;   
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        //第一步，每一个节点后面插入一个本身的复制节点
        RandomListNode *qHead=pHead,*tHead=NULL,*pre=NULL;
        while(qHead){
            RandomListNode* n=new RandomListNode(qHead->label);
            n->next=qHead->next;
            qHead->next=n;
            qHead=n->next;
        }
        
        
        qHead=pHead;
        while(qHead){
            RandomListNode* n=qHead->next;
            if(qHead->random){
                n->random=qHead->random->next;
            }
            qHead=n->next;
        }
        qHead=pHead;
        while(qHead){
            if(tHead==NULL){
                tHead=qHead->next;
                pre=tHead;
            }else{
                pre->next=qHead->next;
                pre=pre->next;
            }
            qHead->next=qHead->next->next;
            
            qHead=qHead->next;
        }

        return tHead;   
    }
};

void t(RandomListNode *&h){
    h=new RandomListNode(3);
    RandomListNode *q=h;
    RandomListNode *r=new RandomListNode(2);
    q->next=r;q=r;
    r=new RandomListNode(6);
    q->next=r;q=r;
    r=new RandomListNode(1);
    q->next=r;q=r;
    r=new RandomListNode(5);
    q->next=r;q=r;
}


int main(){
    RandomListNode *h=NULL;
    t(h);
    Solution s;
    RandomListNode *t=s.Clone(h);
    while(t){
        cout << t->label<<endl;
        t=t->next;
    }


    return 0;
}