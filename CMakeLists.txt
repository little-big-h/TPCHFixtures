cmake_minimum_required(VERSION 3.6)

set(datafiles)
foreach(file customer lineitem nation orders part partsupp region supplier)
  add_custom_command(OUTPUT ${file}.cpp
		COMMAND bash -c \"\(echo '\#include <string>'\;echo 'namespace TPCH{ namespace Fixtures { std::string ${file}Data=R\\\"\('\ \;cat ${PROJECT_SOURCE_DIR}/${file}.tbl\;echo '\)\\\"\;}}'\)\" > ${file}.cpp
		)
	list(APPEND datafiles ${file}.cpp)
endforeach(file)

add_library(TPCHFixtures STATIC ${datafiles})
foreach(file ${datafiles})
add_custom_command(TARGET TPCHFixtures POST_BUILD COMMAND rm "${file}")
endforeach(file)
set_property(TARGET TPCHFixtures PROPERTY CXX_STANDARD 14)
SET_TARGET_PROPERTIES(TPCHFixtures PROPERTIES LINKER_LANGUAGE CXX)
