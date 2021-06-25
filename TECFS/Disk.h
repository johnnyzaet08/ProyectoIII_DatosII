#ifndef MEMORY_H
#define MEMORY_H


#include <iostream>
#include <stdlib.h>
#include <memory.h>
#include "block.h"

class Disk{
    public:
        void *memoryTotal;
        int *memoryUsed;
        Bloque bloque1, bloque2, bloque3, bloque4;
    
    Disk(int tamano){
        if((memoryTotal = malloc(tamano))==NULL){
            std::cout << "No se pudo crear el espacio de memoria solicitado" << std::endl;
        } else{
            std::cout << "Espacio de memoria creado con: " << tamano << " bytes" << std::endl;
            
            bloque1 = new Bloque(memoryTotal);
            bloque2 = new Bloque(memoryTotal);
            bloque3 = new Bloque(memoryTotal);
            bloque4 = new Bloque(memoryTotal);

        }
    }
    bool Revisar(int);
    void* Agregar(std::string);
    void Clear();
};

bool Disk::Revisar(int espacio){
    if((memoryUsed+espacio) > memoryTotal){
        std::cout << "Espacio en memoria insuficiente" << std::endl;
        return false;
    } else{
        return true;
    }
}


void Disk::Clear(){
    this->Clear();
}

#endif