#include "printf.h"
#include "calculate.h"
#include "control.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

void Printf::Ch_printf(void)   //������� 
{
	int wrong=0;
	int right=0;
	int counts=Control().CH_get_times();
	for (int i = 0; i < counts; i++)
	{
		string pol =Control().judge_result();
		cout << pol << "="<<endl;
        double res=Calculate().calculate_formula(pol);
		cout << "��" << i + 1 << "����Ĵ�Ϊ:";
		double number;
		cin >> number;

		if((Control()).get_key_and_exit())
	{
		if(number==res) 
		{
	      cout << "��ȷ"<<endl;
	      right++;
		}
	    else 
	    {
	        cout << "����,��ȷ��Ϊ "<<res<<endl;
        	wrong++;
		}
	}
	else break;	
	}
	cout << "�������ȷ" << right << "���⣬����" << wrong << "���⡣"<<endl;
}

void Printf::En_printf(void)  //Ӣ����� 
{
	int wrong=0;
	int right=0;
	int counts=Control().EN_get_times();
	for (int i = 0; i < counts; i++)
	{
		string pol =Control().judge_result();
		cout << pol << "="<<endl;
        double res=Calculate().calculate_formula(pol);
		cout << "The answer of NO." << i + 1 << "is:";
		double number;
		cin >> number;
		if((Control()).get_key_and_exit())
	{
		if(number==res) 
		{
		  
	      cout<<"You are right."<<endl;
	      right++;
		}
	    else 
	    {
	        cout<<"Sorry,the correct answer is:"<<res<<endl;
        	wrong++;
		}
	}
	else break;	
	}
	cout << "RESULT��Right:" << right <<""<< "Wrong:" << wrong<<endl;
}
