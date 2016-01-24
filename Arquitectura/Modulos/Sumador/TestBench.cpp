#include "TestBench.h"

void TestBench::Test()
{
	// Empezamos a escribir Valores sobre las entradas de mi compuerta //

	a_Out_Test.write(0);
	b_Out_Test.write(0);
	c_Out_Test.write(0);

	wait();
	Print_Result();

	a_Out_Test.write(0);
	b_Out_Test.write(0);
	c_Out_Test.write(1);

	wait();
	Print_Result();

	a_Out_Test.write(0);
	b_Out_Test.write(1);
	c_Out_Test.write(0);

	wait();
	Print_Result();

	a_Out_Test.write(0);
	b_Out_Test.write(1);
	c_Out_Test.write(1);

	wait();
	Print_Result();

	a_Out_Test.write(1);
	b_Out_Test.write(0);
	c_Out_Test.write(0);

	wait();
	Print_Result();

	a_Out_Test.write(1);
	b_Out_Test.write(0);
	c_Out_Test.write(1);

	wait();
	Print_Result();

	a_Out_Test.write(1);
	b_Out_Test.write(1);
	c_Out_Test.write(0);

	wait();
	Print_Result();

	a_Out_Test.write(1);
	b_Out_Test.write(1);
	c_Out_Test.write(1);

	wait();
	Print_Result();

	sc_stop();


}

void TestBench::Print_Result()
{
	cout<<sc_time_stamp()<<"\t"
		<<a_Out_Test.read()<<"\t"
		<<b_Out_Test.read()<<"\t"
		<<c_Out_Test.read()<<"\t"
		<<c_In_Test.read()<<"\t"
		<<d_In_Test.read()<<"\t"<<endl;
}