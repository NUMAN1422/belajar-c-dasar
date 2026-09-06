#include <iostream> 
using namespace std;

int main() {

    int a,b;

    cout << "masukkan bilangan 1 :";
    cin >> a ;

   cout << "masukkan bilangan 2 :";
   cin >> b ;
   
   if(a == b){
    cout << "a dan b sama" << endl;
   }
   else {
    if (a > b){
        cout << "bilangan 1 lebih besar" << endl;
    }
    else {
        cout << " bilangan 2 lebih besar" << endl;
    }

   }
   return 0;
}