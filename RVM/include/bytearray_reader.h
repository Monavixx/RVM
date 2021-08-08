#pragma once

#include <vector>

#include "exceptions/exception.h"

using byte = unsigned char;

class ByteArrayReader
{
public:
	ByteArrayReader(std::vector<byte>&& bytearray) noexcept: bytearray{std::move(bytearray)}
	{
	}

	const byte* read(size_t amount) const
	{
		if (bytearray.size() < currentIndex + amount) {
			throw bytearray_reader_exception("the size of the byte array is too small");
		}
		currentIndex += amount;
		return bytearray.data() + currentIndex - amount;
	}

	template<class Num>
	Num readNum() const
	{
		const byte* data = read(sizeof(Num));
		Num value = 0;
		for (byte i = 0; i < sizeof(Num); ++i) {
			value |= static_cast<byte>(data[i]) << (sizeof(Num) - i - 1) * 8;
		}
		return value;
	}

	std::string readString() const
	{
		const int stringSize = readNum<int>();
		return std::string((char*)read(stringSize), stringSize);
	}
private:
	const std::vector<byte> bytearray;
	mutable size_t currentIndex = 0;
};