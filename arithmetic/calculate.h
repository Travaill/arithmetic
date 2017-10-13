#ifndef CALCULATE_H
#define CALCULATE_H
#include <string>
using namespace std;
class Calculate
{
public:
	double calculateResult(char *str);   
private:
	int change(char *s,int &i);
    void calculatePolynomial(); 
    int Rank(char x) ;          
};
#endif
