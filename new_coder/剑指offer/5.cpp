#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <vector>

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
		vector<int> printListFromTailToHead(ListNode* head) {
			vector<int> v;
			stack<int> s;
			v.clear();
			while(head!=NULL){
				s.push(head->val);
				head=head->next;
			}
			while(!s.empty()){
				v.push_back(s.top());
				s.pop();	
			}
			return v;
		}
};


int main(){
	ListNode l(3);
	Solution s;
	vector<int> res=s.printListFromTailToHead(&l);
	for(int x : res){
		cout << x <<endl;
	}
	
	return 0;
}
