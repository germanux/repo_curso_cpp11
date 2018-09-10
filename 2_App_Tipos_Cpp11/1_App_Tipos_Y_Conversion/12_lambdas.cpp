
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void ej_lambda_simple()
{
	int n1 = []() -> int { return 42 * 2; }();
	cout << n1 << endl;

	int n2 = [](int x) -> int { return x * 2; }(42);
	cout << n2 << endl;

	int n3 = [](int x, int y) -> int { return x * y; }(42, 2);
	cout << n3 << endl;
}
void ej_lambdas_anidadas()
{
	int n = [](int x, int y) -> int { 
		return [](int p)-> int {
			return p * p; }
		(x)* y; 
	}(8, 4);

	int m = [](int x, int y) -> int {
		return x * y; 
	}

	([](int x)->int {
		return x * x;
	}(8), 4);

	cout << n << " " << m << endl;
}
void ej_lambdas_punteros()
{
	auto f = [](int x)->int {return x * x; };
	cout << f(3) << endl;
	cout << f(4) << endl;
}
void ej_lambdas_genericas_cpp14()
{
	auto f = [](auto x)->auto {return x * x; };
	cout << f(3) << endl;
	cout << f(3.1) << endl;
}
void ej_lambdas_como_param()
{
	auto f = [](int x)->int {return x * x; };
	cout << f(3) << endl;
	auto f2 = [](auto x, auto y)->int {return x(y) * 2; };
	cout << f2(f, 5) << endl;
}
void practica_sort_lamba() {

	int n = 10;
	vector<int> v(n);
	for (int i = n - 1, j = 0; i >= 0; i--, j++) v[j] = i + 1;
	v[5] = 25;
	v.insert(v.begin(), 50);
	for (int i = 0; i < n; i++) cout << v[i] << " "; cout << endl;
	sort(v.begin(), v.end(), [](int i, int j) -> bool { return (i < j);});
	for (int i = 0; i < n; i++) cout << v[i] << " "; cout << endl;
}