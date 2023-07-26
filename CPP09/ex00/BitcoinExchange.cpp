/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 23:05:50 by arasal            #+#    #+#             */
/*   Updated: 2023/06/30 23:08:34 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	m_db = other.getDb();
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{

}

const BitcoinExchange::db_type &BitcoinExchange::getDb() const
{
	return m_db;
}

void BitcoinExchange::readDbFromCSV(std::ifstream *file)
{
	std::string content;
	getline(*file, content);

	while (!file->eof())
	{
		getline(*file, content);

		size_t comma_pos = content.find(",");

		std::string date = content.substr(0, comma_pos);
		std::string rate = content.substr(comma_pos + 1);
		m_db.insert(std::pair<std::string, double>(date, strtod(rate.c_str(), NULL)));
	}
}

// Returns the found date or rend() if date was not found
BitcoinExchange::db_type::const_reverse_iterator BitcoinExchange::getRateFromDb(const std::string &date) const
{
	db_type::const_reverse_iterator it = m_db.rbegin();
	db_type::const_reverse_iterator endIt = m_db.rend();

	struct tm tm;
	struct tm date_tm;
	strptime(date.c_str(), "%Y-%m-%d", &date_tm);

	while (it != endIt)
	{
		strptime(it->first.c_str(), "%Y-%m-%d", &tm);
		if (tm.tm_year <= date_tm.tm_year && tm.tm_mon <= date_tm.tm_mon && tm.tm_mday <= date_tm.tm_mday)
			return it;
		it++;
	}
	return endIt;
}

void BitcoinExchange::printExchange(std::ifstream *input_file) const
{
	std::string content;
	getline(*input_file, content);

	// Check if the first line of the input file is 'date | value' if not print error
	if (content.compare("date | value") != 0)
	{
		std::cout << "Input file must specify input format as: \'date | value\'" << std::endl;
		exit(1);
	}

	struct tm tm;
	std::string date;
	std::string value;
	char *e;
	double parsed_value;

	// Read the file line by line
	while (!input_file->eof())
	{
		getline(*input_file, content);

		// Look for the seperator
		size_t seperator_pos = content.find('|');
		if (seperator_pos == std::string::npos)
		{
			std::cout << "Wrong format. Correct format: \"date | value\"" << std::endl;
			continue;
		}

		// get the left side of the seperator which is date and then the right side which is value
		date = content.substr(0, seperator_pos);
		value = content.substr(seperator_pos + 1);

		// Reset errno to check for errors in parsing later on
		errno = 0;
		parsed_value = std::strtod(value.c_str(), &e);

		// Removing whitespace from date and value
		while (date.find(' ') != std::string::npos)
			date.erase(date.find(' '), 1);
		while (value.find(' ') != std::string::npos)
			value.erase(value.find(' '), 1);

		// Check if the date is valid
		if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
		{
			std::cout << "Invalid date => " << date << std::endl;
			continue;
		}
		// Check if the value is correct, if parsing was successful the 'e' variable should be set to the end of the string ('\0' char)
		if (parsed_value <= 0 || parsed_value >= 1000 || *e != '\0' || errno != 0)
		{
			std::cout << "Invalid value => " << value << std::endl;
			continue;
		}

		// getRateFromDb will find the exchange rate for the passed date (date is a string)
		db_type::const_reverse_iterator it = getRateFromDb(date);

		// if the iterator 'it' points to the end of the database it means the database doesn't have any exchange rate for the given date
		if (it == m_db.rend())
		{
			std::cout << "No exchange rate for the given date => " << date << std::endl;
			continue;
		}

		double res = parsed_value * it->second;
		// Print out the result
		std::cout << date << " => " << value << " = " << res << std::endl;
	}
}