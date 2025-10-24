<<<<<<< HEAD
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
=======
#indef BitcoinExchange_hpp
# define BitcoinExchange_hpp
# include <iostream>
# include <map>
# include <fstream>
# include <sstream>

class BitcoinExchange
{
    private:
        std::map<std::string, float> data;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        
        void loadData(const std::string &filename);
        void processInput(const std::string &filename);
        bool isValidDate(const std::string &date);
        bool isValidValue(const std::string &valueStr, float &value);
        float getExchangeRate(const std::string &date);
};
>>>>>>> 75b5230 (push)
