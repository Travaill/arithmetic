#include "control.h"
#include "generate.h"
#include "calculate.h"
#include "printf.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include<fstream>
#include<sstream>
#include<math.h>
using namespace std;
bool Control::judgeExpression(string str)          //���ɵ���ʽ�Ƿ�Ϸ� 
{
	char ptr[35];
    strcpy_s(ptr,str.c_str());
	const char *substr[] = { "/0" ,"/(1-1)","/(2-2)","/(3-3)","/(4-4)","/(5-5)","/(6-6)","/(7-7)","/(8-8)","/(9-9)","/(10-10)" };
	char *s;
	for (int i = 0; i <= 10; i++)
	{
		s = strstr(ptr, substr[i]);
		if (s != NULL)
		{
			break;
		}
	}
     if(s==NULL)
     {
     	return 0;
	 }
	 else
	 {
	 	return 1;
	 }
}

bool Control::getKeyAndExit(void)                 //���E �� e�˳�ѭ��ͳ�ƴ�Ժʹ������ 
{
	char c;
    c = getchar();
    if(c == 'E' || c=='e')  //������yʱ�˳��������ִ�Сд��
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Control::judgeResult(double res)             //�жϽ���Ƿ����Ҫ���Լ��Ƿ����ֵС��100
{

  	if((int)res==res&&abs(res)<=100)
  	{
  		return 0;
	}
	else
	{
		return 1;
	}
}
	
bool Control::JudgeIfGet(char *language)          //�ж�·���Ƿ���ȷ 
{
    fstream file;
	stringstream ss;
	char filepath[200] = "";
	ss<<"Languagerc\\"<<language<<".txt";
	ss>>filepath;
	ss.str("");
	file.open(filepath,ios::in);
	if (file.is_open())
	{
		file.close();
		return true;
	}
	else
	{
		return false;
	}
}

void Control::GetResource(string *Resource,char *language)    //��ȡ��Դ�ļ� 
{
	fstream File;
	stringstream ss;
	char filepath[200] = "";
	ss << "Languagerc\\"<<language<<".txt"; //�����ļ���ַ 
	ss>>filepath;   
	ss.str("");
	File.open(filepath,ios::in);
	string Line;
	for (int i=0;getline(File,Line);i++)
	{
	   swap(Line,Resource[i]);
	}
	File.close();
}

void Control::StatisticalResult(int &wrong, int &right, double res, double number,string *Resource,char *filePath)
{
	if (number == res)
	{
		cout << Resource[3] << endl;
		Printf().FilePrint(filePath, Resource[3]);
		Printf().FilePrint(filePath, "\n");
		right++;
	}
	else
	{
		cout << Resource[4] << res << endl;
		Printf().FilePrint(filePath, Resource[4]);
		Printf().FilePrint(filePath, res);
		Printf().FilePrint(filePath, "\n");
		wrong++;
	}
}

int Control::ReadFile(char *filePath)
{
	int counts;
	fstream file;
	file.open(filePath, ios::in);
	file >> counts;
	file.close();
	return counts;
}