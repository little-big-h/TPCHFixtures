#ifndef TPCHFIXTURES_H
#define TPCHFIXTURES_H
#include <list>
#include <map>
#include <string>
#include <vector>

namespace TPCH {
namespace Fixtures {

enum class SQLType { integer, string, date, decimal15_2 };

const std::map<std::string, std::list<std::pair<std::string, SQLType>>>& getSchema();
const std::map<std::string, std::vector<std::string>>& getPrimaryKeys();
const std::map<std::string, std::list<std::pair<std::vector<std::string>, std::string>>>&
getForeignKeys();

extern std::string customerData;
extern std::string nationData;
extern std::string ordersData;
extern std::string partData;
extern std::string partsuppData;
extern std::string regionData;
extern std::string supplierData;
extern std::string lineitemData;
} // Fixtures
} // TPCH

#endif /* TPCHFIXTURES_H */
