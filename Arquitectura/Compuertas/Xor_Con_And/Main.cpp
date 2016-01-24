#include "Xor_GateComp.h"
#include "TestBench.h"

//EL PROGRAMA CLAVE, DONDE SE CONECTA NUESTRO MODULO CON SU TEST BENCH, para realizar las pruebas pertinentes.

int sc_main(int argc,char *argv[])
{
	sc_time PERIOD(10,SC_NS);	
	sc_time DELAY(10,SC_NS);	
	sc_clock clock("clock",PERIOD,0.5,DELAY,true);

	Xor_GateComp xorcomp_gate("xorcomp_gate");
	TestBench test("test");

	sc_signal<bool> a_sg, b_sg, c_sg; //Se declaran los 'cables' o señales que conectaran el modulo con el testbench

  //Comienza la conexion entre el modulo y el testbench meidante los cables anteriormente declarados
	xorcomp_gate.a_In_Xor(a_sg);
	xorcomp_gate.b_In_Xor(b_sg);
	xorcomp_gate.c_Out_Xor(c_sg);

	test.Clock_In(clock);
	test.c_In_Test(c_sg);
	test.a_Out_Test(a_sg);
	test.b_Out_Test(b_sg);

	sc_start();
	return 0;
}