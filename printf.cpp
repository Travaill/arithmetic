#include "printf.h"
#include "calculate.h"
#include "control.h"
#include "generate.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

void Printf::ShowLanguageList()    //婢幣辛工僉夲議囂冱 
{
	fstream file;//猟周送
	file.open("languagerc//LanguageList.txt",ios::in);
	string language;
	while (getline(file,language))
	{
		cout <<language<<" ";
	}
	file.close();
}

void Printf::printfNeedWhat()     
{
	cout<<"萩補秘低侭俶勣議囂冱議兆各:"<<endl;
    cout<<"Please enter a name for the language you need:"<<endl;
    cout<<"Bitte geben sie ihren namen: die erforderlichen Sprachen:"<<endl;
    cout<<"Prie dans la langue dont vous avez besoin:"<<endl;
	cout<<"秘薦してください。あなたに駅勣な冱匐の兆各:" <<endl; 
}
