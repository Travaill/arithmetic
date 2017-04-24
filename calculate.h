#ifndef CALCULATE_H
#define CALCULATE_H
#include <string>
using namespace std;
class Calculate
{
public:
	double calculateResult(string str);   
private:
    void calculatePolynomial(); 
    int Rank(char x) ;          
};
#endif
