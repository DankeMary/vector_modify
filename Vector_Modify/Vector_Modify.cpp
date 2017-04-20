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

void askForFileName(string& fileName) {
	fileName = "";
	cout << "Введите имя файла" << endl;
	while (fileName == "") {
		getline(cin, fileName);
		if (fileName == "")
		{
			cout << "Ошибка! Имя файла должно быть непустым. Повторите ввод" << endl;
		}
	}
}
bool askForData(int &M, int &N, string &fileName)  
{
	string str;
	bool flag;
	M = N = 0;
	cout << "Введите целое число М (M > 0)" << endl;
	while (M <= 0)
	{
		flag = true;
		try {
			getline(cin, str);
			M = stoi(str);
		}
		catch (std::invalid_argument e) { 
			cout << "Введен неверный символ! " << endl;
			flag = false;
		}		
		
		if (flag && (M < 1))
		{
			cout << "Ошибка! Число должно быть больше 0.Повторите ввод" << endl;
		}
	}
	cout << "Введите целое число N (N > 0)" << endl;
	while (N <= 0)
	{		
		flag = true;
		try {
			getline(cin, str);
			N = stoi(str);
		}
		catch (std::invalid_argument e) {
			cout << "Введен неверный символ! Повторите ввод" << endl;
			flag = false;
		}
		
		if (flag && (N < 1))
		{
			cout << "Ошибка! Число должно быть больше 0" << endl;
		}
	}

	askForFileName(fileName);
	return true;
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
	int min = v.at(0);
	int max = v.at(0);
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
	int min = *first;
	int max = *first;
	do
	{
		if (*first < min) {
			min = *first;
		}
		else if (*first > max) {
			max = *first;
		}
		first++;
	} while (first != last);
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
	string str;
	bool in = false;
	a = -1;
	cout << "Введите левую границу" << endl;
	while ((a < 0) || (a >= v.size()))
	{		
		in = false;
		while (!in)
		{			
			try {
				getline(cin, str);
				a = stoi(str);
				in = true;
			}
			catch (std::invalid_argument e) {
				cout << "Введен неверный символ! Повторите ввод" << endl;
			}
		}	
		if (a < 0)
			cout << "Число должно быть не меньше 0! Повторите ввод" << endl;
		else if (a >= v.size())
			cout << "Число превышает размер вектора (" << v.size() << ")! Повторите ввод" << endl;
		else in = true;
	}	
	
	b = -1;
	cout << "Введите правую границу" << endl;	
	while ((b >= v.size()) || (b < a)) 
	{
		in = false;
		while (!in)
		{
			try {
				getline(cin, str);
				b = stoi(str);
				in = true;
			}
			catch (std::invalid_argument e) {
				cout << "Введен неверный символ! Повторите ввод" << endl;
			}
		}
		if (b >= v.size())
			cout << "Число вне диапазона (0.." << v.size()-1 << ")! Повторите ввод" << endl;
		else if (b < a)
			cout << "Число должно быть больше левой границы (" << a << ")! Повторите ввод" << endl;
		else in = true;
	}
}

void getToElems(vector<int>::iterator &left, vector<int>::iterator &right, int a, int b) {
	for (int i = 0; i < a; i++)
		left++;
	for (int i = 0; i <= b; i++)
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
	int operator()(int n) {
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
	string str;
	fstream f;

	vector<int> v, modifiedV;
	vector<int>::iterator left = v.begin();
	vector<int>::iterator right = v.begin();
	while (option != 11)
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
		cout << "9. Вывести результат на экран\n";
		cout << "10. Вывести результат в файл\n";
		cout << "11. Выход\n";
		cout << "\n";

		option = 0;
		while (option == 0)
		{
			try {
				getline(cin, str);
				option = stoi(str);
			}
			catch (std::invalid_argument e) {
				cout << "Введен неверный символ! Повторите ввод" << endl;
			}
		}
		switch (option) {
		case 1://Заполнить файл рандомными числами
			cout << "Заполнить с помощью : 1 - цикла, 2 - алгоритма : " << endl;
			
			option = 0;
			
			while (option == 0)
			{
				try {
					do {
						getline(cin, str);
						option = stoi(str);
						if (option != 1 && option != 2) {
							cout << "Введено неверное число! Повторите ввод" << endl;
						}
					} while (option != 1 && option != 2);
				}
				catch (std::invalid_argument e) {
					cout << "Введен неверный символ! Повторите ввод" << endl;
					option = 0;
				}
			}
			
			if ((option == 1) && askForData(M, N, fileName))
				f = fillFileRandomCycle(M, N, fileName);
			if ((option == 2) && askForData(M, N, fileName))
				f = fillFileRandomGenerate(M, N, fileName);
			f.close();
			option = 1;
			break;
		case 2://Загрузить элементы из файла			
			askForFileName(fileName);
			f.open(fileName, ios::in);
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
		case 9://Вывести результат на экран
			if (!isEmpty(v)) {
				if (modifiedV.empty())
					modifiedV = v;								
				printToScreen(modifiedV);
				cout << "\n" ;					
			}
			break;
		case 10: //Вывести результат в файл
			if (!isEmpty(v)) 
				printToFile(modifiedV);
			break;
		case 11: //Выход
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

