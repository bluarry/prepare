#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>


using namespace std;


class Solution {
public:
    int llen;
    int findcsum(vector<int>& nums,int l,int r,int p){
        if(l>=r) return nums[l];
        int lsum=INT32_MIN;
        int lcs=0;
        for(int i=p;i>l-1;--i){
            lcs+=nums[i];
            lsum=max(lcs,lsum); 
        }

        int rsum=INT32_MIN;
        int rcs=0;
        for(int i=p+1;i<r+1;++i){
            rcs+=nums[i];
            rsum=max(rcs,rsum);
        }
        return rsum+lsum;
    }
    int run(vector<int>& nums,int l,int r){
        if(l>=r){
            return nums[l];
        }
        int p=(r+l)/2;
       
        int lsum=run(nums,l,p);
        int rsum=run(nums,p+1,r);
        int csum=findcsum(nums,l,r,p);
      
        return max(csum,max(lsum,rsum));
    }
    int maxSubArray(vector<int>& nums) {
        return run(nums,0,nums.size()-1);
    }
};



class Solution2 {
public:
    int llen;
    int maxSubArray(vector<int>& nums) {
        llen=nums.size();
        int r=INT32_MIN;
        int s=0;
        for(int i=0;i<llen;i++){
            s+=nums[i];
            r=max(r,s);
            if(s<0){
                s=0;
            }
        }
        return r;
    }
};

class Solution1 {
public:
    int llen;
    int maxSubArray(vector<int>& nums) {
        llen=nums.size();
        int cur=nums[0],m=nums[0];
        for(int i=1;i<llen;i++){
            cur=max(nums[i],cur+nums[i]);
            m=max(cur,m);
        }
        return m;
    }
};

int main(){
    vector<int> nums={-2,0,-1};
    Solution s;
    cout << s.maxSubArray(nums) <<endl;
    return 0;
}

