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
void ej_thread_vector();

void ej_sincro_threads();
void ej_sincro_threads_atom();
void ej_sincro_mala();
void ej_sincro_buena();
void ej_lock_for();
void ej_future_promise();
void ej_future_status();

int main() {
	/*ej_thread();
	ej_sleep_for();
	ej_thread_lambda();
	ej_thread_concurrencia();
	practica_multithreading();
	ej_thread_param();
	ej_thread_vector();

	ej_sincro_threads();
	ej_sincro_threads_atom();
	
	ej_sincro_mala();
	ej_sincro_buena();
	ej_lock_for();*/
	//ej_future_promise();
	ej_future_status();

	getchar();
	getchar();
	return 0;
}