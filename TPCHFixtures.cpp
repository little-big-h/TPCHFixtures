#include "TPCHFixtures.hpp"
using namespace std;

static const std::map<std::string, std::list<std::pair<std::string, TPCH::Fixtures::SQLType>>>
		schema{{"region",
						{{"r_regionkey", TPCH::Fixtures::SQLType::integer},
						 {"r_name", TPCH::Fixtures::SQLType::string},
						 {"r_comment", TPCH::Fixtures::SQLType::string}}},
					 {"nation",
						{{"n_nationkey", TPCH::Fixtures::SQLType::integer},
						 {"n_name", TPCH::Fixtures::SQLType::string},
						 {"n_regionkey", TPCH::Fixtures::SQLType::integer},
						 {"n_comment", TPCH::Fixtures::SQLType::string}}},
					 {"supplier",
						{{"s_suppkey", TPCH::Fixtures::SQLType::integer},
						 {"s_name", TPCH::Fixtures::SQLType::string},
						 {"s_address", TPCH::Fixtures::SQLType::string},
						 {"s_nationkey", TPCH::Fixtures::SQLType::integer},
						 {"s_phone", TPCH::Fixtures::SQLType::string},
						 {"s_acctbal", TPCH::Fixtures::SQLType::decimal15_2},
						 {"s_comment", TPCH::Fixtures::SQLType::string}}},
					 {"customer",
						{{"c_custkey", TPCH::Fixtures::SQLType::integer},
						 {"c_name", TPCH::Fixtures::SQLType::string},
						 {"c_address", TPCH::Fixtures::SQLType::string},
						 {"c_nationkey", TPCH::Fixtures::SQLType::integer},
						 {"c_phone", TPCH::Fixtures::SQLType::string},
						 {"c_acctbal", TPCH::Fixtures::SQLType::decimal15_2},
						 {"c_mktsegment", TPCH::Fixtures::SQLType::string},
						 {"c_comment", TPCH::Fixtures::SQLType::string}}},
					 {"part",
						{{"p_partkey", TPCH::Fixtures::SQLType::integer},
						 {"p_name", TPCH::Fixtures::SQLType::string},
						 {"p_mfgr", TPCH::Fixtures::SQLType::string},
						 {"p_brand", TPCH::Fixtures::SQLType::string},
						 {"p_type", TPCH::Fixtures::SQLType::string},
						 {"p_size", TPCH::Fixtures::SQLType::integer},
						 {"p_container", TPCH::Fixtures::SQLType::string},
						 {"p_retailprice", TPCH::Fixtures::SQLType::decimal15_2},
						 {"p_comment", TPCH::Fixtures::SQLType::string}}},
					 {"partsupp",
						{{"ps_partkey", TPCH::Fixtures::SQLType::integer},
						 {"ps_suppkey", TPCH::Fixtures::SQLType::integer},
						 {"ps_availqty", TPCH::Fixtures::SQLType::integer},
						 {"ps_supplycost", TPCH::Fixtures::SQLType::decimal15_2},
						 {"ps_comment", TPCH::Fixtures::SQLType::string}}},
					 {"orders",
						{{"o_orderkey", TPCH::Fixtures::SQLType::integer},
						 {"o_custkey", TPCH::Fixtures::SQLType::integer},
						 {"o_orderstatus", TPCH::Fixtures::SQLType::string},
						 {"o_totalprice", TPCH::Fixtures::SQLType::decimal15_2},
						 {"o_orderdate", TPCH::Fixtures::SQLType::date},
						 {"o_orderpriority", TPCH::Fixtures::SQLType::string},
						 {"o_clerk", TPCH::Fixtures::SQLType::string},
						 {"o_shippriority", TPCH::Fixtures::SQLType::integer},
						 {"o_comment", TPCH::Fixtures::SQLType::string}}},
					 {"lineitem",
						{{"l_orderkey", TPCH::Fixtures::SQLType::integer},
						 {"l_partkey", TPCH::Fixtures::SQLType::integer},
						 {"l_suppkey", TPCH::Fixtures::SQLType::integer},
						 {"l_linenumber", TPCH::Fixtures::SQLType::integer},
						 {"l_quantity", TPCH::Fixtures::SQLType::integer},
						 {"l_extendedprice", TPCH::Fixtures::SQLType::decimal15_2},
						 {"l_discount", TPCH::Fixtures::SQLType::decimal15_2},
						 {"l_tax", TPCH::Fixtures::SQLType::decimal15_2},
						 {"l_returnflag", TPCH::Fixtures::SQLType::string},
						 {"l_linestatus", TPCH::Fixtures::SQLType::string},
						 {"l_shipdate", TPCH::Fixtures::SQLType::date},
						 {"l_commitdate", TPCH::Fixtures::SQLType::date},
						 {"l_receiptdate", TPCH::Fixtures::SQLType::date},
						 {"l_shipinstruct", TPCH::Fixtures::SQLType::string},
						 {"l_shipmode", TPCH::Fixtures::SQLType::string},
						 {"l_comment", TPCH::Fixtures::SQLType::string}}}};

static const map<string, string> primaryKeys{{"region", "r_regionkey"},
																						 {"nation", "n_nationkey"},
																						 {"part", "p_partkey"},
																						 {"supplier", "s_suppkey"},
																						 {"customer", "c_custkey"},
																						 {"order", "o_orderkey"},
																						 {"partsupp", "ps_partkey_ps_suppkey"}};

static const std::map<std::string, std::list<std::pair<std::string, std::string>>> foreignKeys{
		{"region", {}},
		{"nation", {{"n_regionkey", "region"}}},
		{"supplier", {{"s_nationkey", "nation"}}},
		{"customer", {{"c_nationkey", "nation"}}},
		{"part", {}},
		{"partsupp", {{"ps_partkey", "part"}, {"ps_suppkey", "supplier"}}},
		{"orders", {}},
		{"lineitem", {}}};

const std::map<std::string, std::list<std::pair<std::string, TPCH::Fixtures::SQLType>>>&
TPCH::Fixtures::getSchema() {
	return schema;
}

const std::map<std::string, std::string>& TPCH::Fixtures::getPrimaryKeys() { return primaryKeys; };

const std::map<std::string, std::list<std::pair<std::string, std::string>>>&
TPCH::Fixtures::getForeignKeys() {
	return foreignKeys;
};
