#ifndef SPLITTER_H
#define SPLITTER_H

#include <systemc.h>

class Splitter : public sc_module
{
	public:

		sc_in<sc_uint <11> > Splitter_In_11;
		sc_out<sc_uint <4> > Splitter_Out_4_a, Splitter_Out_4_b;
		sc_out<sc_uint <3> > Splitter_Out_3;

		SC_CTOR(Splitter)
		{
			SC_METHOD(Splitting)
				sensitive << Splitter_In_11;
		}
	
	private:
		void Splitting()
		{
			Splitter_Out_4_a.write(Splitter_In_11.read().range(10,7));
			Splitter_Out_4_b.write(Splitter_In_11.read().range(6,3));
			Splitter_Out_3.write(Splitter_In_11.read().range(2,0));
		}

};
#endif