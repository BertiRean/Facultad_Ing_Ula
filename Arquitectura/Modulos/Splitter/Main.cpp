#include <Splitter_Reg.h>
#include <TestBench.h>

int sc_main(int argc,char *argv[]){
	sc_time DELAY(10,SC_NS);
	sc_time PERIOD(10,SC_NS);
	
	sc_clock clk("clock",PERIOD,0.5,DELAY,true);
	sc_signal< sc_uint<11> > d1;
	sc_signal< sc_uint<4> > d2, d3;
	sc_signal< sc_uint<3> > d4;
	sc_signal< bool > enable_sg;
	Splitter_Reg splitter_regs("splitter_regs");
	TestBench test("test");

	splitter_regs.Splitter_Reg_In(d1);
	splitter_regs.Splitter_Reg_Out_4_a(d2);
	splitter_regs.Splitter_Reg_Out_4_b(d3);
	splitter_regs.Splitter_Reg_Out_3(d4);
	splitter_regs.Enable_Split(enable_sg);
	splitter_regs.Clk_In_Split_Reg(clk);
	
	
	test.data_out(d1);
	test.data1_in(d2);
	test.data2_in(d3);
	test.data3_in(d4);
	test.enable_out(enable_sg);
	test.clk_in(clk);

	sc_start();
	
	return 0;
}
