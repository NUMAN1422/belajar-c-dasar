#include <iostream>
using namespace std;

int main() {
    int raport = 30;

    if (raport >=90){ //lebih dari sama dengan 50 maka akan keluar tulisan pintar
        cout << "anda pintar" << endl;
    }
    else if(raport >=70){
        cout << "anda lumayan pintar" << endl;
    

    }
    else{
        cout << "anda kurang pintar" << endl;
    }
    return 0;
}