#include <iostream>
#include "Matrix.h"

int main()
{
	Matrix<int> mat1 = Matrix<int>(2, 3);
	mat1.MatRand();
	std::cout << 1 << 2 << mat1;
	Matrix<int> mat2 = Matrix<int>(2, 3);
	mat2.MatRand();
	Matrix<int> mat3 = Matrix<int>(3, 2);
	mat3.MatRand();
	Matrix<int> mat = mat1 + mat2;
	std::cout << mat;
	mat = mat1 + mat3;
	std::cout << mat;
	mat = mat1 * mat3;
	std::cout << mat;
}

