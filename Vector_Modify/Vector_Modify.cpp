// Vector_Modify.cpp: ���������� ����� ����� ��� ����������� ����������.
//18. �������� ������ ������ ����� �� �������� ������������� � ������������ �����. { A) ������ (vector)}
// ��������� : ���������� ����� ������������� (2�, 9�)

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;
bool askForData(int &M, int &N, string &fileName)  
{

	while (M <= 0)
	{
		cout << "������� ����� ����� � (M > 0)" << endl;
		cin >> M;
		if (M < 1)
		{
			int choice = 1;
			cout << "������! ����� ������ ���� ������ 0" << endl;
			cout << "1 - ��������� �������" << endl;
			cout << "2 - ����� � ������� ����" << endl;
			cin >> choice;
			if (choice == 2) return false;
		}
	}

	while (N <= 0)
	{
		cout << "������� ����� ����� N (N > 0)" << endl;
		cin >> N;
		if (N < 1)
		{
			int choice = 1;
			cout << "������! ����� ������ ���� ������ 0" << endl;
			cout << "1 - ��������� �������" << endl;
			cout << "2 - ����� � ������� ����" << endl;
			cin >> choice;
			if (choice == 2) return false;
		}
	}

	cout << "������� ��� �����" << endl;
	cin >> fileName;

	while (fileName == "")
	{
		cout << "������� ��� ����� ��� ����������" << endl;
		cin >> fileName;
		if (fileName == "")
		{
			int choice = 1;
			cout << "������! ��� ����� ������ ���� ��������" << endl;
			cout << "1 - ��������� �������" << endl;
			cout << "2 - ����� � ������� ����" << endl;
			cin >> choice;
			if (choice == 2) return false;
		}
	}
	return true;
}

/*  TO BE CHANGED  */
vector<int> getContainer(ifstream& fin)    
{
	vector<int> v;
	if (!fin.is_open()) // ���� ���� �� ������
	{cout << "���� �� ����� ���� ������!\n"; // �������� �� ����
		v.erase(v.begin(), v.end()); } 
	else
	{
		int a;

		while (fin >> a)
		{
			v.push_back(a);
		}
		getchar();

	}
	
	return v;
}

ofstream fillFileRandomCycle(int M, int N, string fileName)
{
	ofstream output(fileName.c_str());

	for (int i = 0; i < N; i++) {
		output << -M + rand() % M << endl;
	}

	return output;
}

/* CAUSES AN ERROR */
ofstream fillFileRandomGenerate(int M, const int N, string fileName)
{
	vector<int> v(N);
	ofstream output;
	output.open(fileName.c_str());
	generate(v.begin(), v.end(), (rand() % (2 * M + 1) - M));	
	
	for (int i = 0; i < N; i++) {
		output << v[i] << endl;
	}
	
	return output;  
}



int findNumDifference(vector<int> v)
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

int findNumDifference(vector<int>::iterator first, vector<int>::iterator last)
{
	int min = 0;
	int max = 0;
	while (first++ != last)
	{
		if (*first < min) {
			min = *first;
		}
		else if (*first > max) {
			max = *first;
		}
	}
	return (max - min);
}

vector<int> modify(vector<int> v)
{
	int diff = findNumDifference(v);
	for (unsigned i = 0; i < v.size(); i++)
		if (v[i] % 2 == 0) {
			v[i] = diff;
		}
	return v;
}

/*    TO BE CHANGED  */
vector<int> modify(vector<int>::iterator first, vector<int>::iterator last) {
	int diff = findNumDifference(first, last);
	vector<int> v;
	int count = 0;
	int i = 0;
	while (first-- != null) {  
		first--;
		count++;
	}

	while (i != count) {
		v.push_back(*first);
		first++;
	}

	while (first++ != last) {
		if (*first % 2 == 0) {
			*first = diff;
		}
		first++;
	}
	while (last++ != null) {
		v.push_back(*last);
		last++;
	}
	return v;  
}

int returnNum(int num) {
	return num;
}

/* CAUSES AN ERROR */
vector<int> replaceForEach(vector<int> v)
{
	int diff = findNumDifference(v);

	for_each(v.begin(), v.end(), returnNum(diff));

	return v;
}

int findSum(vector<int> v)
{
	int sum = 0;
	for (unsigned i = 0; i < v.size(); i++)
		sum += v.at(i);
	return sum;
}

double findAverage(vector<int> v)
{
	double average = 0;
	unsigned i = 0;

	for (i; i < v.size(); i++)
		average += v.at(i);
	average = average / i;
	return average;
}

void printToScreen(vector<int> v)
{
	for (unsigned i = 0; i < v.size(); i++)
		cout << v.at(i) << "  ";
}

void printToFile(vector<int> v)
{
	ofstream fout;
	string fileName = "";
	while (fileName == "") {
		cout << "������� ��� �����" << endl;
		cin >> fileName;
	}
	fout.open(fileName); 
	for (unsigned i = 0; i < v.size(); i++)
		fout << v.at(i) << "  ";
	fout.close();
}
void printResult(vector<int> v, vector<int> vMod)
{
	cout << "/n�������� ������: " << endl;
	printToScreen(v);
	cout << "/n���������� ������: " << endl;
	printToScreen(vMod);
}

/*    TO BE CHANGED  */
void printMenu()
{
	int option = 0;
	int M = 0, N = 0;
	string fileName = "";
	ifstream fin;
	//ofstream fout;
	vector<int> v, modifiedV;
	while (option != 10)
	{
		cout << "\n";
		cout << "\n1. ��������� ���� ���������� �������\n";
		cout << "2. ��������� ����� �� �����\n";
		cout << "3. ������������� ���������\n";
		cout << "4. ������������� ��������� � �����������\n";
		cout << "5. �������������� � transform\n";
		cout << "6. �������������� � for_each\n";
		cout << "7. ��������� ����� �����\n";  //  
		cout << "8. ��������� ������� �������������� �����\n";   //  
		cout << "9. ������� ���������\n"; //    Check emptiness!
		cout << "10. �����\n";
		cout << "\n";

		cin >> option;


		switch (option) {
		case 1:
			if (askForData(M, N, fileName))
				fillFileRandomCycle(M, N, fileName);
			break;
		case 2:
			v = getContainer(fin);
			break;
		case 3:
			if (v.empty()) {
				cout << "��������� ����" << endl;
			} else
				modifiedV = modify(v);
			break;
		case 4:
			modifiedV = modify(v.begin(), v.end());
			break;
		case 5:
			//modifiedV = replaceTransform(v);
			break;
		case 6:
			modifiedV = replaceForEach(v);
			break;
		case 7:
			cout << "����� ��������� ������� - " << findSum(v) << endl;
			break;
		case 8:
			cout << "������� �������������� ��������� ������� - " << findAverage(v) << endl;
			break;
		case 9:
			cout << "������� ��������� �� �����? 1 - ��, 2 - ��� " << endl;
			cin >> option;
			if (option == 1)
			{
				printToScreen(v);
				option = 9;
			}
			printToFile(v);
			break;
		case 10:;
		default: cout << "������! ��������� ����" << endl;
		}
	}
}

int main()
{
    return 0;
}

