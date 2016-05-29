// ------------------------------------------------------------------------------------------------
/*
**  Olympic CTF - stego challenge
**  penthackon - s3Rious
**  8 Feb 2014
**
**  Challenge  : find the hidden message from the s[] table.
**  Hidden flag: Base_sixty_four_point_five
*/
// ------------------------------------------------------------------------------------------------
#include <string.h>
#include <stdio.h>      /* printf */
#include <string.h>     /* strcat */
#include <stdlib.h>     /* strtol */

char s[256][256] =
{
// awk '{ printf "\"%s\",\n", $0  }' stego.txt; echo ""
"U3RlZ2Fub2dyYXBoeSBpcyB0aGUgYXJ0IGFuZCBzY2llbmNlIG9m",
"IHdyaXRpbmcgaGlkZGVuIG1lc3NhZ2VzIGluIHN1Y2ggYSB3YXkgdGhhdCBubyBvbmV=",
"LCBhcGFydCBmcm9tIHRoZSBzZW5kZXIgYW5kIGludGVuZGVkIHJlY2lwaWVudCwgc3VzcGU=",
"Y3RzIHRoZSBleGlzdGVuY2Ugb2YgdGhlIG1lc3M=",
"YWdlLCBhIGZvcm0gb2Ygc2VjdXJpdHkgdGhyb3VnaCBvYnNjdXJpdHkuIFS=",
"aGUgd29yZCBzdGVnYW5vZ3JhcGh5IGlzIG9mIEdyZWVrIG9yaWdpbiBhbmQgbWVhbnMgImNvbmNlYW==",
"bGVkIHdyaXRpbmciIGZyb20gdGhlIEdyZWVrIHdvcmRzIHN0ZWdhbm9zIG1lYW5pbmcgImNv",
"dmVyZWQgb3IgcHJvdGVjdGVkIiwgYW5kIGdyYXBoZWluIG1lYW5pbmcgInRvIHc=",
"cml0ZSIuIFRoZSBmaXJzdCByZWNvcmRlZCB1c2Ugb2YgdGhlIHRlcm0gd2FzIGluIDE0OTkgYnkgSm9o",
"YW5uZXMgVHJpdGhlbWl1cyBpbiBoaXMgU3RlZ2Fub2dyYXBoaWEsIGEgdHJlYV==",
"dGlzZSBvbiBjcnlwdG9ncmFwaHkgYW5kIHN0ZWdhbm9ncmFwaHkgZGlzZ8==",
"dWlzZWQgYXMgYSBib29rIG9uIG1hZ2ljLiBHZW5lcmFsbHksIG1lc3P=",
"YWdlcyB3aWxsIGFwcGVhciB0byBiZSBzb21ldGhpbmcgZWxzZTogaW1hZ2VzLCBhcnRp",
"Y2xlcywgc2hvcHBpbmcgbGlzdHMsIG9yIHNvbWUgb3R=",
"aGVyIGNvdmVydGV4dCBhbmQsIGNsYXNzaWNhbGx5LCB0aGUgaGlkZGVuIG1lc3NhZ2UgbWF5IGJlIGluIGludmm=",
"c2libGUgaW5rIGJldHdlZW4gdGhlIHZpc2libGUgbGluZXMgb2YgYSBwcml2YXRlIGxldHRlci4NCg0KVGhl",
"IGFkdmFudGFnZSBvZiBzdGVnYW5vZ3JhcGh5LCBvdmVyIGNy",
"eXB0b2dyYXBoeSBhbG9uZSwgaXMgdGhhdCBtZXNzYWdlcyBkbyBub3QgYXR0cmFjdCBhdHRlbnRpb25=",
"IHRvIHRoZW1zZWx2ZXMuIFBsYWlubHkgdmlzaWJsZSBlbmNyeXB0ZWQgbWVzc2FnZXOXbm8gbWF0dGVyIF==",
"aG93IHVuYnJlYWthYmxll3dpbGwgYXJvdXNlIHN=",
"dXNwaWNpb24sIGFuZCBtYXkgaW4gdGhlbXNlbHZlcyBiZSBpbmNyaW1pbmF0aW5nIP==",
"aW4gY291bnRyaWVzIHdoZXJlIGVuY3J5cHRpb24gaXMgaWxsZWdhbC4gVGhlcmVmb3JlLH==",
"IHdoZXJlYXMgY3J5cHRvZ3JhcGh5IHByb3RlY3RzIHRoZSBjb250ZW50cyBvZj==",
"IGEgbWVzc2FnZSwgc3RlZ2Fub2dyYXBoeSBjYW4gYmUgc2FpZCB0byBwcm90ZWN0IGJ=",
"b3RoIG1lc3NhZ2VzIGFuZCBjb21tdW5pY2F0aW5nIHBhcnRpZXMuDQoNClN0ZWdhbm9ncmFwaHkgaW5jbHW=",
"ZGVzIHRoZSBjb25jZWFsbWVudCBvZiBpbmZvcm1hdGlvbiB3aXRoaW4gY29t",
"cHV0ZXIgZmlsZXMuIEluIGRpZ2l0YWwgc3RlZ2Fub2dyYXBoeSwgZWxlY3Ryb25pYyBjb21tdW5pY2F0aW9u",
"cyBtYXkgaW5jbHVkZSBzdGVnYW5vZ3JhcGhpYyBjb2RpbmcgaW5zaZ==",
"ZGUgb2YgYSB0cmFuc3BvcnQgbGF5ZXIsIHN1Y2ggYXMgYSBkb2N1bWVudCBmaWxlLCBpbWFnZSBmaWx=",
"ZSwgcHJvZ3JhbSBvciBwcm90b2NvbC4gTWVkaWEg",
"ZmlsZXMgYXJlIGlkZWFsIGZvciBzdGVnYW5vZ3JhcGhpYyB0cmFuc21pc3Npb+==",
"biBiZWNhdXNlIG9mIHRoZWlyIGxhcmdlIHNpemUuIEFzIB==",
"YSBzaW1wbGUgZXhhbXBsZSwgYSBzZW5kZXIgbWlnaHQgc3RhcnQgd2l0aCBh",
"biBpbm5vY3VvdXMgaW1hZ2UgZmlsZSBhbmQgYWRqdXN0IHRoZSBjb2xvciBvZiBldmVyeSAxMDB0aCBwaXhlbCD=",
"dG8gY29ycmVzcG9uZCB0byBhIGxldHRlciBpbiB0aGUgYWxwaGFiZXQsIGF=",
"IGNoYW5nZSBzbyBzdWJ0bGUgdGhhdCBzb21lb25lIG5vdCBzcGVjaWZpY2FsbHkgbG9va2luZyBm",
"b3IgaXQgaXMgdW5saWtlbHkgdG8gbm90aWNlIGl0Lg0KDQpUaGU=",
"IGZpcnN0IHJlY29yZGVkIHVzZXMgb2Ygc3RlZ2Fub2dyYXBoeSBjYW4gYmUgdHJ=",
"YWNlZCBiYWNrIHRvIDQ0MCBCQyB3aGVuIEhlcm9kb3R1cyBtZW50aW9ucyB0d28gZXhhbXBsZXMgb+==",
"ZiBzdGVnYW5vZ3JhcGh5IGluIFRoZSBIaXN0b3JpZXMgb2Yg",
"SGVyb2RvdHVzLiBEZW1hcmF0dXMgc2VudCBhIHdhcm5pbmcgYWJvdXQgYSB=",
"Zm9ydGhjb21pbmcgYXR0YWNrIHRvIEdyZWVjZSBieSB3",
"cml0aW5nIGl0IGRpcmVjdGx5IG9uIHRoZSB3b29kZW4gYmFja2luZyBvZiBhIHdheCB0YWJsZXQgYmVm",
"b3JlIGFwcGx5aW5nIGl0cyBiZWVzd2F4IHN1cmZhY2UuIFdheCB0YWJsZXRzIHdlcmUgaW4gY29tbW9uIHVzZV==",
"IHRoZW4gYXMgcmV1c2FibGUgd3JpdGluZyBzdXJmYWNlcywgc29tZXRpbWX=",
"cyB1c2VkIGZvciBzaG9ydGhhbmQuIEFub3RoZXIgYW5jaWVudCBleGFtcGxlIGlzIHRoYXQgb9==",
"ZiBIaXN0aWFldXMsIHdobyBzaGF2ZWQgdGhlIGhlYWQgb2YgaGlzIG1vc3QgdHJ1c3RlZCBz",
"bGF2ZSBhbmQgdGF0dG9vZWQgYSBtZXNzYWdlIG9uIGl0LiBBZnRlciBoaXMgaGFpciBoYWQgZ5==",
"cm93biB0aGUgbWVzc2FnZSB3YXMgaGlkZGVuLiBUaGUgcHVycG9zZSB3YXMgdG+=",
"IGluc3RpZ2F0ZSBhIHJldm9sdCBhZ2FpbnN0IHRoZSBQZXJzaWFucy4NCg0KU3RlZ2Fub2dyYXBoeSBoYXMgYm==",
"ZWVuIHdpZGVseSB1c2VkLCBpbmNsdWRpbmcgaW4gcmVjZW50IGhpc3RvcmljYWwgdGltZXMgYW5kIHT=",
"aGUgcHJlc2VudCBkYXkuIFBvc3NpYmxlIHBlcm11dGF0aW9ucyBhcmUgZW5kbGVzcyBhbmT=",
"IGtub3duIGV4YW1wbGVzIGluY2x1ZGU6DQoqIEhpZGRlbiBtZXNzYWdlcyB3aXRoaW4gd2F4IHRh",
"YmxldHM6IGluIGFuY2llbnQgR3JlZWNlLCBwZW9wbGUgd3JvdGUgbWV=",
"c3NhZ2VzIG9uIHRoZSB3b29kLCB0aGVuIGNvdmVyZWQgaXQgd2l0aCB3YXggdXBvbiB3aGljaCBhbiBpbm5vY2Vu",
"dCBjb3ZlcmluZyBtZXNzYWdlIHdhcyB3cml0dGVu",
"Lg0KKiBIaWRkZW4gbWVzc2FnZXMgb24gbWVzc2VuZ2VyJ3MgYm9keTogYWxzbyB1c2VkIGluIGFuY2llbt==",
"dCBHcmVlY2UuIEhlcm9kb3R1cyB0ZWxscyB0aGUgc3Rvcnkgb1==",
"ZiBhIG1lc3NhZ2UgdGF0dG9vZWQgb24gYSBzbGF2ZSdzIHNoYXZlZCBoZWFkLCBoaWRkZW4gYnkgdGhl",
"IGdyb3d0aCBvZiBoaXMgaGFpciwgYW5kIGV4cG9zZWQgYnkgc2hhdmluZyBoaXMgaGVhZM==",
"IGFnYWluLiBUaGUgbWVzc2FnZSBhbGxlZ2VkbHkgY2FycmllZCBhIHdhcm5pbmcgdG8gR3JlZWNlIGFib5==",
"dXQgUGVyc2lhbiBpbnZhc2lvbiBwbGFucy4gVGh=",
"aXMgbWV0aG9kIGhhcyBvYnZpb3VzIGRyYXdiYWNrcyz=",
"IHN1Y2ggYXMgZGVsYXllZCB0cmFuc21pc3Npb24gd2hpbGUgd2FpdGluZyBmb3IgdGhlIHP=",
"bGF2ZSdzIGhhaXIgdG8gZ3JvdywgYW5kIHRoZSByZXN0cmljdGlvbnMgb3==",
"biB0aGUgbnVtYmVyIGFuZCBzaXplIG9mIG1lc3M=",
"YWdlcyB0aGF0IGNhbiBiZSBlbmNvZGVkIG9uIG9uZSBwZXJzb24=",
"J3Mgc2NhbHAuDQoqIEluIFdXSUksIHRoZSBGcmVuY2ggUmVzaXN0YW5jZSBzZW50IHNvbWUgbWVzc2FnZXMgd2==",
"cml0dGVuIG9uIHRoZSBiYWNrcyBvZiBjb3VyaWVycyD=",
"dXNpbmcgaW52aXNpYmxlIGluay4NCiogSGlkZGVuIG1lc3NhZ2VzIG9uIHBhcGVyIHdy",
"aXR0ZW4gaW4gc2VjcmV0IGlua3MsIHVuZGVyIG90aGVyIG1lc3NhZ2Vz",
"IG9yIG9uIHRoZSBibGFuayBwYXJ0cyBvZiBvdGhlct==",
"IG1lc3NhZ2VzLg0KKiBNZXNzYWdlcyB3cml0dGVuIGluIE1vcnNlIGNvZGUgb24ga25pdHRpbmcgeWFybiBhbmQg",
"dGhlbiBrbml0dGVkIGludG8gYSBwaWVjZSBvZiBjbG90aGluZyB3b3K=",
"biBieSBhIGNvdXJpZXIuDQoqIE1lc3NhZ2VzIHdyaXR0ZW4gb24gdGhlIGJhY2sgb5==",
"ZiBwb3N0YWdlIHN0YW1wcy4NCiogRHVyaW5nIGFuZCBhZnRlcm==",
"IFdvcmxkIFdhciBJSSwgZXNwaW9uYWdlIGFnZW50cyB1c2VkIHBob3RvZ3JhcGhpY2FsbHkgcO==",
"cm9kdWNlZCBtaWNyb2RvdHMgdG8gc2VuZCBpbmZvcm1hdGlvbiBiYWNrIGFuZH==",
"IGZvcnRoLiBNaWNyb2RvdHMgd2VyZSB0eXBpY2FsbHkg",
"bWludXRlLCBhcHByb3hpbWF0ZWx5IGxlc3MgdGhhbiB0aGUgc2l6ZSBvZiB0aGUgcGVyaW9kIHByb2R=",
"dWNlZCBieSBhIHR5cGV3cml0ZXIuIFdXSUkgbWljcm9kb3RzIG5lZWRlZCB0byBiZSBlbWJlZGRlZB==",
"IGluIHRoZSBwYXBlciBhbmQgY292ZXJlZCB3aXRoIGFuIGFkaGVzaXZlIChzdWNoIGFzIGNvbGxvZGlvbikuIFR=",
"aGlzIHdhcyByZWZsZWN0aXZlIGFuZCB0aHVzIGRldGVjdGFibGUg",
"Ynkgdmlld2luZyBhZ2FpbnN0IGdsYW5jaW5nIGxpZ2h0LiBBbHRlcm5hdGl2ZSB0ZWNobmlxdWVzIGluY2x1ZGVk",
"IGluc2VydGluZyBtaWNyb2RvdHMgaW50byBzbGl0cyBjdXQgaW50byB0aGUgZWRnZSBvZv==",
"IHBvc3QgY2FyZHMuDQoqIER1cmluZyBXb3JsZCBXYXIgSUksIGEgc3B5IGZvciB=",
"SmFwYW4gaW4gTmV3IFlvcmsgQ2l0eSwgVmVsdmFsZWW=",
"IERpY2tpbnNvbiwgc2VudCBpbmZvcm1hdGlvbiB0byBhY2NvbW1vZGF0aW9=",
"biBhZGRyZXNzZXMgaW4gbmV1dHJhbCBTb3V0aCBBbWVyaWO=",
"YS4gU2hlIHdhcyBhIGRlYWxlciBpbiBkb2xscywgYW5kIG==",
"aGVyIGxldHRlcnMgZGlzY3Vzc2VkIGhvdyBtYW55IG9mIHRoaXMgb3IgdGhhdCBkb2xs",
"IHRvIHNoaXAuIFRoZSBzdGVnb3RleHQgd2FzIHRoZSBkb2xsIG9yZGVycywgd2hpbGUgdGhl",
"IGNvbmNlYWxlZCAicGxhaW50ZXh0IiB3YXMgaXRzZWxmIGVuY2+=",
"ZGVkIGFuZCBnYXZlIGluZm9ybWF0aW9uIGFib3V0IHNoaXAgbW92ZW1lbnRzLF==",
"IGV0Yy4gSGVyIGNhc2UgYmVjYW1lIHNvbWV3aGF0IGZh",
"bW91cyBhbmQgc2hlIGJlY2FtZSBrbm93biBhcyB0aGX=",
"IERvbGwgV29tYW4uDQoqIENvbGQgV2FyIGNvdW50",
"ZXItcHJvcGFnYW5kYS4gSW4gMTk2OCwgY3JldyBtZW1iZW==",
"cnMgb2YgdGhlIFVTUyBQdWVibG8gKEFHRVItMikgaW50ZWxsaWdlbmNlIHNoaXAgaGVsZCBhcyBwcm==",
"aXNvbmVycyBieSBOb3J0aCBLb3JlYSwgY29tbXVuaWNhdGVkIGluIHNpZ25=",
"IGxhbmd1YWdlIGR1cmluZyBzdGFnZWQgcGhvdG8gb3Bwb3J0",
"dW5pdGllcywgaW5mb3JtaW5nIHRoZSBVbml0ZWQgU3RhdGVzIHRoZXkg",
"d2VyZSBub3QgZGVmZWN0b3JzIGJ1dCByYXRoZXIgd2VyZSBiZWluZyBoZWxkIGNh",
"cHRpdmUgYnkgdGhlIE5vcnRoIEtvcmVhbnMuIEluIG90aGVyIHBob3Rv",
"cyBwcmVzZW50ZWQgdG8gdGhlIFVTLCBjcmV3IG1lbWJlcnMgZ2F2ZSAidGhlIGZpbmdlciIgdG8g",
"dGhlIHVuc3VzcGVjdGluZyBOb3J0aCBLb3JlYW5zLCBpbiBhbiBhdHRlbXB0IHRvIE==",
"ZGlzY3JlZGl0IHBob3RvcyB0aGF0IHNob3dlZCB0aGVtIHNtaQ==",
"bGluZyBhbmQgY29tZm9ydGFibGUuDQoNCi0tDQpodHRwOi8vZW4ud2lraXBlZGlhLm9yZw==",
"L3dpa2kvU3RlZ2Fub2dyYXBoeQ0K"

};

char bitstream[512], B[8], base[512];
// ------------------------------------------------------------------------------------------------
int main()
{
    int i, b, len, val;


    printf("+--------------------------------------------------+\n");
    printf("|           Olympic CTF - stego challenge          |\n");
    printf("|                 penthackon - ispo                |\n");
    printf("|                    8 Feb 2014                    |\n");
    printf("+--------------------------------------------------+\n");
    printf( "\nUnused bits: " );

    for( i=0; i<131; i++ )                  // for each row
    {
        len = strlen(s[i]);                 // get length of each line

        if( s[i][len-1] == '=' )            // last character is '='?
        {
            // if yes, padding was used in encoding, so there are unused bits
            if( s[i][len-2] == '=' )        // pre-last character is '='?
            {
                    // "xxxx==" --> There are 4 unused bits
                    // convert last non-'=' character to base 64 value
                     if( s[i][len-3] >= 'A' && s[i][len-3] <= 'Z' ) b = s[i][len-3] - 'A';
                else if( s[i][len-3] >= 'a' && s[i][len-3] <= 'z' ) b = s[i][len-3] - 'a'+26;
                else if( s[i][len-3] >= '0' && s[i][len-3] <= '9' ) b = s[i][len-3] - '0'+52;
                else if( s[i][len-3] == '+'                       ) b = 62;
                else if( s[i][len-3] == '/'                       ) b = 63;


                sprintf( B, "%d%d%d%d", (b&0x8) >> 3, (b&0x4) >> 2, (b&0x2) >> 1, b&0x1 );  // get bits
            }
            else                            // not, only one paddinbg character
            {
                // "xxxx=" -->  There are 2 unused bits
                // convert last non-'=' character to base 64 value
                     if( s[i][len-2] >= 'A' && s[i][len-2] <= 'Z' ) b = s[i][len-2] - 'A';
                else if( s[i][len-2] >= 'a' && s[i][len-2] <= 'z' ) b = s[i][len-2] - 'a'+26;
                else if( s[i][len-2] >= '0' && s[i][len-2] <= '9' ) b = s[i][len-2] - '0'+52;
                else if( s[i][len-2] == '+'                       ) b = 62;
                else if( s[i][len-2] == '/'                       ) b = 63;


                sprintf( B, "%d%d", (b&0x2) >> 1, b&0x1 );  // get bits

            }

            printf( "%s", B );              // display data bits
            strcat( bitstream, B );         // append bits to binary stream
        }
    }


    printf( "\nBit Stream length: %lu\n", strlen(bitstream) );
    printf( "\n\nConverting bits to base64: " );


    for(i=0; i<(int)strlen(bitstream)/6; i++)    // get 6 bits of stream and convert to 1 base64 character
    {
        if( bitstream[6*i] == '\0' ) break;


        int a = bitstream[i*6+0]-48;        // get a bit
        int b = bitstream[i*6+1]-48;
        int c = bitstream[i*6+2]-48;
        int d = bitstream[i*6+3]-48;
        int e = bitstream[i*6+4]-48;
        int f = bitstream[i*6+5]-48;

        val = a*32+ b*16 + c*8 + d*4 + e*2 + f; // get bits value


        // convert to base64 digit
             if( val <= 25 ) sprintf(B, "%c", val + 'A'     );
        else if( val <= 51 ) sprintf(B, "%c", val + 'a' - 26);
        else if( val <= 61 ) sprintf(B, "%c", val + '0' - 52);
        else if( val == 62 ) sprintf(B, "+");
        else if( val == 63 ) sprintf(B, "/");

        strcat( base, B );                  // concat digit to message
    }

    printf ( "%s\nDecoded Message:\n", base );
    sprintf( B,"echo %s | base64 --decode", base );
    system ( B );
    printf ( "\n" );

    return 0;
}
// ------------------------------------------------------------------------------------------------
