// Milestone #2
// ==================================================
// Name   : Diego Bravo Torres
// ID : 138350202
// Email : dbravo-torres@myseneca.ca
// Section : ZAA


#include "CustomerOrder.h"
#include "Station.h"
#include "Utilities.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <iomanip>
#include <algorithm>


namespace sdds{

	size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder() : m_name{ "" }, m_product{ "" }, m_cntItem{ 0 }, m_lstItem{nullptr} { /*Set all to default*/}

	CustomerOrder::CustomerOrder(const std::string str) {

		Utilities localUtil;
		size_t nextPosition = 0;
		bool keepFeeding = true;

		m_name = localUtil.extractToken(str, nextPosition, keepFeeding);
		m_product = localUtil.extractToken(str, nextPosition, keepFeeding);

		m_cntItem = std::count(str.begin(), str.end(), localUtil.getDelimiter()) - 1;
		this->m_lstItem = new Item * [m_cntItem];

		keepFeeding = true;

		for (size_t i = 0; i < m_cntItem; i++)
			m_lstItem[i] = new Item (localUtil.extractToken(str,nextPosition,keepFeeding));


		if (localUtil.getFieldWidth() > m_widthField)
				m_widthField = localUtil.getFieldWidth();

	
	}

	CustomerOrder::CustomerOrder(CustomerOrder& src) {

		throw "Error: Copy operations not allowed";
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {

		*this = std::move(src);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept {

		if (this != &src) {

			if (m_lstItem) {
				for (size_t i = 0; i < m_cntItem; i++)
				{
					delete m_lstItem[i];
				}
			}

			delete [] m_lstItem;
			m_name = src.m_name;
			src.m_name.clear();

			m_product = src.m_product;
			src.m_product.clear();

			m_cntItem = src.m_cntItem;
			src.m_cntItem = 0;

			m_lstItem = src.m_lstItem;
			src.m_lstItem =  nullptr;
		
		}

		return *this;

	}

	CustomerOrder::~CustomerOrder() {


		if (m_lstItem) {
			for (size_t i = 0; i < m_cntItem; i++) {


				delete m_lstItem[i];
			}
		}
		delete[] m_lstItem;
	//	m_lstItem = nullptr;


	}

	bool CustomerOrder::isFilled() const {

		bool rtnValue = true;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (!(m_lstItem[i]->m_isFilled))
				rtnValue = false;
		}
		return rtnValue;
	
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const {

		bool rtnValue = true;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (itemName == m_lstItem[i]->m_itemName) {
				
				if (!(m_lstItem[i]->m_isFilled))
					rtnValue = false;
			
			}
		}

		return rtnValue;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os) {

		for (size_t i = 0; i < m_cntItem; i++) {
			if (station.getItemName() == m_lstItem[i]->m_itemName) {
				if (station.getQuantity() > 0) {

					station.updateQuantity();
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;

					os << std::right << "    Filled " << m_name << ", "<< m_product <<" [" << m_lstItem[i]->m_itemName << "]" << std::endl;
					
				}
				else {
				
					os << std::right << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
				}
					
			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const {

		os << m_name << " - " <<  m_product << std::endl;

		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_isFilled) {

				os << "[" << std::setw(6) << std::setfill('0') << std::right  << m_lstItem[i]->m_serialNumber << "] " << std::setw(m_widthField) << std::setfill(' ') << std::left  << m_lstItem[i]->m_itemName << " - FILLED" << std::endl;
			}
			else {
				os << "[" << std::setw(6) << std::setfill('0') << std::right  << m_lstItem[i]->m_serialNumber << "] " << std::setw(m_widthField) << std::setfill(' ') << std::left << m_lstItem[i]->m_itemName << " - TO BE FILLED" << std::endl;
			
			}

		}

	}



}
