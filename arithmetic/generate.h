#ifndef _GENERATE_H
#define _GENERATE_H
#include <string>
using namespace std;
class Generate
{
public:
	string generateExpression();
private:
    int randomNumber(int low,int high);
    string randomOperation(int rand);
    string generatePolynomial(int rand1,int rand2,string ope,int mode);;
    
};
#endif
