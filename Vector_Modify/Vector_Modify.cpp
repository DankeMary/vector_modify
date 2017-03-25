// Vector_Modify.cpp: определяет точку входа для консольного приложения.
//18. Заменить каждое четное число на разность максимального и минимального чисел. { A) вектор (std::vector)}
// Выполнила : Лактионова Мария Александровна (2к, 9г)

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

bool askForData(int &M, int &N, std::string &fileName)  
{

	while (M <= 0)
	{
		std::cout << "Введите целое число М (M > 0)" << std::endl;
		std::cin >> M;
		if (M < 1)
		{
			int choice = 1;
			std::cout << "Ошибка! Число должно быть больше 0" << std::endl;
			std::cout << "1 - Повторить попытку" << std::endl;
			std::cout << "2 - Выход в главное меню" << std::endl;
			std::cin >> choice;
			if (choice == 2) return false;
		}
	}

	while (N <= 0)
	{
		std::cout << "Введите целое число N (N > 0)" << std::endl;
		std::cin >> N;
		if (N < 1)
		{
			int choice = 1;
			std::cout << "Ошибка! Число должно быть больше 0" << std::endl;
			std::cout << "1 - Повторить попытку" << std::endl;
			std::cout << "2 - Выход в главное меню" << std::endl;
			std::cin >> choice;
			if (choice == 2) return false;
		}
	}

	std::cout << "Введите имя файла" << std::endl;
	std::cin >> fileName;

	while (fileName == "")
	{
		std::cout << "Введите имя файла для заполнения" << std::endl;
		std::cin >> fileName;
		if (fileName == "")
		{
			int choice = 1;
			std::cout << "Ошибка! Имя файла должно быть непустым" << std::endl;
			std::cout << "1 - Повторить попытку" << std::endl;
			std::cout << "2 - Выход в главное меню" << std::endl;
			std::cin >> choice;
			if (choice == 2) return false;
		}
	}
	return true;
}

/*  TO BE CHANGED  
std::vector<int> getContainer(std::ifstream& fin)    
{
	std::vector<int> v;
	if (!fin.is_open()) // если файл не открыт
	{std::cout << "Файл не может быть открыт!\n"; // сообщить об этом
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
}*/

std::ofstream fillFileRandomCycle(int M, int N, std::string fileName)
{
	std::ofstream output(fileName.c_str());

	for (int i = 0; i < N; i++) {
		output << -M + rand() % M << std::endl;
	}

	return output;
}

std::ofstream fillFileRandomGenerate(int M, const int N, std::string fileName)
{
	std::vector<int> v(N);
	std::ofstream output;
	output.open(fileName.c_str());
	std::generate(v.begin(), v.end(), (rand() % (2 * M + 1) - M));	
	
	for (int i = 0; i < N; i++) {
		output << v[i] << std::endl;
	}
	
	return output;  
}



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

int findNumDifference(std::vector<int>::iterator first, std::vector<int>::iterator last)
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

std::vector<int> modify(std::vector<int> v)
{
	int diff = findNumDifference(v);
	for (unsigned i = 0; i < v.size(); i++)
		if (v[i] % 2 == 0) {
			v[i] = diff;
		}
	return v;
}

/*    TO BE CHANGED  
std::vector<int> modify(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	int diff = findNumDifference(first, last);
	std::vector<int> v;
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
}*/

int returnNum(int num) {
	return num;
}

std::vector<int> replaceForEach(std::vector<int> v)
{
	int diff = findNumDifference(v);

	std::for_each(v.begin(), v.end(), returnNum(diff));

	return v;
}

int findSum(std::vector<int> v)
{
	int sum = 0;
	for (unsigned i = 0; i < v.size(); i++)
		sum += v.at(i);
	return sum;
}

double findAverage(std::vector<int> v)
{
	double average = 0;
	unsigned i = 0;

	for (i; i < v.size(); i++)
		average += v.at(i);
	average = average / i;
	return average;
}

void printToScreen(std::vector<int> v)
{
	for (unsigned i = 0; i < v.size(); i++)
		std::cout << v.at(i) << "  ";
}

void printToFile(std::vector<int> v)
{
	std::ofstream fout;
	std::string fileName = "";
	while (fileName == "") {
		std::cout << "Введите имя файла" << std::endl;
		std::cin >> fileName;
	}
	fout.open(fileName); 
	for (unsigned i = 0; i < v.size(); i++)
		fout << v.at(i) << "  ";
	fout.close();
}


int main()
{
    return 0;
}

