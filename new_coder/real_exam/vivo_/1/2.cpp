#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

/**
 * 会越界溢出！！
 * */
class Solution {
public:
    map<int,int> mp;
    bool isPrime(int n){
        if(n==2||n==3)	return 1;
        if(n%6!=1&&n%6!=5)	return 0;
        for(int i=5;i<=floor(sqrt(n));i+=6)
            if(n%i==0||n%(i+2)==0)	return 0;
        return 1;
    }

    //x和n
    int dofind(int x,int n){
        int y=n/x,xx=0,yy=0;
        //cout <<x <<" " <<y <<endl;
        if(x<10 && y<10) return x*10+y;
        else {
            if(0!=mp.count(x)){
                xx= mp[x];
            }else
                xx=x<10?x:solution(x);
            if(0!=mp.count(y)){
                yy= mp[y];
            }else
                yy=y<10?y:solution(y);
            //cout <<xx <<".." <<yy <<endl;
        }
        vector<int> v;
        while(xx){
            v.push_back(xx%10);
            xx/=10;
        }
        while(yy){
            v.push_back(yy%10);
            yy/=10;
        }
        sort(v.begin(),v.end());
       	double ans=0;
        for(int i=0;i<v.size();i++){
                ans=ans*10+v[i];
            
        }
        return ans;
    }


    //返回最小的一位整数组成的数字
    int solution(int n) {
        if(0!=mp.count(n)){
            return mp[n];
        }
        if(isPrime(n)){
            return -1;
        }
        vector<int> y,ans;        
        for(int i=2;i<=(int)sqrt(n);i++){
            if(n%i==0){
                y.push_back(i);
            }
        }
        int mm=INT_MAX-1;
        for(int i=0;i<y.size();i++){
            mm=min(mm,dofind(y[i],n));
        }
        mp[n]=mm;
        return mm;
    }
};


class Solution1 {
public:
    /**
     * 输入一个整形数值，返回一个整形值
     * @param n int整型 n>9
     * @return int整型
     */
   int solution(int n) {
    // write code here
        string s = "";
        for (int i = 9; i >= 2 && n != 1; i--)
        {
            while (n % i == 0)
            {
                s += ('0' + i);
                n /= i;
            }
        }
        reverse(s.begin(), s.end());
        return n == 1 ? stoi(s) : -1;
    }
};
int main(){


    Solution s;
    int c;
    cout <<s.solution(387420489) <<endl;

    


    return 0;
}
