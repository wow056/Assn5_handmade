#ifndef OPERAND_H
#define OPERAND_H

#include <string>

namespace op
{
	std::string operator+(const std::string &s, float n);
	std::string operator+(float n, const std::string &s);

	enum exceptions
	{
		SameTypeError,		//���� Ÿ�԰��� ������ �Ұ����� ��
		DifferentTypeError	//�ٸ� Ÿ�԰��� ������ �Ұ����� ��
	};

	class Matrix
	{
		friend Matrix operator+(const Matrix &m, float n);
		friend Matrix operator-(const Matrix &m, float n);
		friend Matrix operator*(const Matrix &m, float n);
		friend Matrix operator/(const Matrix &m, float n);
	public:
		Matrix(int rows, int cols, int initial);
		Matrix(const Matrix&);
		~Matrix();

		Matrix operator+(const Matrix&) const;
		Matrix operator-(const Matrix&) const;
		Matrix operator*(const Matrix&) const;
		float operator()(int i, int j) const;
		void setValue(int i, int j, float value);
		
	private:
		Matrix(int rows, int cols);
		float **data;
		int rows;
		int cols;
	};
}

#endif // !OPERAND_H
