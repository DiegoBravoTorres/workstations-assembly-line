// Milestone #2
// ==================================================
// Name   : Diego Bravo Torres
// ID : 138350202
// Email : dbravo-torres@myseneca.ca
// Section : ZAA


#ifndef _SDDS_CUSTOMER_ORDER_H_
#define _SDDS_CUSTOMER_ORDER_H_


#include "Utilities.h"
#include "Station.h"
#include <iostream>



namespace sdds {

	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder
	{
		// Instance variables

		std::string m_name = "";
		std::string m_product = "";
		size_t m_cntItem{ 0 };
		Item** m_lstItem = nullptr;

		// Class variable

		static size_t m_widthField;

	public:

		// Member Functions
		CustomerOrder();
		CustomerOrder(const std::string);

		CustomerOrder(CustomerOrder& src);
		CustomerOrder& operator=(const CustomerOrder& src) = delete;

		CustomerOrder(CustomerOrder&& src) noexcept;
		CustomerOrder& operator=( CustomerOrder&& src) noexcept;

		~CustomerOrder();

		bool isFilled() const;
		bool isItemFilled(const std::string& itemName) const;

		void fillItem(Station& station, std::ostream& os);

		void display(std::ostream& os) const;

	};

}

#endif // !_SDDS_CUSTOMER_ORDER_H




