#include <iostream>
#include <string>

using namespace std;

struct HTNode{
    char ch;
    int weight;
    int right=-1;
    int left=-1;
    int parent=-1;
};


void Select(HTNode *HT,int n,int &s1,int &s2){
    int min1=999999;
    int min2=999999;
    s1=s2=-1;
    for(int i=0;i<n;i++){
        if(HT[i].parent==-1){
            if (HT[i].weight<min1) {
                min2=min1;
                s2=s1;
                min1=HT[i].weight;
                s1=i;
            }else if(HT[i].weight<min2){
                min2=HT[i].weight;
                s2=i;
            }
        }
    }
}

void CreatHT(HTNode *HT,int n,int m){

    for(int i=n;i<m;i++){
        int s1,s2;
        Select(HT,i,s1,s2);
        HT[i].left=s1;
        HT[i].right=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
        HT[s1].parent=i;
        HT[s2].parent=i;
    }
}

void HFcoding(HTNode *HT,string *HC,int n){
    for(int i=0;i<n;i++){
     string code="";
     int p=i;
     int parent=HT[p].parent;
     while(parent!=-1){
        if (HT[parent].left==p){
            code='0'+code;
        }else {
            code='1'+code;
        }
        p=parent;
        parent=HT[p].parent;
     }
    HC[i]=code;
    }
}

void Encode(string *HC,string input,string &code,int n,string letters){
    code="";
    for(int i=0;i<input.length();i++){
            for(int j=0;j<n;j++){
                if(input[i]==letters[j]){
                    code=code+HC[j];
                    break;
                }
            }
    }
}

void Decode(HTNode *HT,string code,string &words,int m){
     int p=m-1;
     for (int i=0;i<code.length();i++) {
            if (code[i]=='1') {
                p=HT[p].right;
            }else {
                p=HT[p].left;
            }
            if(HT[p].left==-1 && HT[p].right==-1){
                words=words+HT[p].ch;
                p=m-1;
            }
     }

}

int main(){
    int n=27;
    int m=2*n-1;
    char letters[]="abcdefghijklmnopqrstuvwxyz ";
    int freq[]={8, 2, 3, 4, 13, 2, 2, 6, 7, 1, 1, 4, 2, 7, 8, 2, 1, 6, 6, 9, 3, 1, 2, 1, 2, 1,23};
    HTNode *HT=new HTNode [m];
    string *HC=new string [n];

    for(int i=0;i<n;i++){
        HT[i].weight=freq[i];
        HT[i].ch=letters[i];
    }

    CreatHT(HT,n,m);
    HFcoding(HT,HC,n);

    cout<<"HF code table:"<<endl;
    for(int i=0;i<n;i++){
        cout<<letters[i]<<':'<<HC[i]<<endl;
    }

    cout<<"Enter your words to encode:";
    string input;
    getline(cin,input);

    for(int i=0;i<input.length();i++){
        if (input[i]>='A'&&input[i]<='Z') input[i]=input[i]+32;
    }
    string code;
    string words;
    Encode(HC,input,code,n,letters);
    cout<<"codes are:"<<code<<endl;
    Decode(HT,code,words,m);
    cout<<"Words are:"<<words;

    delete []HT;
    delete []HC;




    return 0;
}