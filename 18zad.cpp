#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int A[20][20];
bool isprosto(int n){
    if(n<2){return false;}
    for(int i = 2; i<=sqrt(n); i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
int n, m;
cin>>n>>m;
for(int i = 0; i<n; i++){
    for(int j = 0; j<m; j++){
        cin>>A[i][j];
    }
}
for(int i = 0; i<n; i++){
    for(int j = 0; j<m; j++){
        cout<<setw(3)<<A[i][j]<<' ';
    }
    cout<<endl;
}
int br = 0;
for(int i = 0; i<n; i++){
    if(isprosto(A[i][n-i-1])==true){
        br++;
    }
}
cout<<br;
    return 0;
}
