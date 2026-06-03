#include <algorithm>
#include <iostream>
using namespace std;

struct Student{
    int id;
    int a;
    int b;
};

bool cmp(const Student &x,const Student &y){
    int sumx=x.a+x.b;
    int sumy=y.a+y.b;
    if(sumx!=sumy){
        return sumx>sumy;
    }else if(x.b!=y.b){
        return x.b>y.b;
    }else{
        return x.id<y.id;
    }
}
 
int main(){
    int n;
    cin>>n;
    Student *s=new Student[n];
    for(int i=0;i<n;i++){
        cin>>s[i].id>>s[i].a>>s[i].b;
    }
    sort(s,s+n,cmp);
    for(int i=0;i<n;i++){
        cout<<s[i].id<<" "<<s[i].a+s[i].b<<endl;
    }
    delete []s;
    return 0;
}
