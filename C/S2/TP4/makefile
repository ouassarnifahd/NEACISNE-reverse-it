#general
CC    		:= gcc
RM			:= rm -rf
MKDIR 		:= mkdir -p
wFlag 		:= -Wall
srcPath		:= src
incPath		:= inc
objPath		:= obj
binPath		:= bin
docPath		:= doc
debugPath	:= debug
Project		:= sort

#Documentation
docName		:= $(Project)_documentation

#Debug
dbgFlags	:= $(wFlag) -D DEBUG

#Colors
RED			:= \033[0;31m
GREEN		:= \033[0;32m
BLUE		:= \033[0;34m
PURPLE		:= \033[0;35m
NOCOLOR		:= \033[0m

#common
inc 	  	:= $(addprefix $(incPath)/,sort.h array.h element.h)
src			:= sort.c array.c element.c main.c
obj			:= $(src:%c=%o)

elems		:= ELEM_SHORT ELEM_LONG ELEM_REAL
sorts		:= selection insertion bubbles merge quick

# TODO: regex!

all: mrproper build makeDoc

build: object
	@for type in $(elems); do \
		echo "Preparing $$type:"; \
		typeDir=`echo "$${type#ELEM_}" | tr /A-Z/ /a-z/`; \
		staticObject="$(objPath)/$$typeDir/element.o"; \
		for sort in $(sorts); do \
			[ -a $(binPath)/$$typeDir/$(Project)_$$sort.o ] || \
			$(MAKE) $(binPath)/$$typeDir/$(Project)_$$sort staticOBJ="$$staticObject" && \
			echo "$(GREEN)Successfuly compiled $(RED)$(Project)_$${sort}$(NOCOLOR)"; \
		done; \
	done; \
	echo "All Done. ";

object: $(inc)
	@for object in $(obj); do \
		if  [ $$object == array.o ] || [ $$object == sort.o ]; then \
			[ -a $(objPath)/$$object ] || $(MAKE) $(objPath)/$$object Flags=$(wFlag); \
		else \
			for type in $(elems); do \
				typeDir=`echo "$${type#ELEM_}" | tr /A-Z/ /a-z/`; \
				typeFlag="-D $$type"; \
				if [ $$object == element.o ]; then \
					[ -a $(objPath)/$$typeDir/$$object ] || \
					$(MAKE) $(objPath)/$$typeDir/$$object typeOBJ=yes typeDir=$$typeDir Flags="$(wFlag) $$typeFlag"; \
				else \
					for sort in $(sorts); do \
						sortFlag="-D `echo "$$sort" | tr /a-z/ /A-Z/`"; \
						if [ $$object == main.o ]; then \
							[ -a $(objPath)/$$typeDir/$(Project)_$${sort}.o ] || \
							$(MAKE) $(objPath)/$$typeDir/$(Project)_$${sort}.o sortOBJ=yes typeDir=$$typeDir Flags="$(wFlag) $$typeFlag $$sortFlag"; \
						fi; \
					done; \
				fi; \
			done; \
		fi; \
	done;

$(debugPath)/%.dbg: $(srcPath)/%.c $(inc)
	@$(MAKE) directory path=$(dir $@)
	@if [ '$(object)' != '' ]; then \
		$(MAKE) compile OBJ='yes' CFlags="$(Flags)" out=$(dir $@)$(object) in=$(dir $<)$(object:%o=%c); \
		$(CC) $(dbgFlags) $(Flags) -o $@ $(dir $@)$(object) $< 2> $(basename $@).err; \
	else \
		$(CC) $(dbgFlags) $(Flags) -o $@ $< 2> $(basename $@).err; \
	fi;

$(binPath)/%: $(objPath)/%.o
	@$(MAKE) directory path=$(dir $@)
	@$(MAKE) compile OBJ='no' CFlags=$(wFlag) out=$@ objects="$(wildcard $(objPath)/*.o) $(staticOBJ) $<";

ifeq ($(typeOBJ),yes)
$(objPath)/$(typeDir)/%.o: $(srcPath)/%.c
	@$(MAKE) directory path=$(dir $@)
	@$(MAKE) compile OBJ='yes' CFlags="$(Flags)" out=$@ in=$<
endif

ifeq ($(sortOBJ),yes)
$(objPath)/$(typeDir)/sort_%.o: $(srcPath)/main.c
	@$(MAKE) directory path=$(dir $@)
	@$(MAKE) compile OBJ='yes' CFlags="$(Flags)" out=$@ in=$<
else
$(objPath)/%.o: $(srcPath)/%.c
	@$(MAKE) directory path=$(dir $@)
	@$(MAKE) compile OBJ='yes' CFlags="$(Flags)" out=$@ in=$<
endif

directory:
	@[ -d $(path) ] || $(MKDIR) $(path)

compile:
	@if [ $(OBJ) == yes ]; then $(CC) $(CFlags) -c -o $(out) $(in); else $(CC) $(CFlags) -o $(out) $(objects); fi

makeDoc:
	@echo "Run $(PURPLE)make doc$(NOCOLOR) to create $(BLUE)documentation$(NOCOLOR)."

doc: $(inc)
	@$(MAKE) directory path=$(docPath)
	@echo "${RED}Generating latex...${NOCOLOR}"
	@doxygen Doxyfile
	@echo "${RED}Generating pdf...${NOCOLOR}"
	@cd $(docPath)/latex; make refman.pdf
	@cp $(docPath)/latex/refman.pdf $(docPath)/$(docName).pdf
	@echo "$(GREEN)Successfuly generated $(RED)$(docName).pdf$(NOCOLOR) @ $(docPath)"

mrproper:
	@[ ! -d $(binPath)   ] || $(RM) $(binPath)/*
	@[ ! -d $(objPath)   ] || $(RM) $(objPath)/*
	@[ ! -d $(debugPath) ] || $(RM) $(debugPath)/*

clean:
	@$(RM) $(binPath) $(objPath) $(docPath) $(debugPath)
