#include<iostream>
using namespace std;

int n;
int m[51];
int cnt;

int main(){
cin>>n;
for(int i = 0; i<n; i++){
    cin>>m[i];
    while(m[i]!=0){
        m[i]/=10;
        cnt++;
    }
}
cout<<cnt;
    return 0;
}

