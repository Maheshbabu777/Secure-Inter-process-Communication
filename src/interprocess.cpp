#include "../include/interprocess.h"
#include <cstring>
#include <cstdio>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>

using namespace std;

void create_shm() {
    int shared_mem = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (shared_mem == -1) {
        printf("Error creating shared memory\n");
        return;
    }
    ftruncate(shared_mem, SHM_SIZE);
    close(shared_mem);
}

void write_to_shm(const string &str) {
    int mem = shm_open(SHM_NAME, O_RDWR, 0666);
    if (mem == -1) {
        printf("Error opening shared memory to write\n");
        return;
    }
    void *ptr = mmap(0, SHM_SIZE, PROT_WRITE, MAP_SHARED, mem, 0);
    if (ptr == MAP_FAILED) {
        printf("Error mapping shared memory\n");
        close(mem);
        return;
    }

    int len = str.size();
    memcpy(ptr, &len, sizeof(int));
    memcpy((char*)ptr + sizeof(int), str.data(), len);

    munmap(ptr, SHM_SIZE);
    close(mem);
}

string read_from_shm() {
    int mem = shm_open(SHM_NAME, O_RDONLY, 0666);
    if (mem == -1) {
        printf("Error opening shared memory to read\n");
        return "";
    }
    void *ptr = mmap(0, SHM_SIZE, PROT_READ, MAP_SHARED, mem, 0);
    if (ptr == MAP_FAILED) {
        printf("Error mapping shared memory\n");
        close(mem);
        return "";
    }

    int len;
    memcpy(&len, ptr, sizeof(int));
    string data((char*)ptr + sizeof(int), len);

    munmap(ptr, SHM_SIZE);
    close(mem);
    return data;
}

void send_msg(const string &str) {
    int msgq = msgget(MSG_KEY, 0666 | IPC_CREAT);
    message msg;
    msg.msg_type = 1;

    memset(msg.mes, 0, SHM_SIZE);
    int len = str.size();
    memcpy(msg.mes, &len, sizeof(int));
    memcpy(msg.mes + sizeof(int), str.data(), len);

    if (msgsnd(msgq, &msg, sizeof(msg.mes), 0) == -1) {
        printf("Error sending message\n");
    }
}

string recive_msg() {
    int msgq = msgget(MSG_KEY, 0666 | IPC_CREAT);
    message msg;
    if (msgrcv(msgq, &msg, sizeof(msg.mes), 1, 0) == -1) {
        printf("Error receiving message\n");
        return "";
    }

    int len;
    memcpy(&len, msg.mes, sizeof(int));
    string data(msg.mes + sizeof(int), len);
    return data;
}
