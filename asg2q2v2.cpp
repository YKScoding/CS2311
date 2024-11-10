
#include <iostream>
//#include <string>

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

int bintodec(string bin) { //simple implementation, since the input is just 3 bits anyway
    int decimal = 0; 
    if (bin[0] == '1') decimal += 4;
    if (bin[1] == '1') decimal += 2;
    if (bin[2] == '1') decimal += 1;
    return decimal;
}


int main() {

    //creating the header reference
    string headerref[256][6]; //array range from 1-256, 0-5
    int count = 1;
    int power = 1;
    int x = 1;
    int y = 1;
    for (x = 1; x < 256 && count < 256;) {
        for (y = 1; y <= x && count < 256; ++y) {
            //cout << power << "," << x << "," << y << "," << count << endl;  //debug
            //x=length of binary, y=binary representation, count=index
            headerref[count][1] = dectobin(y,power);
            headerref[count][2] = to_string(power);
            headerref[count][3] = to_string(x);
            headerref[count][4] = to_string(y);
            headerref[count][5] = to_string(count);
            //cout << headerref[count] << endl; //debug
            ++count;
        }
        ++power;                   
        x = x * 2 + 1; //manual increments to generate the weird key string.
    }

    //done creating the header ref, start io&proc
    string header;
    string code;

    cout << "\nEnter Header: \n";
    getline(cin, header);
    //header = "n(X+# $90\"?";
    cout << "\nEnter code:\n";
    getline(cin, code);
    //code = "011001010100000001100111110000101000000";
    cout << endl;
    //add the header to headerref array
    /*  n   1
        (   01
        X   10, etc
    */
    for (count = 0; count < header.length(); ++count) {
        headerref[count+1][0] = header[count];
        //headerref[count][6] = '0';
    }

    //parse the code.
    string key_length_str, key;
    int key_length = 0; // key_length 0 indicates that we dont have the key length.
    int pointer = 0;
    bool eos = false;

    while (pointer <= code.length()) {
        if (!key_length) { // 1: get the keylength if we dont have it.
            key_length_str = "";
            for (int i = 0; i < 3; ++i) {
                key_length_str += code[pointer + i];
            }
            pointer += 3; // advancing the pointer by 3 ONLY when determining key length
            key_length = bintodec(key_length_str); 
        }

        // getting the key and determining that it isn't the end of a segment
        key = ""; // the key is determined every loop
        eos = true; // assume all eos
        for (int i = 0; i < key_length; ++i) {
            if (code[pointer + i] == '1') {eos = false;} // if there is some 1 over the length of a key length, it mustnt be end of seg
            if (code[pointer] == '0' && key_length == 1) {eos = true;}
            key += code [pointer + i];
        }
        
        if (eos) {
            pointer += key_length; // dont forget to advance the pointer - we are continuing!
            key_length = 0; //if it is end of a segment, we drop our key length and reload it ; go back to 1:
            continue;
        }

        string ref;
        for (int i = 0; i <= header.length(); ++i) {
            ref = headerref[i][1];
            if (headerref[i][2] != to_string(key_length)) {continue;}
            //cout << endl << ref;
            if (ref == key) {cout << headerref[i][0];}
        }

        pointer += key_length; //advancing the point since we have finished parsing this character
    }

    return 0;
}

// n(X+# $90\"?     011001010100000001100111110000101000000






