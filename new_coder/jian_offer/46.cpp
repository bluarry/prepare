#include <bits/stdc++.h>

using namespace std;

//用非正常的手段算1..n的和
class Solution_no {
public:
    int Sum_Solution(int n) {
        int sum=0;
        for(int i=1;i<=n;i++){
               sum+=i;
        }
         return sum;
    }
};

class Tmp{
public:
    Tmp(){++N;sum+=N;}
    static int getSum(){return sum;}
    static void Reset(){N=sum=0;}
private:
    static int N;
    static int sum;
};
int Tmp::N=0;
int Tmp::sum=0;
class Solution {
public:
    
    int Sum_Solution(int n) {
        Tmp::Reset();
        Tmp* t=new Tmp[n];
        delete[] t;
        t=NULL;
        return Tmp::getSum();
    }
};

/*
方法比较多，另外几种用c++特性的
*/
int main(){
    Solution s;
    cout << s.Sum_Solution(10) <<endl;



    return 0;
}