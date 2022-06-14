#include <iostream>
#include <optional>
#include <fstream>
#include <vector>
using namespace std;


struct ethernet_hdr_t 
{
private:
    static const uint8_t SOURCE_HOST_HEADER_OFSET = 6;
    static const uint8_t PROTOCOL_TYPE_HEADER_OFSET = 12;

public:
    uint8_t dst[6] = {};    /* destination host address */
    uint8_t src[6] = {};    /* source host address */
    uint16_t type  = 0;     /* IP? ARP? RARP? etc */

    ethernet_hdr_t();
    ethernet_hdr_t(char* a_pArray);
};


struct ip_hdr_t
{
private:
    static const std::uint8_t DSCP_ECN_HEADER_OFSET = 1;
    static const std::uint8_t PACKET_SIZE_HEADER_OFSET = 2;
    static const std::uint8_t ID_HEADER_OFSET = 4;
    static const std::uint8_t FLAGS_FRAGMENT_HEADER_OFSET = 6;
    static const std::uint8_t LIFETIME_HEADER_OFSET = 8;
    static const std::uint8_t PROTOCOL_TYPE_HEADER_OFSET = 9;
    static const std::uint8_t CHECKSUM_HEADER_OFSET = 10;
    static const std::uint8_t SOURCE_IP_HEADER_OFSET = 12;
    static const std::uint8_t DESTINATION_IP_HEADER_OFSET = 16;

public:
    uint8_t  ip_hl    = 0;
    uint8_t  ip_v     = 0;
    uint8_t  ip_dscp  = 0;
    uint8_t  ip_ecn   = 0;
    uint16_t ip_len   = 0;
    uint16_t ip_id    = 0;
    uint8_t  ip_flags = 0;
    uint16_t ip_off   = 0;
    uint8_t  ip_ttl   = 0;
    uint8_t  ip_p     = 0;
    uint16_t ip_sum   = 0;
    uint32_t ip_src   = 0;
    uint32_t ip_dst   = 0;

    ip_hdr_t();
    ip_hdr_t(char* a_pArray);
};


struct tcp_header_t
{
private:
    static const uint8_t DESTINATION_PORT_HEADER_OFFSET = 2;
    static const uint8_t SEQUENCE_NUMBER_HEADER_OFFSET = 4;
    static const uint8_t ACKNOWLEDGEMENT_NUMBER_HEADER_OFFSET = 8;
    static const uint8_t DATA_HEADER_OFFSET = 12;
    static const uint8_t FLAGS_HEADER_OFFSET = 13;
    static const uint8_t WINDOW_SIZE_HEADER_OFFSET = 14;
    static const uint8_t CHECKSUM_HEADER_OFFSET = 16;
    static const uint8_t URGENT_POINTER_HEADER_OFFSET = 18;
public:

    uint16_t src_port    = 0;
    uint16_t dst_port    = 0;
    uint32_t seq         = 0; 
    uint32_t ack         = 0;
    uint8_t  data_offset = 0;
    uint8_t  flags       = 0;
    uint16_t window_size = 0;
    uint16_t checksum    = 0;
    uint16_t urgent_p    = 0;

    tcp_header_t();
    tcp_header_t(char* a_pArray);
};

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

string to_string(Method method);

Method method_from_string(const string& method);

enum class Version
{
    HTTP_1_0,
    HTTP_1_1,
    HTTP_2_0
};

string to_string(Version version);

Version version_from_string(string& version);

vector<string> split(const string& str, const string& delim);


class HttpHeader
{
private:
    string key;
    string value;

public:
    HttpHeader(const string& key, const string& value);

    const string& get_key() const;

    const string& get_value() const;

    static HttpHeader deserialize(const string& header);
};


class HttpRequest
{
private:
    Version version;
    Method method;
    string resource;
    vector<HttpHeader> headers;

public:
    HttpRequest();

    HttpRequest(Method method, const string& resource, const vector<HttpHeader>& headers, Version version = Version::HTTP_1_1);

    static HttpRequest deserialize(const string& request);
};