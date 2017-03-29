
//18. �������� ������ ������ ����� �� �������� ������������� � ������������ �����. A) ������ (std::vector) 
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
		cout << "Введите целое число М (M > 0)" << endl;
		cin >> M;
		if (M < 1)
		{
			int choice = 1;
			cout << "Ошибка! Число должно быть больше 0" << endl;
			cout << "1 - Повторить попытку" << endl;
			cout << "2 - Выход в главное меню" << endl;
			cin >> choice;
			if (choice == 2) return false;
		}
	}

	while (N <= 0)
	{
		cout << "Введите целое число N (N > 0)" << endl;
		cin >> N;
		if (N < 1)
		{
			int choice = 1;
			cout << "Ошибка! Число должно быть больше 0" << endl;
			cout << "1 - Повторить попытку" << endl;
			cout << "2 - Выход в главное меню" << endl;
			cin >> choice;
			if (choice == 2) return false;
		}
	}

	cout << "Введите имя файла" << endl;
	cin >> fileName;

	while (fileName == "")
	{
		cout << "Введите имя файла для заполнения" << endl;
		cin >> fileName;
		if (fileName == "")
		{
			int choice = 1;
			cout << "Ошибка! Имя файла должно быть непустым" << endl;
			cout << "1 - Повторить попытку" << endl;
			cout << "2 - Выход в главное меню" << endl;
			cin >> choice;
			if (choice == 2) return false;
		}
	}
	return true;
}
void askForFileName(string& fileName) {
	fileName = "";
	while (fileName == "") {
		cout << "Введите имя файла" << endl;
		cin >> fileName;
	}
}

/*  TO BE CHANGED  */

vector<int> getContainer(ifstream& fin)    
{
	vector<int> v;
	if (!fin.is_open()) // если файл не открыт
	{
		cout << "Файл не может быть открыт!\n"; // сообщить об этом
		//v.erase(v.begin(), v.end()); 
	} 
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

bool isEmpty (vector<int> v)
{
	if (v.empty()) {
		cout << "Контейнер пуст" << endl;
		return true;
	}
	return false;		
}

ofstream fillFileRandomCycle(int M, int N, string fileName)
{
	ofstream output(fileName.c_str());

	for (int i = 0; i < N; i++) {
		output << -M + rand() % M << endl;
	}

	return output;
}

struct randNumFromSegment {
	randNumFromSegment(int x) :m(x) {};
	int operator()(){
		return rand() % (2 * m + 1) - m;
	}
	int m;
};

ofstream fillFileRandomGenerate(int M, const int N, string fileName)
{
	vector<int> v(N);
	ofstream output;
	output.open(fileName);
	generate(v.begin(), v.end(), randNumFromSegment(M));	
	
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

void getRange(vector<int> v, int &a, int &b) {
	a = -1;
	b = 0;
	cout << "Введите левую границу" << endl;
	while ((a < 0) || (a >= v.size()))
	{
		cin >> a;
		if ((a < 0) || (a >= v.size()))
			cout << "Число должно быть больше 0! Повторите ввод" << endl;
		else if (a >= v.size())
			cout << "Число превышает размер вектора (" << v.size() << ")! Повторите ввод" << endl;	
	}		
	
	cout << "Введите правую границу" << endl;
	cin >> b;
	while ((b < 0) || (b >= v.size()) || (b < a)) 
	{
		cin >> a;
		if ((b < 0) || (b >= v.size()))
			cout << "Число должно быть не меньше 0! Повторите ввод" << endl;
		else if (b >= v.size())
			cout << "Число вне диапазона (0.." << v.size()-1 << ")! Повторите ввод" << endl;
		else if (b < a)
			cout << "Число должно быть не меньше левой границы (" << a << ")! Повторите ввод" << endl;
	}
}

void getToElems(vector<int>::iterator &left, vector<int>::iterator &right, int a, int b) {
	for (int i = 0; i < a; i++)
		left++;
	for (int i = 0; i < b; i++)
		right++;
}

vector<int> modify(vector<int>::iterator first, vector<int>::iterator last) {
	int diff = findNumDifference(first, last);
	vector<int> v(first, last);
	int i = 0;
	for (unsigned i = 0; i < v.size(); ++i) {
		if (v[i] % 2 == 0)
			v[i] = diff;
	}

	return v;
}

struct returnNum {
	returnNum(){};
	int operator()(int num) {
		return num;
	}
};

vector<int> replaceForEach(vector<int> v)
{
	int diff = findNumDifference(v);

	for_each(v.begin(), v.end(), returnNum());  //Can be replaced with returnIfOdd?

	return v;
}

struct returnIfOdd {
	returnIfOdd(int x) :m(x) {};
	int operator()(int& n) {
		if (n % 2 == 0) {
			return m;
		};
		return n;
	}
	int m;
};

vector<int> replaceTransform(vector<int> v) {
	int diff = findNumDifference(v);
	vector<int> diffV(v.size());
	for (unsigned i = 0; i < diffV.size(); i++)
		diffV[i] = diff;

	transform(v.begin(), v.end(), diffV.begin(), returnIfOdd(diff));

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

void printToScreen(vector<int>::iterator first, vector<int>::iterator last)
{
	while (first++ != last)
	{
		cout << *first << "  ";
	}
}

void printToFile(vector<int> v)
{
	ofstream fout;
	string fileName = "";
	askForFileName(fileName);
	fout.open(fileName); 
	for (unsigned i = 0; i < v.size(); i++)
		fout << v.at(i) << "  " << endl;
	fout.close();
}

void printResult(vector<int> v, vector<int> vMod)
{
	cout << "/nИсходный вектор: " << endl;
	printToScreen(v);
	cout << "/nИзмененный вектор: " << endl;
	printToScreen(vMod);
}

void printResult(vector<int>::iterator first, vector<int>::iterator last, vector<int> vMod)
{
	cout << "/nИсходный вектор: " << endl;
	printToScreen(first, last);
	cout << "/nИзмененный вектор: " << endl;
	printToScreen(vMod);
}

void printMenu()
{
	int option = 0;
	int M = 0, N = 0;
	string fileName = "";
	ifstream fin;
	vector<int> v, modifiedV;
	vector<int>::iterator left = v.begin();
	vector<int>::iterator right = v.begin();
	while (option != 10)
	{
		cout << "\n";
		cout << "\n1. Заполнить файл рандомными числами\n";
		cout << "2. Загрузить элементы из файла\n";
		cout << "3. Преобразовать контейнер\n";
		cout << "4. Преобразовать часть контейнера\n";
		cout << "5. Преобразование с transform\n";
		cout << "6. Преобразование с for_each\n";
		cout << "7. Вычислить сумму элементов\n";  
		cout << "8. Вычислить среднее арифметическое элементов\n";  
		cout << "9. Вывести результат\n"; 
		cout << "10. Выход\n";
		cout << "\n";

		cin >> option;
		if (!(!((option == 1) || (option == 2) || (option == 10)) & isEmpty(v)))
		{
			modifiedV.clear();
			switch (option) {
			case 1:
				if (askForData(M, N, fileName))
					fillFileRandomCycle(M, N, fileName);
				break;
			case 2:
				v.clear();
				askForFileName(fileName);
				fin.open(fileName);
				v = getContainer(fin);
				break;
			case 3:
				modifiedV = modify(v);
				printResult(v, modifiedV);
				break;
			case 4:
				int a, b;
				getRange(v, a, b);

				left = right = v.begin();
				getToElems(left, right, a, b);

				modifiedV = modify(left, right);
				printResult(left, right, modifiedV);
				break;
			case 5:
				modifiedV = replaceTransform(v);
				printResult(v, modifiedV);
				break;
			case 6:
				modifiedV = replaceForEach(v);
				printResult(v, modifiedV);		
				break;
			case 7:
				cout << "Сумма элементов вектора - " << findSum(v) << endl;
				break;
			case 8:
				cout << "Среднее арифметическое элементов вектора - " << findAverage(v) << endl;
				break;
			case 9:
				cout << "Вывести результат на экран? 1 - Да, 2 - Нет " << endl;
				while (option != 1 || option != 2) {
					cin >> option;
					if (option == 1)
					{
						printToScreen(v);
						option = 9;
					}
					else if (option != 2) {
						cout << "Повторите ввод!" << endl;
					}
				}
				printToFile(v);
				break;
			case 10: 
				break;
			default: cout << "Ошибка! Повторите ввод" << endl;
			}
		}
	}
	fin.close();
	v.erase(v.begin(), v.end());
	modifiedV.erase(v.begin(), v.end());
}

int main()
{
	printMenu();
    return 0;
}

