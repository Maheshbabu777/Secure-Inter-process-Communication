#include "../include/security.h"
using namespace std;
const string SECRET_KEY = "Seurity789@";

string encrypt(const string &data) {
    string encrypted_data = data;
    for (int i = 0; i < encrypted_data.size(); i++) {
        encrypted_data[i] = encrypted_data[i] ^ SECRET_KEY[i % SECRET_KEY.size()];  
    }
    return encrypted_data;
}

string decrypt(const string &data) {
    string decrypted_data = data;
    for (int i = 0; i < decrypted_data.size(); i++) {
        decrypted_data[i] = decrypted_data[i] ^ SECRET_KEY[i % SECRET_KEY.size()];  
    }
    return decrypted_data;
}

bool authenticate(const string &user, const string &password) {
    return ((user == "user1" && password == "user@001") || (user == "user2" && password == "user@002"));
}
