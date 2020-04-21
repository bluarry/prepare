#include <bits/stdc++.h>

using namespace std;

//找出所有连续和为sum的数字
class Solution_1 {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > v;
        if(sum<3) return v;
        int low=1,high=2,mid=(sum+1)/2;
        int nsum=low+high;
        while(low<mid){ 
            if(nsum==sum){
                cout << low << " "<<high<<endl;
                vector<int> vt;
                for(int i=low;i<=high;i++){
                    vt.push_back(i);
                }
                v.push_back(vt);
            }
               
 
            while(nsum > sum && low<mid){
                nsum-=low;
                low++;
                if(nsum==sum){
                    cout <<low << " " <<high <<endl;
                    vector<int> vt;
                    for(int i=low;i<=high;i++){
                        vt.push_back(i);
                    }
                    v.push_back(vt);
                }
            }   
            high++;
            nsum+=high;
        } 
        return v;       
    }
};

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> v;
        if(array.size()<=1)return v;
        int low=0,high=array.size()-1;
        int nsum=array[low]+array[high];
        
        while(low<high){
            if(nsum>sum){
                nsum-=array[high];
                high--;
                nsum+=array[high];
            }else if(nsum<sum){
                nsum-=array[low];
                low++;
                nsum+=array[low];
            }else{
                v.push_back(array[low]);
                v.push_back(array[high]);
                break;
            }
        }
        return v;
    }
};
int main(){
    Solution s;
    vector<int> v={1,2,3,4,5,6};
    vector<int> ans=s.FindNumbersWithSum(v,9);
    cout << ans[0] <<" "<< ans[1]<<endl;


    return 0;
}