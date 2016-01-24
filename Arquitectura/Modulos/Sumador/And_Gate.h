#ifndef AND_GATE_H
#define AND_GATE_H

#include <systemc.h>

class And_Gate : public sc_module
{
	public:

		sc_in<bool> a_In, b_In;
		sc_out<bool> c_Out;

		SC_CTOR(And_Gate)
		{
			SC_METHOD(operation);
			sensitive << a_In << b_In;
		}
	
	private:
		void operation()
		{
			c_Out.write(a_In.read() && b_In.read());
		} // Metodo para Definir las operaciones de lectura y escritura de mi compuerta en sus entradas y salidas
};

#endif

