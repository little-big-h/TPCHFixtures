#ifndef TPCHFIXTURES_H
#define TPCHFIXTURES_H
#include <list>
#include <map>
#include <string>

namespace TPCH {
namespace Fixtures {

enum class SQLType { integer, string, date, decimal15_2 };

const std::map<const std::string, const std::list<std::pair<const std::string, const SQLType>>>& getSchema();

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
