#ifndef XOR_GATE_COMP_H
#define XOR_GATE_COMP_H

#include <And_Gate.h>

class Xor_GateComp : public sc_module
{
	public:
		sc_in<bool> a_In_Xor, b_In_Xor;
		sc_out<bool> c_Out_Xor;

		SC_CTOR(Xor_GateComp)
		{
			Gate_1 = new And_Gate("Gate_1");
			Gate_2 = new And_Gate("Gate_2");
			Gate_3 = new And_Gate("Gate_3");

			Gate_1->a_In(a_In_Xor);
			Gate_1->b_In(b_In_Xor);
			Gate_1->c_Out(Wire_1);

			Gate_2->a_In(a_In_Xor);
			Gate_2->b_In(Wire_1);
			Gate_2->c_Out(Wire_2);

			Gate_3->a_In(Wire_1);
			Gate_3->b_In(b_In_Xor);
			Gate_3->c_Out(Wire_3);

		}
	private:
		And_Gate *Gate_1, *Gate_2, *Gate_3;
		sc_signal<bool> Wire_1, Wire_2, Wire_3;
};

#endif