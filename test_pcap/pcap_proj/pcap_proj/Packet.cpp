#include "Packet.h"

Packet::Packet()
{

}

Packet::Packet(char* a_pArray)
	: m_ethernet(a_pArray), m_ip(a_pArray + IP_HEADER_OFFSET),
	m_tcp(a_pArray + IP_HEADER_OFFSET + m_ip.ip_hl),
	m_http(a_pArray + IP_HEADER_OFFSET + m_ip.ip_hl + 20)
{
	cout << "eth.dst = " << hex << m_ethernet.dst << endl;
	cout << "eth.src = " << hex << m_ethernet.src << endl;
	cout << "eth.type = " << m_ethernet.type << endl;
	cout << "ip.ip_len = " << m_ip.ip_len << endl;
	cout << "ip.ip_p = " << dec << m_ip.ip_p << endl;
	cout << "ip.ip_src = " << hex << m_ip.ip_src << endl;
	cout << "ip.ip_dst = " << hex << m_ip.ip_dst << endl;
	cout << "tcp.src_port = " << m_tcp.src_port << endl;
	cout << "tcp.dst_port = " << m_tcp.dst_port << endl;
	cout << "tcp.window_size = " << m_tcp.window_size << endl;
	cout << "tcp.checksum = " << m_tcp.checksum << endl;
	cout << endl;
}