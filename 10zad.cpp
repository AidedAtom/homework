#include<iostream>
using namespace std;

bool check(int a, int b){
    if(a/1000*10 + b/1000 == a%10*10+b%10){
        return true;
    }
    return false;
}

int main(){
int a;
int b;
do{
    cin>>a>>b;
    if(check(a, b)){
        cout<<"true ";
    }else{
        cout<<"false ";
    }
}while(a!=0 && b != 0);


    return 0;
}
