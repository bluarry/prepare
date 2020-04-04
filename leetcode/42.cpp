#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        
    }
};

class Solution1 { //未知区域越界。。。
public:

    int trap(vector<int>& height) {
        int res=0,i=0,j=0,k=0;
        for(i=0;i<height.size();i++){
            for(j=i+1;height[j]< height[i] && j<height.size();j++);
            j--;
            if(j==height.size()-1) continue;
            else{
                for(k=i+1;k<=j;k++){
                    res+=(height[i]-height[k]);
                }
                i=j;
            }
        }
        return res;
    }
};
class Solution2 { //暴力法，时间超限了。。。。
public:
    int trap(vector<int>& height)
    {
        int ans = 0;
        int size = height.size();
        for (int i = 1; i < size - 1; i++) {
            int max_left = 0, max_right = 0;
            for (int j = i; j >= 0; j--) { //Search the left part for max bar size
                max_left = max(max_left, height[j]);
            }
            for (int j = i; j < size; j++) { //Search the right part for max bar size
                max_right = max(max_right, height[j]);
            }
            ans += min(max_left, max_right) - height[i];
        }
        return ans;
    }
};

class Solution3 {
public:
    int trap(vector<int>& height)
    {
        int ans = 0;
        int size = height.size();
        vector<int> left_max(size), right_max(size);
        left_max[0] = height[0];
        for (int i = 1; i < size; i++) {
            left_max[i] = max(height[i], left_max[i - 1]);
        }
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i + 1]);
        }
        for(int i=0;i<size;i++){
            cout << left_max[i] <<" ";
        }cout << endl;
          for(int i=0;i<size;i++){
            cout << right_max[i] <<" ";
        }cout << endl;
        for (int i = 1; i < size - 1; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
};

class Solution4 { //单调栈，栈里元素依次增大
public:
    int trap(vector<int>& height) {
        int ans=0,cur=0;
        stack<int> s;
        while(cur<height.size()){
            while(!s.empty() && height[cur]>height[s.top()]){
                int top=s.top();s.pop();
                if(s.empty()){
                    break;
                }
                int dis=cur-s.top()-1;
                int h=min(height[cur],height[s.top()])-height[top];
                ans+=dis*h;
            }
            s.push(cur++);
        }
        return ans;
    }
};

class Solution5 { //双指针方式扫描，非常巧妙
public:
    int trap(vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                ++left;
            }
            else {
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }
};


int main(){
   vector<int> v={0,1,0,2,1,0,1,3,2,1,2,1};
    // vector<int> v={1,3,2};
    Solution5 s;
    cout << s.trap(v) <<endl;




    return 0;
}
