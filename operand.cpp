#include "operand.h"

using namespace std;

Matrix::Matrix()
	:rows(0), cols(0), data(nullptr)
{
}

Matrix::Matrix(int rows, int cols, int initial)
	: rows(rows), cols(cols)
{
	if (rows == 0 || cols == 0)
	{
		throw MatrixGenerationError;
	}
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

Matrix::Matrix(const Matrix &m)
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
	if ((cols != m.cols) || (rows != m.rows))
		throw CannotCalculateError;

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

Matrix Matrix::operator-(const Matrix &m) const
{
	if ((cols != m.cols) || (rows != m.rows))
		throw CannotCalculateError;

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

Matrix Matrix::operator*(const Matrix &m) const
{
	if (cols != m.rows)
		throw CannotCalculateError;

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

Matrix Matrix::operator+(float n) const
{
	Matrix result(*this);
	for (int i = 0; i < result.rows; i++)
		for (int j = 0; j < result.cols; j++)
			result.data[i][j] += n;
	return result;
}

Matrix Matrix::operator-(float n) const
{
	Matrix result(*this);
	for (int i = 0; i < result.rows; i++)
		for (int j = 0; j < result.cols; j++)
			result.data[i][j] -= n;
	return result;
}

Matrix Matrix::operator*(float n) const
{
	Matrix result(*this);
	for (int i = 0; i < result.rows; i++)
		for (int j = 0; j < result.cols; j++)
			result.data[i][j] *= n;
	return result;
}

Matrix Matrix::operator/(float n) const
{
	Matrix result(*this);
	for (int i = 0; i < result.rows; i++)
		for (int j = 0; j < result.cols; j++)
			result.data[i][j] /= n;
	return result;
}

float Matrix::operator()(int i, int j) const
{
	if (i < rows && j < cols)
	{
		return data[i][j];
	}
	else
	{
		throw CannotCalculateError;
	}
}

Matrix & Matrix::operator=(const Matrix &m)
{
	rows = m.rows;
	cols = m.cols;
	data = new float*[rows];
	for (int i = 0; i < rows; i++)
	{
		data[i] = new float[cols];
		for (int j = 0; j < cols; j++)
		{
			data[i][j] = m.data[i][j];
		}
	}
	return *this;
}

bool Matrix::setValue(int i, int j, float value)
{
	if (i < rows && i >= 0  && j >= 0 && j < cols)
	{
		data[i][j] = value;
		return true;
	}
	else
	{
		return false;
	}
}

int Matrix::Rows() const
{
	return rows;
}

int Matrix::Cols() const
{
	return cols;
}

QString Matrix::to_QString() const
{
	QString result;
	for (int i = 0; i < rows; i++)
	{
		result += "[";
		for (int j = 0; j < cols; j++)
		{
			result += QString("%1, ").arg(data[i][j]);
		}
		result += "]\n";
	}
	return result;
}

Matrix::Matrix(int rows, int cols)
	:rows(rows), cols(cols)
{
	data = new float*[rows];
	for (int i = 0; i < rows; i++)
	{
		data[i] = new float[cols];
	}
}

std::string operator+(const std::string & s, float n)
{
	return s + std::to_string(n);
}

std::string operator+(float n, const std::string & s)
{
	return std::to_string(n) + s;
}

std::string operator*(const std::string & s, float n)
{
	string result;
	for (int i = 0; i < n; i++)
	{
		result += s;
	}
	return result;
}

std::string operator*(float n, const std::string & s)
{
	return s * n;
}

Matrix operator+(float n, const Matrix &m)
{
	return m + n;
}

Matrix operator-(float n, const Matrix &m)
{
	return m - n;
}

Matrix operator*(float n, const Matrix &m)
{
	return m * n;
}

Matrix operator/(float n, const Matrix &m)
{
	return m / n;
}
