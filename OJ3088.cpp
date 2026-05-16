#include <iostream>

using namespace std;

int main(){
    int n,q;
    cin >> n >> q;
    int *a = new int[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    while(q--){
        int x,l,m,h;
        cin>> x;
        l=0;
        h=n-1;
        while(l<h){
            m=(l+h)/2;
            if(a[m]>=x){
                h=m;
            }else l=m+1;
        }
        if(a[l]>=x){
            cout << l+1 << endl;
        }else cout<<0<<endl;
    }
    delete[] a;
    return 0;
}