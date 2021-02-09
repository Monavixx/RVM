#pragma once
#include <QtCore>
struct Args
{
	static inline vector<QString> args = {};

	static bool contains(const QString& arg)
	{
		return std::find(args.begin(), args.end(), arg) != args.end();
	}
};