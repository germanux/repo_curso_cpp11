// 2_App_Multihilo.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <thread>

void ej_thread();
void ej_sleep_for();
void ej_thread_lambda();
void ej_thread_concurrencia();
void practica_multithreading();
void ej_thread_param();

int main() {
	/*ej_thread();
	ej_sleep_for();
	ej_thread_lambda();
	ej_thread_concurrencia();
	practica_multithreading();*/
	ej_thread_param();
	getchar();
	getchar();
	return 0;
}