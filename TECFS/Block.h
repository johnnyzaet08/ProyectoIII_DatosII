/**
 * @file Block.h
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

/**
 * @brief Contiene el almacenador de datos
 * 
 */
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

    /**
     * @brief Guarda el byte del cliente
     * 
     * @param dato 
     */
    void set(int dato){
        data[bytes] = dato;
        dataBytes->insertar(dato);
        bytes++;
    }
    
    /**
     * @brief Accede a los bytes del bloque
     * 
     * @param pos 
     * @return int 
     */
    int get(int pos){
        int temp = dataBytes->obtenerPos(pos);
        return temp;
    }

    /**
     * @brief Revisa si esta vacia
     * 
     * @return true 
     * @return false 
     */
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