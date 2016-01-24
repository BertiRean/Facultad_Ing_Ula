#ifndef NOT_GATE_H
#define NOT_GATE_H

#include <systemc.h>

class Not_Gate : public sc_module
{
	public:

		sc_in<bool> a_In_Not;
		sc_out<bool> c_Out_Not;

		SC_CTOR(Not_Gate)
		{
			SC_METHOD(operation);
			sensitive << a_In_Not;
		}
	
	private:
		void operation()
		{
			c_Out_Not.write(!a_In_Not.read());
		} // Metodo para Definir las operaciones de lectura y escritura de mi compuerta en sus entradas y salidas
};

#endif