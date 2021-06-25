#include <iostream>
#include <cstdlib>
#include "Server.h"



int main(){

    int puerto = 10010;

    Server *Servidor = new Server(puerto);

    std::string text, revisar, textSalida, puntero;

    while(true){
    	textSalida = "";
        
        text = Servidor->Recibir();
        Servidor->Enviar(textSalida);
    }

    return 0;
}