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
	cout<<"---------四则计算器（Calculator）-------/"<<endl;
	cout<<"|      本程序可以选中文和英文           |"<<endl;
	cout<<"|   You can choose Chiness or Engilish  |"<<endl;
	cout<<"|	    输入 CH 选择中文            |"<<endl;
	cout<<"|	Enter EN choose Engilish        |"<<endl;
	cout<<"|输入E 或 e 提前结束程序并统计答题情况  |"<<endl; 
	cout<<"|     Enter E or e quit the program     |"<<endl; 
	cout<<"|---------------------------------------/"<<endl; 
	srand((unsigned)time(NULL));
    Control().choose_lanuage();
	system("pause");
	return 0;
}
