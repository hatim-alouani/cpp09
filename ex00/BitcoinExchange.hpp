#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <cstdlib>

class BitcoinExchange {
	
    std::map<std::string, float> data;

    public:

        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void loadDatabase(const std::string &file);
        void processInput(const std::string &file);

        bool validDate(const std::string &date);
        float getRate(const std::string &date);

};

#endif
