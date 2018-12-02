#ifndef OPERAND_H
#define OPERAND_H

#include <string>
#include <QString>

class Matrix;

Matrix operator+(float n, const Matrix &m);
Matrix operator-(float n, const Matrix &m);
Matrix operator*(float n, const Matrix &m);
Matrix operator/(float n, const Matrix &m);
std::string operator*(const std::string &s, float n);
std::string operator*(float n, const std::string &s);
std::string operator+(const std::string &s, float n);
std::string operator+(float n, const std::string &s);


enum exceptions
{
	MatrixGenerationError = 32,
	CannotCalculateError = 64	//연산이 불가능할때
};

struct Matrix_meta
{
	std::string name;
	int rows;
	int cols;
	float init_value;
};

class Matrix
{
public:
	Matrix operator+(const Matrix&) const;
	Matrix operator-(const Matrix&) const;
	Matrix operator*(const Matrix&) const;
	Matrix operator+(float n) const;
	Matrix operator-(float n) const;
	Matrix operator*(float n) const;
	Matrix operator/(float n) const;

	Matrix();
	Matrix(int rows, int cols, int initial);
	Matrix(const Matrix&);
	~Matrix();
	float operator()(int i, int j) const;
	Matrix& operator=(const Matrix&);
	bool setValue(int i, int j, float value);
	int Rows() const;
	int Cols() const;
	QString to_QString() const;
private:
	Matrix(int rows, int cols);
	float **data;
	int rows;
	int cols;
};


#endif // !OPERAND_H
