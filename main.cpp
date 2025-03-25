#include <iostream>
#include "include/interprocess.h"
#include "include/security.h"
#include "include/management.h"
using namespace std;

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

    string message;
    cout << "Enter your message: ";
    cin.ignore();
    getline(cin, message);

    string encrypted_message = encrypt(message);

    write_to_shm(encrypted_message);
    string shm_message = read_from_shm();
    string decrypted_shm_message = decrypt(shm_message);

    cout << "\nMessage from Shared Memory (Decrypted): " << decrypted_shm_message << endl;
    log_message("Message read from shared memory and decrypted successfully.");

    send_msg(encrypted_message);
    string received_encrypted_msg = recive_msg();
    string decrypted_queue_message = decrypt(received_encrypted_msg);

    cout << "Message from Message Queue (Decrypted): " << decrypted_queue_message << endl;
    log_message("Message sent, received, and decrypted successfully using message queue.");

    return 0;
}
