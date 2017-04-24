#include "generate.h"
#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <string>
#include <sstream>
#include <string.h>

using namespace std;
int Generate::randomNumber(int low,int high)  //����[low,high]����� 
{
	return (rand()% (high - low+1) + low);
}  

string Generate::randomOperation(int rand)     //������������� 
{
	string ope;
    switch(rand) 
    {
    	case 1:ope='+'; break;
    	case 2:ope='-'; break;
    	case 3:ope='*'; break;
    	case 4:ope='/'; break;
	}
	return ope;
}

string Generate::generatePolynomial(int rand1,int rand2,string ope,int mode)  //���ɶ���ʽ 
{
   stringstream ss;
   if(mode==1) 
  {
  	ss << '(' << rand1<<ope<<rand2<<')';
  } 
    if(mode==2)
  {
    ss<<rand1<<ope<<rand2;
  }
    if(mode==3)	
  {
  	if(rand1!=0)
  	{
  	  ss<<rand1;
	}
  }
  	string str = ss.str();  
  	ss.str("");
    return str;
}

string Generate::generateExpression()     //������ʽ 
{
	stringstream ss;
	int rand1=randomNumber(1,10);
	int rand2=randomNumber(1,10);
	int mode =randomNumber(1,3);
	string ope=randomOperation(randomNumber(1,4));
	ss<<generatePolynomial(rand1,rand2,ope,mode);
	for(int i=1;i<randomNumber(2,4);i++)
	{
		int rand1=randomNumber(1,10);
	    int rand2=randomNumber(1,10);
 	    int mode =randomNumber(1,3);
	    string ope=randomOperation(randomNumber(1,4));
	    ss<<generatePolynomial(rand1,rand2,ope,mode);
		ss<<randomOperation(randomNumber(1,4))<<generatePolynomial(rand1,rand2,ope,mode);
	}
	string str = ss.str();  
	ss.str("");
    return str;
    return str;
}

