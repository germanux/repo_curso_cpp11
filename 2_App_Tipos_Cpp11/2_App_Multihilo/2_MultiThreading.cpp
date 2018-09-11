#include "stdafx.h"
#include <iostream>
#include <thread>

using namespace std;

void cuerpo_del_hilo() {
	std::cout << "Hola," << std::endl;
	std::cout << "mundo!" << std::endl;
}
void ej_thread() {
	std::thread hilo_1(cuerpo_del_hilo);
	hilo_1.join();
}
void ej_sleep_for() {
	std::cout << "antes de dormir" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1200));
	std::cout << "después de dormir" << std::endl;
}
void ej_thread_lambda() {
	thread t1([]()->void {cout << "hola lambda" << endl; });
	t1.join();
}
void cuenta_hasta_100() {
	for (int i = 0; i < 20; i++) {
		std::cout << i << std::endl;
		std::this_thread::sleep_for(10ms);
	}
}
void ej_thread_concurrencia() {
	thread t1(cuenta_hasta_100);
	thread t2(cuenta_hasta_100);
	thread t3(cuenta_hasta_100);
	t1.join();
	t2.join();
	t3.join();
}