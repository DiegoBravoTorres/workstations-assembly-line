// Milestone #1
// ==================================================
// Name   : Diego Bravo Torres
// ID : 138350202
// Email : dbravo - torres@myseneca.ca
// Section : ZAA

#include "Utilities.h"
#include <iostream>
#include <string>
#include <algorithm>


namespace sdds {

	char Utilities::m_delimiter = ' ';

	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		std::string retrunValue = "";
		size_t extract = next_pos;
		next_pos = str.find(m_delimiter, extract);

		if (next_pos == std::string::npos) {
			retrunValue = str.substr(extract);
			m_widthField = std::max(retrunValue.length(), m_widthField);
			more = false;
		}
		else if (extract == next_pos)
		{
			more = false;
			throw "No token found!";
		}
		else {
			retrunValue = str.substr(extract, next_pos - extract);
			m_widthField = std::max(retrunValue.length(), m_widthField);
			more = true;
		}

		next_pos++;
		return retrunValue;

	}

	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}




}

