#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <sstream>
#include <math.h>  
#include <iomanip>      
using namespace std;

int menu,menu2,menu3,menu4;


float D11=0; // y
float SCS11=0; //xi1
float SFS5=0; //h



void printKutta();
void printEuler();
void getValues();
float ABS(float number);


int main() {
	
	do {
	

	
		cout<<"\t\tMenu "<<endl<<endl;
	cout<<"1.Hoja de Presentacion"<<endl;
	cout<<"2.Problema - Metodo de Euler Mejorado"<<endl;
	cout<<"3.Problema - Metodo Runge-Kutta"<<endl;
	cout<<"4.Salir"<<endl;
	cout<<"Elija la opcion que desea:"<<endl;
	cin>>menu;
	system("cls");
	
		switch(menu){
			case 1: 
				cout<<"\tUNIVERSIDAD TECNOLOGICA DE PANAMA"<<endl;
					cout<<"\tFACULTAD DE SISTEMAS Y COMPUTACION"<<endl;
					cout<<"LICENCIATURA EN INGENIERIA EN SISTEMAS COMPUTACIONALES"<<endl;
					cout<<"\tMETODOS NUMERICOS PARA INGENIEROS"<<endl;
					cout<<"\t\tPROYECTO FINAL"<<endl;
					cout<<"\t\t   TEMA: "<<endl;
						cout<<"\t EULER, RUNGE-KUTTA"<<endl;
					cout<<"SISTEMAS DE ECUACIONES ALGEBRAICAS LINEALES"<<endl;
					cout<<"FACILITADOR: ING.JACQUELINE S. DE CHING"<<endl;
					cout<<"\t\tINTEGRANTES:"<<endl;
					cout<<"\t IVES DE LA CRUZ 6-720-1526"<<endl;
					cout<<"\t ADOLFO FERNANDEZ 8-934-485"<<endl;
					cout<<"\t\t 1IL-124"<<endl;
					cout<<"\t\t 20/10/19"<<endl;
					system("pause");
					system("cls");
			break;
			
			case 2: 
				cout<<"Euler Modificado "<<endl;
				cout<<"Funcion: y(x)=-1+5+1.5*exp(-x)"<<endl;
				
			
				
				getValues();
				printEuler();
				
				system("pause");
				system("cls");	
			break; 
			
			case 3: 
				cout<<"Metodo Runge-Kutta "<<endl;
				cout<<"Funcion: y(x)=x-1/x "<<endl;
				
				 getValues();
				
				printKutta();
				cout <<"\n";
				system("pause");
				system("cls");	
			break;  
			
		}

	}while(menu!=4);
}

void printKutta(){
	
	float B11=0;//i
	float C11=0; //x
	float C12=0; //x
	float D12=0;
	float E12=0;
	float F12=0;
	float G12=0;
	float H12=0;
	float I12=0;
	float J12=0;
	float K12=0;
	
	 std::cout <<"| i "<<" |   xi "<< "    |    yi  "<< "  |    k1  "<< " |    k2 " << " |    k3 "<< "  |    k4  ";
	 std::cout <<" |  Sol. Exac | "<<" Error abs" << "  |  ERAP   |";
	 cout <<endl;
	 {
	 	cout<<"| ";
	 	 	std::cout<< fixed << std::setprecision(0)<<B11;
	 	 	cout<<"  |  ";
	 	 	std::cout<< fixed << std::setprecision(4)<<SCS11;
	 	 	cout<<"  |  "<< D11;
	 	 	B11=1;
	 	 	cout <<endl;
	 	 	
	 	 	C11 = SCS11;
	 	 	
	 	//std::cout <<"| " << closed [c][0];
	 	}
	 	
	 for (int j=1;j<=10;j++){
	 	
	 	C12=SCS11+(B11*SFS5);
	 	E12=SFS5*(2-D11/C11);
	 	F12=SFS5*(2-((D11+(E12/2))/(C11+(SFS5/2))));
	 	G12=SFS5*(2-((D11+(F12/2))/(C11+(SFS5/2))));
	 	H12=SFS5*(2-((D11+(G12))/(C11+(SFS5))));
	 	D12=((((E12+2*(F12)+2*G12+H12)))/6)+D11;
	 	I12=C12-(1/C12);
	 	J12=(ABS(I12-D12)/I12);
	 	K12=((ABS(I12-D12)/I12)*100);
	 	
		 
	 	cout<<"| ";
	 	 	std::cout<< fixed << std::setprecision(0)<<B11;
	 	 	cout<<"  |  ";
	 	 	std::cout<< fixed << std::setprecision(4)<<C12;
	 	 	cout<<"  |  "<<D12;
	 	 	 cout <<" |  "<< E12;
	 	 	 cout <<" |  "<< F12;
	 	 	 cout <<" |  "<< G12;
	 	 	  cout <<" |  "<< H12;
	 	 	  cout <<" |  "<< I12;
	 	 	   cout <<" |  ";
	 	 	  std::cout<< fixed << std::setprecision(7)<<J12;
	 	 	  cout <<" |  "<< K12;
			  
			  cout <<endl;

			  C11=C12;
			  D11=D12;
			  B11++;
			
			  
			 
			  
			  
			  
			  
			  	
	 	//std::cout <<"| " << closed [c][0];
	 	}
	 		
}

void printEuler(){
	
float B11=0;//i
float C11=0; //x
float C12=0; //x
float D12=0;
float E11=0;
float E12=0;
float F11=0;
float F12=0;
float G11=0;
float G12=0;
float H11=0;
float H12=0;
float I11=0;
float I12=0;
float J12=0;
float K12=0;
	
	 std::cout <<"| i "<<" |   xi "<< "    |    yi "<< "  |   yi,c  "<< " |  yi+1,p " << " | Sol. Ex "<< "| Error Abs " << " | ERP";

	 cout <<endl;
	 
	 {
	 	
	 		C11=SCS11;
	 		D11=D11;
	 		E11=C11-D11;
	 		F11=C11+SFS5-(D11+E11*SFS5);
	 		G11=-1+C11+1.5*exp(-C11);
	 		H11=(ABS(G11-D11)/G11);
	 		
	 		
	 		
	 		cout<<"| ";
	 	 	std::cout<< fixed << std::setprecision(0)<<B11;
	 	 	cout<<"  |  ";
	 	 	std::cout<< fixed << std::setprecision(4)<<C11;
	 	 	cout<<"  |  "<< D11;
	 	 	cout <<" |  "<< E11;
	 	 	cout <<" |  "<< F11;
	 	 	cout <<" |  "<< G11;
	 	 	cout <<" |  "<< H11;
	 	 	
	 	 	
	 	 	cout <<endl;
	 	 	B11++;
	 	
	 }
	 
	 
	 
	  for (int j=1;j<=12;j++){
	  	
	  	//Ciclo for 
	  	
	  		C12=C11+SFS5;
	 		D12=D11+(E11+F11)/2*SFS5;
	 		E12=C12-D12;
	 		F12=C12+SFS5-(D12+E12*SFS5);
	 		G12=-1+C12+1.5*exp(-C12);
	 		H12=(ABS(G12-D12)/G12);
	 		I12=(ABS(G12-D12)/G12)*100;
	 		
	 		cout<<"| ";
	 	 	std::cout<< fixed << std::setprecision(0)<<B11;
	 	 	cout<<"  |  ";
	 	 	std::cout<< fixed << std::setprecision(4)<<C12;
	 	 	cout<<"  |  "<< D12;
	 	 	cout <<" |  "<< E12;
	 	 	cout <<" |  "<< F12;
	 	 	cout <<" |  "<< G12;
	 	 	cout <<" |  "<< H12;
	 	 	cout <<" |  ";
	 		std::cout<< fixed << std::setprecision(2)<<I12*100 <<"%";
	 	 
	  	
	  	
	 	 	 	 
	 	 	  cout <<endl;
	  	
	  	B11++;
	  	C11=C12;
	  	D11=D12;
	  	E11=E12;
	  	F11=F12;
	  	
	  	
	  }
	  	
	  	
	
	
}

void getValues(){
	
	cout <<"Inserte x0: ";
	cin >> SCS11;
	
		cout <<"Inserte y0: ";
	cin >> D11;
	
		cout <<"Inserte h: ";
	cin >> SFS5;
	
		cout <<endl;
			cout <<endl;
	
}


float ABS (float number){
	
	if (number <0){
		number=number *-1;
	}
	return number;
	
}

