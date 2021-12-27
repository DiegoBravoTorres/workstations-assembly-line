// Milestone #1
// ==================================================
// Name   : Diego Bravo Torres
// ID : 138350202
// Email : dbravo - torres@myseneca.ca
// Section : ZAA

#include "Station.h"
#include "Utilities.h"
#include <string>
#include <ostream>
#include <iostream>
#include <iomanip>
#include <algorithm> 

namespace sdds {

	size_t Station::m_widthField = 0;
	size_t Station::id_generator = 0;

	Station::Station(const std::string str)
	{
		id_generator++;
		m_station_id = id_generator;
		Utilities utility;
		size_t nextPos = 0;
		bool isOk = true;

		try {
			m_item_name = utility.extractToken(str, nextPos, isOk);
			m_serial_num = stoi(utility.extractToken(str, nextPos, isOk));
			m_numofItems = stoi(utility.extractToken(str, nextPos, isOk));
			m_widthField = std::max(utility.getFieldWidth(), m_widthField);
			m_description = utility.extractToken(str, nextPos, isOk);
		}
		catch (std::string& err) {
			std::cout << err;
		}
		

	}

	const std::string& Station::getItemName() const
	{
		return m_item_name;
	}

	size_t Station::getNextSerialNumber()
	{
		size_t returnNum = m_serial_num;
		m_serial_num++;
		return returnNum;
	}

	size_t Station::getQuantity() const
	{
		return m_numofItems;
	}

	void Station::updateQuantity()
	{
		if(m_numofItems > 0)
			m_numofItems--;
	}

	void Station::display(std::ostream& os, bool full) const
	{
		
		os << "[";
		os << std::setw(3);
		os << std::right;
		os << std::setfill('0');
		os << m_station_id ;
		os << "] Item: " << std::setw(m_widthField) << std::left << std::setfill(' ') << m_item_name << " ["; 
		os << std::setw(6) << std::right << std::setfill('0') << m_serial_num << "]";
		
		if (full) 
		{
			os << " Quantity: " << std::setw(m_widthField) << std::left << std::setfill(' ') << m_numofItems;
			os << " Description: " << m_description;
		}

		os << std::endl;
	}



}
