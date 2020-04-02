#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    ll n,sum=0,x=0;
    cin >>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> x;
            sum+=x;
        }
    }

    cout <<sum <<endl;

    return 0;
}