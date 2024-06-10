#include<iostream>
#include<cmath>
using namespace std;
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
int main(){
int cnt = 0;
int x;
do{
    cin>>x;
    if(prime(x)==true){
        cnt++;
    }
}while(x!=0);

cout<<cnt;
    return 0;
}
