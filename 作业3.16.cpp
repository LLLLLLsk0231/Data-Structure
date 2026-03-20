#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

template <class elemType>
class seqStack
{
private:
    elemType *elem;
    int top_p;
    int maxSize;
    void doubleSpace();

public:
     seqStack(int initSize=10){
        elem=new elemType[initSize];
        maxSize=initSize;
        top_p=-1;
     }


     ~seqStack(){
        delete[] elem;
     }


     bool isEmpty() const{
        return top_p==-1;
     }


     void push(const elemType &x){
        if (top_p==maxSize-1) doubleSpace();
        elem[++top_p]=x; 
     }


     elemType pop(){
        return elem[top_p--]; 
     }


     elemType top() const{
        return elem[top_p];
     }

};

template<class elemType>
void seqStack<elemType>::doubleSpace(){
    elemType *tmp=elem;
    elem=new elemType[2*maxSize];
    
    for(int i=0;i<maxSize;i++){
        elem[i]=tmp[i];
    }
    maxSize*=2;
    delete[] tmp;
}



class calc{
    char *expression;

    enum token{OPAREN,ADD,SUB,MULTI,DIV,EXP,CPAREN,VALUE,EOL};

    void BinaryOp(token op,seqStack<int>&dataStack);

    token getOp(int &value);
    
public:
    calc(const char *s){
        expression=new char[strlen(s)+1];
        strcpy(expression,s);
    } 


    ~calc(){
        delete[] expression;
    }


    int result();
};


int calc::result(){
    token lastOp,topOp;
    int result_value,Current_Value;
    seqStack<token> opStack;
    seqStack<int>dataStack;
    char *str=expression;

    while((lastOp=getOp(Current_Value))!=EOL){
        switch (lastOp)
        {
            case VALUE:
            dataStack.push(Current_Value);
            break;

            case OPAREN:
            opStack.push(OPAREN);
            break;

            case CPAREN:
            while(!opStack.isEmpty()&&(topOp=opStack.pop())!=OPAREN){
                BinaryOp(topOp,dataStack);
            }
            if(topOp!=OPAREN){
              cerr<<"缺左括号！"<<endl;
            }
            break;

            case ADD:case SUB:
            while(!opStack.isEmpty()&&opStack.top()!=OPAREN){
                BinaryOp(opStack.pop(),dataStack);
            }
            opStack.push(lastOp);
            break;

            case MULTI:case DIV:
            while(!opStack.isEmpty()&&opStack.top()>=MULTI){
                BinaryOp(opStack.pop(),dataStack);   
            }
            opStack.push(lastOp);
            break;

            case EXP:
            opStack.push(EXP);
            break;
        }
    }

      while(!opStack.isEmpty()){
      BinaryOp(opStack.pop(),dataStack);
      }
   
//    if(dataStack.isEmpty()){
//     cout<<"无结果\n";
//     return 0;
//    }
 
      result_value=dataStack.pop();
      if(!dataStack.isEmpty()){
        cout<<"缺操作符";
        return 0;
      }
      expression=str;
      return result_value;


     

}


calc::token calc::getOp(int &value){
    while(*expression&&*expression==' '){
        expression++;
    }

    if(*expression=='\0'){return EOL;}

    if(*expression>='0'&&*expression<='9'){
        value=0;
        while(*expression>='0'&&*expression<='9'){
            value=value*10+(*expression-'0');
            expression++;
        }
        return VALUE;
    }

    switch (*expression)
    {
     case '(':++expression;
              return OPAREN;
     case ')':++expression;
              return CPAREN;
     case '+':++expression;
              return ADD;
     case '-':++expression;
              return SUB;
     case '*':++expression;
              return MULTI;
     case '/':++expression;
              return DIV;
     case '^':++expression;
              return EXP;         
    }
}


void calc::BinaryOp(token op,seqStack<int>&dataStack){
    int num1,num2;
    if(dataStack.isEmpty()){
        cerr<<"缺少右运算数！";
        exit(1);
    }else num2=dataStack.pop();

    if(dataStack.isEmpty()){
        cerr<<"缺少左运算数！";
        exit(1);
    }else num1=dataStack.pop();

    switch (op)
    {
        case ADD:
        dataStack.push(num1+num2);
        break;
        case SUB:
        dataStack.push(num1-num2);
        break;
        case MULTI:
        dataStack.push(num1*num2);
        break;
        case DIV:
        dataStack.push(num1/num2);
        break;
        case EXP:
        // int result=1;
        // for(int i=0;i<num2;i++){
        //     result*=num1;
        // }
        // dataStack.push(result);
        dataStack.push(round(pow(num1,num2)));
        break;
    }
    
}


int main(){
    char a[100];
    cin>>a;
    calc exp(a);
    cout<<exp.result();

    return 0;
}