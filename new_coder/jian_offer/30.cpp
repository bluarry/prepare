#include <bits/stdc++.h>

using namespace std;
class Solution1 {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        sort(input.begin(),input.end());
        int len=input.size();
        vector<int> v;
        if(k>len||k<=0||len<=0) return v;
        for(int i=0;i<k;i++){
            v.push_back(input[i]);
        }
        return v;
    }
};
class Solution2 {
public:
    int partion(vector<int> &num,int start,int end){
        int k=num[start];
        int i=start,j=end;
        while(i<j){
            while(i<j && num[j]>k) j--;
            num[i]=num[j];
            while(i<j && num[i]<=k) i++;
            num[j]=num[i];
        }
        num[i]=k;
        return i;
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int len=input.size();
        vector<int> v;
        if(k>len||k<=0||len<=0) return v;
        int start=0,end=len-1;
        int index=partion(input,0,len-1);
        while(index!=k-1){
            if(index>k-1){
                end=index-1;
                index=partion(input,start,end);
            }else{
                start=index+1;
                index=partion(input,start,end);
            }
        }
        for(int i=0;i<k;i++)
            v.push_back(input[i]);
        return v;
    }
};
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int len=input.size();
        vector<int> v;
        if(k>len||k<=0||len<=0) return v;
        multiset<int,greater<int> > leastk;
        leastk.clear();
        for(int i=0;i<len;i++){
            if(leastk.size()<k){
                leastk.insert(input[i]);
            }else{
                multiset<int,greater<int> >::iterator it=leastk.begin();
                if(*it > input[i]){
                    leastk.erase(it);
                    leastk.insert(input[i]);
                }
            }
        }
        for(multiset<int,greater<int> >::iterator it=leastk.begin();it!=leastk.end();it++){
            v.push_back(*it);
        }
        return v;
    }
};
int main(){
    vector<int> v={4,5,1,6,2,7,3,8};
    Solution s;
    vector<int> ans=s.GetLeastNumbers_Solution(v,4);
    for(int x:ans){
        cout << x <<endl;
    }


    return 0;
}