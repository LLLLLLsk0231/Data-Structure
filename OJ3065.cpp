#include <iostream>
using namespace std;

int maxsize=0;

void push(int j,int *heap){
    maxsize++;
    heap[maxsize]=j;
    int p=maxsize;
    while(p!=1&&heap[p]<heap[p/2]){
      int tmp=heap[p];
      heap[p]=heap[p/2];
      heap[p/2]=tmp;
      p=p/2;
    }
}

void pop(int *heap){
    if (maxsize==0) return;
    cout<<heap[1]<<endl;
    heap[1]=heap[maxsize];
    maxsize--;
    int i=1;
    while(i*2<=maxsize){
      int child=2*i;
      if(child+1<=maxsize&&heap[child+1]<heap[child]){
               child++;
      }
      if(heap[child]<heap[i]){
         int tmp=heap[child];
         heap[child]=heap[i];
         heap[i]=tmp;
         i=child;
      }else break;
    }
}
 int main(){
    int n;
    cin>>n;
    int *heap=new int [n+1];
    for(int i=0;i<n;i++){
      int k,j;
      cin>>k;
      if (k==1) {
         cin>>j;
         push(j,heap);
      }else pop(heap);
    }
   delete[] heap;
    return 0;
 }