#ifndef PACKETS_HEADER
#define PACKETS_HEADER

#include <iostream>
#include "NetworkHeaders.h"

using namespace std;

class Packet
{
private:
    static const uint8_t IP_HEADER_OFFSET = 14;
    static const uint8_t TCP_HEADER_OFFSET = 20;

public:
    Packet();

    /* Create Packet object from a_pArray */
    Packet(char* a_pArray);

    /* Get reference to the current HTTP request*/
    const HttpRequest& getHttpRequest() const;

    /* Show parsed data in packet */
    std::string getString() const;

    /* Operator to show packet data */
    friend std::ostream& operator <<(std::ostream& os, Packet& a_rPack) { os << a_rPack.getString(); return os; }


private:
    ethernet_hdr_t m_ethernet;
    ip_hdr_t m_ip;
    tcp_header_t m_tcp;
    HttpRequest m_http;
};

#endif