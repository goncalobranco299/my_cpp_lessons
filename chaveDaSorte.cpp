#include <iostream>
using namespace std;

 int myArray[] = { 1, 2, 3, 4, 5};

    string letras [2][4];

    string letras2 [2][4] {
        {"A","B","C","D"},
        {"E","F","G","H"}
    };

 int main(){

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 4; j++){
            cout << letras2[i][j] << endl;
    }
    }
        return 0;
}


