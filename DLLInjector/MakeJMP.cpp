#include "pch.h"
#include "FunctionDefinitions.h"

vector<unsigned char> mkjmp(int CurrentAddress, int DestinationAddress)
{
    stringstream addresstohex;
    vector<unsigned char> bytes;
	
	//Calculate the offset for the JMP instruction
	//E9 means it's a JMP instruction
    addresstohex << hex << 0xe9 << _byteswap_ulong(DestinationAddress - CurrentAddress - 5); 
	
	//Make the stringstream into a string
    const string& hex = addresstohex.str();

	//This turns our string into a char
	//Note: there's probably a much better way to do this
    for (unsigned int i = 0; i < hex.length(); i += 2) {
        string byteString = hex.substr(i, 2);
        unsigned char byte = (unsigned char)strtol(byteString.c_str(), NULL, 16);
        bytes.push_back(byte);
    }

    return bytes;
}
