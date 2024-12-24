#include<iostream>
#include<iomanip>
using namespace std;

int A[20][20];

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
if(n==m){
int br = 0;
for(int i = 0; i<n; i++){
    if(A[i][i]<0 && A[i][i]%2==0){
        br++;
    }
}
cout<<br;
}else{
    cout<<"nqma glaven diagonal"<<endl;
}
    return 0;
}
