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
string Control::judge_formula(void)               //生成的算式是否合法 
{
	string str=Generate().generate_formula();
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
     	return str;
	 }
	 else
	 {
	 	return judge_formula();
	 }
}


bool Control::get_key_and_exit(void)            //输出E 或 e退出循环统计答对和答错题数 
{
	char c;
    bool a=1;
    c = getchar();
    if(c == 'E' || c=='e')  //当输入y时退出，不区分大小写。
		{
		  a=0;
		}
	return a;
}

string Control::judge_result(void)          //判断结果是否为整数  
{
  	string str=Control().judge_formula();
  	double res=Calculate().calculate_formula(str);
  	if((int)res==res)
  	{
  		return str;
	}
	else
	{
		return Control().judge_result();
	}
}
	

void Control::ShowLanguageList()    //展示可供选择的语言 
{
	fstream file;//文件流
	file.open("languagerc//LanguageList.txt",ios::in);
	char language[20];
	while (file.getline(language,20))
	{
		cout << language<<endl;
	}
	file.close();
}

bool Control::JudgeIfGet(char *language)          //选择语言 
{
    fstream file;
	stringstream ss;
	char Langpath[200] = "";
	ss<<"Languagerc\\"<<language<<".txt";
	ss>>Langpath;
	ss.str("");
	file.open(Langpath, ios::in);
	if (file.is_open())
	{
		file.close();
		return true;
	}
}

void Control::GetResource(char *filepath)    //得到资源文件 
{
	string Resource[30];
	fstream File;
	stringstream ss; 
	File.open(filepath,ios::in);
	int i,j;
	string Line;
	for (i=0;i<8;i++)
	{
	   getline(File,Line);
	   swap(Line,Resource[i]);
	}
	File.close();
	int wrong=0;
	int right=0;
	cout<<Resource[0];
	int counts;
	cin>>counts;
	for (int i=0;i<counts;i++)
	{
		string pol =Control().judge_result();
		cout << pol << "="<<endl;
        double res=Calculate().calculate_formula(pol);
		cout << Resource[1]<<i+1<<Resource[2];
		double number;
		cin >> number;
		if((Control()).get_key_and_exit())
	{
		if(number==res) 
		{
	      cout <<Resource[3]<<endl;
	      right++;
		}
	    else 
	    {
	        cout << Resource[4]<<res<<endl;
        	wrong++;
		}
	}
	else break;	
	}
	cout <<Resource[5]<< right << Resource[6] << wrong <<Resource[7]<<endl;
	
}
