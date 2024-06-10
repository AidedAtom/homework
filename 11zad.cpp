#include<iostream>
using namespace std;

int check(int a, int b, int c){
    if(a*a + b*b == c*c){
        return a+b+c;
    }else if(a*a + c*c == b*b){
        return a+b+c;
    }else if(b*b + c*c == a*a){
        return a+b+c;
    }else{
        return 0;
    }
}

int main(){
int a, b, c;
for(int i = 0; i<3; i++){
    cin>>a>>b>>c;
    if(check(a,b,c)==0){cout<<"NO ";}
    else{cout<<check(a,b,c)<<' ';}
}
    return 0;
}
