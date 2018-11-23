#include "operand.h"

using namespace op;
using namespace std;

Matrix::Matrix(int rows, int cols, int initial)
	:rows(rows), cols(cols)
{
	data = new float*[rows];
	for (int i = 0; i < rows; i++)
	{
		data[i] = new float[cols];
		for (int j = 0; j < cols; j++)
		{
			data[i][j] = initial;
		}
	}
}

op::Matrix::Matrix(const Matrix &m)
	:rows(m.rows), cols(m.cols)
{
	data = new float*[rows];
	for (int i = 0; i < rows; i++)
	{
		data[i] = new float[cols];
		for (int j = 0; j < cols; j++)
		{
			data[i][j] = m.data[i][j];
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete data[i];
	}
	delete data;
}

Matrix Matrix::operator+(const Matrix &m) const
{
	if ((cols == m.cols) && (rows == m.rows))
	{
		Matrix result(rows, cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				result.data[i][j] = data[i][j] + m.data[i][j];
			}
		}
		return result;
	}
	else
	{
		throw SameTypeError;
	}
}

Matrix op::Matrix::operator-(const Matrix &m) const
{
	if ((cols == m.cols) && (rows == m.rows))
	{
		Matrix result(rows, cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				result.data[i][j] = data[i][j] - m.data[i][j];
			}
		}
		return result;
	}
	else
	{
		throw SameTypeError;
	}
}

Matrix op::Matrix::operator*(const Matrix &m) const
{
	if (cols == m.rows)
	{
		Matrix result(rows, m.cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < m.cols; j++)
			{
				float result_ij = 0;
				for (int k = 0; k < cols; k++)
				{
					result_ij += data[i][k] * m.data[k][j];
				}
				m.data[i][j] = result_ij;
			}
		}
		return result;
	}
	else
	{
		throw SameTypeError;
	}
}

float op::Matrix::operator()(int i, int j) const
{
	if (i < rows && j < cols)
	{
		return data[i][j];
	}
	else
	{
		throw SameTypeError;
	}
}

void op::Matrix::setValue(int i, int j, float value)
{
	if (i < rows && j < cols)
	{
		data[i][j] = value;
	}
	else
	{
		throw SameTypeError;
	}
}

op::Matrix::Matrix(int rows, int cols)
	:rows(rows), cols(cols)
{
	data = new float*[rows];
	for (int i = 0; i < rows; i++)
	{
		data[i] = new float[cols];
	}
}

std::string op::operator+(const std::string & s, float n)
{
	return std::string(s) + to_string(n);
}

std::string op::operator+(float n, const std::string & s)
{
	return to_string(n) + std::string(s);
}

Matrix op::operator+(const Matrix & m, float n)
{
	Matrix result(m);
	for (int i = 0; i < result.rows; i++)
		for (int j = 0; j < result.cols; j++)
			result.data[i][j] += n;
	return result;
}

Matrix op::operator-(const Matrix & m, float n)
{
	Matrix result(m);
	for (int i = 0; i < result.rows; i++)
		for (int j = 0; j < result.cols; j++)
			result.data[i][j]-= n;
	return result;
}

Matrix op::operator*(const Matrix & m, float n)
{
	Matrix result(m);
	for (int i = 0; i < result.rows; i++)
		for (int j = 0; j < result.cols; j++)
			result.data[i][j] *= n;
	return result;
}

Matrix op::operator/(const Matrix & m, float n)
{
	Matrix result(m);
	for (int i = 0; i < result.rows; i++)
		for (int j = 0; j < result.cols; j++)
			result.data[i][j] /= n;
	return result;
}
