#ifndef NAND_GATE_H
#define NAND_GATE_H

#include <systemc.h>

class Nand_Gate : public sc_module
{
	public:

		sc_in<bool> a_In, b_In;
		sc_out<bool> c_Out;

		SC_CTOR(Nand_Gate)
		{
			SC_METHOD(operation);
			sensitive << a_In << b_In;
		}
	
	private:
		void operation()
		{
			c_Out.write(!(a_In.read() && b_In.read()));
		} // Metodo para Definir las operaciones de lectura y escritura de mi compuerta en sus entradas y salidas
};

#endif

