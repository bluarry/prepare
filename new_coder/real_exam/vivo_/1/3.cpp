#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

class Solution {
public:
    map<int,int> m;
    map<int,int> mm;
    Solution(){
        m[0]=0;
        mm[0]=0;
        int v=0,p=0;
        for(int i=1;v+i<200000;i++){
            p=v;
			if(v+i>INT_MAX) {
				return;
			}
			v=v+i;
			mm[i]=mm[i-1]+i;
            m[v]=i;
            for(int j=p+1;j<v;j++){
            	m[j]=i;
			}
        }
    }

    /**
     * 
     * @param n int整型 第n天
     * @return int整型
     */
    int solution(int n) {
    
    	
        int c=m[n];
        int ans=0;
        for(int i =1;i<c;i++){
            ans+=i*i;
        }
        int cc=mm[c-1];
        ans+= c*(n-cc);
        
        return ans;
    }
};

int main(){
    Solution s;

    cout <<s.solution(20) <<endl;



    return 0;
}
