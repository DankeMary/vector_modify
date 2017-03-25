// Vector_Modify.cpp: ���������� ����� ����� ��� ����������� ����������.
//18. �������� ������ ������ ����� �� �������� ������������� � ������������ �����. { A) ������ (std::vector)}
// ��������� : ���������� ����� ������������� (2�, 9�)

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


int findNumDifference(std::vector<int> v)
{
	int min = 0;
	int max = 0;
	for (unsigned i = 0; i < v.size(); ++i)
	{
		if (v[i] < min) {
			min = v[i];
		}
		else if (v[i] > max) {
			max = v[i];
		}
	}
	return (max - min);
}

int findSum(std::vector<int> v)
{
	int sum = 0;
	for (unsigned i = 0; i < v.size(); i++)
		sum += v.at(i);
	return sum;
}
int main()
{
    return 0;
}

