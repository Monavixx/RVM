#pragma once
#include <string>
#include "../Functions/Exit.h"

#ifdef _WIN32
#include <Windows.h>
#endif

class String
{
public:
	String() {}
	String(const char str[])
	{
		_size = strlen(str);
		data = new unsigned short[capacity = _size + 10];
		for (int i = 0; i < _size; ++i)
		{
			data[i] = str[i];
		}
	}
#ifdef _WIN32
	String(const wchar_t str[])
	{
		_size = wcsnlen(str, -1);
		data = new unsigned short[capacity = _size + 10];
		for (int i = 0; i < _size; ++i)
		{
			data[i] = str[i];
		}
	}
#endif
	inline unsigned short* utf16() const
	{
		return data;
	}
	inline long long size() const
	{
		return _size;
	}
#ifdef _WIN32
	static String FromWCharArray(wchar_t buf[], size_t bufsize)
	{
		String res;
		for (size_t i = 0; i < bufsize; ++i)
		{
			res.push_back(buf[i]);
		}
		return res;
	}
#endif
	unsigned short& operator[](size_t index) const
	{
#ifdef DEBUG
		if (index >= _size) Exit("String. Index out of range");
#endif
		return data[index];
	}
	void push_back(unsigned short symbol)
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
	String& operator+=(const String& other)
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
	void truncate(size_t index)
	{
		data[index] = '\0';
		_size = index;
	}
	bool operator==(const String& other) const
	{
		if (_size != other._size) return false;
		for (size_t i = 0; i < _size; ++i)
		{
			if (data[i] != other.data[i]) return false;
		}
		return true;
	}
	bool operator!=(const String& other) const
	{
		return !operator==(other);
	}
	String operator+(const String& other) const
	{
		String res;
		size_t newSize = _size + other._size;
		if (newSize < capacity)
		{
			for (size_t i = _size; i < newSize; ++i)
			{
				res.data[i] = other.data[i];
			}
		}
		else
		{
			unsigned short* newData = new unsigned short[res.capacity = newSize + 10];
			for (size_t i = 0; i < _size; ++i)
			{
				newData[i] = data[i];
			}

			for (size_t i = _size; i < newSize; ++i)
			{
				newData[i] = other.data[i];
			}

			res.data = newData;
		}
		res._size = newSize;

		return res;
	}
private:
	size_t _size = 0;
	size_t capacity = 0;
	unsigned short* data = nullptr;
};

