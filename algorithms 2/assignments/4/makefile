# Makefile for assignment 4
CXX = g++
MAIN = assignment_4_unit_test
CPP_FILES = dl_node.cpp dl_list.cpp
H_FILES = dl_node.h dl_list.h
CXXFLAGS = -Wall -Wextra -pedantic -g

# Type 'make' to create the executable
${MAIN}: ${MAIN}.cpp ${H_FILES} ${CPP_FILES}
	${CXX} ${CXXFLAGS} ${MAIN}.cpp ${CPP_FILES} -o $@
	@echo 'Use ./${MAIN} to run'

# Type 'make style' to check your code style
style: ../../helpful_files/cpplint.py ${FILE} 
	python2 $< --filter=-runtime/references,-legal/copyright,-readability/streams,-runtime/explicit,-build/header_guard,-build/include ${MAIN}.cpp ${H_FILES} ${CPP_FILES}

# Type 'make clean' to remove the executable
clean:
	rm -rf ${MAIN}
