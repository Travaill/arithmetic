#include "generate.h"
#include "calculate.h"
#include "control.h"
#include "printf.h"
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <string>
#include <sstream>
#include <string.h>
using namespace std;

int main(void)
{
	cout<<"---------�����������Calculator��-------/"<<endl;
	cout<<"|      ���������ѡ���ĺ�Ӣ��           |"<<endl;
	cout<<"|   You can choose Chiness or Engilish  |"<<endl;
	cout<<"|	    ���� CH ѡ������            |"<<endl;
	cout<<"|	Enter EN choose Engilish        |"<<endl;
	cout<<"|����E �� e ��ǰ��������ͳ�ƴ������  |"<<endl; 
	cout<<"|     Enter E or e quit the program     |"<<endl; 
	cout<<"|---------------------------------------/"<<endl; 
	srand((unsigned)time(NULL));
    Control().choose_lanuage();
	system("pause");
	return 0;
}
