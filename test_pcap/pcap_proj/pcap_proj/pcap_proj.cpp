// pcap_proj.cpp : Defines the entry point for the application.
//

#include "pcap_proj.h"
#include <fstream>
#include<vector>


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

typedef struct udp_header
{
    uint16_t src;
    uint16_t dst;
    uint16_t length;
    uint16_t checksum;
} udp_header_t;

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

static const std::uint32_t BUFFER_SIZE = 0x80000;

typedef enum HttpMethod { UNSUPPORTED, GET, HEAD } HttpMethod;

typedef struct HttpHeader {
    char* name;
    char* value;
    struct HttpHeader* next;
} HttpHeader;

typedef struct HttpRequest {
    enum HttpMethod method;
    char* url;
    char* version;
    struct HttpHeader* headers;
    char* body;
} HttpRequest;

void ParseHttp(const char* raw)
{
    struct HttpRequest* req = (struct HttpRequest*)malloc(sizeof(struct HttpRequest));

    if (!req) {
        return;
    }
    memset(req, 0, sizeof(struct HttpRequest));

    // Method
    size_t meth_len = strcspn(raw, " ");
    if (memcmp(raw, "GET", strlen("GET")) == 0) {
        req->method = GET;
    }
    else if (memcmp(raw, "HEAD", strlen("HEAD")) == 0) {
        req->method = HEAD;
    }
    else {
        req->method = UNSUPPORTED;
    }
    raw += meth_len + 1; // move past <SP>
    cout << "req->method = " << req->method << endl;

    // Request-URI
    size_t url_len = strcspn(raw, " ");
    req->url = (char*)malloc(url_len + 1);
    if (!req->url) {
        free(req);
        return;
    }
    memcpy(req->url, raw, url_len);
    req->url[url_len] = '\0';
    raw += url_len + 1; // move past <SP>
    cout << "req->url = " << req->url << endl;

    free(req);
}

int main()
{
    const char* path = "C:\\Users\\kshar\\git\\test_repo\\test_pcap\\pcap_proj\\pcap_proj\\test.pcap";
    FILE* ptrFile = fopen(path, "rb");

    struct pcap_hdr_s gheader;

    if (!ptrFile)
    {
        cout << "Error: file could not be opened" << endl;
        return 0;
    }
    else
    {
        cout << "file opened" << endl;
    }

    fread(&gheader, sizeof(char), sizeof(struct pcap_hdr_s), ptrFile);

    // if not ethernet type
    if (gheader.network != 1)
    {
        printf("not ethernet !\n");
        return 1;
    }

    char* buffer = (char*)malloc(gheader.snaplen);

    struct pcaprec_hdr_s pheader;
    struct ethernet_hdr_s eth;
    struct ip_hdr_s ip;
    struct tcp_header_s tcp;

	cout << "Hello CMake." << endl;
    /*cout << "magic = " << gheader.magic_number << endl;
    cout << "major = " << gheader.version_major << endl;
    cout << "minor = " << gheader.version_minor << endl;*/

    int count = 0, bytes_read;

    fread(&pheader, sizeof(char), sizeof(struct pcaprec_hdr_s), ptrFile);

    while (count<4)
    {
        count++;
        cout << "Packet number: " << count << endl;
        cout << "Packet len: " << pheader.orig_len << endl;
        bytes_read = fread(&eth, sizeof(char), sizeof(struct ethernet_hdr_s), ptrFile);
        cout << "eth.dst = " << std::hex <<eth.dst << endl;
        cout << "eth.src = " << std::hex <<eth.src << endl;
        cout << "eth.type = " << eth.type << endl;

        // ip
        if (eth.type == 0x08)
        {
            bytes_read += fread(&ip, sizeof(char), sizeof(struct ip_hdr_s), ptrFile);
            cout << "ip.ip_ttl = " << ip.ip_ttl << endl;
            cout << "ip.ip_dst = " << ip.ip_dst << endl;
            cout << "ip.ip_src = " << ip.ip_src << endl;

            //tcp
            if (ip.ip_p == 0x06)
            {
                bytes_read += fread(&tcp, sizeof(char), sizeof(struct tcp_header_s), ptrFile);
                cout << "tcp.src_port = " << tcp.src_port << endl;
                cout << "tcp.dst_port = " << tcp.dst_port << endl;
                cout << "tcp.window_size = " << tcp.window_size << endl;

                cout << "bytes_read = " << bytes_read << endl;
            }
        }

        //read rest of the packet
        fread(buffer, sizeof(char), pheader.incl_len - bytes_read, ptrFile);
        ParseHttp(buffer);
        //cout << "rest buffer = " << buffer << endl;

        // read next packet's header
        fread(&pheader, sizeof(char), sizeof(struct pcaprec_hdr_s), ptrFile);
        cout << endl;
    }

    cout << "Total packets: " << count << endl;
    /*cout << "magic = " << gheader.magic_number << endl;
    cout << "major = " << gheader.version_major << endl;
    cout << "minor = " << gheader.version_minor << endl;*/

    fclose(ptrFile);
	return 0;
}
