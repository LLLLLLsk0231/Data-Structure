#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int *a=new int[n];
    int *b=new int[n];
    int k=0;
    for(int i=0;i<n;i++){
        bool flag=false;
        cin>>a[i];
        for(int j=0;j<i;j++){
            if(a[j]==a[i]){
                flag=true;
                break;
            }
        }
        if(!flag){
            b[k]=a[i];
            k++; 
        }
    }
    for(int i=k-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(b[j]>b[j+1]){
                int temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            if(a[i]==b[j]){
                cout<<j+1<<" ";
                break;
            }
        }
    }
    delete[] a;
    delete[] b;

    return 0;
}