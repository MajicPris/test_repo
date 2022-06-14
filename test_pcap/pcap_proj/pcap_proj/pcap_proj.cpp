// pcap_proj.cpp : Defines the entry point for the application.
//

#include "pcap_proj.h"
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <sstream>
#include <string>
#include "PcapHandler.h"
#include "NetworkHeaders.h"
using namespace std;


/*static const std::uint32_t BUFFER_SIZE = 0x80000;

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

    // HTTP-Version
    size_t ver_len = strcspn(raw, "\r\n");
    req->version = (char*)malloc(ver_len + 1);
    if (!req->version) {
        free(req);
        return;
    }
    memcpy(req->version, raw, ver_len);
    req->version[ver_len] = '\0';
    raw += ver_len + 2; // move past <CR><LF>
    cout << "req->version = " << req->version << endl;

    struct HttpHeader* header = NULL, * last = NULL;
    while (raw[0] != '\r' && raw[1] != '\n')
    {
        last = header;
        header = (struct HttpHeader*)malloc(sizeof(struct HttpHeader));
        if (!header) {
            free(req);
            return;
        }

        // name
        size_t name_len = strcspn(raw, ":");
        header->name = (char*)malloc(name_len + 1);
        if (!header->name) {
            free(req);
            return;
        }
        memcpy(header->name, raw, name_len);
        header->name[name_len] = '\0';
        raw += name_len + 1; // move past :
        while (*raw == ' ') {
            raw++;
        }
        cout << "header->name = " << header->name << endl;

        // value
        size_t value_len = strcspn(raw, "\r\n");
        header->value = (char*)malloc(value_len + 1);
        if (!header->value) {
            free;
            return;
        }
        memcpy(header->value, raw, value_len);
        header->value[value_len] = '\0';
        raw += value_len + 2; // move past <CR><LF>
        cout << "header->value = " << header->value << endl;

        // next
        header->next = last;
    }

    req->headers = header;
    raw += 2; // move past <CR><LF>

    size_t body_len = strlen(raw);
    req->body = (char*)malloc(body_len + 1);
    if (!req->body) {
        free(req);
        return;
    }
    memcpy(req->body, raw, body_len);
    req->body[body_len] = '\0';

    free(req);
}*/

/*-----------------------------------------------------------*/
void Parse(char* raw)
{
    HttpRequest request = HttpRequest::deserialize(string(raw));

}

int main()
{
    string path = "C:\\Users\\kshar\\git\\test_repo\\test_pcap\\pcap_proj\\pcap_proj\\test.pcap";
    //FILE* ptrFile = fopen(path, "rb");
    PcapHandler handler(path);
    //ifstream file(path, fstream::binary | fstream::in);

    /*struct pcap_hdr_s gheader;

    if (!file)
    {
        cout << "Error: file could not be opened" << endl;
        return 0;
    }
    else
    {
        cout << "file opened" << endl;
    }*/

    //fread(&gheader, sizeof(char), sizeof(struct pcap_hdr_s), ptrFile);
    //file.read((char*)&gheader, sizeof(struct pcap_hdr_s));

    // if not ethernet type
    /*if (gheader.network != 1)
    {
        printf("not ethernet !\n");
        return 1;
    }*/

    //char* buffer = (char*)malloc(gheader.snaplen);
    char* buffer = std::allocator<char>().allocate(handler.getHeader().snaplen);

    struct pcaprec_hdr_s pheader;

	//cout << "Hello CMake." << endl;
    /*cout << "magic = " << gheader.magic_number << endl;
    cout << "major = " << gheader.version_major << endl;
    cout << "minor = " << gheader.version_minor << endl;*/

    int count = 0, bytes_read;

    //fread(&pheader, sizeof(char), sizeof(struct pcaprec_hdr_s), ptrFile);
    uint32_t data_length;
    while (count<4)
    {
        count++;
        //char packet_header_binary[16];
        //handler.getFile().read(packet_header_binary, sizeof packet_header_binary);
        handler.getFile().read((char*)&pheader, sizeof(pcaprec_hdr_s));
        cout << "Packet number: " << count << endl;

        memcpy(&data_length, &pheader.orig_len, sizeof(data_length));
        auto data = std::make_unique<char[]>(data_length);
        handler.getFile().read(data.get(), data_length); //read header

        cout << "Packet len: " << dec << data_length << endl;
        
        ethernet_hdr_t eth(data.get());
        //bytes_read = fread(&eth, sizeof(char), sizeof(struct ethernet_hdr_s), ptrFile);
        //handler.getFile().read((char*)&eth, sizeof(ethernet_hdr_t));
        //bytes_read = sizeof(ethernet_hdr_t);
        cout << "eth.dst = " << hex << eth.dst << endl;
        cout << "eth.src = " << hex << eth.src << endl;
        cout << "eth.type = " << eth.type << endl;

        // ip
        if (eth.type == 0x08)
        {
            ip_hdr_t ip(data.get()+14);
            //bytes_read += fread(&ip, sizeof(char), sizeof(struct ip_hdr_s), ptrFile);
            //handler.getFile().read((char*)&ip, sizeof(ip_hdr_t));
            //bytes_read += sizeof(ip_hdr_t);
            cout << "ip.ip_len = " << ip.ip_len << endl;            
            cout << "ip.ip_p = " << dec << ip.ip_p << endl;
            cout << "ip.ip_src = " << hex << ip.ip_src << endl;
            cout << "ip.ip_dst = " << hex << ip.ip_dst << endl;

            //tcp
            if (ip.ip_p == 0x06)
            {
                tcp_header_t tcp(data.get() + 14 + ip.ip_hl);
                //bytes_read += fread(&tcp, sizeof(char), sizeof(struct tcp_header_s), ptrFile);
                //handler.getFile().read((char*)&tcp, sizeof(tcp_header_t));
                //bytes_read += sizeof(tcp_header_t);
                cout << "tcp.src_port = " << tcp.src_port << endl;
                cout << "tcp.dst_port = " << tcp.dst_port << endl;
                cout << "tcp.window_size = " << tcp.window_size << endl;
                cout << "tcp.checksum = " << tcp.checksum << endl;

                //cout << "bytes_read = " << bytes_read << endl;
                //if (count == 4)
                //{
                    //ParseHttp(buffer);
                HttpRequest request = HttpRequest::deserialize(string(data.get() + 14 + ip.ip_hl + 20));
                    //Parse(data.get() + 14 + ip.ip_hl + 20);
                //}
            }
        }

        //read rest of the packet
        //fread(buffer, sizeof(char), pheader.incl_len - bytes_read, ptrFile);
        //handler.getFile().read(buffer, pheader.incl_len - bytes_read);

        //cout << "rest buffer = " << buffer << endl;

        // read next packet's header
        //fread(&pheader, sizeof(char), sizeof(struct pcaprec_hdr_s), ptrFile);
        //handler.getFile().read((char*)&pheader, sizeof(pcaprec_hdr_s));
        //cout << endl;
    }

    cout << "Total packets: " << count << endl;
    /*cout << "magic = " << gheader.magic_number << endl;
    cout << "major = " << gheader.version_major << endl;
    cout << "minor = " << gheader.version_minor << endl;*/

    //fclose(ptrFile);
    //file.close();
	return 0;
}
