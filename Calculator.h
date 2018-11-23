#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "operand.h"
#include <map>
#include <string>

//Back-end operation class calculator
class Calculator
{
public:
	Calculator();
	~Calculator();

private:
	std::map<std::string, op::Matrix> matrix_variables;
	std::map<std::string, float> numeric_variables;
	std::map<std::string, std::string> string_variables;
};


#endif // !CALCULATOR_H
