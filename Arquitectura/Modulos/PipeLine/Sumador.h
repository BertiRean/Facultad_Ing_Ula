#ifndef SUMADOR_H
#define SUMADOR_H

#include "And_Gate.h"
#include "Or_Gate.h"
#include "Xor_GateComp.h"

class Sumador : public sc_module
{
	public:

		sc_in<bool> a_In_Sumador, b_In_Sumador, c_In_Sumador;
		sc_out<bool> c_Out_Sumador, d_Out_Sumador;

		SC_CTOR(Sumador)
		{

			// Pedido de Memorias de las Compuertas And//

			Gate_And_1 = new And_Gate("Gate_And_1");
			Gate_And_2 = new And_Gate("Gate_And_2");


			// Pedido de Memoria Compuertas Xor

			Gate_Xor_1 = new Xor_GateComp("Gate_Xor_1");
			Gate_Xor_2 = new Xor_GateComp("Gate_Xor_2");

			// Gate Or

			Gate_Or_1 = new Or_Gate("Gate_Or_1");


			// Asignacion de Entradas Compuertas Xor //

			Gate_Xor_1->a_In_Xor(a_In_Sumador);
			Gate_Xor_1->b_In_Xor(b_In_Sumador);
			Gate_Xor_1->c_Out_Xor(Wire_1);

			Gate_Xor_2->a_In_Xor(Wire_1);
			Gate_Xor_2->b_In_Xor(c_In_Sumador);
			Gate_Xor_2->c_Out_Xor(c_Out_Sumador);

			// Asignacion de Entradas Compuertas And //

			Gate_And_1->a_In_And(a_In_Sumador);
			Gate_And_1->b_In_And(b_In_Sumador);
			Gate_And_1->c_Out_And(Wire_2);

			Gate_And_2->a_In_And(Wire_1);
			Gate_And_2->b_In_And(c_In_Sumador);
			Gate_And_2->c_Out_And(Wire_3);

			// Asignacion Compuerta Or

			Gate_Or_1->a_In_Or(Wire_3);
			Gate_Or_1->b_In_Or(Wire_2);
			Gate_Or_1->c_Out_Or(d_Out_Sumador);

		}


	private:
		And_Gate *Gate_And_1, *Gate_And_2;
		Or_Gate *Gate_Or_1;
		Xor_GateComp *Gate_Xor_1, *Gate_Xor_2;
		sc_signal<bool> Wire_1, Wire_2, Wire_3; 
	
};


#endif