#include "printf.h"
#include "calculate.h"
#include "control.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
void Printf::_Printf(string *Resource)
{
	
	int wrong=0;
	int right=0;
   	cout<<Resource[0];
   	int counts;
   	cin>>counts;
	    for (int i=0;i<counts;i++)
	  {
		string pol =Control().judge_result();
		cout << pol << "="<<endl;
        double res=Calculate().calculate_formula(pol);
		cout << Resource[1]<<i+1<<Resource[2];
		double number;
		cin >> number;
		if((Control()).get_key_and_exit())
	 {
		if(number==res) 
		{
	      cout <<Resource[3]<<endl;
	      right++;
		}
	    else 
	    {
	        cout << Resource[4]<<res<<endl;
        	wrong++;
		}
	}
	else break;	
	}
	cout <<Resource[5]<< right << Resource[6] << wrong <<Resource[7]<<endl;
}
