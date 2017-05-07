#general
CC    		 := gcc
RM			 := rm -rf
MKDIR 		 := mkdir -p
wFlag 		 := -Wall
srcPath		 := src
incPath		 := inc
objPath		 := obj
binPath		 := bin
Project		 := sort

#Documentation
docPath		 := doc
docName		 := $(Project)_documentation

#Colors
RED			 := \033[0;31m
GREEN		 := \033[0;32m
BLUE		 := \033[0;34m
PURPLE		 := \033[0;35m
NOCOLOR		 := \033[0m

#common
inc 	  	 := sort.h array.h element.h
src			 := main.c sort.c array.c element.c
obj 		 := $(src:c=o)

all: cleanEasy build makeDoc

test: obj/element.o obj/array.o

build: $(obj)
	@[ -d ${binPath}   ] || $(MKDIR) $(binPath)
	@$(CC) $(wFlags) -o $(binPath) $(srcMain) $^
	@echo "${GREEN}Successfuly compiled ${RED}${intBinary} ${NOCOLOR}  : see $${PWD}/${binPath}"

$(objPath)/%.o: $(srcPath)/%.c
	@[ -d $(dir $@) ] || $(MKDIR) $(dir $@)
	@[ -d $(dir $<) ] || $(MKDIR) $(dir $<)
	@$(CC) $(wFlag) -D ELEM_SHORT -c -o $@ $<

makeDoc:
	@echo "Run ${PURPLE}make doc${NOCOLOR} to create ${BLUE}documentation${NOCOLOR}."

doc: $(inc)
	@[ -d ${docPath} ] || $(MKDIR) $(docPath)
	@echo "${RED}Generating latex...${NOCOLOR}"
	@doxygen Doxyfile
	@echo "${RED}Generating pdf...${NOCOLOR}"
	@cd ${docPath}/latex; make refman.pdf
	@cp ${docPath}/latex/refman.pdf ${docPath}/${docName}.pdf
	@echo "${GREEN}Successfuly generated ${RED}${docName}.pdf${NOCOLOR} @ $${PWD}/${docPath}"

cleanEasy:
	@[ ! -d ${binPath} ] || rm -f $(binPath)/*
	@[ ! -d ${objPath} ] || rm -f $(objPath)/*

clean:
	@$(RM) $(binPath) $(objPath) $(docPath)
