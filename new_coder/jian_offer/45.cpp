#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n<1||m<1) return -1;
        list<int> num;
        for(int i=0;i<n;i++){
            num.push_back(i);
        }
        auto current=num.begin();
        while(num.size()>1){
            for(int i=1;i<m;i++){
                current++;
                if(current==num.end())
                    current=num.begin();
            }
            // cout << *current <<endl;
            auto next=++current;
            if(next==num.end()) next=num.begin();
            --current;
            num.erase(current);
            current=next;
        }
        return *current;
    }
};
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
         if(n<1||m<1) return -1;
         int last=0;
         for(int i=2;i<=n;i++){
             last=(last+m)%i;
         }
         return last;
    }
};
int main(){
    Solution s;
    cout << s.LastRemaining_Solution(5,3)<<endl;



    return 0;
}