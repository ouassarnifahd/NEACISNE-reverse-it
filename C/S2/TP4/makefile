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
inc 	  	 := $(addprefix $(incPath)/,sort.h array.h element.h)
src			 := $(addprefix $(srcPath)/,sort.c array.c main.c element.c)
elems		 := ELEM_SHORT ELEM_LONG ELEM_REAL
sorts		 := selection insertion bubbles merge quick

all: cleanEasy object makeDoc

build: object
	@for type in $(elems); do \
		echo "Preparing $$type:"; \
		[ -d $(binPath)/`echo "$${type#ELEM_}" | tr /A-Z/ /a-z/` ] || $(MKDIR) $(binPath)/`echo "$${type#ELEM_}" | tr /A-Z/ /a-z/`; \
		for sort in $(sorts); do \
			$(CC) $(wFlag) -o $(binPath)/`echo "$${type#ELEM_}" | tr /A-Z/ /a-z/`/$(Project)_$$sort \
				$(wildcard $(objPath)/*.o) $(objPath)/`echo "$${type#ELEM_}" | tr /A-Z/ /a-z/`/element.o \
				$(objPath)/`echo "$${type#ELEM_}" | tr /A-Z/ /a-z/`/$(Project)_$$sort.o ; \
			echo "$(GREEN)Successfuly compiled $(RED)$(Project)_$${sort}\t$(NOCOLOR)"; \
		done; \
	done; \
	echo "All Done. "; 

object: $(inc)
	@made=$$((0)); \
	for source in $(src); do \
		[ $$made -eq 2 ] || if  [ $$(basename $$source) == 'array.c' ] || [ $$(basename $$source) == 'sort.c' ]; then \
			[ -a $(objPath)/`basename $${source/.c/.o}` ] || $(MAKE) $(objPath)/`basename $${source/.c/.o}`; \
			made=$$(($$made+1)); \
		fi; \
		for type in $(elems); do \
			[ -d $(objPath)/`echo "$${type#ELEM_}" | tr /A-Z/ /a-z/` ] || $(MKDIR) $(objPath)/`echo "$${type#ELEM_}" | tr /A-Z/ /a-z/`; \
			if [ $$(basename $$source) == 'element.c' ]; then\
				$(CC) $(wFlag) -D $$type -c $$source -o $(objPath)/`echo "$${type#ELEM_}" | tr /A-Z/ /a-z/`/`basename $${source/.c/.o}`; \
			fi; \
			for sort in $(sorts); do \
				if [ $$(basename $$source) == 'main.c' ]; then \
					$(CC) $(wFlag) -D $$type -D `echo "$$sort" | tr /a-z/ /A-Z/` -c $$source -o $(objPath)/`echo "$${type#ELEM_}" | tr /A-Z/ /a-z/`/"$(Project)_$${sort}.o"; \
				fi; \
			done; \
		done; \
	done;


$(objPath)/%.o: $(srcPath)/%.c
	@[ -d $(dir $@) ] || $(MKDIR) $(dir $@)
	@$(CC) $(wFlag) -c -o $@ $<

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
	@[ ! -d ${binPath} ] || $(RM) $(binPath)/*
	@[ ! -d ${objPath} ] || $(RM) $(objPath)/*

clean:
	@$(RM) $(binPath) $(objPath) $(docPath)
