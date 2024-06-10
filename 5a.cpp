#include<iostream>
using namespace std;



int main(){
int n;
cin>>n;
while(n>0){
for(int i = 1; i<=n; i++){
    cout<<i<<' ';
}
cout<<endl;
n-=1;
}
}
