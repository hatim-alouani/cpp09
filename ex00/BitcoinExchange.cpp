#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
<<<<<<< HEAD

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){
    if (this != &other){
            this->data = other.data;
        }
        return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &file) {
    std::ifstream f(file.c_str());
    std::string line;
    std::getline(f, line);

    while (std::getline(f, line)) {
        std::string date, val;
        size_t i = 0;

        while (i < line.size() && line[i] != ',') {
            date += line[i];
            i++;
        }

        i++;

        while (i < line.size()) {
            val += line[i];
            i++;
        }

        data[date] = std::atof(val.c_str());
    }
}


bool BitcoinExchange::validDate(const std::string &date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') 
        return false;

	int year = std::atoi(date.substr(0,4).c_str());
	int mounth= std::atoi(date.substr(5,2).c_str());
	int day = std::atoi(date.substr(8,2).c_str());

	return year>=2009 && mounth>=1 && mounth<=12 && day>=1 && day<=31;
}

float BitcoinExchange::getRate(const std::string &date) {
	std::map<std::string,float>::iterator it = data.lower_bound(date);
	if (it == data.end() || it->first != date) {
		if (it == data.begin()) 
            return 0;
		--it;
	}
	return it->second;
}

void BitcoinExchange::processInput(const std::string &file) {
    std::ifstream f(file.c_str());
    if (!f.is_open()) { 
        std::cout << "Error: could not open file.\n"; 
        return; 
    }

    std::string line;
    std::getline(f, line);

    while (std::getline(f, line)) {
        std::string date, val;
        size_t i = 0;

        while (i < line.size() && line[i] != '|') {
            date += line[i];
            i++;
        }

        if (i == line.size()) {
            std::cout << "Error: bad input => " << line << "\n";
            continue;
        }

        i++;

        while (i < line.size()) {
            val += line[i];
            i++;
        }

        while (!date.empty() && isspace(date[0])) 
            date.erase(0,1);

        while (!date.empty() && isspace(date[date.size()-1]))
            date.erase(date.size()-1);

        while (!val.empty() && isspace(val[0])) 
            val.erase(0,1);

        while (!val.empty() && isspace(val[val.size()-1])) 
            val.erase(val.size()-1);

        if (!validDate(date)) { 
            std::cout << "Error: bad input => " << date << "\n"; 
            continue; 
        }

        double v = std::atof(val.c_str());

        if (v < 0) { 
            std::cout << "Error: not a positive number.\n"; 
            continue; 
        }
        if (v > 1000) { 
            std::cout << "Error: too large a number.\n"; 
            continue; 
        }

        std::cout << date << " => " << v << " = " << v * getRate(date) << "\n";
    }
}

=======
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : data(other.data) {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadData(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
    
    }
    file.close();
}
>>>>>>> 75b5230 (push)
