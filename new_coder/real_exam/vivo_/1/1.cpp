#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;


namespace blu{

    int dir[16][2]={
            {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},
            {-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}
    };
    int visited[4][4]; //3*3多2防止越界
    int res[10];
    int can(int i,int j){
        if(i<1||i>3||j<1||j>3||visited[i][j]) return 0;
        return 1;
    }
    void dfs(int i,int j,int d){
        if(d>9){
            return ;
        }
        visited[i][j]=true;
        res[d++]++;
        for(int k=0;k<16;k++){
            int ni=i+dir[k][0];
            int nj=j+dir[k][1];
            if(can(ni,nj)){
                dfs(ni,nj,d);
            }else if(k<8){ //题目中的跨一个点搜索
                ni+=dir[k][0];
                nj+=dir[k][1];
                if(can(ni,nj)){
                    dfs(ni,nj,d);
                }
            }
        }
        visited[i][j]=false;
        return ;
    }

}

class Solution {
public:
    /**
     * 实现方案
     * @param m int整型 最少m个键
     * @param n int整型 最多n个键
     * @return int整型
     */
    Solution(){
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                blu::dfs(i,j,1);
            }
        }
        // for(int i=0;i<=9;i++){
        // 	cout << blu::res[i]<<endl;
		// }
    }


    int solution(int m, int n) {
        // write code here
        if(m>n){
            return 0;
        }

        m=m<0?0:m;
        n=n>9?9:n;
        int res=0;
        for(int i=m;i<=n;i++){
            res+=blu::res[i];
        }
        return res;
    }
};

int main(){
    Solution s;

    cout << s.solution(1,9)<<endl;
    



    return 0;
}
