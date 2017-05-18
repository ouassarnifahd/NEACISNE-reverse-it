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
Project		:= time_sort

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

# TODO: regex!

all: mrproper build makeDoc

build: object
	@for elem in $(elems); do \
		echo "Preparing $$elem:"; \
		type=`echo "$${elem#ELEM_}" | tr /A-Z/ /a-z/`; \
		staticObject="$(objPath)/$$type/element.o"; \
		$(MAKE) $(binPath)/$(Project)_$${type} type=$$type staticOBJ="$$staticObject" && \
		echo "$(GREEN)Successfuly compiled $(RED)$(Project)_$${type}$(NOCOLOR)"; \
	done; \
	echo "All Done. ";

object: $(inc)
	@for object in $(obj); do \
		if  [ $$object == array.o ] || [ $$object == sort.o ]; then \
			[ -a $(objPath)/$$object ] || $(MAKE) $(objPath)/$$object Flags=$(wFlag); \
		else \
			for elem in $(elems); do \
				type=`echo "$${elem#ELEM_}" | tr /A-Z/ /a-z/`; \
				elemFlag="-D $$elem"; \
				if [ $$object == element.o ]; then \
					$(MAKE) $(objPath)/$$type/$$object type=$$type Flags="$(wFlag) $$elemFlag"; \
				elif [ $$object == main.o ]; then \
					$(MAKE) $(objPath)/$$type/$(Project).o type=$$type Flags="$(wFlag) $$elemFlag"; \
				fi; \
			done; \
		fi; \
	done;

$(debugPath)/%.dbg: $(srcPath)/%.c $(inc)
	@$(MAKE) directory path=$(dir $@)
	@if [ '$(objects)' != '' ]; then \
		$(MAKE) $(addprefix $(debugPath)/,$(objects)) Flags="$(Flags)"; \
		$(CC) $(dbgFlags) $(Flags) -o $@ $(addprefix $(debugPath)/,$(objects)) $< 2> $(basename $@).err; \
	else \
		$(CC) $(dbgFlags) $(Flags) -o $@ $< 2> $(basename $@).err; \
	fi;

$(debugPath)/%.o: $(srcPath)/%.c
	@$(MAKE) directory path=$(dir $@)
	@$(MAKE) compile OBJ='yes' CFlags="$(Flags)" out=$@ in=$<

$(objPath)/$(type)/%.o: $(srcPath)/%.c
	@$(MAKE) directory path=$(dir $@)
	@$(MAKE) compile OBJ='yes' CFlags="$(Flags)" out=$@ in=$<

$(binPath)/$(Project)_$(type): $(objPath)/$(type)/$(Project).o
	@$(MAKE) directory path=$(dir $@)
	@$(MAKE) compile OBJ='no' CFlags=$(wFlag) out=$@ objects="$(wildcard $(objPath)/*.o) $(staticOBJ) $<";

$(objPath)/$(type)/$(Project).o: $(srcPath)/main.c
	@$(MAKE) directory path=$(dir $@)
	@$(MAKE) compile OBJ='yes' CFlags="$(Flags)" out=$@ in=$<

$(objPath)/%.o: $(srcPath)/%.c
	@$(MAKE) directory path=$(dir $@)
	@$(MAKE) compile OBJ='yes' CFlags="$(Flags)" out=$@ in=$<

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
