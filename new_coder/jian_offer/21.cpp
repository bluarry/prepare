#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;


class Solution {
private:
    stack<int> m_data;
    stack<int> m_min;
public:
    void push(int value) {
        m_data.push(value);

        if(m_min.size()==0||value < m_min.top()){
            m_min.push(value);
        }else{
            m_min.push(m_min.top());
        }
    }
    void pop() {
        if(m_data.size()>0&& m_min.size()>0){
            m_data.pop();
            m_min.pop();
        }
    }
    int top() {
       return m_data.top();
    }
    int min() {
        return m_min.top();
    }
};

int main(){
    Solution s ;
    s.push(1);
    cout << s.min()<<endl;
    s.push(0);
    cout << s.min()<<endl;
    s.pop();
    cout << s.min()<<endl;


    return 0;
}