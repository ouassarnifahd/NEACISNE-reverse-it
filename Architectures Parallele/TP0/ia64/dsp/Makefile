# Compiler/Linker tools and options
CC	= gcc
LD	= gcc
CFLAGS	= -Wall -march=native -std=c99 -o3 # Compiling options
LDFLAGS	= -lm # Linking options
EXEC	= firtest # output file name

# Project tree
PJCT_DIR	= .
TEST_DIR	= $(PJCT_DIR)/test/src
FIRLIB_DIR	= $(PJCT_DIR)/firlib/src
OBJ_DIR		= $(PJCT_DIR)/build/obj
BIN_DIR		= $(PJCT_DIR)/build/bin

# Include dependencies
INCLUDES =						\
		-I$(PJCT_DIR)/test/h 	\
		-I$(PJCT_DIR)/firlib/h

# Object files 
OBJ =							\
	$(OBJ_DIR)/fir_sp.o 		\
	$(OBJ_DIR)/fir_sp_r4.o 		\
	$(OBJ_DIR)/fir_sp_sse_r4.o 	\
	$(OBJ_DIR)/firtest_sys.o 	\
	$(OBJ_DIR)/firtest_main.o

# Make compiling and linking process
all:
		@echo "\n*** Clean all objects et output files ***\n" 
		make clean 	
		@echo "\n*** Building ***" 
		@echo "\n*** Compiling ***\n" 
		@make $(EXEC) 

$(EXEC): 	$(OBJ)	
			@echo "\n*** Linking ***\n" 
			$(LD) $(LDFLAGS) $^ -o $(BIN_DIR)/$@ 
			@echo "\n*** Build Finished $(BIN_DIR)/$@ ***\n" 

# Files dependencies : rebluid sources if header files are modified
$(OBJ_DIR)/fir_sp.o 		: $(PJCT_DIR)/firlib/h/firlib.h
$(OBJ_DIR)/fir_sp_r4.o 		: $(PJCT_DIR)/firlib/h/firlib.h
$(OBJ_DIR)/fir_sp_sse_r4.o 	: $(PJCT_DIR)/firlib/h/firlib.h
$(OBJ_DIR)/firtest_main.o 	: $(PJCT_DIR)/test/h/*.h
$(OBJ_DIR)/firtest_sys.o 	: $(PJCT_DIR)/test/h/*.h

$(OBJ_DIR)/%.o: $(FIRLIB_DIR)/%.c
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Directories and files removed with 'make clean' or 'make mrproper'
.PHONY: clean mrproper

clean:
	@rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*

mrproper: clean
	@rm -rf $(EXEC)
