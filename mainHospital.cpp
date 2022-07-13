#include <iostream>
#include <locale>
#include <cstdlib> //ou <stdlib.h>
#include <cstring>
#include <iomanip> 
#include <climits>
#include <cmath>
#include <utility>
#include <stack>
#include <vector>
#include <string>

using namespace std;

#include "Hospital.cpp"

int main(){
	//Aceita acentuação em português
	setlocale(LC_ALL, "Portuguese");
	int op,r,p,r2,r3;
	int a=0;
	int b=1;
	int c=0;
	int aux=0;
	string name,d;
	Hospital h;
	vector<int>repeticao;
	while(true){
		cout<<"-----------------"<<endl;
		cout<<" Hospital de CG  "<<endl;
		cout<<" -Sala de espera-"<<endl;
		cout<<"-----------------"<<endl;
		cout<<"Digite: "<<endl;
		cout<<"1)Adicionar um novo paciente."<<endl;
		cout<<"2)Atender paciente."<<endl;
		cout<<"3)Remover paciente da fila."<<endl;
		cout<<"4)Exibir fila."<<endl;
		cout<<"5)Exibir dados de um paciente."<<endl;
		cout<<"6)Exibir lista de pacinetes atendidos."<<endl<<endl;
		cout<<"0)sair do programa."<<endl;
		cout<<"Insira a opção desejada: ";
		cin>>op;  
		h.PacientesAtendidos();	
		if(op==0)
			break;
		if(op==1){
			aux=aux+1;
			cout<<"--Adição de paciente na fila--"<<endl;
			cout<<"Paciente necessita de atendimento prioritário? 1- SIM / 2- NÃO: ";
			cin>>p;
			if(p==1){
				cout<<"--Paciente com prioridade--"<<endl<<endl;
				cout<<"Preencha os dados do paciente: "<<endl<<endl;
				cout<<"Nome: ";
				cin>>name;
				cout<<"Doença: ";
				cin>>d;
				cout<<"Registro: ";
				cin>>r;
				repeticao.push_back(r);
				for(int i=b;i<repeticao.size();i++){
					if(repeticao[a]=repeticao[i]){
						c=c+1;
					}
					a=a+1;
					b=b+1;
				}
				if(c>0){
					cout<<"Já existe um paciente com o mesmo registro!"<<endl;
				}
				else{
					cout<<"Paciente cadastrado na fila com sucesso!"<<endl;
			   	   	h.setDados(p,name,d,r);	
					h.FilaPrioridade();
                    h.ExibirPaciente(op);	     	
				}	
			}
			else{
				cout<<"--Paciente sem prioridade--"<<endl<<endl;
				cout<<"Preencha os dados do paciente: "<<endl<<endl;
				cout<<"Nome: ";
				cin>>name;
				cout<<"Doença: ";
				cin>>d;
				cout<<"Registro: ";
				cin>>r;
				repeticao.push_back(r);
				for(int i=b;i<repeticao.size();i++){
					if(repeticao[a]=repeticao[i]){
						c=c+1;
					}
					a=a+1;
					b=b+1;
				}
				if(c>0){
					cout<<"Já existe um paciente com o mesmo registro!"<<endl;
				}
				else{
					cout<<"Paciente cadastrado na fila com sucesso!"<<endl;
			   	   	h.setDados(p,name,d,r);
					h.FilaPrioridade();	  
                    h.ExibirPaciente(op);	   	
				}	
			}
		}
		if(op==2){
			if(aux>0){
				cout<<"Paciente "<<h.getRPaciente()<<" atendido com sucesso!"<<endl;
				aux=aux-1;
			}
			else if(aux==0){
				cout<<"fila vazia: Nenhum paciente na fila de espera!"<<endl;
			}	
		}
		if(op==3){
			cout<<"Insira o registro do paciente: ";
			cin>>r2;
			aux=aux-1;
			cout<<h.RemoverP(r2)<<endl;
		} 
		if(op==4){
			h.ExibirPaciente(op);
		}
		if(op==5){
			cout<<"--Mostrar paciente da fila--"<<endl<<endl;
			cout<<"Digite o número de registro do paciente:";
			cin>>r3;
			h.MostrarPaciente(r3);
		}
		if(op==6){
			cout<<"--Pacientes ja atendidos--"<<endl<<endl;
			h.PacientesAtendidos();
		}
	}	
		
	return 0;
}