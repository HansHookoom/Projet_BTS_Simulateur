
#include "ModBusTCP.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// * ModBUS TCP : Constructeur
//---------------------------------------------------------------------------
ModBusTCP::ModBusTCP(char *addr, unsigned char Num)
{
        // Affectation des attributs
        adresseAPI=new char [30];
        strcpy(adresseAPI,addr);   // Copier l'adresse de l'API
        NumEsclave = Num;
        port=502; // Port par défaut du serveur ModBusTCP

}

//---------------------------------------------------------------------------
// * ModBUS TCP : Connection à l'API
//---------------------------------------------------------------------------
int ModBusTCP::Connect()
{
        // déclaration des variables
        int err=1;

        // Traitement
        WSAStartup(MAKEWORD(2,0), &WSAData);
        sock = socket(AF_INET, SOCK_STREAM, 0);
        sin.sin_port = htons(port);
        sin.sin_addr.s_addr = inet_addr(adresseAPI);
        sin.sin_family = AF_INET;
        // Connection
        co=connect(sock, (SOCKADDR *)&sin, sizeof(sin)); 
        if (co== INVALID_SOCKET)
        {
                err=-1; // Erreur de connection
                closesocket(sock);
                WSACleanup();
        }

      return (err) ; // si -1 alors erreur
}

//---------------------------------------------------------------------------
// * ModBUS TCP : FONCTION 3 : Read Holding Registers
//---------------------------------------------------------------------------
int  ModBusTCP::SendRequete_Fct3(unsigned short Adresse, unsigned short  nbMots)
{

        //Déclaration et initialisation des variables
        int code_retour=0;
        tailleTrame=12; // Une trame de lecture

        unsigned char TrameModbusTCP[20]={0};

        // Entête de la trame ModBusTCP
        TrameModbusTCP[0] = 0x00;  // Transaction Identifier
        TrameModbusTCP[1] = 0x00;  // Transaction Identifier
        TrameModbusTCP[2] = 0x00;   // Protocole Identifier
        TrameModbusTCP[3] = 0x00;   // Protocole Identifier
        TrameModbusTCP[4] = 0x00;   // Length
        TrameModbusTCP[5] = 0x06 ; // Length
        TrameModbusTCP[6] = NumEsclave;  // Init Identifier

        // Fonction 3 : Read Holding Registers
        TrameModbusTCP[7] = 0x03;
        // Adresse de début sur 2 octets
        TrameModbusTCP[8] = (unsigned char)(Adresse & 0xFF00) >>8;
        TrameModbusTCP[9] = (unsigned char)(Adresse & 0x00FF) ;

        // Le nombre de mots à lire sur 2 octets
        TrameModbusTCP[10]= (unsigned char) (nbMots & 0xFF00) >>8;
        TrameModbusTCP[11] =(unsigned char)(nbMots & 0x00FF);

        //envoi de la trame sur le socket
         code_retour=send(sock,(char*)TrameModbusTCP,tailleTrame,0);
        /* Return Values If no error occurs, send returns the total number
         of bytes sent. (Note that this can be less than
        the number indicated by len.) Otherwise,a value of SOCKET_ERROR is
        returned, and a specific error code can be retrieved by
         calling WSAGetLastError.*/
        return(code_retour);

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// * ModBUS TCP : FONCTION 6 : Write Single  Register
//---------------------------------------------------------------------------

int  ModBusTCP::SendRequete_Fct6(unsigned short Adresse, unsigned short  data)
{
        //Déclaration et initialisation des variables
        int code_retour=0;
        tailleTrame=12; // Une trame de lecture

        unsigned char TrameModbusTCP[20]={0};

        // Entête de la trame ModBusTCP
        TrameModbusTCP[0] = 0x00;   // Transaction Identifier
        TrameModbusTCP[1] = 0x00;   // Transaction Identifier
        TrameModbusTCP[2] = 0x00;   // Protocole Identifier
        TrameModbusTCP[3] = 0x00;   // Protocole Identifier
        TrameModbusTCP[4] = 0x00;   // Length
        TrameModbusTCP[5] = 0x06 ;  // Length
        TrameModbusTCP[6] = NumEsclave;  // Init Identifier

        // Fonction 6 : Write Single Register
        TrameModbusTCP[7] = 0x06;
        // Adresse de début sur 2 octets
        TrameModbusTCP[8] = (unsigned char)(Adresse & 0xFF00) >>8;
        TrameModbusTCP[9] = (unsigned char)(Adresse & 0x00FF) ;

        // La donnée  à écrire  sur 2 octets
        TrameModbusTCP[10]=  (unsigned char)(data & 0xFF00) >>8;
        TrameModbusTCP[11] =(unsigned char)(data & 0x00FF);

        //envoi de la trame sur le socket
         code_retour=send(sock,(char*)&TrameModbusTCP,tailleTrame,0);
          /* Return Values If no error occurs, send returns the total number
         of bytes sent. (Note that this can be less than
        the number indicated by len.) Otherwise,a value of SOCKET_ERROR is
        returned, and a specific error code can be retrieved by
         calling WSAGetLastError.*/
        return(code_retour);





}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// * ModBUS TCP : FONCTION 16 : Write Multiple  Registers
//---------------------------------------------------------------------------

int  ModBusTCP::SendRequete_Fct16(unsigned short Adresse,unsigned short  nbMots, unsigned short  *data)
{

//Déclaration et initialisation des variables
        int code_retour=0;
        tailleTrame=13+(2*nbMots); // Une trame de lecture
        unsigned char *TrameModbusTCP;
        TrameModbusTCP = new unsigned char[tailleTrame]; // Calculer la taille du tableau


        // Entête de la trame ModBusTCP
        TrameModbusTCP[0] = 0x00;   // Transaction Identifier
        TrameModbusTCP[1] = 0x00;   // Transaction Identifier
        TrameModbusTCP[2] = 0x00;   // Protocole Identifier
        TrameModbusTCP[3] = 0x00;   // Protocole Identifier
        TrameModbusTCP[4] = (unsigned char)((7+(2*nbMots)) & 0xFF00) >>8;;   // Length
        TrameModbusTCP[5] = (unsigned char)((7+(2*nbMots)) & 0x00FF) ;  // Length
        TrameModbusTCP[6] = NumEsclave;  // Init Identifier

        // Fonction 16 : Write Single Register
        TrameModbusTCP[7] = 0x10;
        // Adresse de début sur 2 octets
        TrameModbusTCP[8] = (unsigned char)(Adresse & 0xFF00) >>8;
        TrameModbusTCP[9] = (unsigned char)(Adresse & 0x00FF) ;

        // Le nombre de mots  à écrire  sur 2 octets
        TrameModbusTCP[10]= (unsigned char) (nbMots & 0xFF00) >>8;
        TrameModbusTCP[11] =(unsigned char)(nbMots & 0x00FF);

        // Le nombre d'octets = 2*nbMots
        TrameModbusTCP[12]= (2*nbMots) ;

        // Ecriture des valeurs
        j=0;
         for ( i=0; i<nbMots; i++)
                {

                       //Ajout des valeurs saisies à la fin de la trame
                        TrameModbusTCP[13+j] = (unsigned char) (data[i] & 0xFF00) >>8;
                        TrameModbusTCP[14+j] =(unsigned char)(data[i] & 0x00FF);
                        j+=2;
                }




        //envoi de la trame sur le socket
         code_retour=send(sock,(char*)TrameModbusTCP,tailleTrame,0);
           /* Return Values If no error occurs, send returns the total number
         of bytes sent. (Note that this can be less than
        the number indicated by len.) Otherwise,a value of SOCKET_ERROR is
        returned, and a specific error code can be retrieved by
         calling WSAGetLastError.*/
        return(code_retour);

}
//---------------------------------------------------------------------------



void ModBusTCP::ReceiveData(unsigned short *TabValeurs, int *nb)
{
        unsigned char donnees[100]={0};
        recv(sock,(char*)donnees,40,0);

        tailleTrame = donnees[8];  // On lit le nombre d'octets
        int i=0, j=0;

        for (i=0; i<tailleTrame; i+=2)
        {
                TabValeurs[j] = (donnees[9+i]*256) + donnees[10+i];
                j++;
        }
        *nb=j;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// * ModBUS TCP : se déconnecter de l'API
//---------------------------------------------------------------------------
int ModBusTCP::DisConnect()
{
       int err=-1;
       if (co!=INVALID_SOCKET)
        {
                err=1; // Erreur de connection
                closesocket(sock);
                WSACleanup();
        }

      return (err) ; // si -1 alors erreur
}


ModBusTCP::~ModBusTCP()
{
    if (co!=INVALID_SOCKET)
            {
                closesocket(sock);
                WSACleanup();
            }
}
//---------------------------------------------------------------------------
