# include "TemperatureData.h"
# include <string>
using std::string;

TemperatureData::TemperatureData() : id(""), year(0), month(0), temperature(0.0) {
	// TODO: implement this function
}

TemperatureData::TemperatureData(std::string id, int year, int month, double temperature) : id(id), year(year), month(month), temperature(temperature) {
	// TODO: implement this function
}

TemperatureData::~TemperatureData() {}

bool TemperatureData::operator<(const TemperatureData& b) {
	// TODO: implement this function
	if (id != b.id) {
        return id < b.id;
    }
    if (year != b.year) {
        return year < b.year;
    }
    return month < b.month;
	
	
	
}

