#pragma once

#include <iostream>
#include <time.h>

using namespace std;
template <typename T>
class Matrix 
{
public:
	int n;
	int m;
	T** data;
	Matrix(int n,int m)
	{
		data = (T**)malloc(n * sizeof(T*));
		for (int i = 0; i < n; i++)
			data[i] = (T*)malloc(m * sizeof(T));
		Matrix::m = m;
		Matrix::n = n;
	}
	void MatRand()
	{
		srand(time(0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				data[i][j] = rand()%1000;
	}
	friend std::ostream& operator<<(std::ostream &out, const Matrix& mat)
	{
		
		for (int i = 0; i < mat.n; i++)
		{
			cout << "\n";
			for (int j = 0; j < mat.m; j++)
				cout << mat.data[i][j] << " ";
		}
		return out;
	}
	friend const Matrix operator+ (const Matrix& l, const Matrix& r)
	{
		
		try
		{
			if ((l.n != r.n) || (l.m != r.m))
				throw "Matrix's sizes doesn't match";
			Matrix<T> result = Matrix<T>(l.n, l.m);
				
				for (int i = 0; i < l.n; i++)
					for (int j = 0; j < l.m; j++)
						result.data[i][j] = l.data[i][j] + r.data[i][j];
				return result;

		}
		catch (const char* ex)
		{
			cerr<< "\n Error:" << ex;
			return Matrix<T>(l.n, l.m);
		}
		

	}
	friend const Matrix operator* (const Matrix& l, const Matrix& r)
	{
		try 
		{
			if ((l.n != r.m))
				throw "Matrix's sizes doesn't match";
			Matrix<T> result = Matrix<T>(l.m, r.n);
			for (int i = 0; i < result.n; i++)
				for (int j = 0; j < result.m; j++)
					for (int k=0; k < l.n;k++)
							result.data[i][j] += l.data[k][j] * r.data[i][k];
			return result;
		}
		catch (const char* ex)
		{
			cerr << "\n Error:" << ex;
			return Matrix<T>(l.n, l.m);
		}
	}
};
