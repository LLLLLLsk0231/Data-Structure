#include <iostream>
using namespace std;


int findkth(int *a,int n,int *b,int m,int k){
    int i=0,j=0;
    while(true){
        if (i>=n) return b[j+k-1];
        if (j>=m) return a[i+k-1];
        if(k==1) {
            if(a[i]<b[j]) {
                return a[i];
            } else return b[j];
        }
        int half=k/2;
        int ni=i+half-1;
        int nj=j+half-1;

        if(ni>=n) ni=n-1;
        if(nj>=m) nj=m-1;

        if(a[ni]<b[nj]) {
            k-=(ni-i+1);
            i=ni+1;
        } else {
            k-=(nj-j+1);
            j=nj+1;
        }
    }
}
int main(){
   int n,m,q;
   cin>>n>>m>>q;
    int *a = new int[n];
    int *b = new int[m];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    while(q--){
        int x;
        cin>>x;
        cout<<findkth(a,n,b,m,x)<<endl;
    }
    delete[] a;
    delete[] b;
    return 0;
}