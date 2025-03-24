#ifndef SECURITY_LAYER_H
#define SECURITY_LAYER_H

#include <openssl/evp.h>
#include <iostream>

std::string encrypt(const std::string &data);
std::string decrypt(const std::string &data);
bool authenticate(const std::string &user, const std::string &password);

#endif
