#include <iostream>

using namespace std;
template<typename compara>
compara valor(compara x,compara y)
{
    return  bool(x+y);
}
 int main(){
     cout<<valor<int>(2,3)<<endl;
 }