#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int GetNumberOfK1(vector<int> data ,int k) {
        int ans=0;
        for(auto x:data){
            if(x==k){
                ans++;
            }
        }
        return ans;
    }
    int firstk(vector<int> &data,int k ,int start,int end){
        if(start>end){
            return -1;
        }
       
        int mid=start+(end-start)/2;
        if(data[mid]==k){
            if((mid>0 && data[mid-1]!=k)||mid==0){
                return mid;
            }else{
                end=mid-1;
            }
        }else if(data[mid]>k){
            end=mid-1;
        }else
            start=mid+1;
        return firstk(data,k,start,end);
    }
    int lastk(vector<int> &data,int k ,int start,int end){
        if(start>end){
            return -1;
        }
        int mid=start+(end-start)/2;
        if(data[mid]==k){
            if((mid<data.size() && data[mid+1]!=k)||mid==data.size()-1){
                return mid;
            }else{
                start=mid+1;
            }
        }else if(data[mid]>k){
            end=mid-1;
        }else
            start=mid+1;

        return lastk(data,k,start,end);
    }
    int GetNumberOfK(vector<int> data ,int k) {
        int fk=firstk(data,k,0,data.size()-1);
        // cout <<fk <<endl;
        int lk=lastk(data,k,0,data.size()-1);
        // cout <<lk<<endl;

        return lk==fk&&lk==-1?0:lk-fk+1;
    }
};
int main(){
    Solution s;
    vector<int> v={1,2,3,3,3,3,3,45,5};
    cout <<s.GetNumberOfK(v,9)<<endl;


    return 0;
}