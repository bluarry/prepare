#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        int x[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string xs[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int ans=0,len=s.length();
        for(int i=0;i<len;){
            for(int j=0;j<13;j++){
                switch (xs[j].length())
                {
                    case 1:
                        if(s[i]==xs[j][0]){
                            ans+=x[j];
                            i++;
                        }
                        break;
                    case 2:
                        if(i+1<len && s[i]==xs[j][0]&&s[i+1]==xs[j][1]){
                            ans+=x[j];
                            i+=2;
                        }
                        break;
                }
            }
        }


		return ans;
    }
};

int main(){
    Solution s;
    string x ;
    while(cin >> x)
        cout << s.romanToInt(x) <<endl;



    return 0;
}
