#include "NetworkHeaders.h"

inline void swap_endian(std::uint16_t& i) 
{
    i = (i << 8) | (i >> 8); 
} // для двухбайтного числа просто старший и младший байты меняются местами.

ethernet_hdr_t::ethernet_hdr_t()
{

}

ethernet_hdr_t::ethernet_hdr_t(char* a_pArray)
{
    std::memcpy(dst, a_pArray, sizeof(dst));
    std::memcpy(src, a_pArray + SOURCE_HOST_HEADER_OFSET, sizeof(src));
    std::memcpy(&type, a_pArray + PROTOCOL_TYPE_HEADER_OFSET, sizeof(type));
    if (type != 8)
        throw ("Only IPv4 supported. Can't read this packet.");
}

ip_hdr_t::ip_hdr_t()
{

}

ip_hdr_t::ip_hdr_t(char* a_pArray)
{
    uint8_t first_byte; // первый байт заголовка в первых 4-х битах которого хранится версия протокола, а во вторых 4-х - длина заголовка.
    uint8_t top4_bits_mask = 0b11110000; // Маски для получения доступа к нужным битам заголовка.
    uint8_t low4_bits_mask = 0b00001111;
    std::memcpy(&first_byte, a_pArray, 1);
    ip_v = (first_byte & top4_bits_mask) >> 4;
    ip_hl = (first_byte & low4_bits_mask) * 4; // Размер заголовка в .pcap файле представлен в количестве двоичных слов (1 слово = 4 байта), а нам нужно в байтах

    uint8_t second_byte; // Далее подобные операции аналогичны.
    uint8_t top6_bits_mask = 0b11111100;
    uint8_t low2_bits_mask = 0b00000011;
    memcpy(&second_byte, a_pArray + DSCP_ECN_HEADER_OFSET, 1);
    ip_dscp = (second_byte & top6_bits_mask) >> 6;
    ip_ecn = second_byte & low2_bits_mask;

    std::memcpy(&ip_len, a_pArray + PACKET_SIZE_HEADER_OFSET, sizeof(ip_len));
    swap_endian(ip_len);
    std::memcpy(&ip_id, a_pArray + ID_HEADER_OFSET, sizeof(ip_id));
    swap_endian(ip_id);

    uint8_t sixth_bite;
    uint8_t top3_bits_mask = 0b11100000;
    uint8_t low5_bits_mask = 0b00011111;
    memcpy(&sixth_bite, a_pArray + FLAGS_FRAGMENT_HEADER_OFSET, 1);
    ip_flags = (sixth_bite & top3_bits_mask) >> 5;
    ip_off = sixth_bite & low5_bits_mask;

    memcpy(&ip_ttl, a_pArray + LIFETIME_HEADER_OFSET, sizeof(ip_ttl));
    memcpy(&ip_p, a_pArray + PROTOCOL_TYPE_HEADER_OFSET, sizeof(ip_p));
    if (ip_p != 6)
        throw ("Only TCP supported. Can't read this packet.");

    memcpy(&ip_sum, a_pArray + CHECKSUM_HEADER_OFSET, sizeof(ip_sum));
    swap_endian(ip_sum);
    memcpy(&ip_src, a_pArray + SOURCE_IP_HEADER_OFSET, sizeof(ip_src));
    memcpy(&ip_dst, a_pArray + DESTINATION_IP_HEADER_OFSET, sizeof(ip_dst));
}

tcp_header_t::tcp_header_t()
{

}
uint16_t src_port = 0;
uint16_t dst_port = 0;
uint32_t seq = 0; //4
uint32_t ack = 0; //4
uint8_t  data_offset = 0; //1
uint8_t  flags = 0; //2
uint16_t window_size = 0; //2
uint16_t checksum = 0; //2
uint16_t urgent_p = 0; //2
static const uint8_t DESTINATION_PORT_HEADER_OFFSET = 2;
static const uint8_t SEQUENCE_NUMBER_HEADER_OFFSET = 4;
static const uint8_t ACKNOWLEDGEMENT_NUMBER_HEADER_OFFSET = 8;
static const uint8_t DATA_HEADER_OFFSET = 12;
static const uint8_t FLAGS_HEADER_OFFSET = 13;
static const uint8_t WINDOW_SIZE_HEADER_OFFSET = 14;
static const uint8_t CHECKSUM_HEADER_OFFSET = 16;
static const uint8_t URGENT_POINTER_HEADER_OFFSET = 18;


static const uint8_t DATA_LENGTH_HEADER_OFFSET = 4;
tcp_header_t::tcp_header_t(char* a_pArray)
{
    std::memcpy(&src_port, a_pArray, sizeof(src_port));
    swap_endian(src_port);
    std::memcpy(&dst_port, a_pArray + DESTINATION_PORT_HEADER_OFFSET, sizeof(dst_port));
    swap_endian(dst_port);
    std::memcpy(&seq, a_pArray + SEQUENCE_NUMBER_HEADER_OFFSET, sizeof(seq));
    std::memcpy(&ack, a_pArray + ACKNOWLEDGEMENT_NUMBER_HEADER_OFFSET, sizeof(ack));
    std::memcpy(&data_offset, a_pArray + DATA_HEADER_OFFSET, sizeof(data_offset));
    std::memcpy(&flags, a_pArray + FLAGS_HEADER_OFFSET, sizeof(flags));
    std::memcpy(&window_size, a_pArray + WINDOW_SIZE_HEADER_OFFSET, sizeof(window_size));
    swap_endian(window_size);
    std::memcpy(&checksum, a_pArray + CHECKSUM_HEADER_OFFSET, sizeof(checksum));
    swap_endian(checksum);
    std::memcpy(&urgent_p, a_pArray + URGENT_POINTER_HEADER_OFFSET, sizeof(urgent_p));
    swap_endian(urgent_p);
}


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


HttpHeader::HttpHeader(const string& key, const string& value)
: key(key), value(value)
{

}

const string& HttpHeader::get_key() const
{
    return this->key;
}

const string& HttpHeader::get_value() const
{
    return this->value;
}

HttpHeader HttpHeader::deserialize(const string& header)
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

    return HttpHeader(key, value);
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

HttpRequest::HttpRequest()
{

}

HttpRequest::HttpRequest(Method method, const string& resource, const vector<HttpHeader>& headers, Version version)
: version(version), method(method), resource(resource), headers(headers)
{

}

HttpRequest HttpRequest::deserialize(const string& request)
{
    vector<string> lines = split(request, string(LINE_END));

    if (lines.size() < 1)
    {
        //throw std::runtime_error("HTTP Request ('" + string(request) + "') consisted of " + /*std::to_string(lines.size()) + */" lines, should be >= 1.");
        return HttpRequest();
    }

    vector<string> segments = split(lines[0], " ");

    if (segments.size() != 3)
    {
        //throw std::runtime_error("First line of HTTP request ('" + string(request) + "') consisted of " + /*std::to_string(segments.size()) + */" space separated segments, should be 3.");
        return HttpRequest();
    }

    const Method method = method_from_string(segments[0]);
    const string resource = segments[1];
    const Version version = version_from_string(segments[2]);

    vector<HttpHeader> headers;

    for (size_t i = 1; i < lines.size() - 1; i++)
    {
        if (lines[i].size() > 0)
        {
            const HttpHeader header = HttpHeader::deserialize(lines[i]);
            headers.push_back(header);
        }
    }

    cout << "Method = " << to_string(method) << endl;
    cout << "version = " << to_string(version) << endl;
    cout << "resource = " << resource << endl;
    for (const auto& it : headers)
        cout << it.get_key() << " " << it.get_value() << endl;

    return HttpRequest(method, resource, headers, version);
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