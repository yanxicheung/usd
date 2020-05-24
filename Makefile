SOURCE_DIRS = src test  #list
INCLUDE_DIRS = include

ALL_SOURCES = ${foreach dir,${SOURCE_DIRS},${wildcard ${dir}/*.cpp}}
${info ${ALL_SOURCES}}  #打印调试信息

ALL_OBJS = ${ALL_SOURCES:.cpp=.o}
${info ${ALL_OBJS}}

ALL_INCLUDES :=${foreach dir,${INCLUDE_DIRS},-I./${dir}}
${info ${ALL_INCLUDES}}

TARGET=main.out
CXX=g++
CXXFLAGS=-std=c++11 -g -Wall -c
GTEST=-lgtest -lpthread

#使用@echo不会回显
${TARGET}:${ALL_OBJS}
	@echo Build demo_prj start...
	${CXX} $^ -o $@ ${GTEST}
	@echo Done

${ALL_OBJS}:%.o:%.cpp
	@echo "compile $<..."
	${CXX} ${CXXFLAGS} ${ALL_INCLUDES} $< -o $@ ${GTEST}

#find 会递归查找;
#rm前加@不会回显
.PHONY:clean
clean:
	@rm -rf $(shell find ./ -name "*.o")
	@rm -rf ${TARGET} 

$(info makefile end)