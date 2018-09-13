
#include "stdafx.h"
#include <iostream>
#include <future>

void trabajo(std::promise<int> * promesa)
{
	std::cout << "trabajamos" << std::endl;
	promesa->set_value(35);
}

void ej_future_promise()
{
	std::promise<int> promesa;
	std::future<int> objetoFuturo = promesa.get_future();
	std::thread th(trabajo, &promesa);
	std::cout << objetoFuturo.get() << std::endl;
	th.join();
}
void trabajo_lento(std::promise<int> * promesa) {
	std::this_thread::sleep_for(std::chrono::seconds(2));
	promesa->set_value(35);
}
void ej_future_status()
{
	std::promise<int> promesa;
	std::future<int> futuro = promesa.get_future();
	std::thread th(trabajo_lento, &promesa);
	std::future_status status;
	do {
		status = futuro.wait_for(std::chrono::milliseconds(100));
		if (status == std::future_status::deferred) {
			std::cout << "deferred\n";
		}
		else if (status == std::future_status::timeout) {
			std::cout << "timeout\n";
		}
		else if (status == std::future_status::ready) {
			std::cout << "ready!\n";
		}
	} while (status != std::future_status::ready);
	std::cout << "resultado " << futuro.get() << '\n';
	th.join();;
}