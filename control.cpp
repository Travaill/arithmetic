#include "control.h"
#include "generate.h"
#include "calculate.h"
#include "printf.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
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
     if(s1==NULL&&s2==NULL&&s3==NULL&&s4==NULL&&s5==NULL&&s6==NULL&&s7==NULL&&s8==NULL&&s9==NULL&&s10==NULL&&s11==NULL&&s12==NULL&&s13==NULL)
     {
     	return str;
	 }
	 else
	 {
	 	return judge_formula();
	 }
    
}

int Control::CH_get_times(void)                     //输入需要的题目数量 
{
	int times;
	cout << "请输入想完成的题目数量:";
	cin >> times;
	return times;
}

int Control::EN_get_times(void)                     //输入需要的题目数量 
{
	int times;
	cout << "How many questions do you want?";
	cin >> times;
	return times;
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
	
void Control::choose_lanuage(void)          //选择英文或者中文 
{
	string x;
	cin>>x;
	if(x=="CH"||x=="ch"||x=="Ch")
	{
		Printf().Ch_printf();
	}
	if(x=="EN"||x=="en"||x=="En")
	{
		Printf().En_printf();
	}
	else
	{
		return Control::choose_lanuage();
	}
	 
}
