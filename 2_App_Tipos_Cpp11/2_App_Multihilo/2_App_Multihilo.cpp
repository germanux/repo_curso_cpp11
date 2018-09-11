// 2_App_Multihilo.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <thread>

void cuerpo_del_hilo() {
	std::cout << "Hola," << std::endl;
	std::cout << "que" << std::endl;
	std::cout << "pasa" << std::endl;
	std::cout << "mundo!" << std::endl;
}

int main() {
	std::thread hilo_1(cuerpo_del_hilo);
	std::thread hilo_2(cuerpo_del_hilo);

	hilo_1.join();
	hilo_2.join();

	getchar();
	return 0;
}