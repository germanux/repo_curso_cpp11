#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class Malo {
	std::mutex sauron;
public:
	void a() {
		std::lock_guard<std::mutex> vigila(sauron);
		std::cout << "A" << std::endl;
	}
	void b() {
		std::lock_guard<std::mutex> vigila(sauron);
		std::cout << "B" << std::endl;
	}
	void ab() {
		std::lock_guard<std::mutex> vigila(sauron);
		a();
		b();
	}
};

class Bueno {
	std::recursive_mutex sauron;
public:
	void a() {
		std::lock_guard<std::recursive_mutex> vigila(sauron);
		std::cout << "A" << std::endl;
	}
	void b() {
		std::lock_guard<std::recursive_mutex> vigila(sauron);
		std::cout << "B" << std::endl;
	}
	void ab() {
		std::lock_guard<std::recursive_mutex> vigila(sauron);
		a();
		b();
	}
};
void ej_sincro_mala() {
	Malo* malo = new Malo();
	malo->a();
	malo->b();
	malo->ab();
}
void ej_sincro_buena() {
	Bueno* malo = new Bueno();
	malo->a();
	malo->b();
	malo->ab();
}
