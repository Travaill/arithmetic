#ifndef _GENERATE_H
#define _GENERATE_H
#include <string>
using namespace std;
class Generate
{
public:
	string generate_formula();
private:
    int generate_rand(int low,int high);
    string generate_operator();
    string generate_polynomial();
    
};
#endif
