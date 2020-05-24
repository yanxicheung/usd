CUR_DIR = $(shell pwd)
SRC_DIR = ${CUR_DIR}/src
TEST_DIR = ${CUR_DIR}/test

INC_DIR = -I${CUR_DIR}/include

SRC = $(wildcard ${SRC_DIR}/*.cpp  \
                   ${TEST_DIR}/*.cpp ) 

OBJ = ${patsubst %.cpp,%.o,${SRC}}

TARGET=main.out
CXX=g++
CXXFLAGS=${INC_DIR}

${TARGET}:${OBJ}
	${CXX} ${OBJ} -o $@  -lgtest -lpthread
	echo "Compile done."

$(OBJ):%.o:%.cpp
	@echo "Compiling $< ==> $@"
	${CXX} ${CXXFLAGS} -c $< -o $@

.PHONY:test
test:
	@echo ${INC_DIR}
	@echo ${SRC_DIR}
	@echo ${TEST_DIR}
	@echo ${SRC}
	@echo ${OBJ}

.PHONY:clean
clean:
	rm -rf ${OBJ}
	rm -rf ${TARGET}