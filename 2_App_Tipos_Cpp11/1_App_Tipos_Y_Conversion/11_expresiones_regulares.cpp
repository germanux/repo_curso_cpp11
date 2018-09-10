
#include "stdafx.h"

#include <iostream>
#include <regex>
#include <string>

using namespace std;

void ej_regex()
{
	string input;
	regex patron("[a-zA-Z0-9]*");
	cout << "Introduzca una cadena: " << endl;
	cin >> input;
	if (regex_match(input, patron)) {
		cout << "OK" << endl;
	}
	else {
		cout << "NOT OK" << endl;
	}
}
void ej_regex_smatch()
{
	std::string s("escribe a algo@ucm.es, correo2@fst.com o 43@uni.pl con tus dudas");
	std::smatch m;
	std::regex e(R"(([[:alnum:]]+)@([[:alnum:]]+\.[[:alnum:]]+))");
	std::cout << "Texto: " << s << std::endl;
	std::cout << "Patron: <([[:alnum:]]+)@([[:alnum:]]+\.[[:alnum:]]+)>" << std::endl;
	std::cout << "Resultado:" << std::endl;
	int vuelta = 0;
	while (std::regex_search(s, m, e)) {
		/*std::smatch::iterator iteraMatch;
		iteraMatch = m.begin();
		while (iteraMatch != m.end()) {
		std::cout << *iteraMatch << " ";
		iteraMatch++;
		}*/
		int subgrupo = 0;
		std::cout << "Match Num: " << vuelta << std::endl;
		for (auto x : m) {
			std::cout << "subgrupo " << subgrupo << " <" << x << "> ";
			subgrupo++;
		}
		std::cout << std::endl;
		s = m.suffix().str();
		vuelta++;
	}
}