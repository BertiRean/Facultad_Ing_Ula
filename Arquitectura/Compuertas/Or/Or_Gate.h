#ifndef OR_GATE_H
#define OR_GATE_H

#include <systemc.h>

class Or_Gate : public sc_module
{
	public:

		sc_in<bool> a_In_Or, b_In_Or;
		sc_out<bool> c_Out_Or;

		SC_CTOR(Or_Gate)
		{
			SC_METHOD(operation);
			sensitive << a_In_Or << b_In_Or;
		}
	
	private:
		void operation()
		{
			c_Out_Or.write(a_In_Or.read() || b_In_Or.read());
		} // Metodo para Definir las operaciones de lectura y escritura de mi compuerta en sus entradas y salidas
};

#endif