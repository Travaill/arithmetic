#ifndef CALCULATE_H
#define CALCULATE_H
#include <string>
using namespace std;
class Calculate
{
public:
	double calculate_formula(string str);   
private:
    void calculate_polynomial(); 
    int Rank(char x) ;          
};
#endif
