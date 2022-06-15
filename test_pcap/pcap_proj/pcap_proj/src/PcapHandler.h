#ifndef PCAP_HANDLER
#define PCAP_HANDLER

#include <iostream>
#include <optional>
#include <fstream>
#include "Packet.h"
using namespace std;

struct pcaprec_hdr_t 
{
private:
    static const uint8_t TIMESTAMP_MICROSECONDS_OFFSET = 4;
    static const uint8_t NUMBER_OF_OCTETS_LENGTH_OFFSET = 8;
    static const uint8_t ORIGINAL_LENGTH_OFFSET = 12;
public:
    uint32_t ts_sec   = 0;       /* timestamp seconds */
    uint32_t ts_usec  = 0;       /* timestamp microseconds */
    uint32_t incl_len = 0;       /* number of octets of packet saved in file */
    uint32_t orig_len = 0;       /* actual length of packet */

    pcaprec_hdr_t();

    /* Create pcaprec_hdr_t object from a_pArray */
    pcaprec_hdr_t(char* a_pArray);
};

struct pcap_hdr_t {
    uint32_t magic_number;   /* magic number */
    uint16_t version_major;  /* major version number */
    uint16_t version_minor;  /* minor version number */
    int32_t  thiszone;       /* GMT to local correction */
    uint32_t sigfigs;        /* accuracy of timestamps */
    uint32_t snaplen;        /* max length of captured packets, in octets */
    uint32_t network;        /* data link type */
};


class PcapHandler
{
public:

    /* Create PcapHandler object and open file from a_rFilePath */
    PcapHandler(const string& a_rFilePath);

    /* Handle next packet and return nullopt if incorrect */
    optional<Packet> handlePacket();

    /* Check end of the file*/
    bool isEof() const;

    /* Get reference to the opened file */
    const ifstream& getFile() const;

    /* Get reference to the Pcap header */
    const pcap_hdr_t& getHeader() const;

    ~PcapHandler();

private:
    pcap_hdr_t m_globalHeader;
    ifstream m_file;
    uint32_t m_packetsCount;
};

#endif