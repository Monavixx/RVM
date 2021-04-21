#include "String.h"
#include "../Functions/Exit.h"

#ifdef _WIN32
String::String(const char str[])
{
	_size = strlen(str);
	data = new unsigned short[capacity = _size + 10];
	for (int i = 0; i < _size; ++i)
	{
		data[i] = str[i];
	}
}

String::String(const std::string& str)
{
	_size = str.size();
	data = new unsigned short[capacity = _size + 10];
	for (int i = 0; i < _size; ++i)
	{
		data[i] = str[i];
	}
}

String::String(long long num)
{
	std::string str = std::to_string(num);
	_size = str.size();
	data = new unsigned short[capacity = _size + 10];
	for (int i = 0; i < _size; ++i)
	{
		data[i] = str[i];
	}
}

String::String(const wchar_t str[])
{
	_size = wcsnlen(str, -1);
	data = new unsigned short[capacity = _size + 10];
	for (int i = 0; i < _size; ++i)
	{
		data[i] = str[i];
	}
}

String String::FromWCharArray(wchar_t buf[], size_t bufsize)
{
	String res;
	for (size_t i = 0; i < bufsize; ++i)
	{
		res.push_back(buf[i]);
	}
	return res;
}

void String::push_back(unsigned short symbol)
{
	if (capacity > _size)
		data[_size++] = symbol;
	else
	{
		unsigned short* newData = new unsigned short[capacity = _size + 10];
		for (size_t i = 0; i < _size; ++i)
		{
			newData[i] = data[i];
		}
		newData[_size++] = symbol;
		delete[] data;
		data = newData;
	}
}

String& String::operator+=(const String& other)
{
	size_t newSize = _size + other._size;
	if (newSize < capacity)
	{
		for (size_t i = _size; i < newSize; ++i)
		{
			data[i] = other.data[i];
		}
	}
	else
	{
		unsigned short* newData = new unsigned short[capacity = newSize + 10];
		for (size_t i = 0; i < _size; ++i)
		{
			newData[i] = data[i];
		}

		for (size_t i = _size; i < newSize; ++i)
		{
			newData[i] = other.data[i];
		}

		delete[] data;
		data = newData;
	}
	_size = newSize;

	return *this;
}

void String::truncate(size_t index)
{
	data[index] = '\0';
	_size = index;
}

bool String::operator==(const String& other) const
{
	if (_size != other._size) return false;
	for (size_t i = 0; i < _size; ++i)
	{
		if (data[i] != other.data[i]) return false;
	}
	return true;
}

bool String::operator!=(const String& other) const
{
	return !operator==(other);
}

String String::operator+(const String& other) const
{
	String res;
	size_t newSize = _size + other._size;
	res.resize(newSize);

	for (size_t i = 0; i < _size; ++i)
	{
		res.data[i] = data[i];
	}
	for (size_t i = _size; i < newSize; ++i)
	{
		res.data[i] = other.data[i - _size];
	}

	return res;
}

String String::operator+(long long num) const
{
	return *this + std::to_string(num);
}

bool String::starts_with(const String& other) const
{
	if (other.size() > _size) return false;
	for (size_t i = 0; i < other.size(); ++i)
	{
		if (data[i] != other.data[i]) return false;
	}
	return true;
}

std::string String::toStdString() const
{
	std::string res;
	res.reserve(_size);
	for (size_t i = 0; i < _size; ++i)
	{
		res.push_back(data[i]);
	}
	return res;
}
std::ostream& operator<<(std::ostream& os, const String& str)
{
	os << str.toStdString();
	return os;
}
#endif


int toInt(const String& str, bool* isOk)
{
	int num;
	try
	{
#ifdef _WIN32
		num = std::stoi(str.toStdString());
#else
		num = std::stoi(str);
#endif
	}
	catch (...)
	{
		*isOk = false;
		num = 0;
		return num;
	}
	*isOk = true;
	return num;
}

std::vector<String> split(const String& source, char sep)
{
	std::vector<String> res(1);
	size_t cur = 0;
	for (size_t i = 0; i < source.size(); ++i)
	{
		if (source[i] == sep)
		{
			++cur;
			res.push_back({});
		}
		else
		{
			res[cur].push_back(source[i]);
		}
	}

	return res;
}
