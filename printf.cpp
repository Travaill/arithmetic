#include "printf.h"
#include "calculate.h"
#include "control.h"
#include "generate.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

void Printf::ShowLanguageList()    //չʾ�ɹ�ѡ������� 
{
	fstream file;//�ļ���
	file.open("languagerc//LanguageList.txt",ios::in);
	string language;
	while (getline(file,language))
	{
		cout <<language<<" ";
	}
	file.close();
}

void Printf::printfNeedWhat()     
{
	cout<<"������������Ҫ�����Ե�����:"<<endl;
    cout<<"Please enter a name for the language you need:"<<endl;
    cout<<"Bitte geben sie ihren namen: die erforderlichen Sprachen:"<<endl;
    cout<<"Prie dans la langue dont vous avez besoin:"<<endl;
	cout<<"�������Ƥ������������ʤ��˱�Ҫ����Ҷ������:" <<endl; 
}
