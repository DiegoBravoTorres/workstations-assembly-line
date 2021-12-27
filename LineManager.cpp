// Milestone #3
// ==================================================
// Name   : Diego Bravo Torres
// ID : 138350202
// Email : dbravo - torres@myseneca.ca
// Section : ZAA

#include "LineManager.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

namespace sdds {

	//size_t LineManager::funCalls = 0;

	//LineManager::LineManager() :m_cntCustomerOrder{ 0 }, m_firstStation{ nullptr }{

	//}

	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{

		std::ifstream fstream(file);

		Utilities util;
		std::string line;

		while (getline(fstream, line)) {

			size_t position = 0u;
			bool keepFeeding = true;

			auto Token = util.extractToken(line, position, keepFeeding);

			auto workStation = *std::find_if(stations.begin(), stations.end(), [&Token](const Workstation* station) {
				return station->getItemName() == Token;
				});

			if (keepFeeding) {
				auto nextToken = util.extractToken(line, position, keepFeeding);


			auto nextWorkStation = *std::find_if(stations.begin(), stations.end(), [&nextToken](const Workstation* station) {
					return station->getItemName() == nextToken;
					});

				if (nextWorkStation) {
					workStation->setNextStation(nextWorkStation);
				}
			}

			activeLine.push_back(workStation);
			m_firstStation = activeLine.front();
			m_cntCustomerOrder = pending.size();
		}


	}

	void LineManager::linkStations()
	{
		std::vector<Workstation*> vector;

		Workstation* station = m_firstStation;

		while (station != nullptr) {
			vector.push_back(station);
			station = station->getNextStation();
		}
		activeLine = vector;

	}

	bool LineManager::run(std::ostream& os)
	{
		static size_t funCalls = 1;
		bool allFilled = false;
		

		os << "Line Manager Iteration: " << funCalls++ << std::endl;

		if (!pending.empty()) {

			*activeLine.front() += std::move(pending.front());
			pending.erase(pending.begin());
		
		}

		std::for_each(activeLine.begin(), activeLine.end(), [&](Workstation* workstation) {
			workstation->fill(os);
			});

		std::for_each(activeLine.begin(), activeLine.end(), [&](Workstation* workstation) {
			workstation->attemptToMoveOrder();
			});

		//m_cntCustomerOrder -= ((completed.size() + incomplete.size()) - ordersCounted);

		allFilled = m_cntCustomerOrder == (completed.size() + incomplete.size());;

		return allFilled;
	}

	void LineManager::display(std::ostream& os) const
	{
		std::for_each(activeLine.begin(), activeLine.end(), [&](Workstation* workstation) {
			workstation->display(os);
			});

		//for (size_t i = 0; i < activeLine.size(); i++) {
		//	activeLine.at(i)->display(os);
		//}
			
	}



}
