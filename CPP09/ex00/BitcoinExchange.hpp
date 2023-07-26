#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cerrno>
#include <cstdlib>

class BitcoinExchange {
	// --------------- typedefs -----------------
public:
	typedef std::map<std::string, double> db_type;

private:
	db_type m_db;
	

public:

	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	const db_type& getDb() const;

	void readDbFromCSV(std::ifstream* file);
	void printExchange(std::ifstream* inputFile) const;
	db_type::const_reverse_iterator getRateFromDb(const std::string& date) const;

};

#endif