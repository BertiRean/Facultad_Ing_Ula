#ifndef TESTBENCH_H
#define TESTBENCH_H

#include "systemc.h"

class TestBench : public sc_module
{
	public:
		sc_in<bool> Clock_In, c_In_Test, d_In_Test;
		sc_out<bool> a_Out_Test, b_Out_Test, c_Out_Test;

		/*
			a_Out_Test: Entrada 1 del Sumador
			b_Out_Test: Entrada 2 del Sumador
			c_Out_Test: Acarreo de Entrada del Sumador
		*/

		SC_CTOR(TestBench)
		{
			SC_THREAD(Test);

			sensitive << Clock_In.pos();
			dont_initialize();
		}

	private:
		void Test();
		void Print_Result();

};


#endif