#include <iostream>
#include <optional>
#include <fstream>

using namespace std;

typedef struct pcap_hdr_s {
    uint32_t magic_number;   /* magic number */
    uint16_t version_major;  /* major version number */
    uint16_t version_minor;  /* minor version number */
    int32_t  thiszone;       /* GMT to local correction */
    uint32_t sigfigs;        /* accuracy of timestamps */
    uint32_t snaplen;        /* max length of captured packets, in octets */
    uint32_t network;        /* data link type */
} pcap_hdr_t;

typedef struct pcaprec_hdr_s {
    uint32_t ts_sec;         /* timestamp seconds */
    uint32_t ts_usec;        /* timestamp microseconds */
    uint32_t incl_len;       /* number of octets of packet saved in file */
    uint32_t orig_len;       /* actual length of packet */
} pcaprec_hdr_t;

typedef struct ethernet_hdr_s {
    uint8_t dst[6];    /* destination host address */
    uint8_t src[6];    /* source host address */
    uint16_t type;     /* IP? ARP? RARP? etc */
} ethernet_hdr_t;

typedef struct ip_hdr_s {
    uint8_t  ip_hl : 4, /* both fields are 4 bits */
             ip_v : 4;
    uint8_t  ip_tos;
    uint16_t ip_len;
    uint16_t ip_id;
    uint16_t ip_off;
    uint8_t  ip_ttl;
    uint8_t  ip_p;
    uint16_t ip_sum;
    uint32_t ip_src;
    uint32_t ip_dst;
}ip_hdr_t;

typedef struct tcp_header_s
{
    uint16_t src_port;
    uint16_t dst_port;
    uint32_t seq;
    uint32_t ack;
    uint8_t  data_offset;  // 4 bits
    uint8_t  flags;
    uint16_t window_size;
    uint16_t checksum;
    uint16_t urgent_p;
} tcp_header_t;

class PcapHandler
{
private:
    pcap_hdr_s m_globalHeader;
    ifstream m_file;
public:
    PcapHandler(string a_filePath);

    ifstream& getFile();

    pcap_hdr_s& getHeader();

    ~PcapHandler();

};