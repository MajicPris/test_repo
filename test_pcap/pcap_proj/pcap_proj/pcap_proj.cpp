#include <iostream>
#include <vector>
#include "src\PcapHandler.h"
#include "src\NetworkHeaders.h"
#include "src\Packet.h"
using namespace std;

/* show only first 4 packets */
void showPacketsData(vector<Packet>& a_vPackets)
{
    for (size_t i = 0; i < 4; ++i)
    {
        cout << a_vPackets[i] << endl;
    } 
}


int main(int argc, const char** argv)
{
    if (argc != 3)
    {
        cout << "You need 2 args to start the program." << endl;
        cout << "pcap_proj \\path_to_pcap_file \\path_to_output_image" << endl;
        return 0;
    }
    //string path = "C:\\Users\\kshar\\git\\test_repo\\test_pcap\\pcap_proj\\pcap_proj\\smallFlows.pcap";
    //PcapHandler handler(path);

    PcapHandler handler(argv[1]);
    vector<Packet> vPackets;

    if (handler)
    {
        //int count = 0;
        //while (count<4)
        while (!handler.isEof())
        {
            auto packet = handler.handlePacket();
            if (packet)
            {
                HttpRequest tmp = packet.value().getHttpRequest();
                tmp.downloadPage(argv[2]);
                //count++;
                vPackets.push_back(packet.value());
            }
        }
        showPacketsData(vPackets);
    }
	return 0;
}
