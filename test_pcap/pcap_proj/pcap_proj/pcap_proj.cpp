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
static string LINE_END = "\r\n";

enum class Method
{
    GET,
    HEAD,
    POST,
    PUT,
    DELETE,
    TRACE,
    OPTIONS,
    CONNECT,
    PATCH
};

string to_string(Method method)
{
    switch (method)
    {
    case Method::GET:
        return "GET";
    case Method::HEAD:
        return "HEAD";
    case Method::POST:
        return "POST";
    case Method::PUT:
        return "PUT";
    case Method::DELETE:
        return "DELETE";
    case Method::TRACE:
        return "TRACE";
    case Method::OPTIONS:
        return "OPTIONS";
    case Method::CONNECT:
        return "CONNECT";
    case Method::PATCH:
        return "PATCH";
    }
}

Method method_from_string(const string& method)
{
    if (method == to_string(Method::GET))
    {
        return Method::GET;
    }
    else if (method == to_string(Method::HEAD))
    {
        return Method::HEAD;
    }
    else if (method == to_string(Method::POST))
    {
        return Method::POST;
    }
    else if (method == to_string(Method::PUT))
    {
        return Method::PUT;
    }
    else if (method == to_string(Method::DELETE))
    {
        return Method::DELETE;
    }
    else if (method == to_string(Method::TRACE))
    {
        return Method::TRACE;
    }
    else if (method == to_string(Method::OPTIONS))
    {
        return Method::OPTIONS;
    }
    else if (method == to_string(Method::CONNECT))
    {
        return Method::CONNECT;
    }
    else if (method == to_string(Method::PATCH))
    {
        return Method::PATCH;
    }
}

enum class Version
{
    HTTP_1_0,
    HTTP_1_1,
    HTTP_2_0
};

string to_string(Version version)
{
    switch (version)
    {
    case Version::HTTP_1_0:
        return "HTTP/1.0";

    case Version::HTTP_1_1:
        return "HTTP/1.1";

    case Version::HTTP_2_0:
        return "HTTP/2.0";
    }
}

Version version_from_string(string& version)
{
    if (version == to_string(Version::HTTP_1_0))
    {
        return Version::HTTP_1_0;
    }
    else if (version == to_string(Version::HTTP_1_1))
    {
        return Version::HTTP_1_1;
    }
    else if (version == to_string(Version::HTTP_2_0))
    {
        return Version::HTTP_2_0;
    }
}

vector<string> split(const string& str, const string& delim)
{
    vector<string> tokens = vector<string>();
    /*string strCopy = str;

    size_t pos = 0;
    string token;

    while ((pos = strCopy.find(delim)) != string::npos)
    {
        token = strCopy.substr(0, pos);
        strCopy.erase(0, pos + delim.length());

        tokens.push_back(token);
    }

    if (strCopy.length() > 0)
    {
        tokens.push_back(strCopy);
    }*/


    size_t last = 0; 
    size_t next = 0; 
    while ((next = str.find(delim, last)) != string::npos)
    { 
        tokens.push_back(str.substr(last, next - last));
        //cout << str.substr(last, next - last) << endl;
        last = next + 1; 
    } 
    tokens.push_back(str.substr(last));
    //cout << str.substr(last) << endl;
    return tokens;
}

/*std::string concat(const std::vector<std::string>& strings, const std::string& delim = "")
{
    std::string result;

    for (std::size_t i = 0; i < strings.size(); i++)
    {
        result += strings[i];

        if ((i + 1) != strings.size())
        {
            result += delim;
        }
    }

    return result;
}*/

class Header
{
private:
    string key;
    string value;

public:
    Header(const string& key, const string& value) 
        : key(key), value(value)
    {
    }

    const string& get_key() const
    {
        return this->key;
    }

    const string& get_value() const
    {
        return this->value;
    }

    /*std::string serialize() const
    {
        std::string header;
        header += this->key;
        header += ": ";
        header += this->value;
        header += LINE_END;

        return header;
    }*/

    static Header deserialize(const string& header)
    {
        size_t  pos = header.find(':');
        if (pos == string::npos) 
        {
            //throw appropriate_exception;
        }
        string key(header.substr(0, pos));

        size_t first = header.find_first_not_of(" \t", pos + 1);
        size_t last = header.find_last_not_of(" \t");
        string value(header.substr(first, last - first + 1));

        return Header(key, value);
    }
};


class Request
{
private:
    Version version;
    Method method;
    string resource;
    vector<Header> headers;

public:
    Request(Method method, const string& resource, const vector<Header>& headers, Version version = Version::HTTP_1_1)
        : version(version), method(method), resource(resource), headers(headers)
    {
    }

    /*std::string serialize() const
    {
        std::string request;
        request += to_string(this->method);
        request += " ";
        request += this->resource;
        request += " ";
        request += to_string(this->version);
        request += LINE_END;

        for (const Header& header : this->headers)
        {
            request += header.serialize();
        }

        request += LINE_END;
        return request;
    }*/

    static Request deserialize(const string& request)
    {
        vector<string> lines = split(request, string(LINE_END));

        if (lines.size() < 1)
        {
            throw std::runtime_error("HTTP Request ('" + string(request) + "') consisted of " + /*std::to_string(lines.size()) + */" lines, should be >= 1.");
        }

        vector<string> segments = split(lines[0], " ");

        if (segments.size() != 3)
        {
            throw std::runtime_error("First line of HTTP request ('" + string(request) + "') consisted of " + /*std::to_string(segments.size()) + */" space separated segments, should be 3.");
        }

        const Method method = method_from_string(segments[0]);
        const string resource = segments[1];
        const Version version = version_from_string(segments[2]);

        vector<Header> headers;

        for (size_t i = 1; i < lines.size()-1; i++)
        {
            if (lines[i].size() > 0)
            {
                const Header header = Header::deserialize(lines[i]);
                headers.push_back(header);
            }
        }

        cout << "Method = " << to_string(method) << endl;
        cout << "version = " << to_string(version) << endl;
        cout << "resource = " << resource << endl;
        for (const auto& it : headers)
            cout << it.get_key() << " " << it.get_value() << endl;

        return Request(method, resource, headers, version);
    }
};

void Parse(char* raw)
{
    Request request = Request::deserialize(string(raw));

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
    struct ethernet_hdr_s eth;
    struct ip_hdr_s ip;
    struct tcp_header_s tcp;

	//cout << "Hello CMake." << endl;
    /*cout << "magic = " << gheader.magic_number << endl;
    cout << "major = " << gheader.version_major << endl;
    cout << "minor = " << gheader.version_minor << endl;*/

    int count = 0, bytes_read;

    //fread(&pheader, sizeof(char), sizeof(struct pcaprec_hdr_s), ptrFile);
    handler.getFile().read((char*)&pheader, sizeof(pcaprec_hdr_s));

    while (count<4)
    {
        count++;
        cout << "Packet number: " << count << endl;
        cout << "Packet len: " << pheader.orig_len << endl;
        //bytes_read = fread(&eth, sizeof(char), sizeof(struct ethernet_hdr_s), ptrFile);
        handler.getFile().read((char*)&eth, sizeof(struct ethernet_hdr_s));
        bytes_read = sizeof(struct ethernet_hdr_s);
        cout << "eth.dst = " << std::hex <<eth.dst << endl;
        cout << "eth.src = " << std::hex <<eth.src << endl;
        cout << "eth.type = " << eth.type << endl;

        // ip
        if (eth.type == 0x08)
        {
            //bytes_read += fread(&ip, sizeof(char), sizeof(struct ip_hdr_s), ptrFile);
            handler.getFile().read((char*)&ip, sizeof(struct ip_hdr_s));
            bytes_read += sizeof(struct ip_hdr_s);
            cout << "ip.ip_ttl = " << ip.ip_ttl << endl;
            cout << "ip.ip_dst = " << ip.ip_dst << endl;
            cout << "ip.ip_src = " << ip.ip_src << endl;

            //tcp
            if (ip.ip_p == 0x06)
            {
                //bytes_read += fread(&tcp, sizeof(char), sizeof(struct tcp_header_s), ptrFile);
                handler.getFile().read((char*)&tcp, sizeof(struct tcp_header_s));
                bytes_read += sizeof(struct tcp_header_s);
                cout << "tcp.src_port = " << tcp.src_port << endl;
                cout << "tcp.dst_port = " << tcp.dst_port << endl;
                cout << "tcp.window_size = " << tcp.window_size << endl;

                cout << "bytes_read = " << bytes_read << endl;
            }
        }

        //read rest of the packet
        //fread(buffer, sizeof(char), pheader.incl_len - bytes_read, ptrFile);
        handler.getFile().read(buffer, pheader.incl_len - bytes_read);
        if (count == 4)
        {
            //ParseHttp(buffer);
            Parse(buffer);
        }
        //cout << "rest buffer = " << buffer << endl;

        // read next packet's header
        //fread(&pheader, sizeof(char), sizeof(struct pcaprec_hdr_s), ptrFile);
        handler.getFile().read((char*)&pheader, sizeof(pcaprec_hdr_s));
        cout << endl;
    }

    cout << "Total packets: " << count << endl;
    /*cout << "magic = " << gheader.magic_number << endl;
    cout << "major = " << gheader.version_major << endl;
    cout << "minor = " << gheader.version_minor << endl;*/

    //fclose(ptrFile);
    //file.close();
	return 0;
}
