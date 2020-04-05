#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;
/*
2,1,3,5,6,4
2
*/


void adjustHeap(vector<int> &myheap, int k){
    int len = myheap.size();
    while(k <= len/2-1){
        if(myheap[k]>myheap[2*k+1] && ((2*(k+1)>=len)||myheap[k]>myheap[2*(k+1)]))
            break;
        if(myheap[k] < myheap[2*k+1] && (myheap[2*k+1] >= myheap[2*(k+1)])){
            swap(myheap[k], myheap[2*k+1]);
            k = 2*k+1; 
        }
        else{
            swap(myheap[k], myheap[2*(k+1)]);
            k = 2*(k+1);
        }
    }
}

void buildheap(vector<int> &myheap){
	if(myheap.size() <= 1) return;
    for(int i = myheap.size()/2-1; i >= 0; i--)
        adjustHeap(myheap, i);

}
int main(){
    vector<int> v;
    int c;
    char cc;
    while(scanf("%d%c",&c,&cc)){	
        v.push_back(c);
        if(cc=='\n') break;
    }
    cin >> c;
    buildheap(v);  
	
	for(int j=0;j<c-1;j++){
		v[0]=v[v.size()-1];
		buildheap(v);
	}
	
	
    
    cout << v[0]<<endl;

    return 0;
}
