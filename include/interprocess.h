#ifndef INTERPROCESS_H
#define INTERPROCESS_H

#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <bits/stdc++.h>

#define SHM_NAME "/interprocess_shm"
#define SHM_SIZE 512
#define MSG_KEY 1234

using namespace std;

struct message
{
       long msg_type;
       char mes[SHM_SIZE];
};
void create_shm();
void write_to_shm(const string &str);
string read_from_shm();
void send_msg(const string &str);
string recive_msg();
#endif