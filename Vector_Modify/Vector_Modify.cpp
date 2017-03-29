
//18. Заменить каждое четное число на разность максимального и минимального чисел. A) вектор (std::vector) 
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
	while (M <= 0)
	{
		cout << "Р’РІРµРґРёС‚Рµ С†РµР»РѕРµ С‡РёСЃР»Рѕ Рњ (M > 0)" << endl;
		cin >> M;
		if (M < 1)
		{
			int choice = 1;
			cout << "РћС€РёР±РєР°! Р§РёСЃР»Рѕ РґРѕР»Р¶РЅРѕ Р±С‹С‚СЊ Р±РѕР»СЊС€Рµ 0" << endl;
			cout << "1 - РџРѕРІС‚РѕСЂРёС‚СЊ РїРѕРїС‹С‚РєСѓ" << endl;
			cout << "2 - Р’С‹С…РѕРґ РІ РіР»Р°РІРЅРѕРµ РјРµРЅСЋ" << endl;
			cin >> choice;
			if (choice == 2) return false;
		}
	}

	while (N <= 0)
	{
		cout << "Р’РІРµРґРёС‚Рµ С†РµР»РѕРµ С‡РёСЃР»Рѕ N (N > 0)" << endl;
		cin >> N;
		if (N < 1)
		{
			int choice = 1;
			cout << "РћС€РёР±РєР°! Р§РёСЃР»Рѕ РґРѕР»Р¶РЅРѕ Р±С‹С‚СЊ Р±РѕР»СЊС€Рµ 0" << endl;
			cout << "1 - РџРѕРІС‚РѕСЂРёС‚СЊ РїРѕРїС‹С‚РєСѓ" << endl;
			cout << "2 - Р’С‹С…РѕРґ РІ РіР»Р°РІРЅРѕРµ РјРµРЅСЋ" << endl;
			cin >> choice;
			if (choice == 2) return false;
		}
	}

	cout << "Р’РІРµРґРёС‚Рµ РёРјСЏ С„Р°Р№Р»Р°" << endl;
	cin >> fileName;

	while (fileName == "")
	{
		cout << "Р’РІРµРґРёС‚Рµ РёРјСЏ С„Р°Р№Р»Р° РґР»СЏ Р·Р°РїРѕР»РЅРµРЅРёСЏ" << endl;
		cin >> fileName;
		if (fileName == "")
		{
			int choice = 1;
			cout << "РћС€РёР±РєР°! РРјСЏ С„Р°Р№Р»Р° РґРѕР»Р¶РЅРѕ Р±С‹С‚СЊ РЅРµРїСѓСЃС‚С‹Рј" << endl;
			cout << "1 - РџРѕРІС‚РѕСЂРёС‚СЊ РїРѕРїС‹С‚РєСѓ" << endl;
			cout << "2 - Р’С‹С…РѕРґ РІ РіР»Р°РІРЅРѕРµ РјРµРЅСЋ" << endl;
			cin >> choice;
			if (choice == 2) return false;
		}
	}
	return true;
}
void askForFileName(string& fileName) {
	fileName = "";
	while (fileName == "") {
		cout << "Р’РІРµРґРёС‚Рµ РёРјСЏ С„Р°Р№Р»Р°" << endl;
		cin >> fileName;
	}
}

/*  TO BE CHANGED  */

vector<int> getContainer(ifstream& fin)    
{
	vector<int> v;
	if (!fin.is_open()) // РµСЃР»Рё С„Р°Р№Р» РЅРµ РѕС‚РєСЂС‹С‚
	{
		cout << "Р¤Р°Р№Р» РЅРµ РјРѕР¶РµС‚ Р±С‹С‚СЊ РѕС‚РєСЂС‹С‚!\n"; // СЃРѕРѕР±С‰РёС‚СЊ РѕР± СЌС‚РѕРј
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
		cout << "РљРѕРЅС‚РµР№РЅРµСЂ РїСѓСЃС‚" << endl;
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
	cout << "Р’РІРµРґРёС‚Рµ Р»РµРІСѓСЋ РіСЂР°РЅРёС†Сѓ" << endl;
	while ((a < 0) || (a >= v.size()))
	{
		cin >> a;
		if ((a < 0) || (a >= v.size()))
			cout << "Р§РёСЃР»Рѕ РґРѕР»Р¶РЅРѕ Р±С‹С‚СЊ Р±РѕР»СЊС€Рµ 0! РџРѕРІС‚РѕСЂРёС‚Рµ РІРІРѕРґ" << endl;
		else if (a >= v.size())
			cout << "Р§РёСЃР»Рѕ РїСЂРµРІС‹С€Р°РµС‚ СЂР°Р·РјРµСЂ РІРµРєС‚РѕСЂР° (" << v.size() << ")! РџРѕРІС‚РѕСЂРёС‚Рµ РІРІРѕРґ" << endl;	
	}		
	
	cout << "Р’РІРµРґРёС‚Рµ РїСЂР°РІСѓСЋ РіСЂР°РЅРёС†Сѓ" << endl;
	cin >> b;
	while ((b < 0) || (b >= v.size()) || (b < a)) 
	{
		cin >> a;
		if ((b < 0) || (b >= v.size()))
			cout << "Р§РёСЃР»Рѕ РґРѕР»Р¶РЅРѕ Р±С‹С‚СЊ РЅРµ РјРµРЅСЊС€Рµ 0! РџРѕРІС‚РѕСЂРёС‚Рµ РІРІРѕРґ" << endl;
		else if (b >= v.size())
			cout << "Р§РёСЃР»Рѕ РІРЅРµ РґРёР°РїР°Р·РѕРЅР° (0.." << v.size()-1 << ")! РџРѕРІС‚РѕСЂРёС‚Рµ РІРІРѕРґ" << endl;
		else if (b < a)
			cout << "Р§РёСЃР»Рѕ РґРѕР»Р¶РЅРѕ Р±С‹С‚СЊ РЅРµ РјРµРЅСЊС€Рµ Р»РµРІРѕР№ РіСЂР°РЅРёС†С‹ (" << a << ")! РџРѕРІС‚РѕСЂРёС‚Рµ РІРІРѕРґ" << endl;
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
	cout << "/nРСЃС…РѕРґРЅС‹Р№ РІРµРєС‚РѕСЂ: " << endl;
	printToScreen(v);
	cout << "/nРР·РјРµРЅРµРЅРЅС‹Р№ РІРµРєС‚РѕСЂ: " << endl;
	printToScreen(vMod);
}

void printResult(vector<int>::iterator first, vector<int>::iterator last, vector<int> vMod)
{
	cout << "/nРСЃС…РѕРґРЅС‹Р№ РІРµРєС‚РѕСЂ: " << endl;
	printToScreen(first, last);
	cout << "/nРР·РјРµРЅРµРЅРЅС‹Р№ РІРµРєС‚РѕСЂ: " << endl;
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
		cout << "\n1. Р—Р°РїРѕР»РЅРёС‚СЊ С„Р°Р№Р» СЂР°РЅРґРѕРјРЅС‹РјРё С‡РёСЃР»Р°РјРё\n";
		cout << "2. Р—Р°РіСЂСѓР·РёС‚СЊ СЌР»РµРјРµРЅС‚С‹ РёР· С„Р°Р№Р»Р°\n";
		cout << "3. РџСЂРµРѕР±СЂР°Р·РѕРІР°С‚СЊ РєРѕРЅС‚РµР№РЅРµСЂ\n";
		cout << "4. РџСЂРµРѕР±СЂР°Р·РѕРІР°С‚СЊ С‡Р°СЃС‚СЊ РєРѕРЅС‚РµР№РЅРµСЂР°\n";
		cout << "5. РџСЂРµРѕР±СЂР°Р·РѕРІР°РЅРёРµ СЃ transform\n";
		cout << "6. РџСЂРµРѕР±СЂР°Р·РѕРІР°РЅРёРµ СЃ for_each\n";
		cout << "7. Р’С‹С‡РёСЃР»РёС‚СЊ СЃСѓРјРјСѓ СЌР»РµРјРµРЅС‚РѕРІ\n";  
		cout << "8. Р’С‹С‡РёСЃР»РёС‚СЊ СЃСЂРµРґРЅРµРµ Р°СЂРёС„РјРµС‚РёС‡РµСЃРєРѕРµ СЌР»РµРјРµРЅС‚РѕРІ\n";  
		cout << "9. Р’С‹РІРµСЃС‚Рё СЂРµР·СѓР»СЊС‚Р°С‚\n"; 
		cout << "10. Р’С‹С…РѕРґ\n";
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
				cout << "РЎСѓРјРјР° СЌР»РµРјРµРЅС‚РѕРІ РІРµРєС‚РѕСЂР° - " << findSum(v) << endl;
				break;
			case 8:
				cout << "РЎСЂРµРґРЅРµРµ Р°СЂРёС„РјРµС‚РёС‡РµСЃРєРѕРµ СЌР»РµРјРµРЅС‚РѕРІ РІРµРєС‚РѕСЂР° - " << findAverage(v) << endl;
				break;
			case 9:
				cout << "Р’С‹РІРµСЃС‚Рё СЂРµР·СѓР»СЊС‚Р°С‚ РЅР° СЌРєСЂР°РЅ? 1 - Р”Р°, 2 - РќРµС‚ " << endl;
				while (option != 1 || option != 2) {
					cin >> option;
					if (option == 1)
					{
						printToScreen(v);
						option = 9;
					}
					else if (option != 2) {
						cout << "РџРѕРІС‚РѕСЂРёС‚Рµ РІРІРѕРґ!" << endl;
					}
				}
				printToFile(v);
				break;
			case 10: 
				break;
			default: cout << "РћС€РёР±РєР°! РџРѕРІС‚РѕСЂРёС‚Рµ РІРІРѕРґ" << endl;
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

