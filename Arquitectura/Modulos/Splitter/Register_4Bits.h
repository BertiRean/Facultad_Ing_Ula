#ifndef REGISTER_4BITS_H
#define REGISTER_4BITS_H

#include <systemc.h>

class Register_4Bits : public sc_module
{
	public:
		sc_in<bool> Clock_In_Reg, Enable_In_Reg;
		sc_in<sc_uint <4> > Reg_In_4;
		sc_out<sc_uint <4> > Reg_Out_4;

		sc_uint<4> Reg_Data;

		SC_CTOR(Register_4Bits)
		{
			Reg_Data = 0;
			SC_METHOD(Input_Of_Register);
				sensitive << Reg_In_4 << Enable_In_Reg << Clock_In_Reg.pos();

			SC_METHOD(Output_Of_Register);
				sensitive << Clock_In_Reg.neg();
		}

	private:
		void Input_Of_Register()
		{
			if(Enable_In_Reg.read())
				Reg_Data = Reg_In_4.read();
		}

		void Output_Of_Register()
		{
			Reg_Out_4.write(Reg_Data);
		}
	
};

#endif