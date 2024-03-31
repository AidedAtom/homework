#include<iostream>
using namespace std;

int n;
int m[51];
double x;
double average;
double minn;

int main(){
cin>>n;
for(int i = 0; i<n; i++){
    cin>>m[i];
    average += m[i];
}
average /= n;
x = m[0];
minn = x - average;
for(int i = 1; i<n; i++){
    if(m[i]-average<minn){
        x = m[i];
    }
    minn = x - average;
}
cout<<minn;
    return 0;
}
