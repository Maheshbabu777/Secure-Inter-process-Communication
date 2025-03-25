#include "../include/management.h"
#include <fstream>
using namespace std;

void log_message(const string &message) {
    ofstream logfile("ipc_log.txt", ios::app);
    logfile << "Log: " << message << endl;
    logfile.close();
}
