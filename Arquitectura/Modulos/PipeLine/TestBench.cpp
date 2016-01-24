#include "TestBench.h"
#include <iostream>

void TestBench::Test()
{
	int n = 0;
	//std::cout<< "\n" <<endl<<"\t\tX\tY\tSEL\tR"<<endl;
	std::cout<<"\t\t__________________________________________"<<endl<<endl;
	
	std::cout << "\t\tCLOCK: " << n << "\n"; n++;

	a_Out_Test.write(0);
	b_Out_Test.write(0);
	c_Out_Test.write(0);
	d_Out_Test.write(0);
	e_Out_Test.write(0);

	wait();
	Print_Result();

	std::cout << "\t\tCLOCK: " << n << "\n"; n++;

	a_Out_Test.write(1);
	b_Out_Test.write(0);
	c_Out_Test.write(0);
	d_Out_Test.write(0);
	e_Out_Test.write(0);

	wait();
	Print_Result();

	std::cout << "\t\tCLOCK: " << n << "\n"; n++;

	a_Out_Test.write(1);
	b_Out_Test.write(1);
	c_Out_Test.write(0);
	d_Out_Test.write(0);
	e_Out_Test.write(0);


	wait();
	Print_Result();

	std::cout << "\t\tCLOCK: " << n << "\n"; n++;
	std::cout << "\t\tSE COMIENZAN A VER LOS RESULTADOS DE LOS DATOS ENVIADOS EN EL CLOCK 0:\n";

	a_Out_Test.write(1);
	b_Out_Test.write(1);
	c_Out_Test.write(1);
	d_Out_Test.write(0);
	e_Out_Test.write(0);


	wait();
	Print_Result();

	std::cout << "\t\tCLOCK: " << n << "\n"; n++;
  	std::cout << "\t\tSE COMIENZAN A VER LOS RESULTADOS DE LOS DATOS ENVIADOS EN EL CLOCK 1:\n";

	a_Out_Test.write(1);
	b_Out_Test.write(1);
	c_Out_Test.write(1);
	d_Out_Test.write(1);
	e_Out_Test.write(0);


	wait();
	Print_Result();

	std::cout << "\t\tCLOCK: " << n << "\n"; n++;
  	std::cout << "\t\tSE COMIENZAN A VER LOS RESULTADOS DE LOS DATOS ENVIADOS EN EL CLOCK 2:\n";

	a_Out_Test.write(1);
	b_Out_Test.write(1);
	c_Out_Test.write(1);
	d_Out_Test.write(1);
	e_Out_Test.write(1);

	wait();
	Print_Result();

	sc_stop();

}

void TestBench::Print_Result()
{
  std::cout << "                a | b | c | d" << endl;
  std::cout<< "Datos enviados: " << a_Out_Test.read()<< " | " << b_Out_Test.read() << " | " << c_Out_Test.read() << " | " << d_Out_Test.read() << " | " << e_Out_Test.read() <<\
		"\n\nDatos recibidos: s --> " <<s_In_Test.read()<<\
		"\t"<<"\n";

	std::cout<<"\t\t__________________________________________"<<"\n";
}