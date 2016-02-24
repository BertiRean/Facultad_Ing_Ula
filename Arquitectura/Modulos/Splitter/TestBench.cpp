#include "TestBench.h"

void TestBench::test(){
	//std::cout<< "\n" <<endl<<"\t\tX\tY\tSEL\tR"<<endl;
	std::cout<<"\t\t__________________________________________"<<endl<<endl;
	std::cout << "\t\t" << "d_out" << "\t | " << "en_out" << "\t || " << "data splitted" << "\n\n";

  //RECUERDEN QUE CUANDO EL ENABLE ES 0, NO habra escritura en el registro, y cuando es 1 SI habra escritura
	
  data_out.write(1402);
  enable_out.write(1);
  
	wait();
	print();
	
	data_out.write(7);
  enable_out.write(0);
  
	wait();
	print();
	
	data_out.write(128);
  enable_out.write(1);
  
	wait();
	print();
	
	data_out.write(6);
  enable_out.write(0);
  
	wait();
	print();
	
	
	sc_stop();
}



void TestBench::print(){
  std::cout << "\t\t" << data_out.read() << "\t | " << enable_out.read() << "\t\t || " << data1_in.read() << " \t\t " << data2_in.read() << " \t\t " << data3_in.read() << "\n";
  std::cout << "\t\t" << data_out.read() << "\t | " << enable_out.read() << "\t\t || " << data1_in.read().to_string(SC_BIN) << "  " << data2_in.read().to_string(SC_BIN)  << "  " << data3_in.read().to_string(SC_BIN)  << "\n\n";
  //OTRA MANERA DE IMPRIMIR LOS DATOS (PARA VERLOS COMO NUMEROS BINARIOS)
	std::cout<<"\t\t__________________________________________"<<"\n";
}
