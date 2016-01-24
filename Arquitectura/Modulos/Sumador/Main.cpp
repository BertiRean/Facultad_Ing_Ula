#include "Sumador.h"
#include "TestBench.h"

//EL PROGRAMA CLAVE, DONDE SE CONECTA NUESTRO MODULO CON SU TEST BENCH, para realizar las pruebas pertinentes.

int sc_main(int argc,char *argv[])
{
	sc_time PERIOD(10,SC_NS);	
	sc_time DELAY(10,SC_NS);	
	sc_clock clock("clock",PERIOD,0.5,DELAY,true);

	Sumador Sumador_Test("Sumador_Test");
	TestBench test("test");

	sc_signal<bool> a_sg, b_sg, c_sg, d_sg, sum_sg; //Se declaran los 'cables' o señales que conectaran el modulo con el testbench

  //Comienza la conexion entre el modulo y el testbench meidante los cables anteriormente declarados
	Sumador_Test.a_In_Sumador(a_sg);
	Sumador_Test.b_In_Sumador(b_sg);
	Sumador_Test.c_In_Sumador(c_sg);
	Sumador_Test.c_Out_Sumador(sum_sg);
	Sumador_Test.d_Out_Sumador(d_sg);


	test.Clock_In(clock);
	
	test.a_Out_Test(a_sg);
	test.b_Out_Test(b_sg);
	test.c_Out_Test(c_sg);
	test.c_In_Test(sum_sg);
	test.d_In_Test(d_sg);

	sc_start();
	return 0;
}