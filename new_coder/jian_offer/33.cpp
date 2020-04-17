#include <bits/stdc++.h>

using namespace std;

class Solution1 { //递归层数过多,栈溢出
public:
    void all(vector<int> nums,vector<vector<int> > &v,int index){
        if((int)nums.size()==0){
            return;
        }
        if(index==(int)nums.size()-1){
            v.push_back(nums);
        }else{
            for(int i=index;i<(int)nums.size();i++){
                swap(nums[index],nums[i]);
                all(nums,v,index+1);
                swap(nums[index],nums[i]);
            }
        }
    }

    string PrintMinNumber(vector<int> numbers) {
        vector<vector<int> > v;
        all(numbers,v,0);
        vector<string> ans;
        for(vector<int> x:v){
            string str;
            for(int xx:x){
                str.append(to_string(xx));
            }
            //cout <<str<<endl;
            ans.push_back(str);
        }
        sort(ans.begin(),ans.end());
        return ans[0];        
    }
};

class Solution {
public:
    static bool cmp(int a,int b){
        return (to_string(a)+to_string(b))<(to_string(b)+to_string(a));
    }
    string PrintMinNumber(vector<int> numbers) {
        if(numbers.size()==0)return "";
        sort(numbers.begin(),numbers.end(),cmp);
        string str;

        for(int x : numbers){
            str+=(to_string(x));
        }
        return str;
    }
};


int main(){
    vector<int> v={1,2,3};
    Solution s;
    cout << s.PrintMinNumber(v)<<endl;

    return 0;
}