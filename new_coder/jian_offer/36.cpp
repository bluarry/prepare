#include <bits/stdc++.h>

using namespace std;
class Solution_sort {
public:
    void merge(vector<int> &v,vector<int> &t,int start,int mid,int end){
        int i=start,j=mid+1,k=start;
        while(i!=mid+1 && j!=end+1){
            if(v[i]>v[j]) t[k++]=v[j++];
            else  t[k++]=v[i++];
        }
        while(i!=mid+1) t[k++]=v[i++];
        while(j!=end+1) t[k++]=v[j++];
        // for(i=start;i<=end;i++){
        //     v[i]=t[i];
        // }
    }
    void mergesort(vector<int> &v,vector<int> &t,int start,int end){
        if(start>=end) return ;
        int mid=start+(end-start)/2;
        mergesort(t,v,start,mid);
        mergesort(t,v,mid+1,end);
        merge(t,v,start,mid,end);
    }
    void sort(vector<int> &v){
        vector<int> tmpv=v;
        mergesort(v,tmpv,0,v.size()-1);
    }

};
class Solution {
public:
    const int MOD=1000000007;
    int helper(vector<int> &v,vector<int> &t,int start,int end){
        if(start>=end) return 0;
        int mid=start+(end-start)/2;
        int l=helper(t,v,start,mid);
        int r=helper(t,v,mid+1,end);

        int i=mid,j=end,index=end,cnt=0;

        while(i>=start && j>mid){
            if(t[i]>t[j]){
                v[index--]=t[i--];
                cnt=(cnt+(j-mid))%MOD;
            }else{
                v[index--]=t[j--];
            }
        }
        while(i>=start) v[index--]=t[i--];
        while(j>mid) v[index--]=t[j--];
        return (l+r+cnt)%MOD;
    }
    int InversePairs(vector<int> data) {
        vector<int> tmpv=data;
        return helper(data,tmpv,0,data.size()-1);
    }
};

int main(){
    vector<int> v={1,2,3,4,5,7,6,0};
    //  Solution_sort ss;
    //  ss.sort(v);
    // for(auto x:v){
    //     cout << x <<endl;
    // }
    
    
    Solution s;
    cout << s.InversePairs(v)<<endl;
    
    
    
    return 0;
}