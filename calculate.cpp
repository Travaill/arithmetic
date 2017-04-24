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
	char ope=ope_stk.top();
    double a,b,res;
    b=num_stk.top();
    num_stk.pop();
    a=num_stk.top();
    num_stk.pop();
    switch(ope)
    {
        case '+':res=a+b; break;
        case '-':res=a-b; break;
        case '*':res=a*b; break;
        case '/':res=a/b; break;
        default: break;
    }
    num_stk.push(res);
    ope_stk.pop();
}

int Calculate::Rank(char x)                //计算优先级 
{
    if(x=='(')
        return 1;
    else if(x=='+')
        return 2;
    else if(x=='-')
        return 3;
    else if(x=='*')
        return 4;
    else if(x=='/')
        return 5;
}

double Calculate::calculateResult(string str)     //计算算式 
{
	
	int x=0;
	int  num_flag=0;
	for(int i=0;i<str.size();i++)
	{
        if((str[i]>='0')&&(str[i]<='9'))
		{
            x=x*10+str[i]-'0';
            num_flag=1;
            if(i==str.size()-1)
            num_stk.push(x);
        }
        else{
            if(x)
			{
                num_stk.push(x);
                x=0;
                num_flag=0;
            }
            if(ope_stk.empty())
                ope_stk.push(str[i]);
            else if(str[i]=='(')
                ope_stk.push(str[i]);
            else if(str[i]==')')
            {
                while(ope_stk.top()!='(')
                    calculatePolynomial();                
                    ope_stk.pop();
            }
            else if((Rank(str[i]))<=Rank(ope_stk.top()))
            {
                calculatePolynomial();
                ope_stk.push(str[i]);
            }
            else
			{
                ope_stk.push(str[i]);
            }
        }
    }
    while(!ope_stk.empty())
    calculatePolynomial();
    double res=num_stk.top();
    return res;
}
