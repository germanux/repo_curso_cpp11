#include "stdafx.h"
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>

using namespace std;

void prod_escalar(const std::vector<int> &v1,
	const std::vector<int> &v2, int &result, int Ini, int Fin) {
	for (int i = Ini; i < Fin; ++i) {
		result += v1[i] * v2[i];
	}
}

static std::mutex gandalf;

void prod_escalar_mutex(const std::vector<int> &v1,
	const std::vector<int> &v2, int &result, int Ini, int Fin) {
	int suma_parcial = 0;
	for (int i = Ini; i < Fin; ++i) {
		suma_parcial += v1[i] * v2[i];
	}
	std::lock_guard<std::mutex> no_puedes_pasar(gandalf);
	result += suma_parcial;
}
int borde(int nr_threads, int nr_elements, int segmento) {
	if (segmento == nr_threads) {
		return nr_elements;
	}
	else {
		return (nr_elements / nr_threads)*segmento;
	}
}
void ej_sincro_threads() {
	int nr_elements = 100000;
	int nr_threads = 4;
	int result = 0;
	vector<thread> threads;
	vector<int> v1(nr_elements, 1), v2(nr_elements, 2);
	for (int i = 0; i < nr_threads; ++i) {
		threads.push_back(
			std::thread(prod_escalar /* prod_escalar_mutex */, std::ref(v1), std::ref(v2),
						std::ref(result), 
						borde(nr_threads, nr_elements, i), 
						borde(nr_threads, nr_elements, i + 1) ));
	}

	for (auto &t : threads) {
		t.join();
	}
	cout << result << endl;
}

void prod_escalar_atom(const std::vector<int> &v1,
	const std::vector<int> &v2, std::atomic<int> &result, int Ini, int Fin) {
	int suma_parcial = 0;
	for (int i = Ini; i < Fin; ++i) {
		suma_parcial += v1[i] * v2[i];
	}
	result += suma_parcial;
}
void ej_sincro_threads_atom() {
	int nr_elements = 100000;
	int nr_threads = 4;
	std::atomic<int> result(0);
	vector<thread> threads;
	vector<int> v1(nr_elements, 1), v2(nr_elements, 2);
	for (int i = 0; i < nr_threads; ++i) {
		threads.push_back(std::thread(prod_escalar_atom, std::ref(v1), std::ref(v2),
			std::ref(result), borde(nr_threads, nr_elements, i), borde(nr_threads, nr_elements, i + 1)));
	}

	for (auto &t : threads) {
		t.join();
	}
	cout << result << endl;
}