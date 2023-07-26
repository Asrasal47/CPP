
#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	BitcoinExchange bitcoinExchange;
	std::ifstream database_file;
	std::ifstream input_file;

	if (argc != 2) {
		std::cout << "Program requires an input file" << std::endl;
		return 1;
	}

	std::cout.precision(10); //Set the precision so output is more precise
	database_file.open("data.csv", std::ios::in);
	input_file.open(argv[1], std::ios::in);
	if (!database_file || !input_file) {
		std::cout << "Could't open a file" << std::endl;
		return 1;
	}
	
	bitcoinExchange.readDbFromCSV(&database_file);
	bitcoinExchange.printExchange(&input_file);
	return 0;
}