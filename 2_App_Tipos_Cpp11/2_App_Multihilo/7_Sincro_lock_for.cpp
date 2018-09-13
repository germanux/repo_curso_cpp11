#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::timed_mutex elrond;

void prueba_lock_for(const char * hilo) {
	std::chrono::milliseconds timeout(100);
	while (true) {
		if (elrond.try_lock_for(timeout)) {
			std::cout << std::this_thread::get_id() << "  -  Pude entrar en " << hilo << std::endl;
			std::chrono::milliseconds dormir(250);
			std::this_thread::sleep_for(dormir);
			elrond.unlock();
			std::this_thread::sleep_for(dormir);
		}
		else {
			std::cout << std::this_thread::get_id() << "  -  No pude entrar en " << hilo << std::endl;
			std::chrono::milliseconds dormir(100);
			std::this_thread::sleep_for(dormir);
		}
	}
}

void ej_lock_for() {
	std::thread t1(prueba_lock_for, "Hilo 1");
	std::thread t2(prueba_lock_for, "Hilo 2");
	std::thread t3(prueba_lock_for, "Hilo 3");
	t1.join();
	t2.join();
	t3.join();
}