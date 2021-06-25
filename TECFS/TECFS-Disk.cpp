#include <iostream>
#include <cstdlib>
#include "Server.h"
#include "Client.h"
#include <tinyxml.h>
using namespace std;
int revisar(string texto){
int i = 0;
while(i < texto.size()){
if(texto[i] == 1 || texto[i] == 2 || texto[i] == 3 || texto[i] == 4 || texto[i] == 5){
return isdigit(texto[i]);
}
i++;
}
}

string abrirxml(int file){
TiXmlDocument doc;
doc.LoadFile("./xml/" + to_string(file) + ".xml");
auto Element = doc.RootElement();

cout << Element->GetText();
}

int main(){

    int puerto = 10010;

    //Server *Servidor = new Server(puerto);
    Client *Cliente = new Client(10001);
    
    string text, textSalida, puntero;
    abrirxml(2);

    //while(true){
    	textSalida = "";
        
        text = Cliente->Recibir();
        int file = revisar(text);
        abrirxml(file);
        cin >> puntero;
        Cliente->Enviar(textSalida);
    //}

    return 0;
}
