#ifndef AND_GATE_H
#define AND_GATE_H

#include <systemc.h>

class And_Gate : public sc_module
{
	public:

		sc_in<bool> a_In_And, b_In_And;
		sc_out<bool> c_Out_And;

		SC_CTOR(And_Gate)
		{
			SC_METHOD(operation);
			sensitive << a_In_And << b_In_And;
		}
	
	private:
		void operation()
		{
			c_Out_And.write(a_In_And.read() && b_In_And.read());
		} // Metodo para Definir las operaciones de lectura y escritura de mi compuerta en sus entradas y salidas
};

#endif

