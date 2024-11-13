
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

int main() {
    //creating a preset header reference
    string headerref[256]; //array starts from 1
    int count = 1;
    int power = 1;
    for (int i = 1; i < 256 && count < 256;) {
        for (int j = 1; j <= i && count < 256; j++) {
            //cout << power << "," << i << "," << j << "," << count << endl;  //debug
            //i=length of binary, j=binary representation, count=index
            headerref[count] = dectobin(j,power);
            //cout << headerref[count] << endl; //debug
            count++;
        }
        power++;
        i = (1 << power) - 1; //manual increments to generate the weird key string.
    }
    
    //done creating the header ref, start io&proc
    string header;
    string check;

    cout << "\nEnter Header: \n";
    getline(cin, header);
    cout << "\nCharacter?";
    getline(cin, check);
    int position = 0;
    while ((position = header.find(check, position + 1)) != string::npos) {
        cout << headerref[position+1] << endl;
    }
    return 0;
}
