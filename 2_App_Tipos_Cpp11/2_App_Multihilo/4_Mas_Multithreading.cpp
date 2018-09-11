#include "stdafx.h"
#include <thread>
#include <iostream>

using namespace std;

void cuenta_hasta_x(int x) {
	for (int i = 0; i < x; i++) {
		std::cout << "<" << x << " veces> " << i << std::endl;
		std::this_thread::sleep_for(10ms);
	}
}
void ej_thread_param() {
	int por_ref = 20;
	thread t1(cuenta_hasta_x, 10);
	thread t2(cuenta_hasta_x, std::ref(por_ref));
	thread t3(cuenta_hasta_x, 15);
	t1.join();
	t2.join();
	t3.join();
}