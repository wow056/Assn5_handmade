#include "Calculator.h"

using namespace std;


Calculator::Calculator()
{
}


Calculator::~Calculator()
{
}

void Calculator::NewVariable(const std::string & name, int rows, int cols, float init)
{
	if (name == "result")
	{
		throw ReservedWordError;
	}
	if (matrix_variables.find(name) != matrix_variables.end())
	{
		throw AlreadyExistError;
	}
	if (numeric_variables.find(name) != numeric_variables.end())
	{
		throw AlreadyExistError;
	}
	if (string_variables.find(name) != string_variables.end())
	{
		throw AlreadyExistError;
	}
	matrix_variables[name] = Matrix(rows, cols, init);
}

void Calculator::NewVariable(const std::string & name, float value)
{
	if (name == "result")
	{
		throw ReservedWordError;
	}
	if (matrix_variables.find(name) != matrix_variables.end())
	{
		throw AlreadyExistError;
	}
	if (numeric_variables.find(name) != numeric_variables.end())
	{
		throw AlreadyExistError;
	}
	if (string_variables.find(name) != string_variables.end())
	{
		throw AlreadyExistError;
	}
	numeric_variables[name] = value;
}

void Calculator::NewVariable(const std::string & name, std::string value)
{
	if (name == "result")
	{
		throw ReservedWordError;
	}
	if (matrix_variables.find(name) != matrix_variables.end())
	{
		throw AlreadyExistError;
	}
	if (numeric_variables.find(name) != numeric_variables.end())
	{
		throw AlreadyExistError;
	}
	if (string_variables.find(name) != string_variables.end())
	{
		throw AlreadyExistError;
	}
	string_variables[name] = value;
}

void Calculator::SetResult(const Matrix & value)
{
	matrix_variables.erase("result");
	numeric_variables.erase("result");
	string_variables.erase("result");
	matrix_variables["result"] = value;
}

void Calculator::SetResult(float value)
{
	matrix_variables.erase("result");
	numeric_variables.erase("result");
	string_variables.erase("result");
	numeric_variables["result"] = value;
}

void Calculator::SetResult(std::string value)
{
	matrix_variables.erase("result");
	numeric_variables.erase("result");
	string_variables.erase("result");
	string_variables["result"] = value;
}

void Calculator::Add(std::string key1, std::string key2)
{
	map<string, Matrix>::iterator matrix_it[2];
	map<string, float>::iterator numeric_it[2];
	map<string, string>::iterator string_it[2];
	if ((matrix_it[0] = matrix_variables.find(key1)) != matrix_variables.end()) // 첫째 항이 matrix일 때
	{
		Matrix &op0 = matrix_it[0]->second;
		if ((matrix_it[1] = matrix_variables.find(key1)) != matrix_variables.end()) // 둘째 항이 matrix일 때
		{
			SetResult(op0 + matrix_it[1]->second);
		}
		else if ((numeric_it[1] = numeric_variables.find(key1)) != numeric_variables.end()) // 둘째 항이 numeric일 때
		{
			SetResult(op0 + numeric_it[1]->second);
		}
		else if ((string_it[1] = string_variables.find(key1)) != string_variables.end()) // 둘째 항이 string일 때
		{
			throw CannotCalculateError;
		}
	}
	else if ((numeric_it[0] = numeric_variables.find(key1)) != numeric_variables.end()) // 첫째 항이 numeric일 때
	{
		float &op0 = numeric_it[0]->second;
		if ((matrix_it[1] = matrix_variables.find(key1)) != matrix_variables.end()) // 둘째 항이 matrix일 때
		{
			SetResult(op0 + matrix_it[1]->second);
		}
		else if ((numeric_it[1] = numeric_variables.find(key1)) != numeric_variables.end()) // 둘째 항이 numeric일 때
		{
			SetResult(op0 + numeric_it[1]->second);
		}
		else if ((string_it[1] = string_variables.find(key1)) != string_variables.end()) // 둘째 항이 string일 때
		{
			SetResult(op0 + string_it[1]->second);
		}
	}
	else if ((string_it[0] = string_variables.find(key1)) != string_variables.end()) // 첫째 항이 string일 때
	{
		string &op0 = string_it[0]->second;
		if ((matrix_it[1] = matrix_variables.find(key1)) != matrix_variables.end()) // 둘째 항이 matrix일 때
		{
			throw CannotCalculateError;
		}
		else if ((numeric_it[1] = numeric_variables.find(key1)) != numeric_variables.end()) // 둘째 항이 numeric일 때
		{
			SetResult(op0 + numeric_it[1]->second);
		}
		else if ((string_it[1] = string_variables.find(key1)) != string_variables.end()) // 둘째 항이 string일 때
		{
			SetResult(op0 + string_it[1]->second);
		}
	}
}

void Calculator::Sub(std::string key1, std::string key2)
{
	map<string, Matrix>::iterator matrix_it[2];
	map<string, float>::iterator numeric_it[2];
	map<string, string>::iterator string_it[2];
	if ((matrix_it[0] = matrix_variables.find(key1)) != matrix_variables.end()) // 첫째 항이 matrix일 때
	{
		Matrix &op0 = matrix_it[0]->second;
		if ((matrix_it[1] = matrix_variables.find(key1)) != matrix_variables.end()) // 둘째 항이 matrix일 때
		{
			SetResult(op0 - matrix_it[1]->second);
		}
		else if ((numeric_it[1] = numeric_variables.find(key1)) != numeric_variables.end()) // 둘째 항이 numeric일 때
		{
			SetResult(op0 - numeric_it[1]->second);
		}
		else if ((string_it[1] = string_variables.find(key1)) != string_variables.end()) // 둘째 항이 string일 때
		{
			throw CannotCalculateError;
		}
	}
	else if ((numeric_it[0] = numeric_variables.find(key1)) != numeric_variables.end()) // 첫째 항이 numeric일 때
	{
		float &op0 = numeric_it[0]->second;
		if ((matrix_it[1] = matrix_variables.find(key1)) != matrix_variables.end()) // 둘째 항이 matrix일 때
		{
			SetResult(op0 - matrix_it[1]->second);
		}
		else if ((numeric_it[1] = numeric_variables.find(key1)) != numeric_variables.end()) // 둘째 항이 numeric일 때
		{
			SetResult(op0 - numeric_it[1]->second);
		}
		else if ((string_it[1] = string_variables.find(key1)) != string_variables.end()) // 둘째 항이 string일 때
		{
			throw CannotCalculateError;
		}
	}
	else if ((string_it[0] = string_variables.find(key1)) != string_variables.end()) // 첫째 항이 string일 때
	{
		string &op0 = string_it[0]->second;
		if ((matrix_it[1] = matrix_variables.find(key1)) != matrix_variables.end()) // 둘째 항이 matrix일 때
		{
			throw CannotCalculateError;
		}
		else if ((numeric_it[1] = numeric_variables.find(key1)) != numeric_variables.end()) // 둘째 항이 numeric일 때
		{
			throw CannotCalculateError;
		}
		else if ((string_it[1] = string_variables.find(key1)) != string_variables.end()) // 둘째 항이 string일 때
		{
			throw CannotCalculateError;
		}
	}
}

void Calculator::Mul(std::string key1, std::string key2)
{
	map<string, Matrix>::iterator matrix_it[2];
	map<string, float>::iterator numeric_it[2];
	map<string, string>::iterator string_it[2];
	if ((matrix_it[0] = matrix_variables.find(key1)) != matrix_variables.end()) // 첫째 항이 matrix일 때
	{
		Matrix &op0 = matrix_it[0]->second;
		if ((matrix_it[1] = matrix_variables.find(key1)) != matrix_variables.end()) // 둘째 항이 matrix일 때
		{
			SetResult(op0 * matrix_it[1]->second);
		}
		else if ((numeric_it[1] = numeric_variables.find(key1)) != numeric_variables.end()) // 둘째 항이 numeric일 때
		{
			SetResult(op0 * numeric_it[1]->second);
		}
		else if ((string_it[1] = string_variables.find(key1)) != string_variables.end()) // 둘째 항이 string일 때
		{
			throw CannotCalculateError;
		}
	}
	else if ((numeric_it[0] = numeric_variables.find(key1)) != numeric_variables.end()) // 첫째 항이 numeric일 때
	{
		float &op0 = numeric_it[0]->second;
		if ((matrix_it[1] = matrix_variables.find(key1)) != matrix_variables.end()) // 둘째 항이 matrix일 때
		{
			SetResult(op0 * matrix_it[1]->second);
		}
		else if ((numeric_it[1] = numeric_variables.find(key1)) != numeric_variables.end()) // 둘째 항이 numeric일 때
		{
			SetResult(op0 * numeric_it[1]->second);
		}
		else if ((string_it[1] = string_variables.find(key1)) != string_variables.end()) // 둘째 항이 string일 때
		{
			SetResult(op0 * string_it[1]->second);
		}
	}
	else if ((string_it[0] = string_variables.find(key1)) != string_variables.end()) // 첫째 항이 string일 때
	{
		string &op0 = string_it[0]->second;
		if ((matrix_it[1] = matrix_variables.find(key1)) != matrix_variables.end()) // 둘째 항이 matrix일 때
		{
			throw CannotCalculateError;
		}
		else if ((numeric_it[1] = numeric_variables.find(key1)) != numeric_variables.end()) // 둘째 항이 numeric일 때
		{
			SetResult(op0 * numeric_it[1]->second);
		}
		else if ((string_it[1] = string_variables.find(key1)) != string_variables.end()) // 둘째 항이 string일 때
		{
			throw CannotCalculateError;
		}
	}
}

void Calculator::Div(std::string key1, std::string key2)
{
	map<string, Matrix>::iterator matrix_it[2];
	map<string, float>::iterator numeric_it[2];
	map<string, string>::iterator string_it[2];
	if ((matrix_it[0] = matrix_variables.find(key1)) != matrix_variables.end()) // 첫째 항이 matrix일 때
	{
		Matrix &op0 = matrix_it[0]->second;
		if ((matrix_it[1] = matrix_variables.find(key1)) != matrix_variables.end()) // 둘째 항이 matrix일 때
		{
			throw CannotCalculateError;
		}
		else if ((numeric_it[1] = numeric_variables.find(key1)) != numeric_variables.end()) // 둘째 항이 numeric일 때
		{
			SetResult(op0 / numeric_it[1]->second);
		}
		else if ((string_it[1] = string_variables.find(key1)) != string_variables.end()) // 둘째 항이 string일 때
		{
			throw CannotCalculateError;
		}
	}
	else if ((numeric_it[0] = numeric_variables.find(key1)) != numeric_variables.end()) // 첫째 항이 numeric일 때
	{
		float &op0 = numeric_it[0]->second;
		if ((matrix_it[1] = matrix_variables.find(key1)) != matrix_variables.end()) // 둘째 항이 matrix일 때
		{
			SetResult(op0 / matrix_it[1]->second);
		}
		else if ((numeric_it[1] = numeric_variables.find(key1)) != numeric_variables.end()) // 둘째 항이 numeric일 때
		{
			SetResult(op0 / numeric_it[1]->second);
		}
		else if ((string_it[1] = string_variables.find(key1)) != string_variables.end()) // 둘째 항이 string일 때
		{
			throw CannotCalculateError;
		}
	}
	else if ((string_it[0] = string_variables.find(key1)) != string_variables.end()) // 첫째 항이 string일 때
	{
		string &op0 = string_it[0]->second;
		if ((matrix_it[1] = matrix_variables.find(key1)) != matrix_variables.end()) // 둘째 항이 matrix일 때
		{
			throw CannotCalculateError;
		}
		else if ((numeric_it[1] = numeric_variables.find(key1)) != numeric_variables.end()) // 둘째 항이 numeric일 때
		{
			throw CannotCalculateError;
		}
		else if ((string_it[1] = string_variables.find(key1)) != string_variables.end()) // 둘째 항이 string일 때
		{
			throw CannotCalculateError;
		}
	}
}

void Calculator::EditValue(std::string key, int row, int col, float value)
{
	matrix_variables.find(key)->second.setValue(row, col, value);
}

void Calculator::EditValue(std::string key, float value)
{
	numeric_variables.find(key)->second = value;
}

void Calculator::EditVAlue(std::string key, std::string value)
{
	string_variables.find(key)->second = value;
}



QString Calculator::GetInfo(std::string key) const
{
	map<string, Matrix>::const_iterator matrix_it;
	map<string, float>::const_iterator numeric_it;
	map<string, string>::const_iterator string_it;
	if (matrix_variables.end() != (matrix_it = matrix_variables.find(key)))
	{
		int rows = matrix_it->second.Rows();
		int cols = matrix_it->second.Cols();
		return QString("Type = Matrix / Rows = %d / Comums = %d").arg(rows, cols);
	}
	if (numeric_variables.end() != (numeric_it = numeric_variables.find(key)))
	{
		return QString("Type = Numeric");
	}
	if (string_variables.end() != (string_it = string_variables.find(key)))
	{
		return QString("Type = String");
	}
}

QString Calculator::GetVarialbeValue(std::string key) const
{
	map<string, Matrix>::const_iterator matrix_it;
	map<string, float>::const_iterator numeric_it;
	map<string, string>::const_iterator string_it;
	set<QString> result;
	
	matrix_it = matrix_variables.find(key);
	if (matrix_it != matrix_variables.end())
	{
		return matrix_it->second.to_QString();
	}
	else
	{
		numeric_it = numeric_variables.find(key);
		if (numeric_it != numeric_variables.end())
		{
			return QString::number(numeric_it->second);
		}
		else
		{
			string_it = string_variables.find(key);
			if (string_it != string_variables.end())
			{
				return QString::fromStdString(string_it->second);
			}
			else
			{
				return QString();
			}
		}
	}
}

QStringList Calculator::getVariableNameList() const
{
	map<string, Matrix>::const_iterator matrix_it;
	map<string, float>::const_iterator numeric_it;
	map<string, string>::const_iterator string_it;
	QStringList result;

	for (matrix_it = matrix_variables.begin(); matrix_it != matrix_variables.end(); matrix_it++)
	{
		result << QString::fromStdString(matrix_it->first);
	}
	for (numeric_it = numeric_variables.begin(); numeric_it != numeric_variables.end(); numeric_it++)
	{
		result << QString::fromStdString(numeric_it->first);
	}
	for (string_it = string_variables.begin(); string_it != string_variables.end(); string_it++)
	{
		result << QString::fromStdString(string_it->first);
	}
	result.sort();
	return result;
}

