#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct data{
    string nombre;
    int problemas [10] = {0,0,0,0,0,0,0,0,0,0};
    int problemasAceptados =0;
    int tiempo=0;
    int cont = 0;
    int penalty [10] = {0,0,0,0,0,0,0,0,0,0};
};

bool comparacion(data v1, data v2){
    if(v1.problemasAceptados==v2.problemasAceptados){
        return v1.tiempo < v2.tiempo;
    }
    return v1.problemasAceptados > v2.problemasAceptados;
}

int main(){
    int T, P;
    int S;
    string nombre;

    cin >> T >> P;
    vector<data> datos(T);

    for(int x=0;x<T;x++){
        cin >> datos[x].nombre;
    }
    cin >> S;

    string nom, resp;
    char prob;
    int time;
    for(int x=0;x<S;x++){
        cin >> nom >> prob >> time >> resp;
        for(int y=0;y<T;y++){
            if(datos[y].nombre==nom){
                if(resp == "A"){
                    datos[y].problemasAceptados++;
                    datos[y].tiempo += (time-datos[y].problemas[prob-65]);
                    datos[y].tiempo += datos[y].penalty[prob-65]*20;
                }else{
                    datos[y].penalty[prob-65]++;
                }
            }
        }
    }

    sort(datos.begin(), datos.end(), comparacion);

    for(int x=0;x<T;x++){
        cout << x+1 << " - " << datos[x].nombre << " " << datos[x].problemasAceptados << " ";
        datos[x].tiempo > 0 ? cout << datos[x].tiempo << endl : cout << "-" << endl;
    }
}
