#ifndef _CONTROL_H
#define _CONTROL_H
#include <string>
using namespace std;

class Control
 {
public:
	string judge_formula();
	int CH_get_times();
	int EN_get_times();   
	bool get_key_and_exit();
	string judge_result();
	void choose_lanuage();
};
#endif
