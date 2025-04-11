#include <iostream>
#include "include/interprocess.h"
#include "include/security.h"
#include "include/management.h"
using namespace std;

void print_hex(const string &data) {
    for (unsigned char c : data) {
        printf("%02X ", c);
    }
    printf("\n");
}


int main() {
    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (!authenticate(username, password)) {
        log_message("Failed login attempt: " + username);
        cout << "Authentication Failed!" << endl;
        return 0;
    }

    log_message("Login successful: " + username);
    create_shm();

    int role;
    cout << "\nSelect :\n1. Sender\n2. Receiver\nChoice: ";
    cin >> role;
    cin.ignore();

    if (role == 1) {
        string message;
        cout << "Enter your message: ";
        getline(cin, message);

        string encrypted_message = encrypt(message);
        cout << "Encrypted Message: " << encrypted_message << endl;
        print_hex(encrypted_message);

        write_to_shm(encrypted_message);
        send_msg(encrypted_message);

        log_message("Message encrypted, written to SHM, and sent via queue.");
    } else if (role == 2) {
        string shm_message = read_from_shm();
        string decrypted_shm = decrypt(shm_message);
        cout << "Message from Shared Memory (Decrypted): " << decrypted_shm << endl;

        string queue_message = recive_msg();
        string decrypted_queue = decrypt(queue_message);
        cout << "Message from Message Queue (Decrypted): " << decrypted_queue << endl;

        log_message("Message read from SHM and MQ, then decrypted.");
    } else {
        cout << "Invalid role selected!" << endl;
    }

    return 0;
}
