/**
 * @file Disk.h
 * @author Johnny Aguero
 * @brief Disco para con sus bloques
 * @version 0.1
 * @date 2021-06-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef DISK_H
#define DISK_H


#include <iostream>
#include <stdlib.h>
#include <memory.h>
#include "Block.h"

/**
 * @brief Crea el disco y sus bloques para almacenar datos
 * 
 */
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

/**
 * @brief Revisa si aun tiene espacio
 * 
 * @param espacio 
 * @return true 
 * @return false 
 */
bool Disk::Revisar(int espacio){
    if((memoryUsed+espacio) > memoryTotal){
        std::cout << "Espacio en memoria insuficiente" << std::endl;
        return false;
    } else{
        return true;
    }
}

/**
 * @brief Elimina el disco
 * 
 */
void Disk::Clear(){
    this->Clear();
}

#endif
