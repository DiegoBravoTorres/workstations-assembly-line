// Milestone #1
// ==================================================
// Name   : Diego Bravo Torres
// ID : 138350202
// Email : dbravo - torres@myseneca.ca
// Section : ZAA

#ifndef SDDS_STATION_H_
#define SDDS_STATION_H_

#include <string>

namespace sdds {

	class Station
	{
		int m_station_id;
		std::string m_item_name;
		std::string m_description;
		size_t m_serial_num;
		size_t m_numofItems;
		static size_t m_widthField;
		static size_t id_generator;
	
	public:

		Station(const std::string str);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;



	};
}

#endif // SDDS_STATION_H_





