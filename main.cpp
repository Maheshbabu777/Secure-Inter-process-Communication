#include "include/interprocess.h"

int main() {
    printf("Creating shared memory\n");
    create_shm();

    string data_to_write = "Yo! This is for you.\n";
    printf("Writing to shared memory: %s", data_to_write.c_str());
    write_to_shm(data_to_write);
    
    string message_to_send = data_to_write;
    printf("Sending message\n");
    send_msg(message_to_send);
    
    string message_received = recive_msg();
    printf("Message received from queue\n");
    
    string data_read = read_from_shm();
    printf("Data read from shared memory: %s\n", data_read.c_str());


    return 0;
}
