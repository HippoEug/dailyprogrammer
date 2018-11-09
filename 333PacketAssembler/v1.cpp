#include <iostream>
#include <sstream>
#include <string>

struct Packet {
	size_t messageID;
	size_t packetID;
	size_t messageCount;
	std::string messageText;

	Packet() {}

	Packet(size_t messageID, size_t packetID, size_t messageCount, std::string messageText) {
		this->messageID = messageID;
		this->packetID = packetID;
		this->messageCount = messageCount;
		this->messageText = messageText;
	}
};

int main() {
	std::string line;

	Packet packet;

	while (std::getline(std::cin, line)) { // Extracts characters from cin and stores into line until delim or \n is found. Will get next input operation until end of file is reached
		std::stringstream stringIn(line); // Copies line into stringstream ss

		stringIn >> packet.messageID >> packet.packetID >> packet.messageCount >> packet.messageText;
		std::getline(stringIn, packet.messageText);

		std::cout << packet.messageID << std::endl;
		std::cout << packet.packetID << std::endl;
		std::cout << packet.messageCount << std::endl;
		std::cout << packet.messageText << std::endl;
	}
}
