#include <gtest/gtest.h>
#include <iostream>
#include "parser.h"
#include "scanner.h"
#include "exp.h"
#include <sstream>

using namespace std;

string& checkcomanndcc123456(string &s);

int main( int argc , char **argv ) {
	do {
		cout << "?-";
		string input;
		getline(cin, input);
		if (checkcomanndcc123456(input) == "halt.")
			break;
		if (checkcomanndcc123456(input) == "")
			continue;
		Scanner s(input);
		Parser p(s);
		try{
			p.buildExpression();
			string result = p.getExpressionTree()->getExpressionResult() + '.';
			cout << result << endl;
		} catch (std::string & msg) {
			cout << msg << endl;
		}
	} while(true);
    return 0;
}

string& checkcomanndcc123456(string &s) {
    if (s.empty()) {
         return s;
    }
    int index = 0;
    string str="";
    for(int i=0 ; i<s.size() ; i++){
        if(s[i] != ' '){
            index = i;
            str = str + s[i];
        }
    }
    s = str;
    return s;
}
