#include "PcapHandler.h"

PcapHandler::PcapHandler(string a_filePath)
{
	try
	{
		m_file.open(a_filePath, fstream::binary | fstream::in);
		if (m_file.is_open())
		{
			m_file.read((char*)&m_globalHeader, sizeof(pcap_hdr_s));
		}
	}
	catch (const iostream::failure& ex)
	{
		cout << ex.what() << endl;
	}
}

ifstream& PcapHandler::getFile()
{
	return m_file;
}

pcap_hdr_s& PcapHandler::getHeader()
{
	return m_globalHeader;
}

PcapHandler::~PcapHandler()
{
	m_file.close();
}