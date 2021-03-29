#pragma once
#include <string>
#include <iostream>
#include "../Functions/Exit.h"

#ifdef _WIN32
#include <Windows.h>


class String
{
public:
	String() {}
	String(const char str[]);
	String(const std::string& str);
	String(long long num);
	constexpr String(const char* str, size_t size)
	{
		_size = size;
		data = new unsigned short[capacity = _size + 10];
		for (int i = 0; i < _size; ++i)
		{
			data[i] = str[i];
		}
	}
	String(const wchar_t str[]);
	constexpr String(const wchar_t str[], size_t size)
	{
		_size = size;
		data = new unsigned short[capacity = _size + 10];
		for (int i = 0; i < _size; ++i)
		{
			data[i] = str[i];
		}
	}
	static String FromWCharArray(wchar_t buf[], size_t bufsize);

	inline unsigned short* utf16() const
	{
		return data;
	}
	inline size_t size() const
	{
		return _size;
	}
	inline unsigned short& operator[](size_t index) const
	{
#ifdef _DEBUG
		if (index >= _size) Exit("String. Index out of range\n");
#endif
		return data[index];
	}
	void push_back(unsigned short symbol);
	String& operator+=(const String& other);
	void truncate(size_t index);
	bool operator==(const String& other) const;
	bool operator!=(const String& other) const;
	String operator+(const String& other) const;
	String operator+(long long num) const;
	inline void SetSize(size_t newSize)
	{
		_size = newSize;
		capacity = newSize;
	}
	bool startsWith(const String& other) const;
	std::string toStdString() const;
	int toInt(bool* isOk = nullptr) const
	{
		int num;
		try
		{
			num = std::stoi(toStdString());
		}
		catch (...)
		{
			*isOk = false;
			num = 0;
		}
		return num;
	}
	wchar_t* toWCharArray() const
	{
		wchar_t* res = new wchar_t[_size+1];
		for (size_t i = 0; i < _size; ++i)
		{
			res[i] = (*this)[i];
		}
		res[_size] = '\0';
		return res;
	}

	void Resize(size_t size)
	{
		if (data == nullptr)
		{
			data = new unsigned short[capacity = size + 10]{ 0 };
		}
		else
		{
			unsigned short* newData = new unsigned short[capacity = size + 10];
			for (size_t i = 0; i < (_size > size ? size : _size); ++i)
			{
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
		}
		_size = size;
	}

	void reserve(size_t capacitySize)
	{
		if (data == nullptr)
		{
			data = new unsigned short[capacity = capacitySize]{ 0 };
		}
		else
		{
			unsigned short* newData = new unsigned short[capacity = capacitySize];
			for (size_t i = 0; i < _size; ++i)
			{
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
		}
	}
private:
	size_t _size = 0;
	size_t capacity = 0;
	unsigned short* data = nullptr;
};

constexpr String operator"" _ss(const char* str, size_t size)
{
	return String(str, size);
}

constexpr String operator"" _ss(const wchar_t* str, size_t size)
{
	return String(str, size);
}
namespace std
{
	template<>
	struct hash<String>
	{
		size_t operator()(const String& s) const
		{
			static const int A = 54059;
			static const int B = 76963;
			static const int FIRSTH = 37;
			size_t h = FIRSTH;
			for (size_t i = 0; i < s.size(); ++i) {
				h = (h * A) ^ ((long long)(s[0]) * B);
			}
			return h;
		}
	};
}
#else
typedef std::string String;
#endif