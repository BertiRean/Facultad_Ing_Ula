#ifndef SPLITTER_WITH_REG
#define SPLITTER_WITH_REG

#include <systemc.h>
#include "Register_3Bits.h"
#include "Register_4Bits.h"
#include "Splitter.h"


class Splitter_Reg : public sc_module
{
	public:

		sc_in<bool> Clk_In_Split_Reg, Enable_Split;
		sc_in<sc_uint <11> > Splitter_Reg_In;
		sc_out<sc_uint <4> > Splitter_Reg_Out_4_a, Splitter_Reg_Out_4_b;
		sc_out<sc_uint <3> > Splitter_Reg_Out_3;

		SC_CTOR(Splitter_Reg)
		{
			// Pedido de Memoria

			Reg_1 = new Register_4Bits("Reg_1");
			Reg_2 = new Register_4Bits("Reg_2");
			Reg_3 = new Register_3Bits("Reg_3");
			Split = new Splitter("Split");

			// Manejo de Entradas

			Split->Splitter_In_11(Splitter_Reg_In);
			Split->Splitter_Out_4_a(Spliter_Signal_1);
			Split->Splitter_Out_4_b(Spliter_Signal_2);
			Split->Splitter_Out_3(Spliter_Signal_3);

			Reg_1->Reg_In_4(Spliter_Signal_1);
			Reg_1->Reg_Out_4(Splitter_Reg_Out_4_a);

			Reg_1->Clock_In_Reg(Clk_In_Split_Reg);
			Reg_1->Enable_In_Reg(Enable_Split);

			Reg_2->Reg_In_4(Spliter_Signal_2);
			Reg_2->Reg_Out_4(Splitter_Reg_Out_4_b);

			Reg_2->Clock_In_Reg(Clk_In_Split_Reg);
			Reg_2->Enable_In_Reg(Enable_Split);

			Reg_3->Reg_In_3(Spliter_Signal_3);
			Reg_3->Reg_Out_3(Splitter_Reg_Out_3);

			Reg_3->Clock_In_Reg(Clk_In_Split_Reg);
			Reg_3->Enable_In_Reg(Enable_Split);
		}

	private:
		Register_4Bits *Reg_1, *Reg_2;
		Register_3Bits *Reg_3;
		Splitter *Split;
		sc_signal<sc_uint<4> > Spliter_Signal_1, Spliter_Signal_2;
		sc_signal<sc_uint<3> > Spliter_Signal_3;
};

#endif