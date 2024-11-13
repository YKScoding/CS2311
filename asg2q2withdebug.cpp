
#include <iostream>
#include <cstring>

using namespace std;

string dectobin(int num, int length) {
    string binary = "";
    while (num>0) {
        binary = (num % 2 == 0 ? "0" : "1") + binary;
        num /= 2;
    }
    while (binary.length() < length) {
        binary.insert(binary.begin(), '0'); // Insert '0' at the beginning
    }
    return binary;
}

int bintodec(string bin) { // simple implementation, since the input is just 3 bits anyway
    int decimal = 0; 
    if (bin[0] == '1') decimal += 4;
    if (bin[1] == '1') decimal += 2;
    if (bin[2] == '1') decimal += 1;
    return decimal;
}

int main() {

    // creating the header reference
    string headerref[256][3]; // array range from 1-256, 0-5
    int count = 1;
    int power = 1;
    int x = 1;
    int y = 1;
    for (x = 1; x < 256 && count < 256;) {
        for (y = 1; y <= x && count < 256; ++y) {
            // cout << power << "," << x << "," << y << "," << count << endl;  //debug
            // x=length of binary, y=binary representation, count=index
            headerref[count][1] = dectobin(y,power);
            headerref[count][2] = power;
            // headerref[count][3] = sprintf(x);
            // headerref[count][4] = sprintf(y);
            // headerref[count][5] = sprintf(count);
            // cout << headerref[count] << endl; //debug
            ++count;
        }
        ++power;
        // x = (1 << power) - 1; //manual increments to generate the weird key string.
        x = x * 2 + 1;
    }

    // done creating the header ref, start io&proc
    char header[257];
    char code[65536]; // skill issue

    cout << "\nEnter Header: \n";
    cin.getline(header,256);
        int headerlength;
        for (int i = 0; i < 256; ++i) {
            if (header[i] == '\0') {
                headerlength = i;
                break;
            }
        }
        
    cout << "\nEnter code:\n";
    cin.getline(code,65535);
        int codelength;
        for (int i = 0; i < 65535; ++i) {
            if (code[i] == '\0') {
                codelength = i;
                break;
            }
        }
        
    cout << endl;
    // add the header to headerref array
    /*  n   1
        (   01
        X   10, etc
    */
    
    for (count = 0; count < headerlength; ++count) {
        headerref[count+1][0] = header[count];
        // headerref[count][6] = '0';
    }

    /*for(int i = 1; i < headerlength; ++i) {
	  	for(int j=0;j<4;++j) {
	  		cout<<j<<": "<<headerref[i][j]<< "\t";}
		cout<<endl;
    }*/ //debug: showing the array
    
    // parse the code.
    string key_length_str, key, ref;
    int key_length = 0; // key_length 0 indicates that we dont have the key length.
    string keylengthc = "";
    int pointer = 0;
    bool eos = false;
    
    while (pointer <= codelength) {
        if (!key_length) { // 1: get the keylength if we dont have it.
            key_length_str = "";
            for (int i = 0; i < 3; ++i) {
                key_length_str += code[pointer + i];
            }
            pointer += 3; // advancing the pointer by 3 ONLY when determining key length
            key_length = bintodec(key_length_str); 
        }
        
        // debug block A 
        /*
            cout << endl;
            cout << "Block A";
            cout << "\tkey_length: " << key_length << ", " << key_length_str;
            cout << "\tpointer: " << pointer;
            cout << "\teos: " << eos;
            cout << "\tkey: " << key << endl;
        */
        //^^^^^^^^^^^^^debug block 

        // getting the key and determining that it isn't the end of a segment
        key = ""; // the key is determined every loop
        eos = true; // assume all eos
        for (int i = 0; i < key_length; ++i) {
            if (code[pointer + i] == '1') eos = false; // if there is some 1 over the length of a key length, it mustnt be end of seg
            if (code[pointer] == '0' && key_length == 1) eos = true;
            key += code [pointer + i];
        }
        
        // debug block B
        /*
            cout << endl;
            cout << "Block B";
            cout << "\tkey_length: " << key_length << ", " << key_length_str;
            cout << "\tpointer: " << pointer;
            cout << "\teos: " << eos;
            cout << "\tkey: " << key << endl;
        */
        //^^^^^^^^^^^^^debug block
        
        if (eos) {
            pointer += key_length; // dont forget to advance the pointer - we are continuing!
            key_length = 0; //if it is end of a segment, we drop our key length and reload it ; go back to 1:
            continue;
        }

        // debug block C
        /*
            cout << endl;
            cout << "Block C";
            cout << "\tkey_length: " << key_length << ", " << key_length_str;
            cout << "\tpointer: " << pointer;
            cout << "\teos: " << eos;
            cout << "\tkey: " << key << endl;
        */
        //^^^^^^^^^^^^^debug block
        
        keylengthc = key_length + '0' - '0';
        for (int i = 0; i <= headerlength; ++i) {
            ref = headerref[i][1];
            if (headerref[i][2] != keylengthc) continue;
            // cout << endl << ref; // debug
            if (ref == key) cout << headerref[i][0];
        }
        pointer += key_length; //advancing the point since we have finished parsing this character
    }
    

    /*for(int i=1;i< headerlength;++i) {
	  	for(int j=0;j<6;++j) {
	  		cout<<j<<": "<<"\t"<<headerref[i][j]<< "\t";}
		cout<<endl;
    }*/ // debug: showing the array

    return 0;
}

// n(X+# $90\"?     011001010100000001100111110000101000000




