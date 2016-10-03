cmake_minimum_required(VERSION 3.6)

set(datafiles)
foreach(file customer lineitem nation orders part partsupp region supplier)
  add_custom_command(OUTPUT ${file}.o
		COMMAND bash -c \"\(echo '\#include <string>'\;echo 'namespace TPCH{ namespace Fixtures { std::string ${file}Data=R\\\"\('\ \;cat ../${file}.tbl\;echo '\)\\\"\;}}'\)\" | ${CMAKE_CXX_COMPILER} -std=c++11 -c -x c++ -o ${file}.o -
		)
	list(APPEND datafiles build/${file}.o)
endforeach(file)

add_library(TPCHFixtures STATIC ${datafiles})
SET_TARGET_PROPERTIES(TPCHFixtures PROPERTIES LINKER_LANGUAGE CXX)
