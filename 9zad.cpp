#include<iostream>
using namespace std;

int m[10000];

bool prime(int x){
    if(x==1 || x==0){return false;}
    if(x==2){return true;}
    for(int i = 2; i<x; i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}

bool check(int n){
    if(n%5==0){
        int sum = 0;
        while(n!=0){
            sum += n%10;
            n/=10;
        }
        if(prime(sum)){
            return true;
        }
    }
    return false;
}

int main(){
int x;
int smh;
for(int i = 0; x!=0 ;){
    cin>>x;
    if(check(x)){
        m[i] = x;
        i++;
    }
}
if(m[0]==0){
    cout<<"NO";
    return 0;
}

for(int i = 0; ;i++){
    cout<<m[i]<<' ';
    if(m[i+1]==0){break;}
}
    return 0;
}

