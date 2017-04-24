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
	srand((unsigned)time(NULL));             //�������� 
	Printf().ShowLanguageList();             //չʾ��ѡ�������б� 
	cout<<endl<<endl;
	Printf().printfNeedWhat();
	char language[20];           
	gets(language);                         //��ȡ�û���ѡ������� 
	while(!Control().JudgeIfGet(language)){  //�ж�������Դ�ļ��Ƿ�����ɹ� 
	Printf().printfNeedWhat();
	gets(language);
	}
    string Resource[30];       
	Control().GetResource(Resource,language);  //��������Դ����resouce���� 
	
	int wrong=0;
	int right=0;
   	cout<<Resource[0];
   	int counts;
   	cin>>counts;
	for (int i=0;i<counts;i++){
	string exp = Generate().generateExpression();   //���ɱ��ʽ 
	cout << exp << "="<<endl;
    double res=Calculate().calculateResult(exp);     //������ʽ��� 
	cout << Resource[1]<<i+1<<Resource[2];
	double number;
	cin >> number;
	if((Control()).getKeyAndExit()) {              //���e�˳�ѭ����ͳ�ƴ������ 
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
