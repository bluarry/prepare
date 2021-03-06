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
class Solution1 {
public:
    ListNode* FindKthToTail(ListNode* Head, unsigned int k) {
        if(Head==NULL || k==0) return NULL;
        
        ListNode* pHead=Head;
        ListNode* pEnd=Head;
        
        int num=0;
        while(pHead && num!=k-1){
            pHead=pHead->next;
            num++;
        }
        if(pHead==NULL) return NULL;
        
        while(pHead->next!=NULL){
            pHead=pHead->next;
            pEnd=pEnd->next;
        }
        
        return pEnd;
    }
};

class Solution {
public:
    void reOrderArray(vector<int> &ar) {
    	int len = ar.size();
    	int r=len-1,l=len-1;
    	while(l>=0){
    		if(l==0 &&(ar[l]&1) ==1) return;
    		while(l>=0 && (ar[l]&1) ==1 )l--;
    		if(l<0 ) return;
    		int k=ar[l];
    		int i=l--;
    		while(i<r){
    			ar[i]=ar[i+1];
    			i++;
			}
			ar[r--]=k;
		}
    }
};

int main(){
	Solution s;
	vector<int> a={2,4,6,1,3,5,7};
	//vector<int> a={1,2,3,4,5,6,7};
	
	s.reOrderArray(a);
	
	for(int x:a){
		cout << x <<endl;
	}
	
	
	return 0;
}
