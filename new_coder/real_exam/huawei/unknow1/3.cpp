#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;
int c=0;
   
bool IsSwap(char* pBegin, char* pEnd)
{  
    char* p;  
    for (p=pBegin; p<pEnd; p++)  
    {  
        if (*p == *pEnd)  
            return false;  
    }  
    return true;  
}  
  
void Permutation(char* pStr,char* pBegin)  
{  
    if (*pBegin == '\0')  
        c++;
        //cout << pStr <<endl;  
    else  
    {  
        for (char* pCh = pBegin; *pCh!='\0'; pCh++)  
        {  
            if( IsSwap(pBegin,pCh) )  
            {    
                swap(*pCh,*pBegin);
                Permutation(pStr, pBegin+1);    
                swap(*pCh,*pBegin);
            }  
        }  
    }  
}

int main(){
    string s;
    cin >> s; 
    char buf[s.size()+1];
    s.copy(buf,s.size());
    buf[s.size()]='\0';
    Permutation(buf,buf);
    cout << c <<endl;
    return 0;
}
