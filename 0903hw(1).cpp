#include<iostream>
using namespace std;



int main(){
int m, n;
char c;
cin>>m>>n>>c;
for(int i = 0; i<(m*n-(m-1)); i++){
    cout<<c;
}
cout<<endl;
for(int i = 0; i<n-1; i++){
    for(int j = 0; j<m; j++){
        cout<<c;
        for(int k = 0; k<n-2; k++){
            cout<<" ";
        }
    }
    cout<<c<<endl;
}
for(int i = 0; i<(m*n-(m-1)); i++){
    cout<<c;
}

    return 0;
}
