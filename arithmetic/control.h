#ifndef _CONTROL_H
#define _CONTROL_H
#include <string>
using namespace std;

class Control
 {
public:
	bool judgeExpression(string str);
	bool getKeyAndExit();
	bool judgeResult(double res);
    bool JudgeIfGet(char* lanuage);
	void GetResource(string *Resource,char *filepath); 
	void StatisticalResult(int &wrong, int &right, double res, double number, string *Resource, char *filePath);
	int ReadFile(char *fileName);
};
#endif
