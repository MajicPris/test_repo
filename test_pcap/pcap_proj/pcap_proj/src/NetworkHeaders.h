#ifndef NETWORK_HEADERS
#define NETWORK_HEADERS

#include <iostream>
#include <optional>
#include <fstream>
#include <vector>
using namespace std;

struct ethernet_hdr_t 
{
private:
    static const uint8_t SOURCE_HOST_HEADER_OFFSET = 6;
    static const uint8_t PROTOCOL_TYPE_HEADER_OFFSET = 12;

public:
    uint8_t dst[6] = {};    /* destination host address */
    uint8_t src[6] = {};    /* source host address */
    uint16_t type  = 0;     /* IP? ARP? RARP? etc */

    ethernet_hdr_t();

    /* Create ethernet_hdr_t object from a_pArray */
    ethernet_hdr_t(char* a_pArray);
};


struct ip_hdr_t
{
private:
    static const uint8_t DSCP_ECN_HEADER_OFFSET = 1;
    static const uint8_t PACKET_SIZE_HEADER_OFFSET = 2;
    static const uint8_t ID_HEADER_OFFSET = 4;
    static const uint8_t FLAGS_FRAGMENT_HEADER_OFFSET = 6;
    static const uint8_t LIFETIME_HEADER_OFFSET = 8;
    static const uint8_t PROTOCOL_TYPE_HEADER_OFFSET = 9;
    static const uint8_t CHECKSUM_HEADER_OFFSET = 10;
    static const uint8_t SOURCE_IP_HEADER_OFFSET = 12;
    static const uint8_t DESTINATION_IP_HEADER_OFFSET = 16;

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

    /* Create ip_hdr_t object from a_pArray */
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

    /* Create tcp_header_t object from a_pArray */
    tcp_header_t(char* a_pArray);
};


/* HTTP methods */
enum Method
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

/* convert method to string */
string methodToString(Method method);

/* convert string to method */
Method methodFromString(const string& method);


/* HTTP versions */
enum Version
{
    HTTP_1_0,
    HTTP_1_1,
    HTTP_2_0
};

/* convert version to string */
string versionToString(Version version);

/* convert string to version */
Version versionFromString(string& version);

/* split current string with delim to vector */
vector<string> split(const string& str, const string& delim);


class HttpHeader
{
public:
    HttpHeader();

    /* Create HttpHeader object from a_pArray */
    HttpHeader(string a_pArray);

    /* Init HttpHeader fields */
    void InitHeader(const string& header);

    /* Get m_key */
    const string& get_key() const;

    /* Get m_value */
    const string& get_value() const;

private:
    string m_key;
    string m_value;
};


class HttpRequest
{
public:

    HttpRequest();

    /* Create HttpRequest object from a_pArray */
    HttpRequest(char* a_pArray);

    /* Init HttpRequest fields */
    void InitRequest(const string& request);

    /* Download web page (host + resource) with WGET util */
    void downloadPage(const string& a_rPage);

    /* Get m_version */
    const Version& get_Version() const;

    /* Get m_method */
    const Method& get_Method() const;

    /* Get m_resource */
    const string& get_Resources() const;

    /* Get m_vHeaders */
    const vector<HttpHeader>& get_Headers() const;

private:
    static const string LINE_END;
    Version m_version;
    Method m_method;
    string m_resource;
    vector<HttpHeader> m_vHeaders;
};

#endif