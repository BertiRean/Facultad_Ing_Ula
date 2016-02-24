#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>
#include <iostream>


class TestBench: public sc_module{

	public:
		sc_in<bool> clk_in;
		sc_in < sc_uint<4> > data1_in, data2_in;
		sc_in < sc_uint<3> > data3_in;
		sc_out < sc_uint<11> > data_out;
		sc_out<bool> enable_out;
	
		SC_CTOR(TestBench){
			SC_THREAD(test);
				sensitive<<clk_in.pos();
				dont_initialize();
}
	private:
		void test();
		void print();
};

#endif
