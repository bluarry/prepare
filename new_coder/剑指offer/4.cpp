#include<iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std; 

class Solution1 {
public:
	void replaceSpace(char *str,int length) {
		if(str==NULL||length<=0) return;
		
		int i=0,stlen=0,spnum=0;
		while(str[i]!='\0'){
			stlen++;
			if(str[i]==' ') spnum++;
			i++;
		}
		int filen=stlen+2*spnum;
		if(filen>=length){
			char *p=new char[filen];
			strcpy(p,str);	
		}
		
		int p=filen,q=stlen;
		
		while(spnum--){
			while(1)
			{
				if(str[q]==' ')
				{
					q--;
					break;	
				}	
				str[p]=str[q];
				p--;
				q--;
			}
			str[p--]='0';
			str[p--]='2';
			str[p--]='%';
		}
		
	}
};


class Solution {
public:
	void replaceSpace(char *str,int length) {
		if(str==NULL||length<=0) return;
		
		int i=0,stlen=0,spnum=0;
		while(str[i]!='\0'){
			if(str[i]==' ') spnum++;
			i++;
		}
		string ss(str);
		while(spnum--){
			ss.replace(ss.find(' '),1,"%20");
		}
		const char* p=ss.data();
		strcpy(str,p);
	}
};



#define TA "hello world"

int main(){
	char str[13]=TA;
	Solution s;
	s.replaceSpace(str,13);
	
	cout << str<<endl;
	/*
	string ss(TA);
	ss.replace(ss.find(' '),1,"20%");
	cout <<ss <<endl;
	*/
	
	
	return 0;
}
