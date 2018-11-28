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
	enum {AlreadyExistError, ReservedWordError};
	enum {Add, Sub, Mul, Div};
	Calculator();
	~Calculator();
	void NewVariable(const std::string &name, int rows, int cols, float init);
	void NewVariable(const std::string &name, float value);
	void NewVariable(const std::string &name, std::string value);
	void Add(std::string key1, std::string key2);
	void Sub(std::string key1, std::string key2);
	void Mul(std::string key1, std::string key2);
	void Div(std::string key1, std::string key2);
	void EditValue(std::string key, int row, int col, float value);
	void EditValue(std::string key, float value);
	void EditVAlue(std::string key, std::string value);
	QString GetInfo(std::string key) const;
	QString GetVarialbeValue(std::string key) const;
	QStringList getVariableNameList() const;
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
