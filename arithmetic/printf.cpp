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
	file.open("languagerc\\LanguageList.txt",ios::in);
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

void Printf::FilePrint(char *filePath,int x)
{
	fstream fout;
	fout.open(filePath, ios::app);
	fout << x;
	fout.close();
    
}

void Printf::FilePrint(char *filePath,string x)
{
	fstream fout;
	fout.open(filePath, ios::app);
	fout << x;
	fout.close();
}

void Printf::FilePrint(char *filePath, double x)
{
	fstream fout;
	fout.open(filePath, ios::app);
	fout << x;
	fout.close();
}
void Printf::FilePrint(char *filePath,char* x)
{
	fstream fout;
	fout.open(filePath, ios::app);
	fout << x;
	fout.close();
}
void Printf::PrintfExpressionToFile(char* filePath, string x1, string x2, string x3,int x4, string x5)
{
	Printf().FilePrint(filePath, x1);
	Printf().FilePrint(filePath, x2);
	Printf().FilePrint(filePath, x3);
	Printf().FilePrint(filePath,x4);
	Printf().FilePrint(filePath, x5);
}

void Printf::PrintfResultToFile(char* filePath, string x1, int x2, string x3, int x4, string x5, string x6)
{
	Printf().FilePrint(filePath, x1);
	Printf().FilePrint(filePath, x2);
	Printf().FilePrint(filePath, x3);
	Printf().FilePrint(filePath, x4);
	Printf().FilePrint(filePath, x5);
	Printf().FilePrint(filePath, x6);
}