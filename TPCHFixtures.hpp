#ifndef TPCHFIXTURES_H
#define TPCHFIXTURES_H
#include <map>
#include <string>

namespace TPCH {
namespace Fixtures {

enum class SQLType { integer, string, date, decimal15_2 };

const std::map<const std::string,
							 const std::list<const std::pair<const std::string, const SQLType>>>&
getSchema() {
	auto integer = SQLType::integer;
	auto string = SQLType::string;
	auto decimal15_2 = SQLType::decimal15_2;
	auto date = SQLType::date;

	static const std::map<const std::string,
												const std::list<const std::pair<const std::string, const SQLType>>>
			schema{{"region", {{"r_regionkey", integer}, {"r_name", string}, {"r_comment", string}}},
						 {"nation",
							{{"n_nationkey", integer},
							 {"n_name", string},
							 {"n_regionkey", integer},
							 {"n_comment", string}}},
						 {"supplier",
							{{"s_suppkey", integer},
							 {"s_name", string},
							 {"s_address", string},
							 {"s_nationkey", integer},
							 {"s_phone", string},
							 {"s_acctbal", decimal15_2},
							 {"s_comment", string}}},
						 {"customer",
							{{"c_custkey", integer},
							 {"c_name", string},
							 {"c_address", string},
							 {"c_nationkey", integer},
							 {"c_phone", string},
							 {"c_acctbal", decimal15_2},
							 {"c_mktsegment", string},
							 {"c_comment", string}}},
						 {"part",
							{{"p_partkey", integer},
							 {"p_name", string},
							 {"p_mfgr", string},
							 {"p_brand", string},
							 {"p_type", string},
							 {"p_size", integer},
							 {"p_container", string},
							 {"p_retailprice", decimal15_2},
							 {"p_comment", string}}},
						 {"partsupp",
							{{"ps_partkey", integer},
							 {"ps_suppkey", integer},
							 {"ps_availqty", integer},
							 {"ps_supplycost", decimal15_2},
							 {"ps_comment", string}}},
						 {"orders",
							{{"o_orderkey", integer},
							 {"o_custkey", integer},
							 {"o_orderstatus", string},
							 {"o_totalprice", decimal15_2},
							 {"o_orderdate", date},
							 {"o_orderpriority", string},
							 {"o_clerk", string},
							 {"o_shippriority", integer},
							 {"o_comment", string}}},
						 {"lineitem",
							{{"l_orderkey", integer},
							 {"l_partkey", integer},
							 {"l_suppkey", integer},
							 {"l_linenumber", integer},
							 {"l_quantity", integer},
							 {"l_extendedprice", decimal15_2},
							 {"l_discount", decimal15_2},
							 {"l_tax", decimal15_2},
							 {"l_returnflag", string},
							 {"l_linestatus", string},
							 {"l_shipdate", date},
							 {"l_commitdate", date},
							 {"l_receiptdate", date},
							 {"l_shipinstruct", string},
							 {"l_shipmode", string},
							 {"l_comment", string}}}};
	return schema;
}

extern std::string customerData;
extern std::string nationData;
extern std::string ordersData;
extern std::string partData;
extern std::string partsuppData;
extern std::string regionData;
extern std::string supplierData;
} // Fixtures
} // TPCH

#endif /* TPCHFIXTURES_H */
