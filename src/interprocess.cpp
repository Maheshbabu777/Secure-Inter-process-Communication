#include "../include/interprocess.h"

void create_shm()
{
     int shared_mem = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
     if (shared_mem == -1)
     {
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
     memset(ptr, 0, SHM_SIZE);  // Clear the shared memory before writing
     memcpy(ptr, str.c_str(), str.length() + 1);  // Write message with null terminator
     munmap(ptr, SHM_SIZE);
     close(mem);
 }
 
string read_from_shm()
{
     int mem = shm_open(SHM_NAME, O_RDONLY, 0666);
     void *ptr = mmap(0, SHM_SIZE, PROT_READ, MAP_SHARED, mem, 0);
     char *c_ptr = static_cast<char *>(ptr);
     string temp(c_ptr);
     string data = temp;
     munmap(ptr, SHM_SIZE);
     close(mem);
     return data;
}
void send_msg(const string &str)
{
     int msgq = msgget(MSG_KEY, 0666 | IPC_CREAT);
     message msg;
     msg.msg_type = 1;
     strncpy(msg.mes, str.c_str(), SHM_SIZE - 1);
     msg.mes[SHM_SIZE - 1] = '\0';
     if (msgsnd(msgq, &msg, sizeof(msg.mes), 0) == -1)
     {
          printf("error sending message");
     }
}
string recive_msg()
{
     int msgq = msgget(MSG_KEY, 0666 | IPC_CREAT);
     message msg;
     if (msgrcv(msgq, &msg, sizeof(msg.mes), 1, 0) == -1)
     {
          printf("Error receiving messagee\n");
          return "";
     }
     return string(msg.mes);
}
