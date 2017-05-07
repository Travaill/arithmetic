#ifndef PRINTF_H
#define PRINTF_H
#include <string>
using namespace std;
class Printf
{
public:
	void ShowLanguageList();
	void printfNeedWhat();
	void FilePrint(char *filePath, int x);
	void FilePrint(char *filePath, string x);
	void FilePrint(char *filePath, double x);
	void FilePrint(char *filePath, char *x);
	void PrintfExpressionToFile(char* filePath, string x1, string x2, string x3, int x4, string x5);	
	void PrintfResultToFile(char* filePath, string x1, int x2, string x3, int x4, string x5, string x6);
};
#endif
