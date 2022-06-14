#include "PcapHandler.h"

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

PcapHandler::PcapHandler(string a_filePath)
    :m_packetsCount(0)
{
	try
	{
		m_file.open(a_filePath, fstream::binary | fstream::in);
		if (m_file.is_open())
		{
			m_file.read((char*)&m_globalHeader, sizeof(pcap_hdr_t));
		}
	}
	catch (const iostream::failure& ex)
	{
		cout << ex.what() << endl;
	}
}

optional<Packet> PcapHandler::handlePacket()
{
    uint32_t data_length;
    pcaprec_hdr_t pheader;
    m_file.read((char*)&pheader, sizeof(pcaprec_hdr_t)); //read header
    if (!m_file.eof())
    {
        m_packetsCount++;
        cout << "Packet number: " << m_packetsCount << endl;
        memcpy(&data_length, &pheader.orig_len, sizeof(data_length));
        auto data = std::make_unique<char[]>(data_length);
        m_file.read(data.get(), data_length); 
        return Packet(data.get());
    }
    else
    {
        return nullopt;
    }
}

ifstream& PcapHandler::getFile()
{
	return m_file;
}

pcap_hdr_t& PcapHandler::getHeader()
{
	return m_globalHeader;
}

PcapHandler::~PcapHandler()
{
	m_file.close();
}