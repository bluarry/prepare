#include <bits/stdc++.h>

using namespace std;


class Solution1 {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        sort(numbers.begin(),numbers.end());
        int len=numbers.size();
        int half=len/2;
        //if(len==1) return numbers[0];
        for(int i=0;i<=half+1;i++){
            if(numbers[i]==numbers[i+half]) return numbers[i];
        }
        return 0;
    }
};

class Solution2 {
public:
    int partition(vector<int> &num,int start,int end){
        
        int k=num[start];
        int i=start,j=end;
        while(j>i){
            while(j>i && num[j]>k)j--;
            num[i]=num[j];
            while(i<j && num[i]<=k)i++;
            num[j]=num[i];
        }
        num[i]=k;
        return i;
    }
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size()==0) return 0;
        int len=numbers.size();
        int start=0,end=numbers.size()-1,mid=len>>1;
        int index=partition(numbers,start,end);
        while(index!=mid){
            if(index>mid){
                end=index-1;
                index=partition(numbers,start,end);
            }else{
                start=index+1;
                index=partition(numbers,start,end);
            }
        }
        int ans=numbers[mid],times=0;
        for(int i=0;i<len;i++){
            if(numbers[i]==ans) times++;
        }
        if(times*2<=len) ans=0;
        return ans;
    }

};

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len=numbers.size();
        if(len==0)return 0;

        int res=numbers[0],time=1;
        for(int i=1;i<len;i++){
            if(time==0){
                res=numbers[i];
                time=1;
            }else if(numbers[i]==res){
                time++;
            }else
                time--;
            cout <<i<<" "<<res << " " <<time <<endl;
        }
        int t=0;        
        for(int i=0;i<len;i++){
            if(numbers[i]==res)t++;
        }
        if(t*2<=len){
            res=0;
        }
        return res;
    }
};
int main(){
    vector<int> v={1,2,3,2,2,2,5,2,2};
    Solution s;
    cout << s.MoreThanHalfNum_Solution(v) <<endl;


    return 0;
}