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
using namespace std;
bool Control::judgeExpression(string str)          //���ɵ���ʽ�Ƿ�Ϸ� 
{
	char ptr[35];
    strcpy(ptr,str.c_str()); 
	const char *substr1="/0";
	const char *substr2="/(1-1)";
	const char *substr3="/(2-2)";
	const char *substr4="/(3-3)";
	const char *substr5="/(4-4)";
	const char *substr6="/(5-5)";
	const char *substr7="/(6-6)";
	const char *substr8="/(7-7)";
	const char *substr9="/(8-8)";
	const char *substr10="/(9-9)";
	const char *substr11="/(10-10)";
	const char *substr12="0*";
	const char *substr13="0/";
	const char *substr14="+0";
	const char *substr15="-0";
    char *s1 = strstr(ptr, substr1);
    char *s2 = strstr(ptr, substr2);
    char *s3 = strstr(ptr, substr3);
    char *s4 = strstr(ptr, substr4);
    char *s5 = strstr(ptr, substr5);
    char *s6 = strstr(ptr, substr6);
    char *s7 = strstr(ptr, substr7);
    char *s8 = strstr(ptr, substr8);
    char *s9 = strstr(ptr, substr9);
    char *s10 = strstr(ptr, substr10);
    char *s11 = strstr(ptr, substr11);
    char *s12 = strstr(ptr, substr12);
    char *s13 = strstr(ptr, substr13);
    char *s14 = strstr(ptr, substr13);
    char *s15 = strstr(ptr, substr13);
     if(s1==NULL&&s2==NULL&&s3==NULL&&s4==NULL&&s5==NULL&&s6==NULL&&s7==NULL&&s8==NULL&&s9==NULL&&s10==NULL&&s11==NULL&&s12==NULL&&s13==NULL&&s14==NULL&&s15==NULL)
     {
     	return 1;
	 }
	 else
	 {
	 	return 0;
	 }
}

bool Control::getKeyAndExit(void)                 //���E �� e�˳�ѭ��ͳ�ƴ�Ժʹ������ 
{
	char c;
    bool a=1;
    c = getchar();
    if(c == 'E' || c=='e')  //������yʱ�˳��������ִ�Сд��
		{
		  a=0;
		}
	return a;
}

bool Control::judgeResult(double res)             //�жϽ���Ƿ�Ϊ����  
{
  	if((int)res==res)
  	{
  		return 1;
	}
	else
	{
		return 0;
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
}

void Control::GetResource(string *Resource,char *language)    //��ȡ��Դ�ļ� 
{
	fstream File;
	stringstream ss;
	char filepath[200] = "";
	ss<<"Languagerc\\"<<language<<".txt";   //�����ļ���ַ 
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

