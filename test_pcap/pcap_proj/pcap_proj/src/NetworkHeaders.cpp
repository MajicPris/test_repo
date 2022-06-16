#include "NetworkHeaders.h"
#include <algorithm>
#include <cstring>

//to change endian
inline void swap_endian(std::uint16_t& i) 
{
    i = (i << 8) | (i >> 8); 
}

ethernet_hdr_t::ethernet_hdr_t()
{

}

ethernet_hdr_t::ethernet_hdr_t(char* a_pArray)
{
    memcpy(dst, a_pArray, sizeof(dst));
    memcpy(src, a_pArray + SOURCE_HOST_HEADER_OFFSET, sizeof(src));
    memcpy(&type, a_pArray + PROTOCOL_TYPE_HEADER_OFFSET, sizeof(type));
    if (type != 8)
        throw ("Only IPv4 supported. Can't read this packet.");
}

ip_hdr_t::ip_hdr_t()
{

}

ip_hdr_t::ip_hdr_t(char* a_pArray)
{
    uint8_t first_byte; // first 4 bits - version, second 4 bits header lnen
    uint8_t top4_bits_mask = 0b11110000; // mask to extract a value
    uint8_t low4_bits_mask = 0b00001111;
    memcpy(&first_byte, a_pArray, 1);
    ip_v = (first_byte & top4_bits_mask) >> 4;
    ip_hl = (first_byte & low4_bits_mask) * 4; // 1 word = 4 bytes

    uint8_t second_byte; // the same foranother bytes
    uint8_t top6_bits_mask = 0b11111100;
    uint8_t low2_bits_mask = 0b00000011;
    memcpy(&second_byte, a_pArray + DSCP_ECN_HEADER_OFFSET, 1);
    ip_dscp = (second_byte & top6_bits_mask) >> 6;
    ip_ecn = second_byte & low2_bits_mask;

    memcpy(&ip_len, a_pArray + PACKET_SIZE_HEADER_OFFSET, sizeof(ip_len));
    swap_endian(ip_len);
    memcpy(&ip_id, a_pArray + ID_HEADER_OFFSET, sizeof(ip_id));
    swap_endian(ip_id);

    uint8_t sixth_bite;
    uint8_t top3_bits_mask = 0b11100000;
    uint8_t low5_bits_mask = 0b00011111;
    memcpy(&sixth_bite, a_pArray + FLAGS_FRAGMENT_HEADER_OFFSET, 1);
    ip_flags = (sixth_bite & top3_bits_mask) >> 5;
    ip_off = sixth_bite & low5_bits_mask;

    memcpy(&ip_ttl, a_pArray + LIFETIME_HEADER_OFFSET, sizeof(ip_ttl));
    memcpy(&ip_p, a_pArray + PROTOCOL_TYPE_HEADER_OFFSET, sizeof(ip_p));
    if (ip_p != 6)
        throw ("Only TCP supported. Can't read this packet.");

    memcpy(&ip_sum, a_pArray + CHECKSUM_HEADER_OFFSET, sizeof(ip_sum));
    swap_endian(ip_sum);
    memcpy(&ip_src, a_pArray + SOURCE_IP_HEADER_OFFSET, sizeof(ip_src));
    memcpy(&ip_dst, a_pArray + DESTINATION_IP_HEADER_OFFSET, sizeof(ip_dst));
}

tcp_header_t::tcp_header_t()
{

}

tcp_header_t::tcp_header_t(char* a_pArray)
{
    memcpy(&src_port, a_pArray, sizeof(src_port));
    swap_endian(src_port);
    memcpy(&dst_port, a_pArray + DESTINATION_PORT_HEADER_OFFSET, sizeof(dst_port));
    swap_endian(dst_port);
    memcpy(&seq, a_pArray + SEQUENCE_NUMBER_HEADER_OFFSET, sizeof(seq));
    memcpy(&ack, a_pArray + ACKNOWLEDGEMENT_NUMBER_HEADER_OFFSET, sizeof(ack));
    memcpy(&data_offset, a_pArray + DATA_HEADER_OFFSET, sizeof(data_offset));
    memcpy(&flags, a_pArray + FLAGS_HEADER_OFFSET, sizeof(flags));
    memcpy(&window_size, a_pArray + WINDOW_SIZE_HEADER_OFFSET, sizeof(window_size));
    swap_endian(window_size);
    memcpy(&checksum, a_pArray + CHECKSUM_HEADER_OFFSET, sizeof(checksum));
    swap_endian(checksum);
    memcpy(&urgent_p, a_pArray + URGENT_POINTER_HEADER_OFFSET, sizeof(urgent_p));
    swap_endian(urgent_p);
}


string methodToString(Method method)
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

Method methodFromString(const string& method)
{
    if (method == methodToString(Method::GET))
    {
        return Method::GET;
    }
    else if (method == methodToString(Method::HEAD))
    {
        return Method::HEAD;
    }
    else if (method == methodToString(Method::POST))
    {
        return Method::POST;
    }
    else if (method == methodToString(Method::PUT))
    {
        return Method::PUT;
    }
    else if (method == methodToString(Method::DELETE))
    {
        return Method::DELETE;
    }
    else if (method == methodToString(Method::TRACE))
    {
        return Method::TRACE;
    }
    else if (method == methodToString(Method::OPTIONS))
    {
        return Method::OPTIONS;
    }
    else if (method == methodToString(Method::CONNECT))
    {
        return Method::CONNECT;
    }
    else if (method == methodToString(Method::PATCH))
    {
        return Method::PATCH;
    }
}

string versionToString(Version version)
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

Version versionFromString(string& version)
{
    if (version == versionToString(Version::HTTP_1_0))
    {
        return Version::HTTP_1_0;
    }
    else if (version == versionToString(Version::HTTP_1_1))
    {
        return Version::HTTP_1_1;
    }
    else if (version == versionToString(Version::HTTP_2_0))
    {
        return Version::HTTP_2_0;
    }
}

vector<string> split(const string& str, const string& delim)
{
    vector<string> tokens = vector<string>();

    size_t last = 0;
    size_t next = 0;
    while ((next = str.find(delim, last)) != string::npos)
    {
        tokens.push_back(str.substr(last, next - last));
        last = next + 1;
    }
    tokens.push_back(str.substr(last));
    return tokens;
}


HttpHeader::HttpHeader()
{

}

HttpHeader::HttpHeader(string a_pArray)
{
    InitHeader(a_pArray);
}


const string& HttpHeader::get_key() const
{
    return this->m_key;
}

const string& HttpHeader::get_value() const
{
    return this->m_value;
}

void HttpHeader::InitHeader(const string& a_rHeader)
{
    size_t  pos = a_rHeader.find(':');
    if (pos != string::npos)
    {
        m_key = a_rHeader.substr(0, pos);

        size_t first = a_rHeader.find_first_not_of(" \t", pos + 1);
        size_t last = a_rHeader.find_last_not_of(" \t");
        m_value = a_rHeader.substr(first, last - first + 1);
    }
}

const string HttpRequest::LINE_END = "\r\n";

HttpRequest::HttpRequest()
{

}

HttpRequest::HttpRequest(char* a_pArray)
{
    InitRequest(string(a_pArray));
}

void HttpRequest::InitRequest(const string& a_rRequest)
{
    vector<string> lines = split(a_rRequest, string(LINE_END));

    if (lines.size() < 1)
    {
        throw runtime_error("HTTP Request should be >= 1 lines");
    }

    vector<string> segments = split(lines[0], " ");

    if (segments.size() != 3)
    {
        throw runtime_error("First line of HTTP request should be 3 space separated segments");
    }

    m_method = methodFromString(segments[0]);
    m_resource = segments[1];
    m_version = versionFromString(segments[2]);

    for (size_t i = 1; i < lines.size() - 1; i++)
    {
        if (lines[i].size() > 0)
        {
            HttpHeader header(lines[i]);
            m_vHeaders.push_back(header);
        }
    }
}


void HttpRequest::downloadPage(const string& a_rPage)
{
    auto result = find_if(m_vHeaders.begin(), m_vHeaders.end(),
                         [](const HttpHeader& m) -> bool { return m.get_key() == "\nHost"; });
    if (result != m_vHeaders.end())
    {
        string resStr = result->get_value() + m_resource;
        cout << "result URL =  " << resStr << endl;
        string outStr = "wget -O " + a_rPage + " " + resStr;
        system(outStr.c_str());
    } 
}

const Version& HttpRequest::get_Version() const
{
    return m_version;
}

const Method& HttpRequest::get_Method() const
{
    return m_method;
}

const string& HttpRequest::get_Resources() const
{
    return m_resource;
}

const vector<HttpHeader>& HttpRequest::get_Headers() const
{
    return m_vHeaders;
}