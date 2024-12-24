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
    for(int j = 0; j<m; j++){
        cout<<setw(3)<<A[i][j]<<' ';
    }
    cout<<endl;
}
for(int j = 0; j<m; j++){
    int x = A[0][j];
    bool y = false;
    for(int i = 1; i<n; i++){
        if(A[i][j]!=x){
            y = true;
            break;
        }
    }
    if(y == true){
        cout<<setw(3)<<"Yes"<<' ';
    }else{
        cout<<setw(3)<<"No"<<' ';
    }
}
return 0;
}
