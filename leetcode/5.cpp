/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Solutionx {
    /*
    暴力法： 时间超限
    kyyrjtdplseovzwjkykrjwhxquwxsfsorjiumvxjhjmgeueafubtonhlerrgsgohfosqssmizcuqryqomsipovhhodpfyudtusjhonlqabhxfahfcjqxyckycstcqwxvicwkjeuboerkmjshfgiglceycmycadpnvoeaurqatesivajoqdilynbcihnidbizwkuaoegmytopzdmvvoewvhebqzskseeubnretjgnmyjwwgcooytfojeuzcuyhsznbcaiqpwcyusyyywqmmvqzvvceylnuwcbxybhqpvjumzomnabrjgcfaabqmiotlfojnyuolostmtacbwmwlqdfkbfikusuqtupdwdrjwqmuudbcvtpieiwteqbeyfyqejglmxofdjksqmzeugwvuniaxdrunyunnqpbnfbgqemvamaxuhjbyzqmhalrprhnindrkbopwbwsjeqrmyqipnqvjqzpjalqyfvaavyhytetllzupxjwozdfpmjhjlrnitnjgapzrakcqahaqetwllaaiadalmxgvpawqpgecojxfvcgxsbrldktufdrogkogbltcezflyctklpqrjymqzyzmtlssnavzcquytcskcnjzzrytsvawkavzboncxlhqfiofuohehaygxidxsofhmhzygklliovnwqbwwiiyarxtoihvjkdrzqsnmhdtdlpckuayhtfyirnhkrhbrwkdymjrjklonyggqnxhfvtkqxoicakzsxmgczpwhpkzcntkcwhkdkxvfnjbvjjoumczjyvdgkfukfuldolqnauvoyhoheoqvpwoisniv

    */
public:
    bool ish(string s){
        int len=s.length();
        for(int i=0,j=len-1;i<=j;i++,j--){
            if(s[i]!=s[j]){
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                string t=s.substr(i,j-i+1);
                if(ish(t) && t.length()>ans.length()){
                    ans=t;
                }
            }
        }
        return ans;
    }
};
class Solution {
    /*
        动态规划法:
        f(i,j)表示s[i]....s[j]是回文的
        f(i,j)=true/false
        f(i,j)= f(i+1,j-1) && s[i]==s[j]
    */

public:
    string longestPalindrome(string s) {
        int len=s.length();
        int dp[len][len];
        if(len==0){
            return "";
        }
        memset(dp,0,sizeof(dp));
        string ans;
        //初始化
        for(int i=0;i<len;i++){
            dp[i][i]=1;
        }
        for(int i=0;i<len-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
            }
        }

        for(int k=3;k<=len;k++)
            for(int i=0;i<len-k+1;i++)
            {
                if(dp[i+1][i+k-2] && s[i]==s[i+k-1]){
                    dp[i][i+k-1]=1;
                }
            }
        int flag=0;
        for(int k=len;k>0 && flag==0;k--)
            for(int i=0;i<len-k+1;i++){
                if(dp[i][i+k-1]){
                    ans=s.substr(i,k);
                    flag=1;
                    break;
                }
            }
        return ans;
    }
};

int main(){ 
    Solution s;
    string a;
    while(cin >> a){
        cout << s.longestPalindrome(a) <<endl;
    }

    return 0;
}