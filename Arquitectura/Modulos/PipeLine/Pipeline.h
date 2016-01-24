#ifndef PIPELINE_H
#define PIPELINE_H

#include "Register.h"
#include "And_Gate.h"
#include "Or_Gate.h"
#include "Not_Gate.h"
#include "Sumador.h"


class Pipeline : public sc_module
{	
	public:
		sc_in<bool> a_In_Pipe, b_In_Pipe, c_In_Pipe, d_In_Pipe, e_In_Pipe;
		sc_in<bool> Clock_In_Pipe;
		sc_out<bool> s_Out_Pipe, r_Out_Pipe;

		SC_CTOR(Pipeline)
		{

			Gate_And = new And_Gate("Gate_And");
			Gate_Or = new Or_Gate("Gate_Or");

			Gate_And->a_In_And(a_In_Pipe);
			Gate_And->b_In_And(b_In_Pipe);
			Gate_And->c_Out_And(Wire_1);

			Gate_Or->a_In_Or(c_In_Pipe);
			Gate_Or->b_In_Or(d_In_Pipe);
			Gate_Or->c_Out_Or(Wire_2);

			//Entradas de los Registros 1, 2, 3

			Reg1 = new Register("Reg1");
			Reg2 = new Register("Reg2");
			Reg3 = new Register("Reg3");

			Reg1->d_In_Reg(Wire_1);
			Reg2->d_In_Reg(Wire_2);
			Reg3->d_In_Reg(e_In_Pipe);

			// Reloj Registro 1,2,3

			Reg1->Clock_In_Reg(Clock_In_Pipe);
			Reg2->Clock_In_Reg(Clock_In_Pipe);
			Reg3->Clock_In_Reg(Clock_In_Pipe);

			// Salidas de los Registros 1 ,2 , 3
			Reg1->d_Out_Reg(Wire_3);
			Reg2->d_Out_Reg(Wire_4);
			Reg3->d_Out_Reg(Wire_5);

			// Sumador de 1 Bit
			Adder = new Sumador("Adder");
			Adder->a_In_Sumador(Wire_3);
			Adder->b_In_Sumador(Wire_4);
			Adder->c_In_Sumador(Wire_5);

			Adder->c_Out_Sumador(Wire_6);
			Adder->d_Out_Sumador(Wire_7);

			// Entradas de los Registros 4,5
			Reg4 = new Register("Reg4");
			Reg5 = new Register("Reg5");
			Reg4->d_In_Reg(Wire_6);
			Reg5->d_In_Reg(Wire_7);

			//Relojes Registros 4, 5

			Reg4->Clock_In_Reg(Clock_In_Pipe);
			Reg5->Clock_In_Reg(Clock_In_Pipe);

			// Salidas de los Registros 4,5

			Reg4->d_Out_Reg(Wire_8);
			Reg5->d_Out_Reg(Wire_9);

			// Compuerta NOT

			Gate_Not = new Not_Gate("Gate_Not");

			Gate_Not->a_In_Not(Wire_9);
			Gate_Not->c_Out_Not(Wire_10);

			// Entradas de los Registros 6, 7
			Reg6 = new Register("Reg6");
			Reg7 = new Register("Reg7");
			Reg6->d_In_Reg(Wire_8);
			Reg7->d_In_Reg(Wire_10);

			// Relojes Registro 6, 7

			Reg6->Clock_In_Reg(Clock_In_Pipe);
			Reg7->Clock_In_Reg(Clock_In_Pipe);

			// Salidas de los Registros 6,7

			Reg6->d_Out_Reg(s_Out_Pipe);
			Reg7->d_Out_Reg(r_Out_Pipe);

		}

		~Pipeline()
		{
			delete Gate_And;
			delete Gate_Or;
			delete Gate_Not;
			delete Adder;
			delete Reg1;
			delete Reg2;
			delete Reg3;
			delete Reg4;
			delete Reg5;
			delete Reg6;
			delete Reg7;
		}

	private:
		And_Gate *Gate_And;
		Or_Gate  *Gate_Or;
		Not_Gate *Gate_Not;
		Sumador  *Adder;
		Register *Reg1, *Reg2, *Reg3, *Reg4, *Reg5, *Reg6, *Reg7;

		sc_signal<bool> Wire_1, Wire_2, Wire_3, Wire_4, Wire_5 , Wire_6, Wire_7, Wire_8, Wire_9, Wire_10;

};

#endif
