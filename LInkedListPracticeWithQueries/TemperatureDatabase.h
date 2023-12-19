# ifndef TEMP_DB
# define TEMP_DB

# include <string>
# include "LinkedList.h"

const int CurrentYear = 2023;
class TemperatureDatabase {
	public:
		TemperatureDatabase();
		~TemperatureDatabase();
		void loadData(const std::string& data_file);
		void outputData(const std::string& out_file);
		void performQuery(const std::string& query_filename);
		void myTest();

	private:
		LinkedList records;
};

# endif
