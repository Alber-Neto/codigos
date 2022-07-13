#ifndef HOSPITAL_H
#define HOSPITAL_H
class Hospital{
		int prioridade;
		string nome;
		string doenca;
		int opcao;
		int registro;
		int registro2;
		int registro3;
		vector<int> np;
		vector<int> sp;
		vector<int>reg;
		vector<string>dc;
		vector<string>n;
		vector<int>Ratendidos;
		vector<string>Datendidos;
		vector<string>Natendidos;
	public:
		void setDados(int,string,string,int);
		void FilaPrioridade();
		int getRPaciente();
		string RemoverP(int);
		void ExibirPaciente(int);
		void MostrarPaciente(int);
		void PacientesAtendidos();
};

#endif