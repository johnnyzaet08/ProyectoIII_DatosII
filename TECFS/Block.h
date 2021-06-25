/**
 * @file bloque.h
 * @author Johnny Aguero
 * @brief  Struc of the node disk
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef BLOQUE_H
#define BLOQUE_H

#include <stddef.h>
#include "listasimple.h"


class Bloque {
public:
    int bytes = 0;
    int* data;
    ListaSimple<int> *dataBytes = new ListaSimple<int>();

    // Constructores
    Bloque(){

    }
    Bloque(void * memoryT){
        data = (int*)memoryT;
    }

    void set(int dato){
        data[bytes] = dato;
        dataBytes->insertar(dato);
        bytes++;
    }
    
    int get(int pos){
        int temp = dataBytes->obtenerPos(pos);
        return temp;
    }

    bool empty(){
        if (bytes == 256){
            return true;
        }
        else{
            return false;
        }
    }
};

#endif