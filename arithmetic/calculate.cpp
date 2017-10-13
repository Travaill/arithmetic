#include "calculate.h"
#include "generate.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>
using namespace std;
stack<double> num_stk;
stack<char> ope_stk;
void Calculate::calculatePolynomial()      //计算多项式结果 
{
	 int x=num.top();
	num.pop();  
    int y=num.top();
	num.pop(); 
    int res=0;  
    char op=ope.top();
    ope.pop();
    if(op=='+')    
    {    
        res=x+y;  
    }    
    else if(op=='-')    
    {    
        res=y-x;   
    }    
    else if(op=='/')    
    {    
        res=y/x;  
    }   
    else if(op=='*')    
    {    
        res=y*x;  
    }    
    num.push(res);  
}

int Calculate::Rank(char x)                //计算优先级 
{
	if(x=='('||x==')') return 0;    
    else if(x=='+'||x=='-') return 1;    
    else if(x=='*'||x=='/') return 2;  
}
int Calculate::change(char *s,int &i){  
    int n = s[i]-'0';  
    i++;  
    while(s[i] >= '0'&& s[i] <= '9'){  
        n = n*10 + s[i] - '0';  
        i++;  
    }  
    return n;  
}   
double Calculate::calculateResult(char* exp)     //计算算式 
{
	ope.push('\0');
	int i;
	int flag = 1;  
	 while(flag){  
        if(exp[i] >= '0'&& exp[i] <= '9'){  
            num.push(change(exp,i));  
        }  
        else if(exp[i] == '\0' && ope.top() == '\0') flag = 0;  
        else if(exp[i] == '(' || rank(exp[i]) > rank(ope.top() )){    ////运算符优先级高于栈顶运算符 入栈   
            ope.push(exp[i]);  
            i++;  
        }  
        else if(exp[i] == ')' && ope.top() == '('){  /// 把括号消除   
            ope.pop() ;  
            i++;  
        }  
        else if(rank(exp[i]) <= rank(ope.top())){  ///运算符优先级低于栈顶运算符 运算   
           cal();
        }  
    }  
	cout<<num.top();
}
