#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "operand.h"
#include <map>
#include <string>
#include <set>
#include <QString>
#include <QStringList>

//Back-end operation class calculator
//Dynamic Singleton
//http://vallista.tistory.com/entry/1-Singleton-Pattern-in-C
class Calculator
{
public:
	enum {AlreadyExistError = 256, ReservedWordError};
	enum {MATRIX, NUMERIC, STRING};
	Calculator();
	~Calculator();
	int NewVariable(const std::string &name, int rows, int cols, float init);
	int NewVariable(const std::string &name, float value);
	int NewVariable(const std::string &name, std::string value);
	int Add(std::string key1, std::string key2);
	int Sub(std::string key1, std::string key2);
	int Mul(std::string key1, std::string key2);
	int Div(std::string key1, std::string key2);
	bool EditValue(std::string key, int row, int col, float value);
	bool EditValue(std::string key, float value);
	bool EditValue(std::string key, std::string value);
	QString getVariableInfo(std::string key) const;
	QString GetVariableValue(std::string key) const;
	int getVariableType(std::string key) const;
	QStringList getVariableNameList() const;
	void deleteVariable(std::string key);
	void Clear();

	static Calculator* GetInstance()
	{
		if (instance == nullptr)
			instance = new Calculator();
		return instance;
	}
private:
	std::map<std::string, Matrix> matrix_variables;
	std::map<std::string, float> numeric_variables;
	std::map<std::string, std::string> string_variables;
	void SetResult(const Matrix & value);
	void SetResult(float value);
	void SetResult(std::string value);

	static Calculator* instance;
};

#endif // !CALCULATOR_H
