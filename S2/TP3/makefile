#general
MKDIR		 := mkdir -p
RM			 := rm -rf

CC    		 := gcc
wFlag 		 := -Wall

srcPath		 := src
incPath		 := inc
objPath		 := obj
binPath		 := bin
docPath		 := doc

Project		 := queue
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

#common
incProject 	 := $(incPath)/$(Project).h
incElement   := $(incPath)/Elements/element.h
srcProject   := $(srcPath)/$(Project).c
srcElement   := $(srcPath)/Elements/element.c
srcMain		 := $(srcPath)/main.c

#int
intFlags     := $(wFlag) -D _INT_
intBinPath	 := $(binPath)/int
intObjPath	 := $(objPath)/int
intObjects   := $(intObjPath)/$(Project).o $(intObjPath)/element.o
intBinary	 := $(Project).int

#float
floatFlags   := $(wFlag) -D _FLOAT_
floatBinPath := $(binPath)/float
floatObjPath := $(objPath)/float
floatObjects := $(floatObjPath)/$(Project).o $(floatObjPath)/element.o
floatBinary  := $(Project).float

build: cleanEasy int float makeDoc

int: intObj
	@[ -d ${intBinPath}   ] || $(MKDIR) $(intBinPath)
	@$(CC) $(intFlags) -o $(intBinPath)/$(intBinary) $(srcMain) $(intObjects)
	@echo "${GREEN}Successfuly compiled ${RED}${intBinary} ${NOCOLOR}  : see $${PWD}/${intBinPath}"

float: floatObj
	@[ -d ${floatBinPath} ] || $(MKDIR) $(floatBinPath)
	@$(CC) $(floatFlags) -o $(floatBinPath)/$(floatBinary) $(srcMain) $(floatObjects)
	@echo "${GREEN}Successfuly compiled ${RED}${floatBinary} ${NOCOLOR}: see $${PWD}/${floatBinPath}"

intObj:
	@[ -d ${intObjPath}   ] || $(MKDIR) $(intObjPath)
	@$(CC) $(intFlags) -c $(srcElement) -o $(intObjPath)/element.o
	@$(CC) $(intFlags) -c $(srcProject) -o $(intObjPath)/$(Project).o

floatObj:
	@[ -d ${floatObjPath} ] || $(MKDIR) $(floatObjPath)
	@$(CC) $(floatFlags) -c $(srcElement) -o $(floatObjPath)/element.o
	@$(CC) $(floatFlags) -c $(srcProject) -o $(floatObjPath)/$(Project).o

$(srcPath)/%.c:$(objPath)/%.o
	@$(CC) $(wFlag) -c $< -o $@

makeDoc:
	@echo "Run ${PURPLE}make doc${NOCOLOR} to create ${BLUE}documentation${NOCOLOR}."

doc:
	@[ -d ${docPath} ] || $(MKDIR) $(docPath)
	@echo "${RED}Generating latex...${NOCOLOR}"
	@doxygen Doxyfile
	@echo "${RED}Generating pdf...${NOCOLOR}"
	@cd $(docPath)/latex; make refman.pdf
	@cp $(docPath)/latex/refman.pdf $(docPath)/$(docName).pdf
	@echo "${GREEN}Successfuly generated ${RED}${docName}.pdf${NOCOLOR} @ $${PWD}/${docPath}"

cleanEasy:
	@[ ! -d ${intBinPath}   ] || rm -f $(intBinPath)/*
	@[ ! -d ${intObjPath}   ] || rm -f $(intObjPath)/*
	@[ ! -d ${floatBinPath} ] || rm -f $(floatBinPath)/*
	@[ ! -d ${floatObjPath} ] || rm -f $(floatObjPath)/*

clean:
	@$(RM) $(binPath) $(objPath) $(docPath)
