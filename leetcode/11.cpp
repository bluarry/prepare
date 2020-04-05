#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>


using namespace std;

class Solution1 {
public:
    int maxArea(vector<int>& height) {
        int maxarea=0;
         for (int i = 0; i < height.size(); i++)
            for (int j = i + 1; j < height.size(); j++)
                maxarea =max(maxarea, min(height[i], height[j]) * (j - i));
        return maxarea;
    }
};



class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea=0,l=0,r=height.size()-1;
        while(l<r){
            maxarea=max(maxarea,min(height[l],height[r])*(r-l));
            if(height[r]>height[l]){
                l++;
            }else{
                r--;
            }
        }
        return maxarea;
    }
};
int main(){

    Solution s;
    vector<int> v={1,8,6,2,5,4,8,3,7};
    cout << s.maxArea(v)<<endl;

    return 0;
}
