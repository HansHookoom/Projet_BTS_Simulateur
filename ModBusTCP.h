#ifndef ModBusTCP_H //Pour eviter les inclusions mutliples,
#define ModBusTCP_H  //on utilise ces directives pour le compilateur


#include <winsock2.h>

class ModBusTCP
{
    private:
                        char *adresseAPI;
                        int port;
                        unsigned char NumEsclave;
                        int co , tailleTrame,i,j;
                        WSADATA WSAData;
                        SOCKET sock;
                        SOCKADDR_IN sin;

	public:
            ModBusTCP(char *addr, unsigned char  Num) ;
                        int Connect();
                        int SendRequete_Fct3(unsigned short Adresse, unsigned short  nbMots) ;
                        int SendRequete_Fct6(unsigned short Adresse, unsigned short  data);
                        int SendRequete_Fct16(unsigned short Adresse,unsigned short  nbMots, unsigned short  *data);
                     	void ReceiveData(unsigned short *TabValeurs, int *nb);
                        int DisConnect();
                        ~ModBusTCP();
};
#endif
