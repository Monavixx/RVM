#include "Line.h"

using namespace Core;

Line::Line() : _str(""), _numbersLines({}), _lines({})
{
}

Line::Line(const QString& str) : _str(str), _numbersLines({}), _lines({})
{
}

QList<QString> Line::SplitStringByOperators(const QString& line, const QList<QString>& operators, const QList<QString>& keywords)
{
	QList<QString> resultLine;
	resultLine.append(line);
	QString currentOperator = "";					
	quint32 amountSeparators = 0;
	QString currentKeyword = "";					
	QList<quint32> indexesWithoutProcessing;
	bool isProcessing = true;						
	quint32 amountBraces = 0;

	for (quint32 i = 0; i < line.length(); ++i)
	{
		if (line[i] == '\"')
		{
			isProcessing = !isProcessing;
			if (isProcessing)
			{
				indexesWithoutProcessing.push_back(i);
				continue;
			}
		}

		if (!isProcessing)
		{
			indexesWithoutProcessing.push_back(i);
			continue;
		}

		for (quint32 j = 0; j < operators.size(); ++j)
		{
			for (quint32 k = 0; k < operators[j].length(); ++k)
			{
				if (line[i + k] == operators[j][k])
				{
					currentOperator += operators[j][k];

					if (operators[j].length() - 1 == k)
					{
						++amountSeparators;
						break;
					}
				}
				else
				{
					currentOperator = "";
					break;
				}
			}

			if (currentOperator != "")
			{
				if (amountSeparators == 1)
				{
					quint32 indexOperator = line.indexOf(currentOperator);

					for (quint32 l = 0; l < indexesWithoutProcessing.size(); ++l)
					{
						if (indexOperator == indexesWithoutProcessing[l])
						{
							indexOperator = line.indexOf(currentOperator, indexOperator + 1);
						}
					}
					resultLine = functions::split(line, indexOperator, indexOperator + currentOperator.length());
				}
				else
				{
					int indexOperator = resultLine.back().indexOf(currentOperator);

					quint32 differenceLocalAndGlobalIndexes = 0;

					for (quint32 l = 0; l < resultLine.size() - 1; ++l)
					{
						differenceLocalAndGlobalIndexes += resultLine[l].length();
					}

					for (quint32 l = 0; l < indexesWithoutProcessing.size(); ++l)
					{
						if (indexOperator == indexesWithoutProcessing[l] - differenceLocalAndGlobalIndexes) 
						{
							indexOperator = resultLine.back().indexOf(currentOperator, indexOperator + 1);
						}
					}

					QList<QString> temp = functions::split(resultLine.back(), indexOperator, indexOperator + currentOperator.length());
					resultLine.pop_back();

					for (const auto& item : temp)
						resultLine.push_back(item);
				}
				currentOperator = "";
			}
		}

		for (quint32 j = 0; j < keywords.size(); ++j)
		{

			for (quint32 k = 0; k < keywords[j].length(); ++k)
			{
				if (line[i + k] == keywords[j][k])
				{
					currentKeyword += keywords[j][k];

					if (keywords[j].length() - 1 == k)
					{
						bool isNeedCheckInStart = i != 0;									
						bool isNeedCheckInEnd = line.length() >= keywords[j].size() + i;	

						QString tempKeyword = line.mid((isNeedCheckInStart ? i - 1 : i), (isNeedCheckInEnd ? (keywords[j].size() + (isNeedCheckInStart ? 2 : 1)) : (keywords[j].size())));

						bool startIsEmpty = isNeedCheckInStart ? (tempKeyword[0] == ' ' || tempKeyword[0] == '\t' || tempKeyword[0] == '\n') : true;

						bool endIsEmpty = isNeedCheckInEnd ? (tempKeyword[tempKeyword.size() - 1] == ' ' || tempKeyword[tempKeyword.size() - 1] == '\t' || tempKeyword[tempKeyword.size() - 1] == '\n') : true;

						if (startIsEmpty && endIsEmpty)
						{
							++amountSeparators;
							break;
						}
						else
						{
							currentKeyword = "";
						}
					}
				}
				else
				{
					currentKeyword = "";
					break;
				}
			}

			if (currentKeyword != "")
			{
				if (amountSeparators == 1)
				{
					quint32 indexOperator = line.indexOf(currentKeyword);

					for (quint32 l = 0; l < indexesWithoutProcessing.size(); ++l)
					{
						if (indexOperator == indexesWithoutProcessing[l])
						{
							indexOperator = line.indexOf(currentKeyword, indexOperator + 1);
						}
					}
					resultLine = functions::split(line, indexOperator, indexOperator + currentKeyword.length());
				}
				else
				{
					int indexKeyword = resultLine.back().indexOf(currentKeyword);

					quint32 differenceLocalAndGlobalIndexes = 0;

					for (quint32 i = 0; i < resultLine.size() - 1; ++i)
					{
						differenceLocalAndGlobalIndexes += resultLine[i].length();
					}

					for (quint32 l = 0; l < indexesWithoutProcessing.size(); ++l)
					{
						if (indexKeyword == indexesWithoutProcessing[l] - differenceLocalAndGlobalIndexes) 
						{
							indexKeyword = resultLine.back().indexOf(currentKeyword, indexKeyword + 1);
						}
					}

					QList<QString> temp = functions::split(resultLine.back(), indexKeyword, indexKeyword + currentKeyword.length());
					resultLine.pop_back();

					for (const auto& item : temp)
						resultLine.push_back(item);
				}
				currentKeyword = "";
			}
		}
	}

	return resultLine;
}

void Line::SplitStringByOperators(const QList<QString>& operators, const QList<QString>& keywords)
{
	QList<QString> temp = SplitStringByOperators(this->_str, operators, keywords);
	this->_lines.reserve(temp.size());

	for (const auto& item : temp)
	{
		this->_lines.push_back(item);
	} 
	
}

QList<quint32> Line::ProcessNumberLines(const QList<QString>& line, const quint32& startNumberLine)
{
	QList<quint32> numberLines;
	quint32 numberLine = startNumberLine;
	bool isEnd = false;

	for (const auto& item : line)
	{
		isEnd = false;
		for (quint32 i = 0; i < item.length(); ++i)
		{
			if (item[i] == '\n')
			{
				++numberLine;
			}
			if (item[i] != '\n' && item[i] != '\t' && item[i] != ' ')
			{
				numberLines.push_back(numberLine);
				break;
			}
			if (i == item.length() - 1)
			{
				isEnd = true;
			}
		}

		if (!isEnd)
		{
			for (quint32 i = item.length() - 1; i > 0; --i)
			{
				if (item[i] == '\n')
				{
					++numberLine;
				}
				if (item[i] != '\n' && item[i] != '\t' && item[i] != ' ')
				{
					break;
				}
			}
		}
	}
	return numberLines;
}

QList<quint32>& Core::Line::ProcessNumberLines(const quint32& startNumberLine)
{
	SetNumbersLines(Line::ProcessNumberLines(_lines, startNumberLine));
	return _numbersLines;
}

void Line::RemoveSpaces()
{
	for (auto& str : _lines)
	{
		str = str.simplified();
	}

	_lines.removeAll("");
}
/*
QList<QString> Core::Line::TestSplitStringByOperators(const QString& str, const QList<QString>& operators, const QList<QString>& keywords)
{
	
}

QList<QString> Core::Line::TestSplitOutQuotes(const QString& str)
{
	bool isCurrentWordInQuotes = false;
	QList<QString> output;
	QString word = "";

}
*/

const QList<quint32>& Line::GetNumbersLines() const
{
	return _numbersLines;
}

const QList<QString>& Line::GetLines() const
{
	return _lines;
}

const QString& Core::Line::GetLine(const quint32& index) const
{
	return _lines[index];
}

const quint32& Core::Line::GetNumberLine(const quint32& index) const
{
	return _numbersLines[index];
}

const QString& Line::GetString() const
{
	return _str;
}

void Core::Line::SetString(const QString& str)
{
	this->_str = str;
}

void Line::SetLines(const QList<QString>& line)
{
	_lines = {};
	_lines.reserve(line.size());
	for (const auto& item : line)
	{
		_lines.push_back(item);
	}
}

void Line::SetNumbersLines(const QList<quint32>& numberLines)
{
	_numbersLines = {};
	_numbersLines.reserve(numberLines.size());
	for (const auto& item : numberLines)
	{
		_numbersLines.push_back(item);
	}
}

void Line::AddLine(const QString& line)
{
	_lines.push_back(line);
}

void Line::Clear()
{
	_lines.clear();
	_str.clear();
	_numbersLines.clear();
}

Line::_Line Core::Line::operator[](quint32 index)
{
	return _Line{ _lines[index], _numbersLines[index] };
}