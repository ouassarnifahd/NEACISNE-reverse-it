#general
CC    		 := gcc
wFlag 		 := -Wall
srcPath		 := src
objPath		 := obj
binPath		 := bin
Project		 := pile

#Documentation
docPath		 := doc
docName		 := $(Project)_documentation

#Colors
BLACK		 := \033[0;30m
GRAY		 := \033[1;30m
RED			 := \033[0;31m
LRED		 := \033[1;31m
GREEN		 := \033[0;32m
LGREEN		 := \033[1;32m
BROWN		 := \033[0;33m
YELLOW		 := \033[1;33m
BLUE		 := \033[0;34m
LBLUE		 := \033[1;34m
PURPLE		 := \033[0;35m
LPURPLE		 := \033[1;35m
CYAN		 := \033[0;36m
LCYAN		 := \033[1;36m
LGRAY		 := \033[0;37m
WHITE		 := \033[1;37m
NOCOLOR		 := \033[0m

#int
intFlags     := $(wFlag) -D _INT_
intBinPath	 := $(binPath)/int
intObjPath	 := $(objPath)/int
intObjects   := $(intObjPath)/main.o $(intObjPath)/$(Project).o $(intObjPath)/element.o
intBinary	 := $(Project).int

#float
floatFlags   := $(wFlag) -D _FLOAT_
floatBinPath := $(binPath)/float
floatObjPath := $(objPath)/float
floatObjects := $(floatObjPath)/main.o $(floatObjPath)/$(Project).o $(floatObjPath)/element.o
floatBinary  := $(Project).float

srcElement	 := $(srcPath)/Elements

build: cleanEasy int float makeDoc

int: intObj
	@[ -d ${intBinPath}   ] || mkdir -p ${intBinPath}
	@${CC} ${wFlag} -o ${intBinPath}/${intBinary} ${intObjects}
	@echo "${GREEN}Successfuly compiled ${RED}${intBinary} ${NOCOLOR}  : see $${PWD}/${intBinPath}"

float: floatObj
	@[ -d ${floatBinPath} ] || mkdir -p ${floatBinPath}
	@${CC} ${wFlag} -o ${floatBinPath}/${floatBinary} ${floatObjects}
	@echo "${GREEN}Successfuly compiled ${RED}${floatBinary} ${NOCOLOR}: see $${PWD}/${floatBinPath}"

intObj:
	@[ -d ${intObjPath}   ] || mkdir -p ${intObjPath}
	@${CC} ${intFlags} -c ${srcElement}/element.c -o ${intObjPath}/element.o
	@${CC} ${intFlags} -c ${srcPath}/${Project}.c -o ${intObjPath}/${Project}.o
	@${CC} ${intFlags} -c ${srcPath}/main.c -o ${intObjPath}/main.o

floatObj:
	@[ -d ${floatObjPath} ] || mkdir -p ${floatObjPath}
	@${CC} ${floatFlags} -c ${srcElement}/element.c -o ${floatObjPath}/element.o
	@${CC} ${floatFlags} -c ${srcPath}/${Project}.c -o ${floatObjPath}/${Project}.o
	@${CC} ${floatFlags} -c ${srcPath}/main.c -o ${floatObjPath}/main.o

makeDoc:
	@echo "Run ${PURPLE}make doc${NOCOLOR} to create ${BLUE}documentation${NOCOLOR}."

doc:
	@[ -d ${docPath} ] || mkdir -p ${docPath}
	@echo "${RED}Generating latex...${NOCOLOR}"
	@doxygen Doxyfile >> /dev/null
	@echo "${RED}Generating pdf...${NOCOLOR}"
	@cd ${docPath}/latex; make refman.pdf >> /dev/null
	@cp ${docPath}/latex/refman.pdf ${docPath}/${docName}.pdf
	@echo "${GREEN}Successfuly generated ${RED}${docName}.pdf${NOCOLOR} @ $${PWD}/${docPath}"

cleanEasy:
	@[ ! -d ${intBinPath}   ] || rm -f ${intBinPath}/*
	@[ ! -d ${intObjPath}   ] || rm -f ${intObjPath}/*
	@[ ! -d ${floatBinPath} ] || rm -f ${floatBinPath}/*
	@[ ! -d ${floatObjPath} ] || rm -f ${floatObjPath}/*

clean:
	@rm -rf ${binPath} ${objPath} ${docPath}
