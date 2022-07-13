#include "Hospital.h"

void Hospital::setDados(int p,string name,string d,int r){
	prioridade=p;
	nome=name;
	doenca=d;
	registro=r;
}
void Hospital::FilaPrioridade(){
	if(prioridade==1){ 
		sp.push_back(registro);
        dc.push_back(doenca);
		n.push_back(nome);
	}
	else{ 
		np.push_back(registro);
        dc.push_back(doenca);
		n.push_back(nome);
    }	
}
int Hospital::getRPaciente(){
	int aux,aux2;
	int a=1;
	if(prioridade==1){ 
		aux=sp[0];
		sp[0]=sp[a];
		a=a+1;	
		return aux;		
	}
	if(prioridade==2){
		aux2=np[0];	
		np[0]=np[1];
		return aux2;
	}
} 
string Hospital::RemoverP(int r2){
	registro2=r2;
	for(int i=0;i<sp.size();i++){
		if(registro2==sp[i]){
			sp[i]=0;
			return "Paciente removido da fila com sucesso";
		}
		else{
			return "Paciente não encontrado";
        }
	}	
	for(int i=0;i<np.size();i++){
		if(registro2==np[i]){
			np[i]=0;
			return "Paciente removido da fila com sucesso";
		}
		else{
			return "Paciente não encontrado";
        }	
	}	
}
void Hospital::ExibirPaciente(int op){
	opcao=op;
	int a=0;
	if(opcao==1){ 
		reg.push_back(registro);
		dc.push_back(doenca);
		n.push_back(nome);
	}	
	if(opcao==2){
		reg[a]=0;
		dc[a]="";
		n[a]="";
		a=a+1;
   }
	for(int i=0;i<reg.size();i++){
   	   if(opcao==3 & registro2==reg[i]){
	   	   reg[i]=0;
	   	   dc[i]="";
	   	   n[i]="";
 	   }
	}   	
	if(opcao==4){
		for(int i=0;i<reg.size();i++){
			cout<<reg[i]<<"|"<<n[i]<<"|"<<dc[i]<<endl;
		}
	}	 				
}
void Hospital::MostrarPaciente(int r3){
	registro3=r3;
	for(int i=0;i<reg.size();i++){
		if(registro3==reg[i]){
			cout<<"Paciente:"<<n[i]<<endl;
			cout<<"Doença:"<<dc[i]<<endl;
		}
	}	
}
void Hospital::PacientesAtendidos(){
	if(opcao==2){
		Ratendidos.push_back(registro);
		Datendidos.push_back(doenca);
		Natendidos.push_back(nome);
	}
	if(opcao==6){
		for(int i=0;i<Ratendidos.size();i++){
			cout<<Ratendidos[i]<<"|"<<Natendidos[i]<<"|"<<Datendidos[i]<<endl;
		}
	}
}