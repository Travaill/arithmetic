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
	srand((unsigned)time(NULL));             //�������� 
	Printf().ShowLanguageList();             //չʾ��ѡ�������б� 
	cout << endl << endl;
	char language[20];                    //��ȡ�û���ѡ������� 
	{
		Printf().printfNeedWhat();
		gets_s(language);
	} while (!Control().JudgeIfGet(language));//�ж�������Դ�ļ��Ƿ�����ɹ�
	string Resource[30];
	Control().GetResource(Resource, language);  //��������Դ����resouce���� 
	int wrong = 0, right = 0;
	int counts = Control().ReadFile(argv[1]);

	for (int i = 0; i < counts; i++)
	{
		string exp;
		double res;
		do
		{
			exp = Generate().generateExpression();   //������ʽ
			res = Calculate().calculateResult(exp);  //������ʽ���
		} while (Control().judgeExpression(exp) || Control().judgeResult(res));  //�ж����ɵ���ʽ�Ƿ����Ҫ��
		cout << exp << endl << Resource[1] << i + 1 << Resource[2];
		Printf().PrintfExpressionToFile(argv[2],exp, "\n", Resource[1], i + 1, Resource[2]);
		double number;
		cin >> number;
		Printf().FilePrint(argv[2], number);
		if ((Control()).getKeyAndExit())  //���e�˳�ѭ����ͳ�ƴ������ 
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
