#pragma once

#include <QtCore>

class Exception
{
public:
	Exception(const QString& message) : message(message)
	{
	}

	const QString& What() const
	{
		return message;
	}

protected:
	QString message;
};