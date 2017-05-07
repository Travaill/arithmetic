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
int main(int argc,char *argv[])
{
	srand((unsigned)time(NULL));             //重置种子 
	Printf().ShowLanguageList();             //展示可选择语言列表 
	cout << endl << endl;
	char language[20];                    //获取用户所选择的语言 
	{
		Printf().printfNeedWhat();
		gets_s(language);
	} while (!Control().JudgeIfGet(language));//判断语言资源文件是否载入成功
	string Resource[30];
	Control().GetResource(Resource, language);  //将语言资源导入resouce数组 
	int wrong = 0, right = 0;
	int counts = Control().ReadFile(argv[1]);

	for (int i = 0; i < counts; i++)
	{
		string exp;
		double res;
		do
		{
			exp = Generate().generateExpression();   //生成算式
			res = Calculate().calculateResult(exp);  //计算算式结果
		} while (Control().judgeExpression(exp) || Control().judgeResult(res));  //判断生成的算式是否符合要求
		cout << exp << endl << Resource[1] << i + 1 << Resource[2];
		Printf().PrintfExpressionToFile(argv[2],exp, "\n", Resource[1], i + 1, Resource[2]);
		double number;
		cin >> number;
		Printf().FilePrint(argv[2], number);
		if ((Control()).getKeyAndExit())  //输出e退出循环并统计答题情况 
		{
			Control().StatisticalResult(wrong, right, res, number, Resource,argv[2]);
		}
		else break;
	}
	cout << Resource[5] << right << Resource[6] << wrong << Resource[7] << endl;
	Printf().FilePrint(argv[2],"\0");
	Printf().PrintfResultToFile(argv[2], Resource[5], right, Resource[6], wrong, Resource[7], "\n");
	system("pause");
	return 0;
}
