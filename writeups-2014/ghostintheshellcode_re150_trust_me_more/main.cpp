//-------------------------------------------------------------------------------------------
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 7457   // set local port


using namespace std;



char fuzz[65536] =
{

"-----BEGIN RSA PRIVATE KEY-----\n"
"MIIDfQIBAAKBwQDBIv1Y+afRBbU9NeEhxu3tC2pqYBXqJkyxQd4MYbXKu/12X9Ww\n"
"mu+DiyGZRqWSDqBtwQ2tAzqdHVoBoVdTStbjj+3rs4l1TS5KfBnGeZQGHvZPEQnB\n"
"uzRMh2SbySEND+eMz2u5NdB/pG4U++Agoc+pmvmEbkT7asKorXyzchl/pINQJ0kh\n"
"jrSt96L2mozMbG2VfjtosfXH8mwzhhwSLeK8yO7Bh2eh9gCqERe9si15ZATrehMH\n"
"ByBrbHfls/LNI+0CAwEAAQKBwQC/itf/ufl5D1QjlJ/mQ8gLY1ryjMCvK7S7xztU\n"
"xELrAW3qTDk9oSsRJpb30Fy8cc0hjGjnwWAMGeP94ekdLgfYQBIRxEj7EMRsEo/t\n"
"iv4G5AYbfCZVADhp/Y0GA37H2ZBsy13XZc5lf/4Hecor8VMC2Wv8xVaqxvtDEaui\n"
"S8G03p7cb/tAfJ2UCJQ+GLD/Jr5EIY+RmsiruKIv8c7Lo0p8Iu+VFwSeI4DeHsjf\n"
"zPi6okyQtJz5eamBzCWw+4z1twECYQDto5vPc2iXcRz/ff0bN6EohsMK9BvqH4YV\n"
"0Gos2SPeck5eqHcBaVVLvyTQcV7quT9X2D/FzVVvHXaMi+rLsy+ji53CyNPCEAWT\n"
"alQjUrbZvs/U41oSFxXAlmtgevmSo5ECYQDQDyTOEFaALYFLuHTrb+OW4cU8bAvb\n"
"kEAcRf0hgFGmrXEpdgflGPMdMLl8pq+HVNHHvXFsLt6tzub3a+Jajve6lDiXPaY1\n"
"aj8UcnZIsVLEZ7gwH2eXN7benZ3+9ILflJ0CYG5RfYuYr/1d7XBONKnl8VK2/OSg\n"
"3jSZ3c1Sq3eWdihWODuJSXXGSGqZmaWKe93LkbReF3zkDb0/mEE20xEtZfguYFaE\n"
"lImKlowQ2G5tf6UmB6V0xeOQA/Eb400uyZ1hgQJhAMf7lmPe/lXr51hx7ygR/w8a\n"
"6Ws/a1Ja39SNTVazMUhlc9znT4VcqumG2PNAgH0zAQTdSbUzg+RKeGSftQ1YWDNl\n"
"ntN4dVboTcOIlbsffi+8hiTzOq315ncpxyC1w0nGXQJgayz47tAFwfwX+jjIzYmo\n"
"hR6W19nX5bzvjLk+M9KmtvBdvSmbfjD4CyWx7bOUL/qCgVB6pSoOfpnXRBdmmJVH\n"
"1oxIe44QKb98qurd03l/XVti8a617FzjWGKJBCF78Ucu\n"
"-----END RSA PRIVATE KEY-----\n"
/*
"-----BEGIN RSA PRIVATE KEY-----\n"
"Proc-Type: 4,ENCRYPTED\n"
"DEK-Info: AES-128-CBC,07AA97E74B31F814D4BA2B8A1C17258F\n"
"\n"
"P5XroGef68ABlZcCaQ+L7XGoGtwaoPIcaG6FHtSj4PToHroZfhgSEgmT5s5KqcT0\n"
"5oeE5hCF74uqxJ2x4KK25VG1VPR9LuAZ3VCJikavqFkjX/yAaG9xfPe07N8xQPQl\n"
"dtsqKsZJGAcHAa19FLc5vW6ZPsj6RSobOSkxbSvmjBVcmNdKOar/KKw3EPFdfu73\n"
"difgamY0wjciTskvwZOKQatCHE3qdkWWP+FNSEqnVKWiOHrg8RMqYLTzePLqtncZ\n"
"6jPdKSaB362CgGeGQTIufWE/7A29H2uyTuO77kHCwNA+FVs58qOgTYRNn04/SX2Q\n"
"KCYjdUQQ4jYK4SDJ/LcZ65zoEgCqTA/kboGbJtkLqADEab8QDaDyTgTjNAnW2MKo\n"
"fcSqOruQX2Vpv7Y9emzKz11dvZay9n74uXpiOOQ9hAAdQpUuw7qmBbjr7NR8sOBG\n"
"SKaJedb8+KhIBV3YUOCQhPNrb6KIMsi4V9HLkeb7duMbtFgPAZB6bdJkKa8e18ni\n"
"nzBLGJbe8OvJJ5JTvMkVM/DfKnw46mRHxrU7ItiHIghNfuIbj3nkJZqTrv5UhvN3\n"
"OoCN1c7DNSkp8Z1tJv0UDz8kUkoTAanTgSjg/z/R4lYZ8focHkQUmXw4RBuUjSBq\n"
"-----END RSA PRIVATE KEY-----\n"*/

/*
"-----BEGIN RSA PRIVATE KEY-----\n"
"Proc-Type: 4,ENCRYPTED\n"
"DEK-Info: AES-128-CBC,629D88F32511C19CD2D981483C2801AA\n"
"\n"
"kYocXK5o9WEsgrRsZyUKt1jqhqLDmYDIID9ZZq+1wvD99y+gX5YrHdG+yzKfsaZp\n"
"o/Lh1SawiCq/3Sy1RqIo4LHqKuDYrPbTAQXI9scdlK9VDnIJ4HO1JHi+nKHXrHru\n"
"cMt2u0pbqUSvWkuNepOS38sjdWdpX8p3D7atLjuJRLg2tSJhwzIK3qiSC/muOk1V\n"
"9rQ9DEGcI4wE6tK4lgVKSTZwiKvzzOQSjcpuksm1V5H+Qgxp0FH9SqHu+SpjH+9/\n"
"fqqZoPtBz6yZvxOV/pAvo/dOt40kp2f/G0weSjiB9bX9B41P89nsGG/P7AyZAlYK\n"
"VBEM4N8ifJhjC4qvC2/mnsCcYcY6ZjyjM6atFJbNqxsSDSs2UtCWp7GfZOXdFArG\n"
"aVn7ev+YDBKB7j/1IOkAr4ldjcgjpBeAC09LGOuxgQB4/B7I2aTEehizQY1E+MJz\n"
"MZEd/TTvkvZo/r7b6m+gBXQSxrCuUuOsQinkj5BRfQJPVp2EwcaPyzVHNJ8tvmKW\n"
"CG11lQyD3A/H4YV/Dte+bN9AvMEommuYUFocHm/iyaL27/oLsNYkX91Zsy+9Zo5u\n"
"v6esIbXd/FXrvwBZsWYLfH1UhfgLV0+3R0YI8KYyC6nuRNQYqacifEypmuXpCSsi\n"
"i/YkIOU1Z8E+uhwokOq8VBk10izaNL96c0riRdMsKgwQfaK7VSmMJXlb/qRXrDg7\n"
"pUf7FFzcdsXKOynQ1zQWTPAavBKosYVmEfhjR7iY7wZB16mRgNB1BLROZZZp7N4U\n"
"oMSUIa3Z5TWjoS2isd0BGxJ+XHixI0deCI2QrNqPWSu0fyR1dDYk4VNSiD+9grcU\n"
"6YGYUkd+T+PCY+0txlE+lIs99tdtxJCRP2RG/NBtIi1buiSaxrpHZ7jKpRcimEh5\n"
"v2FSPNcAKSnd8OahhPz3dnJjbCsXPczw7FJyAyNyp8cwbS8TbHTAc0j+2knNUhC3\n"
"nCKcfeNiujhwzc2fXylP8UuDgvEl70YCrxdE7AQRG4aSYAD+3nunfRjHh8vMK/q7\n"
"jFELddtWPuyZCGPVbqsHpfj6amjSxDIV5UduYgyPbAuAWNKgqZxrg99FRao7vDKW\n"
"c3MbOrcYJnepf88+FMc3vg==\n"
"-----END RSA PRIVATE KEY-----\n"
*/
};

//-------------------------------------------------------------------------------------------
void f( int C, char ch )
{




}
//-------------------------------------------------------------------------------------------
int main()
{

    struct sockaddr_in host_addr;  // host internet socket address

    int sockd;       // server socket descriptor

    char buffer[64]; // buffer for transmmiting messages
    struct hostent *server;


    sockd = socket( PF_INET, SOCK_STREAM, 0 ); // create socket


    host_addr.sin_family      = AF_INET;        // IP protocol
    host_addr.sin_port        = htons( PORT );  // set local port

    server = gethostbyname( "trustmemore.2014.ghostintheshellcode.com" );

    bcopy((char *)server->h_addr,
           (char *)&host_addr.sin_addr.s_addr,
                server->h_length);

    memset( &(host_addr.sin_zero), 0, 8 );      // clear the rest of the struct


    connect( sockd, (sockaddr*) &host_addr, sizeof(sockaddr) ); // connect with the server


    memset( buffer, 0, 64 );                   // clear buffer
    recv( sockd, buffer, 64, 0 );              // receive data
    cout << "SERVER: " << buffer << endl;      // display received message


    strcpy( buffer, "trust is 74u57 -- but l33t doesn't have a u\n" );
    send( sockd, buffer, strlen(buffer), 0 );  // send data
    cout << buffer << endl;


    memset( buffer, 0, 64 );                   // clear buffer
    recv( sockd, buffer, 64, 0 );              // receive data
    cout << "SERVER: " << buffer << endl;      // display received message



    FILE *in = fopen( "/root/rsa/key", "r" );

   // fread(fuzz, 65536, 1, in );

    fclose( in );


    //for( int i=0; i<C; i++ )
        //fuzz[i] = ch;
    //memset( fuzz, 'A', 1277 );                   // clear buffer

    int C = strlen(fuzz);
    int r = send( sockd, fuzz, C, 0 );  // send data

    cout << "send: " << r << endl;


  //  strcpy( buffer, "this is a test\n" );
  //  send( sockd, buffer, strlen(buffer), 0 );  // send data
    //cout << buffer << endl;

    memset( buffer, 0, 64 );                   // clear buffer
    r = recv( sockd, buffer, 64, 0 );              // receive data
    cout << "r: " << r << " SERVER: " << buffer << endl;      // display received message


    strcpy( buffer, "password" );
    send( sockd, buffer, strlen(buffer), 0 );  // send data
    cout << buffer << endl;

    memset( buffer, 0, 64 );                   // clear buffer
    r = recv( sockd, buffer, 64, 0 );              // receive data
    cout << "r: " << r << " SERVER: " << buffer << endl;      // display received message

    close( sockd );                                // close connection



    return 0;
}
//-------------------------------------------------------------------------------------------
