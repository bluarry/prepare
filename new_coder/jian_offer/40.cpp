#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int findindex(int data){
        int index=0;
        while(((data&1)==0)&& index < 8*sizeof(int)){
            data=data>>1;
            index++;
        }
        return index;
    }
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int len=data.size();
        if(len<=0) return;
        int res=0;
        for(auto x:data) res^=x;
        int indexi=findindex(res);
        //cout << indexi<<endl;
        *num1=*num2=0;
        for(int i=0;i<data.size();i++){
            if(((data[i]>>indexi)&1)==1){
                *num1 ^=data[i];
            }else{
                *num2 ^=data[i];
            }
        }
    }
};

int main(){
    vector<int> v={1,1,3,6};
    int num1,num2;
    Solution s;
    s.FindNumsAppearOnce(v,&num1,&num2);
    cout << num1 << " " << num2 <<endl;


    return 0;
}