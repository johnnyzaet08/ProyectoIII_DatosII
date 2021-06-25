#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Server.h"
#include "Disk.h"
#include <tinyxml.h>
#include "tinyxml/tinyxml.h"


int main(){

    int puerto = 10001;
    int tamano = 1024;

    Disk *Disco1 = new Disk(tamano);
    Disk *Disco2 = new Disk(tamano);
    Disk *Disco3 = new Disk(tamano);
    Disk *Disco4 = new Disk(tamano);
    Server *Servidor = new Server(puerto);

    srand(time(NULL));
    nodeDisk = rand() % 10;
    build_simple_doc("127.0.0.1", 10005, nodeDisk);

    std::string text, revisar, textSalida, puntero;

    while(true){
    	textSalida = "";
        
        text = Servidor->Recibir();
        Servidor->Enviar(textSalida);
    }

    return 0;


void build_simple_doc(std::string ip, int puerto, int Nodedisk)
{
	TiXmlDocument doc;
	TiXmlDeclaration * decl = new TiXmlDeclaration( "1.0", "", "" );
    doc.LinkEndChild( decl );

	TiXmlElement * elementP = new TiXmlElement( "IP" );
	TiXmlText * textP = new TiXmlText(to_str(ip));
	elementP->LinkEndChild( textP );
	doc.LinkEndChild( elementP );

    TiXmlElement * elementM = new TiXmlElement( "Puerto" );
	TiXmlText * textM = new TiXmlText( to_strPo(puerto) );
	elementM->LinkEndChild( textM );
	doc.LinkEndChild( elementM );

	doc.SaveFile( "./xml/" + std::to_string(Nodedisk) + ".xml" );
}