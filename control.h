#ifndef _CONTROL_H
#define _CONTROL_H
#include <string>
using namespace std;

class Control
 {
public:
	string judge_formula();
    void ShowLanguageList();
	bool get_key_and_exit();
	string judge_result();
    bool JudgeIfGet(char *lanuage);
	void GetResource(char *filepath); 
};
#endif
