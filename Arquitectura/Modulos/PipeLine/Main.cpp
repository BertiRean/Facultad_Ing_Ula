#include "Pipeline.h"
#include "TestBench.h"

int sc_main(int argc,char *argv[]){
	sc_time DELAY(10,SC_NS);
	sc_time PERIOD(10,SC_NS);
	
	sc_clock clk("clock",PERIOD,0.5,DELAY,true);
	sc_signal<bool> a,b,c,d,e,s,r;
	Pipeline pipeline("pipeline");
	TestBench test("test");

	pipeline.a_In_Pipe(a);
	pipeline.b_In_Pipe(b);
	pipeline.c_In_Pipe(c);
	pipeline.d_In_Pipe(d);
	pipeline.e_In_Pipe(e);
	pipeline.s_Out_Pipe(s);
	pipeline.r_Out_Pipe(r);
	pipeline.Clock_In_Pipe(clk);
	
	
	test.a_Out_Test(a);
	test.b_Out_Test(b);
	test.c_Out_Test(c);
	test.d_Out_Test(d);
	test.e_Out_Test(e);
	test.s_In_Test(s);
	test.r_In_Test(r);
	test.Clock_In_Test(clk);

	sc_start();
	
return 0;
}
