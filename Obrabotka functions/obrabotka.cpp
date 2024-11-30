#include<iostream>
#include<cmath>
#include<thread>

#include<functional>

// передача функций в другие функции 
// указатель на функцию 
// шаблонная функция 
// функторы 
// предикаты 
// 


typedef int(*Curwy)(int, int);
using Curly = int(*)(int, int);

int Summ(int a, int b) {
	return a + b;
}

int Substruct(int a, int b) {
	return a - b;
}

int Multiply(int a, int b) {
	return a * b;
}

int DoAction1(int a, int b, Curly func) {
	return func(a, b);
}

int DoAction2(int a, int b, Curwy func) {
	return func(a, b);
}




int main() {
	int a(4);// инициализация в стиле C не рекомендуется и может приводить к 
	// ошибкам если не передать значения

	int b = ::exp(1);// инициализация присваиванием допустима но она не проверяет 
	// потери данных при внесении значений 

	int c{ };// унивсальная инициализация. Рекомендована к использованию 
		// проверяет что данные переданные в переменну подходящего типа 

	std::cout << "Enter first number:";
	int first{};
	std::cin >> first;
	std::cout << "Enter second number:";
	int second{};
	std::cin >> second;
	//std::cout << Summ << ' ' << Substruct << ' ' << Multiply << '\n';
	//// int Summ(int a, int b)
	//std::function<int(int, int)>var = Summ;
	//Curwy var2 = Multiply;
	//Curly arrFunk[]{ Multiply, Substruct, Summ };
	//for (auto& funk :arrFunk )
	//{
	//	std::cout << first << "and" << second << "=" << funk(first, second);
	//	std::cout << '\n';
	//}
	//
	std::cout << "Enter type of action:\n\
1- summ;\n2-substruct;\n3-multiply.\n";
int key{};
std::cin >> key;
int answer{};
switch (key)
{
case 1:
	answer = DoAction1(first, second, Summ);
	break;
case 2:
	answer = DoAction2(first, second, Substruct);
	break;
case 3:
	answer = DoAction2(first, second, Multiply);
	break;
}
std::cout << "Your result:" << answer << '\n';

std::thread tr(Summ, 3, first);

tr.join();

//tr.detach();
	return 0;
}