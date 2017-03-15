#include "generate.h"
#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <string>
#include <sstream>
#include <string.h>

using namespace std;
int Generate::generate_rand(int low,int high)  //����[low,high]����� 
{
	return (rand()% (high - low+1) + low);
}  

string Generate::generate_operator(void)     //������������� 
{
	string ope;
    switch(generate_rand(1,4)) 
    {
    	case 1:ope='+'; break;
    	case 2:ope='-'; break;
    	case 3:ope='*'; break;
    	case 4:ope='/'; break;
	}
	return ope;
}

string Generate::generate_polynomial(void)  //���ɶ���ʽ 
{
	int a,b,c;
    stringstream ss;
	a=generate_rand(0,10);    
    b=generate_rand(0,10);
    c=generate_rand(1,3);  
   if(c==1) 
  {
  	ss << '(' << a<<generate_operator()<<b<<')';
  } 
    if(c==2)
  {
    ss<<a<< generate_operator()<<b;
  }
    if(c==3)	
  {
	ss<<a;
  }
  	string str = ss.str();  
  	ss.str("");
    return str;
}

string Generate::generate_formula(void)     //������ʽ 
{
	stringstream ss;
	ss<<generate_polynomial();
	for(int i=1;i<generate_rand(2,4);i++)
	{
		ss<<generate_operator()<<generate_polynomial();
	}
	string str = ss.str();  
	ss.str("");
    return str;
}

