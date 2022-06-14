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
private:
    pcap_hdr_t m_globalHeader;
    ifstream m_file;
    uint32_t m_packetsCount;
public:
    PcapHandler(string a_filePath);

    optional<Packet> handlePacket();

    inline bool isEof() const { return m_file.eof(); }

    ifstream& getFile();

    pcap_hdr_t& getHeader();

    ~PcapHandler();

};