#include <iostream>
using namespace std;
struct PolyNode{
    double coef;
    int exp;
    PolyNode *next;
};

int main(){


    //输入第一个多项式,依次输入系数和次数,且输入完成后输入“0 0”终止多项式的存储
    //例如“2x^3+4x+2”输入为“2 3 4 1 2 0 0 0”
double c1;
int e1;
PolyNode *head1,*rear1;
head1=rear1=new PolyNode;
while(true){
    cin>>c1>>e1;
    if (c1==0) break;
    rear1->next=new PolyNode;
    rear1=rear1->next;
    rear1->coef=c1;
    rear1->exp=e1;
}
rear1->next=nullptr;

     //输入第二个多项式,依次输入系数和次数,且输入完成后输入“0 0”终止多项式的存储
    //例如“2x^3+4x+2”输入为“2 3 4 1 2 0 0 0”
double c2;
int e2;
PolyNode *head2,*rear2;
head2=rear2=new PolyNode;
while(true){
    cin>>c2>>e2;
    if (c2==0) break;
    rear2->next=new PolyNode;
    rear2=rear2->next;
    rear2->coef=c2;
    rear2->exp=e2;
}
rear2->next=nullptr;

PolyNode *head,*rear,*q1,*q2;
head=rear=new PolyNode;
q1=head1->next;
q2=head2->next;
while(q1!=nullptr||q2!=nullptr){
    if (q1==nullptr||q2!=nullptr&&q2->exp>q1->exp) {
        rear->next=new PolyNode;
        rear=rear->next;
        rear->coef=q2->coef;
        rear->exp=q2->exp;
        q2=q2->next;
        continue;
    }
    if (q2==nullptr||q1!=nullptr&&q1->exp>q2->exp) {
        rear->next=new PolyNode;
        rear=rear->next;
        rear->coef=q1->coef;
        rear->exp=q1->exp;
        q1=q1->next;
        continue;
    }
    rear->next=new PolyNode;
    rear=rear->next;
    rear->coef=q2->coef+q1->coef;
    rear->exp=q2->exp;
    q2=q2->next;
    q1=q1->next;
    
}
rear->next=nullptr;

PolyNode *q=head->next;
while(q!=nullptr){
    cout<<q->coef<<"x^"<<q->exp;
    q=q->next;
    if(q!=nullptr) cout<<'+';
}

return 0;
}




#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

int compare_abs(char a[], char b[]) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    
    // 处理符号
    if (a[0] == '-') len_a--;
    if (b[0] == '-') len_b--;
    
    // 比较长度
    if (len_a > len_b) return 1;
    if (len_a < len_b) return -1;
    
    // 长度相等时比较每一位
    int start_a = (a[0] == '-') ? 1 : 0;
    int start_b = (b[0] == '-') ? 1 : 0;
    
    for (int i = 0; i < len_a; i++) {
        if (a[start_a + i] > b[start_b + i]) return 1;
        if (a[start_a + i] < b[start_b + i]) return -1;
    }
    
    return 0; // 相等
}


//a-b,a的绝对值大于b的绝对值
void subtract_positive(char a[], char b[], char result[], int& len_result) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int tmp = 0;
    len_result = 0;
    
    int i = len_a - 1, j = len_b - 1;
    while (j >= 0) {
        int diff = (a[i] - '0') - (b[j] - '0') - tmp;
        if (diff < 0) {
            diff += 10;
            tmp = 1;
        } else {
            tmp = 0;
        }
        result[len_result++] = diff + '0';
        i--; j--;
    }
    
    while (i >= 0) {
        int diff = (a[i] - '0') - tmp;
        if (diff < 0) {
            diff += 10;
            tmp = 1;
        } else {
            tmp = 0;
        }
        result[len_result++] = diff + '0';
        i--;
    }
}


int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    char a[1000],b[1000];
    cout<<"请输入第一个大整数：";
    cin>>a;
    cout<<"请输入第二个大整数：";
    cin>>b;
    int len_a=strlen(a);
    int len_b=strlen(b);
    char result[1001];
    int len_result=0;
    int tmp=0;


    if(a[0]!='-'&&b[0]!='-'){
        while(len_a>0&&len_b>0){
             result[len_result]=(a[len_a-1]-'0'+b[len_b-1]-'0'+tmp)%10+'0';
             tmp=(a[len_a-1]-'0'+b[len_b-1]-'0'+tmp)/10;
             len_result++;
             len_a--;
             len_b--;   
        }
        if(len_a==0){
            while(len_b>0){
                result[len_result]=(b[len_b-1]-'0'+tmp)%10+'0';
                tmp=(b[len_b-1]-'0'+tmp)/10;
                len_result++;
                len_b--;
            }
        }else while(len_a>0){
                result[len_result]=(a[len_a-1]-'0'+tmp)%10+'0';
                tmp=(a[len_b-1]-'0'+tmp)/10;
                len_result++;
                len_a--;
            }
        if(tmp>0){
            result[len_result]=tmp+'0';
            len_result++;
        }
        for(int i=len_result-1;i>=0;i--){
            cout<<result[i];
        }    

     }
    

    if(a[0]=='-'&&b[0]=='-'){
        while(len_a>1&&len_b>1){
             result[len_result]=(a[len_a-1]-'0'+b[len_b-1]-'0'+tmp)%10+'0';
             tmp=(a[len_a-1]-'0'+b[len_b-1]-'0'+tmp)/10;
             len_result++;
             len_a--;
             len_b--;   
        }
        if(len_a==1){
            while(len_b>1){
                result[len_result]=(b[len_b-1]-'0'+tmp)%10+'0';
                tmp=(b[len_b-1]-'0'+tmp)/10;
                len_result++;
                len_b--;
            }
        }else while(len_a>1){
                result[len_result]=(a[len_a-1]-'0'+tmp)%10+'0';
                tmp=(a[len_b-1]-'0'+tmp)/10;
                len_result++;
                len_a--;
            }
        if(tmp>0){
            result[len_result]=tmp+'0';
            len_result++;
        }

        result[len_result]='-';
        len_result++;

        for(int i=len_result-1;i>=0;i--){
            cout<<result[i];
        }    

     }
    


    if(a[0]=='-'&&b[0]!='-'){
        int cmp=compare_abs(&a[1],b);
        if(cmp>0){
         subtract_positive(&a[1],b,result,len_result);
         result[len_result]='-';
         for(int i=len_result;i>=0;i--){
            cout<<result[i];
         }
        }
        else if (cmp<0){
            subtract_positive(b,&a[1],result,len_result);
            for(int i=len_result-1;i>=0;i--){
            cout<<result[i];
        } 
    }else cout<<0;
    } 
    


    if(b[0]=='-'&&a[0]!='-'){
        int cmp=compare_abs(&b[1],a);
        if(cmp>0){
         subtract_positive(&b[1],a,result,len_result);
         result[len_result]='-';
         for(int i=len_result;i>=0;i--){
            cout<<result[i];
         }
        }
        else if (cmp<0){
            subtract_positive(a,&b[1],result,len_result);
            for(int i=len_result-1;i>=0;i--){
            cout<<result[i];
        } 
    }else cout<<0;
    } 
    
     


    return 0;
}