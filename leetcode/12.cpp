#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>


using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string res;
        while(num>0)
        {
            if(num-1000>=0)
            {
                num-=1000;
                res+="M";
                continue;
            }
            
            if(num-900>=0)
            {
                num-=900;
                res+="CM";
                continue;
            }

            if(num-500>=0)
            {
                num-=500;
                res+="D";
                continue;
            }
            if(num-400>=0)
            {
                num-=400;
                res+="CD";
                continue;
            }
            if(num-100>=0)
            {
                num-=100;
                res+="C";
                continue;
            }
            if(num-90>=0)
            {
                num-=90;
                res+="XC";
                continue;
            }
            if(num-50>=0)
            {
                num-=50;
                res+="L";
                continue;
            }
            if(num-40>=0)
            {
                num-=40;
                res+="XL";
                continue;
            }
            
            if(num-10>=0)
            {
                num-=10;
                res+="X";
                continue;
            }
            if(num-9>=0)
            {
                num-=9;
                res+="IX";
                continue;
            }
            if(num-5>=0)
            {
                num-=5;
                res+="V";
                continue;
            }
            if(num-4>=0)
            {
                num-=4;
                res+="IV";
                continue;
            }
            if(num-1>=0)
            {
                num-=1;
                res+="I";
                continue;
            }

        }
    return res;   
    }
};




class Solution1 {
public:
    map<int,string> m;
    Solution1(){
        m={
            {1,"I"},
            {4,"IV"},
            {5,"V"},
            {9,"IX"},
            {10,"X"},
            {40,"XL"},
            {50,"L"},
            {90,"XC"},
            {100,"C"},
            {400,"CD"},
            {500,"D"},
            {900,"CM"},
            {1000,"M"}
        };
    }
    string intToRoman(int num) {
        if(num<=0) return "";
        string res;
        map<int,string>::iterator it=m.upper_bound(num);        
        if(it!=m.begin()){
            it--;
        }
        //cout << it->first<<endl;
        res+=it->second;
        return res+=intToRoman(num-(it->first));
    }
};

int main(){

    Solution s;
    int x;
    while(cin >> x)
        cout << s.intToRoman(x)<<endl;
    return 0;
}
