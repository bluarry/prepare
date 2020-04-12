#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
	public:
		void push(int node) {
			stack1.push(node);
		}

		int pop() {
			int re=0;
			if(!stack2.empty()) {
				re=stack2.top();
				stack2.pop();
			} else {
				while(!stack1.empty()) {
					stack2.push(stack1.top());
					stack1.pop();
				}
				re=stack2.top();
				stack2.pop();
			}
			return re;
		}

	private:
		stack<int> stack1;
		stack<int> stack2;
};

int main() {
	Solution s;
	s.push(5);
	s.push(4);;
	s.push(3);
	cout << s.pop()<<endl;
	s.push(4);;
	s.push(3);
	cout << s.pop()<<endl;
	cout << s.pop()<<endl;
	cout << s.pop()<<endl;
	return 0;
}
