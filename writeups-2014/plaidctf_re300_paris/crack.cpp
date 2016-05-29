// ------------------------------------------------------------------------------------------------
/*
**  Plaid CTF 2014
**  RE300 - paris challenge (VM crackme)
**  April 2014
**
**  Flag is: V1rTu4L_M4ch1n3s_4r3_Aw3s0m3!
**
**  Special Thanks to jjk, for his important help,
**  ispo@penthackon
*/
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>


typedef unsigned short int  USHORT;
typedef unsigned int        UINT;
typedef unsigned char       UCHAR;
// ------------------------------------------------------------------------------------------------
UCHAR H[] =                     // our Hash table
{
    0xF2,0xAE,0x8B,0x4F,0x49,0xC3,0xE5,0xA3,0xA3,0x1A,0x2D,0xA5,0x90,0x7A,0x8E,0x08,
    0xE5,0x0F,0x41,0x61,0x52,0xD7,0x40,0xC0,0x78,0xA9,0x5D,0x2B,0x8B,0xC4,0x33,0xC2,
    0x42,0xCB,0x22,0x81,0x77,0x3E,0x09,0xEF,0xCB,0x6C,0xCF,0xB0,0xF4,0xC4,0x75,0x10,
    0xC1,0x93,0xAE,0xD9,0x1D,0xEC,0xE8,0x11,0x16,0xDC,0x2D,0x3B,0x25,0x6C,0xB8,0xC5,
    0xC3,0xC1,0x1C,0xA9,0x18,0x85,0xE1,0xAB,0x1D,0xD0,0x0C,0xA0,0xB9,0x43,0x97,0xE3,
    0x85,0xB5,0xDB,0x20,0x48,0xFC,0x1E,0xCD,0x79,0x5B,0xBB,0xBD,0x02,0xE3,0x32,0xE4,
    0x63,0xC0,0x1D,0x95,0xCA,0x48,0x63,0x9D,0x87,0x22,0xAA,0xE9,0x7E,0x26,0x26,0x0A,
    0x9B,0x37,0x50,0x54,0xCC,0x61,0x13,0x7E,0x5A,0xF8,0xBF,0xF7,0x45,0x45,0x82,0xAB,
    0x1C,0x6F,0xAB,0xE8,0x27,0x48,0x07,0x25,0x71,0xAB,0x42,0x29,0x73,0xC3,0x55,0xE4,
    0x54,0xF6,0x0B,0xD6,0x17,0x39,0xB5,0xAE,0xE8,0x5C,0x85,0x05,0xE5,0x2C,0xDD,0x3C,
    0x3B,0xDA,0x09,0x7D,0xC4,0x42,0x86,0x12,0x8B,0x2B,0x72,0x99,0xF8,0x86,0x9D,0xC3,
    0xF1,0x65,0x85,0x2E,0x05,0x53,0x6F,0x48,0xED,0x13,0x9C,0xAB,0x68,0x44,0x57,0x03,
    0x6A,0xA6,0xD7,0x9E,0xB9,0xE6,0x16,0xA3,0x27,0xF6,0xCC,0x5A,0xC6,0xCB,0xEA,0x06,
    0x05,0xCA,0x4F,0x95,0x90,0x93,0x72,0x42,0xCE,0xA3,0x08,0x1A,0x47,0x2A,0xB8,0xD0,
    0x76,0x29,0x86,0x24,0x62,0xE5,0x32,0xD0,0x7D,0xB2,0x0D,0xC7,0xAD,0xA7,0xEE,0x98,
    0x26,0xB9,0xDD,0x9D,0x57,0xA6,0x8B,0xE9,0x13,0x3E,0x42,0x0E,0x3D,0xAF,0xE4,0x19,
    0x2B,0x7D,0x17,0x90,0xC4,0x52,0x9E,0x5B,0xD4,0x96,0x5F,0x6D,0xDC,0xE7,0x08,0x99,
    0x2A,0x0B,0x54,0xE5,0xA4,0xE0,0xA1,0x7C,0x81,0x56,0xF2,0x02,0x76,0x46,0x4C,0xB6,
    0xDA,0xE3,0xF6,0x4A,0xC0,0x07,0x1B,0x6B,0x16,0x8A,0x0F,0x6A,0x0D,0x18,0xF6,0x8C,
    0xCC,0xB3,0xC2,0x6A,0xBD,0xE9,0x3D,0x0E,0xF6,0x15,0x7C,0x4C,0x57,0x61,0xF2,0xA9,
    0x08,0x5B,0x06,0x72,0x97,0x9B,0xFB,0xF6,0xB0,0x7D,0x89,0x69,0xAF,0x3D,0xFD,0x93,
    0xBD,0xA0,0xC5,0x24,0xD1,0xE3,0x20,0x87,0xE9,0xBC,0x56,0x8D,0x2D,0x7A,0xB3,0x66,
    0x5C,0xE9,0xDA,0xC9,0xAE,0x4B,0xB0,0x53,0x15,0x8F,0xF2,0xF1,0x99,0xA3,0x3B,0x28,
    0xCB,0x5B,0x9C,0x31,0xEB,0x7B,0xC2,0xF1,0x5B,0x8C,0xBF,0xDC,0xC5,0x66,0xB9,0xB2,
    0xA6,0xDC,0x26,0x52,0x39,0x30,0x64,0x55,0x9B,0x4B,0x00,0xE1,0x41,0xE0,0xB1,0x02,
    0x55,0xDE,0xC9,0xEA,0x27,0x2D,0x45,0xD9,0x27,0xD2,0x17,0x3E,0x88,0xB4,0x3E,0xBD,
    0xB0,0xE4,0x25,0x68,0x65,0x9B,0xAB,0x0D,0xFB,0xA3,0x2C,0xDC,0xCF,0x58,0x98,0x58,
    0xEB,0xEA,0x71,0x05,0xE1,0x60,0x95,0x56,0xF0,0xE6,0x34,0x3B,0x7D,0x28,0x65,0x45,
    0x70,0x02,0x37,0xAD,0x2A,0x70,0xB0,0x46,0xEF,0x9C,0xF8,0xC0,0x56,0x2D,0x49,0x3A,
    0xC9,0x19,0xF7,0xB1,0x46,0x28,0xEF,0x64,0x01,0x07,0x58,0xBE,0xEC,0xE7,0xB4,0x8D,
    0xD6,0xB1,0xAC,0x9E,0xF4,0x12,0x9E,0xBB,0x7A,0x33,0x39,0x93,0x82,0x38,0x82,0x34,
    0x8C,0xC3,0x00,0x88,0x8E,0x12,0x9C,0xC3,0x4D,0x62,0x2F,0xDC,0x7C,0x5A,0xAA,0xA5
};

UCHAR key[] =                   // our Key to XOR Hash table
{
    0xA9,0x2D,0xF2,0x6D,0x2E,0x34,0xAA,0x55,0x7A,0xC3,0x94,0xCC,0xA2,0x11,0xD8,0xB9,
    0xA5,0xF0,0xE2,0x8C,0x54,0xCB,0x5D,0x18,0xD8,0x79,0x5F,0x3A,0x15,0x9E,0xDA,0xEA,
    0xFC,0x77,0x2B,0x91,0x4F,0x21,0x29,0x26,0x1F,0x60,0x8F,0xC4,0xBE,0x63,0x87,0xD8,
    0x81,0x1E,0x3F,0x76,0xE8,0x61,0xEB,0x94,0xF6,0xFA,0x74,0x47,0xFB,0x52,0xBA,0x53,
    0x7C,0x59,0x6F,0x51,0x3E,0xC8,0xEE,0x2F,0x3A,0x69,0x80,0x1A,0xCF,0x74,0x60,0xCD,
    0x0F,0xC9,0x72,0xC7,0xF9,0x45,0xAD,0x91,0x45,0x95,0x45,0x14,0xCF,0xF5,0x57,0x6F,
    0x39,0x5A,0xD8,0x3C,0xDF,0x96,0xF0,0xCE,0x90,0xBE,0x29,0x8E,0xFE,0x67,0xD7,0x7B,
    0x8D,0x4F,0x22,0xD9,0x7A,0x76,0x47,0x98,0x50,0x4A,0xF7,0x47,0x4C,0x92,0x63,0x44,
    0x98,0xD9,0x34,0x2D,0xF8,0xC2,0x95,0xCA,0xD4,0xBC,0x89,0xC6,0x98,0x64,0x16,0xBC,
    0xAD,0xE2,0x0E,0xFD,0xD0,0x58,0x6D,0x75,0xC9,0x10,0xD6,0x5B,0x0F,0x2A,0xBB,0xCF,
    0x32,0x3D,0xB4,0x4A,0xFF,0x36,0xB5,0xD2,0x27,0x4A,0x91,0xB8,0xA6,0x0C,0x33,0x3A,
    0x35,0xF2,0x66,0x39,0x7F,0x7A,0xFB,0x4B,0x35,0x41,0x1E,0xC2,0x50,0xE1,0x4F,0xD5,
    0x60,0xB4,0x1E,0x7D,0xE4,0x35,0xDC,0xFC,0x3B,0xA9,0x78,0xF5,0x66,0xAD,0xA0,0x5E,
    0x93,0x17,0xDB,0x99,0x59,0x61,0x86,0x2F,0x6F,0x63,0xF8,0xF6,0xEF,0xFB,0x94,0x47,
    0x9B,0x17,0xD8,0x5D,0x08,0x26,0x40,0xE9,0x1C,0x73,0xF5,0x1A,0x4D,0xB4,0x85,0x02,
    0xE9,0xCF,0xCF,0x14,0x65,0xCA,0x74,0xE7,0xF9,0x9D,0xB6,0x1A,0xC1,0xA7,0xF2,0x94
};

UCHAR cipher[256] =              // flag to decrypt
{
/*
This is the cipher to decrypt. Password is compared with this in reverse, Big Endian
order. So we inverse it:

0x0B,0x2E,0x02,0x6D,0x92,0x74,0x0C,0x87,0xB9,0x93,0xB3,0xED,0x2C,0x31,0x07,0x71,
0x10,0x7D,0x07,0x20,0xC6,0xE7,0x1B,0x3A,0xD8,0xBA,0x17,0x94,0x6B,0xFA,0x6C,0xBE,
0x1D,0x62,0x3B,0x4D,0xAD,0x47,0x7A,0x7A,0x9D,0x3E,0xA2,0x53,0x2F,0xF2,0xA9,0xD1,
0x74,0xF5,0x73,0x81,0xBC,0x11,0x15,0xAE,0x79,0x61,0x21,0xAF

0x21af is the termination flag. We replace this flag with 0x4d5a which is the
seed in our XOR encryption.
*/

                    0x4D,0x5A,0x79,0x61,0x15,0xAE,0xBC,0x11,0x73,0x81,0x74,0xF5,
0xA9,0xD1,0x2F,0xF2,0xA2,0x53,0x9D,0x3E,0x7A,0x7A,0xAD,0x47,0x3B,0x4D,0x1D,0x62,
0x6C,0xBE,0x6B,0xFA,0x17,0x94,0xD8,0xBA,0x1B,0x3A,0xC6,0xE7,0x07,0x20,0x10,0x7D,
0x07,0x71,0x2C,0x31,0xB3,0xED,0xB9,0x93,0x0C,0x87,0x92,0x74,0x02,0x6D,0x0B,0x2E


// for example password "kyriakos" hashed:
// 0x4D,0x5A,0xA9,0x43,0x90,0x90,0xF1,0x1B,0x29,0xB4,0x47,0xBF,0x5F,0x2F,0x1C,0x20,0x1B,0x15
//           k         y         r         i         a         k         o         s
};

USHORT encr[256] = { 0x5a4d };              // "stack" initialize with the "MZ" value
UCHAR iH[512];                              // auxilary hash table
UCHAR flag[32];                             // store flag here

char psw[256] = { "kyriakos\0" };           // array used for encryption only
// ------------------------------------------------------------------------------------------------
/*
**  xchg(): This function is the equivalent of htons(). xchg(), swaps the order of the bytes in a
**      2 byte word.
**
**  Return Value: The integer in Big Endian format.
*/
short int xchg( short int value )
{
    USHORT hb = (value & 0xff00) >> 8;      // high order byte
    USHORT lb = (value & 0xff);             // low  order byte

    return (lb << 8) | hb;                  // swap bytes
}
// ------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    UINT curr, prev, r_e;               // registers
    int i, j, m, idx;                   // counter



    printf("+--------------------------------------------------+\n");
    printf("|          Plaid CTF 2014 - RE300 - paris          |\n");
    printf("|            April 2014 - ispo@penthackon          |\n");
    printf("+--------------------------------------------------+\n");

    memcpy(iH, H, 512);                 // back up original Hash table

    /*
    **  This is the encryption algorithm. We use it as a reference.
    */
    for( i=0; i<(int)strlen(psw); i++ ) // for each password character
    {
        /*
        **  $0 register is reduced by 0x1111 after each exception return control back to
        **  the program. So, between the password read (4th function) and copy of $e to $0 (2nd function)
        **  there are 18 functions:
        **      #  8	cmd: 4	addr:0x4020a1	eip:15	$0[ccd5] = psw[$6[0]]
        **      #  9	cmd: 2	addr:0x402323	eip:17	mov  $e[8], $0[22ff]
        **  Thus the value of the $e is reduce by 0x1111 * 18 = 0x13332 = 0x3332 (WORD).
        */
        r_e = xchg((psw[i]*256 + psw[i+1] - 0x1111*18) & 0xffff);   // read 2 chars from password
		r_e = ~((r_e & 0xff00) >> 8) ^ ~(r_e & 0xff);               // convert 2 bytes to 1 byte index
        r_e *= 2;
		r_e = ((H[r_e+1]<<8) + H[r_e]);                             // hash index

		encr[i+1] = r_e ^ encr[i];                                  // XOR with previous encrypted word

        for( j=0; j<0x200; j++) H[j] ^= key[i];                     // XOR hash table
    }

    // for a N byte password, the cipher has length 2*(N+1) (plus 1 for NULL byte)
    // cipher is 60 bytes. Thus the password is 29 character long.

    /*
    **  This is the decryption algorithm.
    */
    const int p_len = 29;                   // set the password length


    for( i=0; i<p_len; i++ )                // XOR hash  table as many times as password length
        for( j=0; j<0x200; j++ ) iH[j] ^= key[i];


    for( i=p_len-1, idx=2*(p_len+1); i>=0; i--, idx-=2 )    // start decrypting character from the end
    {
        for( j=0; j<0x200; j++)             // cancel XOR of hash table
            iH[j] ^= key[i];

        curr = (((cipher[idx-1]&0xff)*256) | ((cipher[idx-2])&0xff)) & 0xffff;
        prev = (((cipher[idx-3]&0xff)*256) | ((cipher[idx-4])&0xff)) & 0xffff;

        curr ^= prev;                       // XOR the 2 values at the top of the "stack"


        // The hash table is quite small, we don't need to inverse it.
        for( j=0; j<0x200; j++ )                    // search all table
            if( iH[ j ] ==  (curr & 0xff) &&        // a byte is the same, and
                iH[j+1] == ((curr & 0xff00) >> 8) ) // next byte is the same
                    break;                          // if yes break and get value of j

        j /= 2;                                      // divide index by 2


        /*
        ** We have a problem here. The step: r_e = ~((r_e & 0xff00) >> 8) ^ ~(r_e & 0xff)
        ** transform input from 2 bytes to 1 byte. How we can recover the 2 byte from 1
        ** byte? It seems that there are many possible solution, but there're not. Keep in
        ** mind that we know the last byte of the password: the NULL byte. Knowing one byte
        ** we can find the other, and we can use the other byte to find the next one, and
        ** so on. The small universe of valid characters (32~127), makes a BF solution
        ** acceptable.
        */
        for( m=32; m<127; m++ )             // for each possible character
        {
            r_e = xchg((m*256 + flag[i+1] - 0x1111*18) & 0xffff);   // read 2 chars from password
            r_e = ~((r_e & 0xff00) >> 8) ^ ~(r_e & 0xff);           // convert 2 bytes to 1 byte index

            if( r_e == (UINT) j )  break;   // if character found, break loop
        }

        flag[i] = m;                        // store character found
    }

    printf( "\nFlag found: %s\n", flag);    // print flag

    return 0;
}
// ------------------------------------------------------------------------------------------------