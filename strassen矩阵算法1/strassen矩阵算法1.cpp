#include "stdafx.h"
#include<iostream>
using namespace std;
#include<vector>
using std::vector;
//useless comment
struct matrix
{
	size_t row = 0;
	size_t column = 0;
	vector<double> mtx;
	//输出矩阵
	void print_matrix() const;
	void ones(size_t i);
	void zeros(size_t i); 
	void rand(size_t i);
};
//复杂度为N^3的矩阵乘法
matrix multi_N3(matrix &a, matrix &b);
//a=a-b,return a-b;
matrix sub_m1(matrix &a, matrix &b);
//a=a,return a-b;
matrix sub_m2(matrix a, matrix &b);
//全1
void matrix::ones(size_t i=1) 
{
	row = i;
	column = i;
	i = i*i;
	for (size_t j = 0; j < i; j++)
		mtx.push_back(1);
}
//全0
void matrix::zeros(size_t i=1)
{
	row = i;
	column = i;
	i = i*i;
	for (size_t j = 0; j < i; j++)
		mtx.push_back(0);
}
//随机生成矩阵
void matrix::rand(size_t i=1)
{
	row = i;
	column = i;
	i = i*i;
	for (size_t j = 0; j < i; j++)
		mtx.push_back(std::rand()%100);
}
//输出矩阵
void matrix::print_matrix() const 
{
	cout << endl;
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < column; j++)
		{
			cout << mtx[i*column + j] << ' ';
		}
		cout << endl;
	}
}
//a=a,return a-b;
matrix sub_m2(matrix a, matrix &b)
{
	if (a.column != b.column || a.row != b.row)
		cerr << "invalid operation" << endl;
	for (size_t i = 0; i < a.column*a.row; i++)
	{
		a.mtx[i] -= b.mtx[i];
	}
	return a;
}
//复杂度为N^3的矩阵乘法
matrix multi_N3(matrix &a, matrix &b)
{
	if (a.column != b.row)
		cerr << "can't multiply" << endl;
	matrix ans;
	ans.row = a.row;
	ans.column = b.column;
	for (size_t i = 0; i < ans.row; i++)
	{
		for (size_t j = 0; j < ans.column; j++)
		{
			ans.mtx.push_back(0);
		}
	}
	for (size_t i = 0; i < ans.row; i++)
	{
		for (size_t j = 0; j < ans.column; j++)
		{
			for (size_t k = 0;  k< a.column; k++)
			{
				ans.mtx[i*ans.column + j] += a.mtx[i*a.column + k] * b.mtx[k*b.column + j];
			}
		}
	}
	return ans;
}
//a=a-b
matrix sub_m1(matrix &a, matrix &b)
{
	if (a.column != b.column || a.row != b.row)
		cerr << "invalid operation" << endl;
	for (size_t i = 0; i < a.column*a.row; i++)
	{
		a.mtx[i] -= b.mtx[i];
	}
	return a;
}
int main()
{
	matrix a, b, d,e;
	a.rand(10);
	b.rand(10);
	d=sub_m2(a, b);
	e = d;
	e.mtx[0] = 10;
	d.print_matrix();
	e.print_matrix();
	//matrix c = multi_N3(a, b);
	//c.print_matrix();
    return 0;
}
