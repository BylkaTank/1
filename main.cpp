#include <iostream>
#include <string>
using namespace std;

string encrypt_caesar(string encryptionString, int shift){

    int position = 1;
    if(shift >= 0){
        for(int i = 0; i < encryptionString.length(); i++){
            if (encryptionString[i] >= 'A' && encryptionString[i] <= 'Z') encryptionString[i] = ((encryptionString[i] - 'A' + shift) % 26 ) + 'A';
            else if (encryptionString[i] >= 'a' && encryptionString[i] <= 'z') encryptionString[i] = ((encryptionString[i] - 'a' + shift) % 26 ) + 'a';
        }
        return encryptionString;
    } else {
        shift -= shift * 2;
        for(int i = 0; i < encryptionString.length(); i++){
            if (encryptionString[i] >= 'A' && encryptionString[i] <= 'Z') encryptionString[i] = (26 - ((encryptionString[i] - 'A' + shift) % 26 )) + 'A' + position + i;
            else if (encryptionString[i] >= 'a' && encryptionString[i] <= 'z') encryptionString[i] = (26 - ((encryptionString[i] - 'a' + shift) % 26 )) + 'a' + position + i;
            position++;
        }
        return encryptionString;
    }
}

string decrypt_caesar(string decryptionString, int shift){
    if (shift > 0) return encrypt_caesar(decryptionString, 26 - shift);
    else return encrypt_caesar(decryptionString, 26 - shift  - 1);
}

int main() {
    string encryptionString , decryptionString;
    int shift;
    cout << "Enter the encryption string: " << endl;
    getline(cin,encryptionString);
    cout << "Enter the shift: " << endl;
    cin >> shift;
    cout << encrypt_caesar(encryptionString, shift) << endl;
    cout << "Enter the shift: " << endl;
    cin >> shift;
    cout << decrypt_caesar(encrypt_caesar(encryptionString, shift),shift);
}
