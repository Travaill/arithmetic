#include "generate.h"
#include "calculate.h"
#include "control.h"
#include "printf.h"
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
int main(void)
{
	srand((unsigned)time(NULL));             //重置种子 
	Printf().ShowLanguageList();             //展示可选择语言列表 
	cout<<endl<<endl;
	Printf().printfNeedWhat();
	char language[20];           
	gets(language);                         //获取用户所选择的语言 
	while(!Control().JudgeIfGet(language)){  //判断语言资源文件是否载入成功 
	Printf().printfNeedWhat();
	gets(language);
	}
    string Resource[30];       
	Control().GetResource(Resource,language);  //将语言资源导入resouce数组 
	
	int wrong=0;
	int right=0;
   	cout<<Resource[0];
   	int counts;
   	cin>>counts;
	for (int i=0;i<counts;i++){
	string exp = Generate().generateExpression();   //生成表达式 
	cout << exp << "="<<endl;
    double res=Calculate().calculateResult(exp);     //计算表达式结果 
	cout << Resource[1]<<i+1<<Resource[2];
	double number;
	cin >> number;
	if((Control()).getKeyAndExit()) {              //输出e退出循环并统计答题情况 
	 if(number==res) {
	    cout <<Resource[3]<<endl;
	    right++;
	 }
	 else {
	    cout << Resource[4]<<res<<endl;
        wrong++;
	 }
	}
	else break;	
	}
	cout <<Resource[5]<< right << Resource[6] << wrong <<Resource[7]<<endl;
	system("pause");
	return 0;
}
