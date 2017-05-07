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
bool Control::judgeExpression(string str)          //生成的算式是否合法 
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

bool Control::getKeyAndExit(void)                 //输出E 或 e退出循环统计答对和答错题数 
{
	char c;
    c = getchar();
    if(c == 'E' || c=='e')  //当输入y时退出，不区分大小写。
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Control::judgeResult(double res)             //判断结果是否符合要求以及是否绝对值小于100
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
	
bool Control::JudgeIfGet(char *language)          //判断路径是否正确 
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

void Control::GetResource(string *Resource,char *language)    //读取资源文件 
{
	fstream File;
	stringstream ss;
	char filepath[200] = "";
	ss << "Languagerc\\"<<language<<".txt"; //生成文件地址 
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