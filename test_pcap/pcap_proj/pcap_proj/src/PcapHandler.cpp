#include "PcapHandler.h"
#include <memory>
#include <cstring>

pcaprec_hdr_t::pcaprec_hdr_t()
{

}

pcaprec_hdr_t::pcaprec_hdr_t(char* a_pArray)
{
	memcpy(&ts_sec, a_pArray, sizeof(ts_sec));
	memcpy(&ts_usec, a_pArray + TIMESTAMP_MICROSECONDS_OFFSET, sizeof(ts_usec));
	memcpy(&incl_len, a_pArray + NUMBER_OF_OCTETS_LENGTH_OFFSET, sizeof(incl_len));
	memcpy(&orig_len, a_pArray + ORIGINAL_LENGTH_OFFSET, sizeof(incl_len));
}

PcapHandler::PcapHandler(const string& a_rFilePath)
    :m_packetsCount(0)
{
	m_file.exceptions(ifstream::badbit | ifstream::failbit);
	try
	{
		m_file.open(a_rFilePath, fstream::binary | fstream::in);
		if (m_file.is_open())
		{
			m_file.read(reinterpret_cast<char*>(& m_globalHeader), sizeof(pcap_hdr_t));
		}
	}
	catch (const ifstream::failure& ex)
	{
		cout << "Failed to open file" << endl;
		cout << ex.what() << endl;
	}
}

optional<Packet> PcapHandler::handlePacket()
{
	try
	{
		uint32_t data_length;
		pcaprec_hdr_t pheader;
		m_file.read(reinterpret_cast<char*>(&pheader), sizeof(pcaprec_hdr_t)); //read header
		if (!m_file.eof())
		{
			m_packetsCount++;
			cout << "Packet number: " << m_packetsCount << endl;
			memcpy(&data_length, &pheader.orig_len, sizeof(data_length));
			auto data = make_unique<char[]>(data_length);
			m_file.read(data.get(), data_length);
			return Packet(data.get());
		}
		else
		{
			return nullopt;
		}
	}
	catch (const std::exception& e)
	{
		cout << e.what() << std::endl
			<< "Error while reading packet with number" << m_packetsCount << std::endl;
		return nullopt;
	}
	catch (const string& e) 
	{
		cout << e << std::endl
			<< "Error while reading packet with number" << m_packetsCount << std::endl;
		return nullopt;
	}

}

bool PcapHandler::isEof() const
{ 
	return m_file.eof(); 
}

const ifstream& PcapHandler::getFile() const
{
	return m_file;
}

const pcap_hdr_t& PcapHandler::getHeader() const
{
	return m_globalHeader;
}

PcapHandler::~PcapHandler()
{
	m_file.close();
}