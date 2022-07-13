#include <iostream>
 
using namespace std;

 int main(){
    int a=0,opcao,b;
    string nomes[a],atendidos[b];
    while(opcao!=4){
        cout<<"1-inseri\n2-remover\n3-percurso\n 4-sair"<<endl;
        cout<<"digite sua opcao"<<endl;
        cin>>opcao;
    
            if(opcao==1){
                a++;
                cin>>nomes[a-1];
            }
            if (opcao==2){
                b++;
                atendidos[b] = nomes[0];
                for(int i=0;i<a;i++){
                    nomes[i]=nomes[i+1];
                }
                a--;}
            if(opcao==3){
                for(int i=0;i<a;i++){
                    cout<<nomes[i]<<endl;
                }
            }

            

        
    }
 }