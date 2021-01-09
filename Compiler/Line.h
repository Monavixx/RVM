#pragma once
#include <QtCore>

#include "../Libs/ConsoleTextStream.h"
#include "./split.h"


namespace Core
{
	class Line
	{
	public:

		struct _Line
		{
			QString str;
			quint32 numberLine;
			bool operator!=(const _Line& other)
			{
				return (this->str != other.str) || (this->numberLine != other.numberLine);
			}
		};
		Line();
		Line(const QString& str);

		static QList<QString> SplitStringByOperators(const QString& line, const QList<QString>& operators, const QList<QString>& keywords = {});
		void SplitStringByOperators(const QList<QString>& operators, const QList<QString>& keywords = {});
		static QList<quint32> ProcessNumberLines(const QList<QString>& line, const quint32& startNumberLine = 1);
		QList<quint32>& ProcessNumberLines(const quint32& startNumberLine = 1);
		void RemoveSpaces();
		
		const QList<quint32>& GetNumbersLines() const;
		const QList<QString>& GetLines() const;
		const QString& GetLine(const quint32& index) const;
		const quint32& GetNumberLine(const quint32& index) const;
		const QString& GetString() const;
		
		void SetString(const QString& str);
		void SetLines(const QList<QString>& lines);
		void SetNumbersLines(const QList<quint32>& numbersLines);
		
		void AddLine(const QString& line);
		void Clear();
		_Line operator[](quint32 index);

	private:
		QList<QString> _lines;
		QList<quint32> _numbersLines;
		QString _str;
	};
}