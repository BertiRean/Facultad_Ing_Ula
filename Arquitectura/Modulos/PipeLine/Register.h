#ifndef REG_H
#define REG_H

#include <systemc.h>

class Register : public sc_module
{
	public:
		sc_in<bool> d_In_Reg;
		sc_out<bool> d_Out_Reg;
		sc_in<bool> Clock_In_Reg;
		bool internal_Data;

		SC_CTOR(Register)
		{
			internal_Data = false;

			SC_METHOD(Input_Of_Register);
			sensitive << d_In_Reg << Clock_In_Reg.pos();

			SC_METHOD(Output_Of_Register);
			sensitive << Clock_In_Reg.neg();
		}

	private:
		void Input_Of_Register()
		{
			internal_Data = d_In_Reg.read();
		}

		void Output_Of_Register()
		{
			d_Out_Reg.write(internal_Data);
		}
	
};

#endif
