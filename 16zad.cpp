#include<iostream>
#include<iomanip>
using namespace std;

int A[20][10];

int main(){
int n, m;
cin>>n>>m;
for(int i = 0; i<n; i++){
    for(int j = 0; j<m; j++){
        cin>>A[i][j];
    }
}
for(int i = 0; i<n; i++){
    cout<<setw(3)<<A[i][0]<<' ';
    int br = 0;
    if(A[i][0]==A[i][1]){
        br++;
    }
    for(int j = 1; j<m; j++){
        cout<<setw(3)<<A[i][j]<<' ';
        if(A[i][j] != A[i][j-1] && A[i][j]==A[i][j+1]){
            br++;
        }
    }
    cout<<br;
    cout<<endl;
}


return 0;
}
