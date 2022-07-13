#include <iostream>
#include <iomanip>
using namespace std;
 
int main() {
double salariofixo, montante;
string nome;
cin >> nome;
cin >> salariofixo;
cin >> montante;
cout << fixed << setprecision(2);
cout << "TOTAL = R$ "<< salariofixo + (montante * 0.15) << endl; 
    
    return 0;
}