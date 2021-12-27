// Milestone #3
// ==================================================
// Name   : Diego Bravo Torres
// ID : 138350202
// Email : dbravo - torres@myseneca.ca
// Section : ZAA


#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <deque>

#include "CustomerOrder.h"
#include "Station.h"


namespace sdds {

	extern std::deque<CustomerOrder> pending;
	extern std::deque<CustomerOrder> completed;
	extern std::deque<CustomerOrder> incomplete;


	class Workstation : public Station
	{

		std::deque<CustomerOrder> m_orders;
		Workstation* m_pNextStation = nullptr;


	public:
		
		Workstation(std::string);
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);




		Workstation(Workstation& src) = delete;
		Workstation& operator=(const Workstation& src) = delete;

		Workstation(Workstation&& src) = delete;
		Workstation& operator=(Workstation&& src) noexcept;



	};
}


#endif // !SDDS_WORKSTATION_H


