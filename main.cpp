#include "generate.h"
#include "calculate.h"
#include "control.h"
#include "printf.h"
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include<fstream>
using namespace std;
int main(void)
{
	Control().ShowLanguageList();
	cout<<endl;
	cout<<endl;
    cout<<"萩補秘低侭俶勣議囂冱議兆各:"<<endl;
    cout<<"Please enter a name for the language you need:"<<endl;
    cout<<"Bitte geben sie ihren namen: die erforderlichen Sprachen:"<<endl;
    cout<<"Prie dans la langue dont vous avez besoin:"<<endl;
	cout<<"秘薦してください。あなたに駅勣な冱匐の兆各:" <<endl; 
	srand((unsigned)time(NULL));
	char language[20];
	gets(language);
	while(!Control().JudgeIfGet(language))
	{
		cout<<"萩補秘低侭俶勣議囂冱議兆各:"<<endl;
        cout<<"Please enter a name for the language you need:"<<endl;
        cout<<"Bitte geben sie ihren namen: die erforderlichen Sprachen"<<endl;
        cout<<"Prie dans la langue dont vous avez besoin:"<<endl;
	    cout<<"秘薦してください。あなたに駅勣な冱匐の兆各:" <<endl; 
		gets(language);
		if(Control().JudgeIfGet(language)) break;
	}
	    fstream file;
	    stringstream ss;
	    char filepath[200] = "";
	    ss<<"Languagerc\\"<<language<<".txt";
	    ss>>filepath;
	    ss.str("");
        string Resource[30];
		Control().GetResource(Resource,filepath);  
        Printf()._Printf(Resource);
	    system("pause");
	    return 0;
}
