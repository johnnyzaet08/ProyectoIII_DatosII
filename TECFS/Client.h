/**
 * @file Client.h
 * @author Johnny Aguero
 * @brief Create the Client socket and the necessary logic
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>


/**
 * @brief create the client socket
 */
class Client{
    public:
        int client;
        int portNum = 10500;
        const char* ip = "127.0.0.1";
    
    //Constructor
    Client(){
        struct sockaddr_in server_addr;
        client = socket(AF_INET, SOCK_STREAM, 0);

        if (client < 0){
            std::cout << "\nError al establecer el socket" << std::endl;
            exit(1);
        }

        std::cout << "\n=> Socket del cliente creado" << std::endl;
        
        server_addr.sin_addr.s_addr = inet_addr(ip);
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(portNum);

        if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
            std::cout << "=> Conectando al servidor en el puerto: " << portNum << std::endl;
    }

    //Metodos
    void Enviar(std::string);

};

/**
 * @brief send the menssage of the server
 * @return string menssage to send at the server.
 */
void Client::Enviar(std::string text){
    int bufsizeS = 1024;
    char bufferS[1024];
    std::copy(text.begin(), text.end(), bufferS);
    send(client, bufferS, bufsizeS, 0);
}

#endif
