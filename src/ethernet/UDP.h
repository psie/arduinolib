#ifndef __ETHERNET_UDP_H__
#define __ETHERNET_UDP_H__

#include <stdint.h>
#include <string.h>

#include "Wiz5100.h"

class UDPSock {
	private:
		uint8_t sock;
		uint16_t txOffset;
		struct {
			uint8_t remoteIP[4];
			uint16_t remotePort;
			uint16_t length;
		} header;

	public:
		UDPSock(uint8_t s, uint16_t sport) {
			sock = s;
			Wiz5100::socket(s, Wiz5100::MR_UDP, sport);
			memset(&header, 0, sizeof(header));
		}
		~UDPSock() {
			Wiz5100::close(sock);
		}
		void UDPBegin(uint8_t *ipp, uint16_t dport);
		void UDPFillbuf(uint8_t *buf, unsigned int n);
		void UDPSend();
		unsigned int UDPStartRecv();
		unsigned int UDPRead(uint8_t *buf, unsigned int n);
		void UDPFlush();
};
#endif
