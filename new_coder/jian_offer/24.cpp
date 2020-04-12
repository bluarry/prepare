#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool verify(vector<int> s,int l,int r){
        int len=s.size();
        if(0==len ||l > r)return false;
        

        int left=l,root=s[r];
        //首先找着左子树
        for(;left<r;left++){
            if(s[left]>root) break;
        }
        int right=left;
        for(;right<r;right++){
            if(s[right]<root) return false;
        }

        bool ll=true;
        if(left>l)
            ll=verify(s,l,left-1);

        bool rr=true;
        if(right<r-1)
            rr=verify(s,left,r);
        return ll && rr;
    }


    bool VerifySquenceOfBST(vector<int> sequence) {
        return verify(sequence,0,sequence.size()-1);
    }
};


int main(){
    vector<int> v={5,7,6,9,11,10,8};
    Solution s;

    cout <<s.VerifySquenceOfBST(v)<<endl;



    return 0;
}