#include <bits/stdc++.h>

using namespace std;

/*
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
不能使用除法。（注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，B[n-1] = A[0] * A[1] * ... * A[n-2];）
*/
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n=A.size();
        vector<int> f1(n,1),f2(n,1);
        for(int i=1;i<n;i++){
            f1[i]=f1[i-1]*A[i-1];
        }
        for(int i=n-2;i>=0;--i){
            f2[i]=f2[i+1]*A[i+1];
        }
        vector<int> B(n,0);
        for(int i=0;i<n;i++){
            B[i]=f1[i]*f2[i];
        }
        
        return B;
    }
};
int main(){




    return 0;
}