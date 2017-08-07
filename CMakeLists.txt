cmake_minimum_required(VERSION 3.2)

set(datafiles)
foreach(file customer lineitem nation orders part partsupp region supplier)
	if(WIN32)
		add_custom_command(OUTPUT ${file}.cpp
			COMMAND ${echo} "Set-Content ${file}.cpp '\#include\<string\>'"
			COMMAND ${echo} "Add-Content ${file}.cpp 'namespace TPCH{namespace Fixtures{'"
			COMMAND ${echo} "Add-Content ${file}.cpp -NoNewline 'std::string ${file}Data=R\\\"\('"
			COMMAND ${echo} "Get-Content ${CMAKE_CURRENT_SOURCE_DIR}/${file}.tbl | Add-Content ${file}.cpp -NoNewline"
			COMMAND ${echo} "Add-Content ${file}.cpp '\)\\\";\}\}'"
			)
	else()
		add_custom_command(OUTPUT ${file}.cpp
			COMMAND bash -c \"\(echo '\#include <string>'\;echo -n 'namespace TPCH{ namespace Fixtures { std::string ${file}Data=R\\\"\('\ \;cat ${CMAKE_CURRENT_SOURCE_DIR}/${file}.tbl\;echo '\)\\\"\;}}'\)\" > ${file}.cpp)
	endif()
	list(APPEND datafiles ${file}.cpp)
endforeach(file)

add_library(TPCHFixtures STATIC TPCHFixtures.cpp ${datafiles})
set_property(TARGET TPCHFixtures PROPERTY CXX_STANDARD 14)
SET_TARGET_PROPERTIES(TPCHFixtures PROPERTIES LINKER_LANGUAGE CXX)
