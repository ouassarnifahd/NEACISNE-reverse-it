#general
CC    		:= gcc
RM			:= rm -rf
MKDIR 		:= mkdir -p
wFlag 		:= -Wall
srcPath		:= src
incPath		:= inc
objPath		:= obj
binPath		:= bin
Project		:= sort

#Documentation
docPath		:= doc
docName		:= $(Project)_documentation

#Colors
RED			:= \033[0;31m
GREEN		:= \033[0;32m
BLUE		:= \033[0;34m
PURPLE		:= \033[0;35m
NOCOLOR		:= \033[0m

#common
inc 	  	:= $(addprefix $(incPath)/,sort.h array.h element.h)
src			:= $(addprefix $(srcPath)/,sort.c array.c main.c element.c)
elems		:= ELEM_SHORT ELEM_LONG ELEM_REAL
sorts		:= selection insertion bubbles merge quick

all: cleanEasy build makeDoc

build: object
	for type in $(elems); do \
		echo "Preparing $$type:"; \
		outDir=`echo "$${type#ELEM_}" | tr /A-Z/ /a-z/`; \
		staticObjects="$(wildcard $(objPath)/*.o) $(objPath)/$$outDir/element.o"; \
		[ -d $(binPath)/$${outDir} ] || $(MKDIR) $(binPath)/$${outDir}; \
		for sort in $(sorts); do \
			[ -a $(binPath)/$$outDir/"$(Project)_$$sort.o" ] || \
			$(CC) $(wFlag) -o $(binPath)/$$outDir/$(Project)_$$sort $$staticObjects $(objPath)/$$outDir/"$(Project)_$$sort.o"; \
			echo "$(GREEN)Successfuly compiled $(RED)$(Project)_$${sort}$(NOCOLOR)"; \
		done; \
	done; \
	echo "All Done. ";

object: $(inc)
	@made=$$((0)); \
	for source in $(src); do \
		file=$$(basename $$source); \
		outfile=$${file/.c/.o}; \
		[ $$made -eq 2 ] || if  [ $$file == 'array.c' ] || [ $$file == 'sort.c' ]; then \
			[ -a $(objPath)/$$file ] || $(MAKE) $(objPath)/$$outfile; \
			made=$$(($$made+1)); \
		fi; \
		for type in $(elems); do \
			outDir="`echo "$${type#ELEM_}" | tr /A-Z/ /a-z/`"; \
			typeFlag="-D $$type"; \
			[ -d $(objPath)/$$outDir ] || $(MKDIR) $(objPath)/$$outDir; \
			if [ $$(basename $$source) == 'element.c' ]; then \
				[ -a $(objPath)/$$outDir/$$outfile ] || \
				$(CC) $(wFlag) $$typeFlag -c $$source -o $(objPath)/$$outDir/$$outfile; \
			fi; \
			for sort in $(sorts); do \
				sortFlag="-D `echo "$$sort" | tr /a-z/ /A-Z/`"; \
				if [ $$file == 'main.c' ]; then \
					[ -a $(objPath)/$$outDir/"$(Project)_$${sort}.o" ] || \
					$(CC) $(wFlag) $$typeFlag $$sortFlag -c $$source -o $(objPath)/$$outDir/"$(Project)_$${sort}.o"; \
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
	@echo "${GREEN}Successfuly generated ${RED}${docName}.pdf${NOCOLOR} @ ${docPath}"

cleanEasy:
	@[ ! -d ${binPath} ] || $(RM) $(binPath)/*
	@[ ! -d ${objPath} ] || $(RM) $(objPath)/*

clean:
	@$(RM) $(binPath) $(objPath) $(docPath)
