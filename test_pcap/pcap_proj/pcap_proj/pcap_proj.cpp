// pcap_proj.cpp : Defines the entry point for the application.
//
#define _HAS_STD_BYTE 0 
#include <iostream>
#include <vector>
#include "PcapHandler.h"
#include "NetworkHeaders.h"
#include "Packet.h"

using namespace std;


void showPacketsData(vector<Packet>& a_vPackets)
{

}

/*-----------------------------------------------------------*/

int main(int argc, const char** argv)
{
    PcapHandler handler(argv[1]);
    vector<Packet> vPackets;

    int count = 0;

    //while (!handler.isEof())
    while (count<4)
    {
        auto packet = handler.handlePacket();
        if (packet)
        {
            count++;
            vPackets.push_back(packet.value());
        }
    }

    showPacketsData(vPackets);

	return 0;
}
