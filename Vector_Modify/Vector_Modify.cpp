// Vector_Modify.cpp: определяет точку входа для консольного приложения.
//18. Заменить каждое четное число на разность максимального и минимального чисел. { A) вектор (vector)}
// Выполнила : Лактионова Мария Александровна (2к, 9г)

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
	string str;
	M = N = 0;
	while (M <= 0)
	{
		cout << "Введите целое число М (M > 0)" << endl;
		//cin >> M;
		getline(cin, str);
		while (M == 0)
		{
			try {
				getline(cin, str);
				M = stoi(str);
			}
			catch (std::invalid_argument e) {
				cout << "Введен неверный символ! Повторите ввод" << endl;
			}
		}
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
		//cin >> N;
		//getline(cin, str);
		while (N == 0)
		{
			try {
				getline(cin, str);
				N = stoi(str);
			}
			catch (std::invalid_argument e) {
				cout << "Введен неверный символ! Повторите ввод" << endl;
			}
		}
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
			int choice = 0;
			cout << "Ошибка! Имя файла должно быть непустым" << endl;
			cout << "1 - Повторить попытку" << endl;
			cout << "2 - Выход в главное меню" << endl;
			getline(cin, str);
			while (choice == 0)
			{
				try {
					getline(cin, str);
					choice = stoi(str);
				}
				catch (std::invalid_argument e) {
					cout << "Введен неверный символ! Повторите ввод" << endl;
				}
			}
			//cin >> choice;
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

vector<int> getContainer(fstream& fin)    
{
	vector<int> v;
	if (!fin.is_open()) 
	{
		cout << "Файл не может быть открыт!\n"; 
	} 
	else
	{
		int a;

		while (fin >> a)
		{
			v.push_back(a);
		}
		getchar();
		fin.close();
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

fstream fillFileRandomCycle(int M, int N, string fileName)
{
	fstream output(fileName, ios::out);

	for (int i = 0; i < N; i++) {
		output << rand() % (2 * M + 1) + (-M) << endl;
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

fstream fillFileRandomGenerate(int M, const int N, string fileName)
{
	vector<int> v(N);
	fstream output;
	output.open(fileName, ios::out);
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
//!!!!!!!!!!!!!!!!!!!!!
int findNumDifference(vector<int>::iterator first, vector<int>::iterator last)
{
	int min = *first;
	int max = *first;
	last++;
	while (first != last)
	{
		if (*first < min) {
			min = *first;
		}
		else if (*first > max) {
			max = *first;
		}
		first++;
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
//*
void getRange(vector<int> v, int &a, int &b) {
	a = -1;
	b = -1;
	string str;
	
	cout << "Введите левую границу" << endl;
	while ((a < 0) || (a >= v.size()))
	{
		getline(cin, str);
		while (a == -1)
		{			
			try {
				getline(cin, str);
				a = stoi(str);
			}
			catch (std::invalid_argument e) {
				cout << "Введен неверный символ! Повторите ввод" << endl;
			}
		}	
		if (a < 0)
			cout << "Число должно быть больше 0! Повторите ввод" << endl;
		else if (a >= v.size())
			cout << "Число превышает размер вектора (" << v.size() << ")! Повторите ввод" << endl;
	}		
	
	cout << "Введите правую границу" << endl;	
	while ((b >= v.size()) || (b < a)) 
	{
		while (b == -1)
		{
			try {
				getline(cin, str);
				b = stoi(str);
			}
			catch (std::invalid_argument e) {
				cout << "Введен неверный символ! Повторите ввод" << endl;
			}
		}
		if (b < 0)
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

void modify(vector<int>::iterator first, vector<int>::iterator last) {
	int diff = findNumDifference(first, last);
	int i = 0;

	do {
		if (*first % 2 == 0)
			*first = diff;
		first++;
	} while (first != last);	
}

struct changeIfEven {
	changeIfEven(int x) :m(x) {};
	void operator()(int& n) {
		if (n % 2 == 0) 
			n = m;
	}
	int m;
};

struct replaceIfEven {
	replaceIfEven(int x) :m(x) {};
	int operator()(int& n) {
		if (n % 2 == 0) {
			return m;
		};
		return n;
	}
	int m;
};

vector<int> replaceForEach(vector<int> v)
{
	int diff = findNumDifference(v);

	for_each(v.begin(), v.end(), changeIfEven(diff)); 

	return v;
}

vector<int> replaceTransform(vector<int> v) {
	int diff = findNumDifference(v);
	
	transform(v.begin(), v.end(), v.begin(), replaceIfEven(diff));

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
	fstream fout;
	string fileName = "";
	askForFileName(fileName);
	fout.open(fileName, ios::out);
	for (unsigned i = 0; i < v.size(); i++)
		fout << v.at(i) << "  " << endl;
	fout.close();
}

void printResult(vector<int> v, vector<int> vMod)
{
	cout << "\nИсходный вектор: " << endl;
	printToScreen(v);
	cout << "\nИзмененный вектор: " << endl;
	printToScreen(vMod);
}

void printMenu()
{
	int option = 0;
	int M, N;
	string fileName = "";
	fstream f;

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
		
		switch (option) {
		case 1://Заполнить файл рандомными числами
			cout << "Заполнить с помощью : 1 - цикла, 2 - алгоритма : ";
			cin >> option;

			if ((option == 1) && askForData(M, N, fileName))
				f = fillFileRandomCycle(M, N, fileName);
			if ((option == 2) && askForData(M, N, fileName))
				f = fillFileRandomGenerate(M, N, fileName);
			f.close();
			option = 1;
			break;
		case 2://Загрузить элементы из файла
			v.clear();
			if (fileName == "") 
				askForFileName(fileName);
			f.open(fileName);
			v = getContainer(f);
			modifiedV.clear();
			modifiedV = v;
			f.close();
			break;
		case 3://Преобразовать контейнер
			if (!isEmpty(v)) {
				modifiedV.clear();
				modifiedV = modify(v);
				printResult(v, modifiedV);
			}
				
			break;
		case 4://Преобразовать часть контейнера
			int a, b;
			if (!isEmpty(v)) {
				getRange(v, a, b);
				modifiedV = v;
				left = right = modifiedV.begin();
				getToElems(left, right, a, b);

				//modifiedV.clear();  ???
				
				modify(left, right);
				printResult(v, modifiedV);
			}
			break;
		case 5://Преобразование с transform
			if (!isEmpty(v)) {
				modifiedV.clear();
				modifiedV = replaceTransform(v);
				printResult(v, modifiedV);
			}
			break;
		case 6://Преобразование с for_each
			if (!isEmpty(v)) {
				modifiedV.clear();
				modifiedV = replaceForEach(v);
				printResult(v, modifiedV);
			}
			break;
		case 7://Вычислить сумму элементов
			if (!isEmpty(v)) {
				printToScreen(v);
				cout << "\nСумма элементов вектора - " << findSum(v) << endl;
			}
			break;
		case 8://Вычислить среднее арифметическое элементов
			if (!isEmpty(v)) {
				printToScreen(v);
				cout << "\nСреднее арифметическое элементов вектора - " << findAverage(v) << endl;
			}
			break;
		case 9://Вывести результат
			if (!isEmpty(v)) {
				if (modifiedV.empty())
					modifiedV = v;
				cout << "Вывести результат на экран? 1 - Да, 2 - Нет " << endl;
				while (option != 1 && option != 2) {
					cin >> option;
					if (option == 1)
					{						
						printToScreen(modifiedV);
						cout << "\n" ;
					}
					else if (option != 2) {
						cout << "Повторите ввод!" << endl;
					}
				}
				option = 9;
				printToFile(modifiedV);
			}
			break;
		case 10: //Выход
			break;		
		default: cout << "Ошибка! Повторите ввод" << endl;
		
		}
	}
	v.erase(v.begin(), v.end());
	modifiedV.erase(modifiedV.begin(), modifiedV.end());
}

int main()
{
	setlocale(LC_ALL, "Russian");
	printMenu();
    return 0;
}

