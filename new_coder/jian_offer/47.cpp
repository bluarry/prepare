#include <bits/stdc++.h>

using namespace std;

//不用加减乘除做加法

class Solution {
public:
    int Add(int num1, int num2)
    {
        int sum,carry;
        do{
            sum=num1^num2;
            carry=(num1&num2)<<1;
            num1=sum;
            num2=carry;
        }while(num2!=0);
        return sum;
    }
};
int main(){

    Solution s;
    cout <<s.Add(-1,2) <<endl;


    return 0;
}