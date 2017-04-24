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
};
#endif
