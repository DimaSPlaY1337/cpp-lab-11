#include "KontAndIter.h"
#include <fstream>
#include <iostream>
#include <deque>

using namespace std;

void KontAndIter::Task1()
{
	cout << "Started task 1" << endl;
	int n, element;
	cout << "Count of elements: " << endl;
	cin >> n;
	vector<int> numbers;
	for (int i = 0; i < n; ++i)
	{
		cin >> element;
		numbers.push_back(element);
	}
	vector<int>::iterator iter = numbers.begin();
	vector<int>::iterator iterEnd = numbers.end();
	iterEnd -= 2;
	cout << "Show count of elements between first and last: " << iterEnd - iter << endl;
	cout << "Show all elements: " << endl;
	while (iter != numbers.end())    // пока не дойдем до конца
	{
		cout << *iter << " ";// получаем элементы через итератор
		++iter;             // перемещаемся вперед на один элемент
	}
	cout << endl;
}

void KontAndIter::Task2()
{
	cout << "Started task 2" << endl;
	cout << "First part with list: " << endl;
	list<int> list1{ -5, 8, 12 };
	list<int> listNew{ 1, -2, 3 };

	auto front_it = front_inserter(list1);
	auto back_it = back_inserter(list1);
	auto mid_it = inserter(list1, next(list1.begin()));

	for (auto elem : listNew)
	{
		if (elem < 0)
		{
			*back_it = elem;
		}
		else
		{
			*front_it = elem;
		}
	}
	*mid_it = 77;
	for (auto elem : list1)
	{
		cout << elem << " ";
	}
	cout << endl;

	cout << "Second part with vector: " << endl;
	vector<int> Vector{ 2, -3, 4, 5454 };
	vector<int> NewVector{ -22, 3, -2 };
	vector<int>::iterator iter = Vector.begin();
	auto back_it1 = back_inserter(Vector);
	auto mid_it1 = inserter(Vector, next(Vector.begin()));
	*(++iter) = 0;//удалил средний элемент
	for (auto elem : NewVector)
	{
		/*if (elem < 0) если писать так то краш почему-то
		{
			*back_it1 = elem;
		}
		else
		{
			*mid_it1 = elem;
		}*/
		if (elem > 0)
		{
			*back_it1 = elem;
		}
		else
		{
			*mid_it1 = elem;
		}
		cout << elem << " ";
	}
	cout << endl;
	for (auto elem : Vector)
	{
		cout << elem << " ";
	}
}/*
Используйте стандартные итераторы для чтения и записи файлов.Напишите программу, которая
демонстрирует работу с текстовым файлом с помощью итераторов.*/
void KontAndIter::Task3()
{
	cout << "Started task 3" << endl;
	cout << "Read and write out" << endl;
	vector<string> data;
	char FileName[] = "C:\\Users\\PC\\Desktop\\Лабы\\Программ\\Лабы\\cpp-lab-11\\FileOne.txt";
	ifstream in(FileName);
	char ch;
	string s;

	while ((ch = in.get()) != EOF)
	{
		if (char(ch) != '\n')
			s = s + char(ch);
		else
		{
			data.push_back(s);
			s.clear();
		}
	}
	data.push_back(s);
	s.clear();
	in.close();
	copy(data.begin(), data.end(), ostream_iterator<string>(cout, "\n"));

	ofstream file_output;
	file_output.open(FileName);
	ostream_iterator<string> output_iter(file_output);
	vector <string>::iterator iter = data.begin();

	while (iter != data.end())
	{
		*output_iter = *iter;
		++iter;
	}
}

void KontAndIter::Task4()
{
	cout << "Started task 4" << endl;
	vector<int> Vector{ 1, 2, 3, 4 };
	vector<int>::iterator IterVStart;

	deque<int> Deque{ 9, 9, 9, 9};
	deque<int>::iterator IterD = Deque.begin();

	copy(Vector.begin(), Vector.end(), Deque.begin());
	while (IterD != Deque.end())
	{
		cout << *IterD << endl;
		++IterD;
	}
}

void KontAndIter::Task5()
{
	cout << "Started task 5" << endl;
	int n, element;
	cout << "Count of elements: " << endl;
	cin >> n;
	vector<int> numbers;
	for (int i = 0; i < n; ++i)
	{
		cin >> element;
		numbers.push_back(element);
	}

	//переворачиваем контейнер
	vector<int> numbersNew;
	vector<int>::iterator it = numbers.end();
	auto rIt = make_reverse_iterator(it);
	while (rIt != numbers.rend())
	{
		numbersNew.push_back(*rIt);
		cout << *rIt << ' ';
		++rIt;
	}
	numbers = numbersNew;
	cout << endl;
}
