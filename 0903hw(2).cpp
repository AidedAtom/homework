#include<iostream>
using namespace std;


int main(){
int a, b;
char c;
cin>>a>>c>>b;
switch(c){
    case '+':cout<<a+b<<endl; break;
    case '-':cout<<a-b<<endl; break;
    case '*':cout<<a*b<<endl; break;
    default:cout<<"nah bro its only '-', '+' and '*'"<<endl;
}
    return 0;
}
