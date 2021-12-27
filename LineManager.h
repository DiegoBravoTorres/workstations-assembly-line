// Milestone #3
// ==================================================
// Name   : Diego Bravo Torres
// ID : 138350202
// Email : dbravo - torres@myseneca.ca
// Section : ZAA



#ifndef _LINE_MANAGER_H_
#define _LINE_MANAGER_H_

#include<vector>
#include"Workstation.h"


namespace sdds {

	class LineManager
	{
		std::vector<Workstation*> activeLine;
		size_t m_cntCustomerOrder = 0u;
		Workstation* m_firstStation = nullptr;

	public:
		/*LineManager();*/
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void linkStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;


	};
}

#endif




