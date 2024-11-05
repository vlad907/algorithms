# Makefile for Lab 6
CXX = g++
MAIN = lab_6
CPP_FILES = 
H_FILES = 
CXXFLAGS = -Wall -Wextra -pedantic -g
<<<<<<< HEAD
=======
python = python2
>>>>>>> 1dbdbfe4ffab367454b2c081f437d0b2cb78229a

# Type 'make' to create the executable
${MAIN}: ${MAIN}.cpp ${H_FILES} ${CPP_FILES}
	${CXX} ${CXXFLAGS} ${MAIN}.cpp ${CPP_FILES} -o $@
	@echo 'Use ./${MAIN} to run'

# Type 'make style' to check your code style
style: ../../helpful_files/cpplint.py ${FILE} 
<<<<<<< HEAD
	python $< --filter=-runtime/references,-legal/copyright,-readability/streams,-runtime/explicit,-build/header_guard,-build/include ${MAIN}.cpp ${H_FILES} ${CPP_FILES}
=======
	${python} $< --filter=-runtime/references,-legal/copyright,-readability/streams,-runtime/explicit,-build/header_guard,-build/include ${MAIN}.cpp ${H_FILES} ${CPP_FILES}
>>>>>>> 1dbdbfe4ffab367454b2c081f437d0b2cb78229a

# Type 'make clean' to remove the executable
clean:
	rm -rf ${MAIN}
<<<<<<< HEAD
=======
	

>>>>>>> 1dbdbfe4ffab367454b2c081f437d0b2cb78229a
