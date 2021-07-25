#pragma once

#include <vector>

class ByteArrayReader
{
public:
	ByteArrayReader(std::vector<unsigned char>&& bytearray) : bytearray{std::move(bytearray)}
	{
	}

	unsigned char* read(size_t amount)
	{
		if (bytearray.size() < currentIndex + amount) {
			throw "the size of the byte array is too small";
		}
		currentIndex += amount;
		return bytearray.data() + currentIndex - amount;
	}

	template<class Num>
	Num readNum()
	{
		unsigned char* data = read(sizeof(Num));
		Num value = 0;//static_cast<unsigned char>(data[0]) << (sizeof(Num) - 1) * 8;
		for (unsigned char i = 0; i < sizeof(Num); ++i) {
			value |= static_cast<unsigned char>(data[i]) << (sizeof(Num) - i - 1) * 8;
		}
		return value;
	}

private:
	std::vector<unsigned char> bytearray;
	size_t currentIndex = 0;
};