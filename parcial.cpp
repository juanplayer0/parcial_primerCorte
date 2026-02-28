#include <iostream>
#include <cmath>

using namespace std;

struct Point{
    double x;
    double y;
};

double calcularMayorMagnitud(Point puntos[], int n, int &indiceMayor){
    if(n <= 0){
        indiceMayor = -1;
        return 0;
    }

    double mayor = 0;
    indiceMayor = 0;

    for(int i = 0; i < n; i++){
        double m = sqrt(puntos[i].x * puntos[i].x + puntos[i].y * puntos[i].y);
        if(i == 0){
            mayor = m;
            indiceMayor = 0;
        }else{
            if(m > mayor){
                mayor = m;
                indiceMayor = i;
            }
        }
    }

    return mayor;
}

int main(){
    int n;
    cout << "Cantidad de puntos: ";
    cin >> n;

    if(n <= 0){
        cout << "No valido";
        return 0;
    }

    Point puntos[100];

    for(int i = 0; i < n; i++){
        cout << "Punto " << i << endl;
        cout << "x: ";
        cin >> puntos[i].x;
        cout << "y: ";
        cin >> puntos[i].y;
    }

    int indice;
    double resultado = calcularMayorMagnitud(puntos, n, indice);

    cout << "Indice mayor: " << indice << endl;
    cout << "Magnitud mayor: " << resultado << endl;

    return 0;
}
