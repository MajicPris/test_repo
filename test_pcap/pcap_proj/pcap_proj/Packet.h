#ifndef PACKETS_HEADER
#define PACKETS_HEADER

#include <iostream>
#include "NetworkHeaders.h"

using namespace std;

class Packet
{
private:
    static const uint8_t IP_HEADER_OFFSET = 14;

public:
    Packet();
    Packet(char* a_pArray);

private:
    ethernet_hdr_t m_ethernet;
    ip_hdr_t m_ip;
    tcp_header_t m_tcp;
    HttpRequest m_http;
};

#endif