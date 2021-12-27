// Milestone #3
// ==================================================
// Name   : Diego Bravo Torres
// ID : 138350202
// Email : dbravo - torres@myseneca.ca
// Section : ZAA


#include "Workstation.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>



namespace sdds {

	std::deque<CustomerOrder> pending{};
	std::deque<CustomerOrder> completed{};
	std::deque<CustomerOrder> incomplete{};

	
	Workstation::Workstation(std::string str): Station(str), m_pNextStation(nullptr) {}

	void Workstation::fill(std::ostream& os)
	{
		/*if (m_orders.size()) {

			m_orders.front().fillItem(*this, os);
		
		}*/

		if (!m_orders.empty() && !m_orders.front().isItemFilled(getItemName())) {

			m_orders.front().fillItem(*this, os);

		}

	}

	bool Workstation::attemptToMoveOrder()
	{
		if (m_orders.empty())
			return false;

		if (m_orders.front().isItemFilled(getItemName()) || getQuantity() <= 0) {
			if (m_pNextStation != nullptr) {
				*m_pNextStation += std::move(m_orders.front());
				m_orders.pop_front();
			}
			else {
				if (m_orders.front().isFilled()) {
					completed.push_back(std::move(m_orders.front()));
				}
				else {
					incomplete.push_back(std::move(m_orders.front()));
				}
				m_orders.pop_front();
			}
		}
		
		return true;

	}

	void Workstation::setNextStation(Workstation* station= nullptr)
	{
		m_pNextStation = station;
	}

	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}

	void Workstation::display(std::ostream& os) const
	{
		os << getItemName() <<" --> ";

		if (m_pNextStation == nullptr) {
			os << "End of Line";
		}
		else {
			os  << m_pNextStation->getItemName();
		}

		os << std::endl;
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
	
		m_orders.push_back(std::move(newOrder));
		return *this;

		// TODO: insert return statement here
	}




}
