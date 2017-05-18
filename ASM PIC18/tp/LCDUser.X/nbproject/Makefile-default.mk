#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=lib
DEBUGGABLE_SUFFIX=
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/LCDUser.X.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=lib
DEBUGGABLE_SUFFIX=
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/LCDUser.X.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=LCD_Init_User.c LCD_String_XY_User.c LCD_Char_User.c LCD_Char_XY_User.c LCD_Command_User.c LCD_String_User.c LCD_Cursor_XY_User.c LCD_Write_Register_User.c LCD_Write_Data_User.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/LCD_Init_User.o ${OBJECTDIR}/LCD_String_XY_User.o ${OBJECTDIR}/LCD_Char_User.o ${OBJECTDIR}/LCD_Char_XY_User.o ${OBJECTDIR}/LCD_Command_User.o ${OBJECTDIR}/LCD_String_User.o ${OBJECTDIR}/LCD_Cursor_XY_User.o ${OBJECTDIR}/LCD_Write_Register_User.o ${OBJECTDIR}/LCD_Write_Data_User.o
POSSIBLE_DEPFILES=${OBJECTDIR}/LCD_Init_User.o.d ${OBJECTDIR}/LCD_String_XY_User.o.d ${OBJECTDIR}/LCD_Char_User.o.d ${OBJECTDIR}/LCD_Char_XY_User.o.d ${OBJECTDIR}/LCD_Command_User.o.d ${OBJECTDIR}/LCD_String_User.o.d ${OBJECTDIR}/LCD_Cursor_XY_User.o.d ${OBJECTDIR}/LCD_Write_Register_User.o.d ${OBJECTDIR}/LCD_Write_Data_User.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/LCD_Init_User.o ${OBJECTDIR}/LCD_String_XY_User.o ${OBJECTDIR}/LCD_Char_User.o ${OBJECTDIR}/LCD_Char_XY_User.o ${OBJECTDIR}/LCD_Command_User.o ${OBJECTDIR}/LCD_String_User.o ${OBJECTDIR}/LCD_Cursor_XY_User.o ${OBJECTDIR}/LCD_Write_Register_User.o ${OBJECTDIR}/LCD_Write_Data_User.o

# Source Files
SOURCEFILES=LCD_Init_User.c LCD_String_XY_User.c LCD_Char_User.c LCD_Char_XY_User.c LCD_Command_User.c LCD_String_User.c LCD_Cursor_XY_User.c LCD_Write_Register_User.c LCD_Write_Data_User.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/LCDUser.X.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4550
MP_PROCESSOR_OPTION_LD=18f4550
MP_LINKER_DEBUG_OPTION=-r=ROM@0x7DC0:0x7FFF -r=RAM@GPR:0x3F4:0x3FF -u_DEBUGSTACK
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/LCD_Init_User.o: LCD_Init_User.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCD_Init_User.o.d 
	@${RM} ${OBJECTDIR}/LCD_Init_User.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/LCD_Init_User.o   LCD_Init_User.c 
	@${DEP_GEN} -d ${OBJECTDIR}/LCD_Init_User.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_Init_User.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/LCD_String_XY_User.o: LCD_String_XY_User.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCD_String_XY_User.o.d 
	@${RM} ${OBJECTDIR}/LCD_String_XY_User.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/LCD_String_XY_User.o   LCD_String_XY_User.c 
	@${DEP_GEN} -d ${OBJECTDIR}/LCD_String_XY_User.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_String_XY_User.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/LCD_Char_User.o: LCD_Char_User.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCD_Char_User.o.d 
	@${RM} ${OBJECTDIR}/LCD_Char_User.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/LCD_Char_User.o   LCD_Char_User.c 
	@${DEP_GEN} -d ${OBJECTDIR}/LCD_Char_User.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_Char_User.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/LCD_Char_XY_User.o: LCD_Char_XY_User.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCD_Char_XY_User.o.d 
	@${RM} ${OBJECTDIR}/LCD_Char_XY_User.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/LCD_Char_XY_User.o   LCD_Char_XY_User.c 
	@${DEP_GEN} -d ${OBJECTDIR}/LCD_Char_XY_User.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_Char_XY_User.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/LCD_Command_User.o: LCD_Command_User.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCD_Command_User.o.d 
	@${RM} ${OBJECTDIR}/LCD_Command_User.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/LCD_Command_User.o   LCD_Command_User.c 
	@${DEP_GEN} -d ${OBJECTDIR}/LCD_Command_User.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_Command_User.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/LCD_String_User.o: LCD_String_User.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCD_String_User.o.d 
	@${RM} ${OBJECTDIR}/LCD_String_User.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/LCD_String_User.o   LCD_String_User.c 
	@${DEP_GEN} -d ${OBJECTDIR}/LCD_String_User.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_String_User.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/LCD_Cursor_XY_User.o: LCD_Cursor_XY_User.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCD_Cursor_XY_User.o.d 
	@${RM} ${OBJECTDIR}/LCD_Cursor_XY_User.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/LCD_Cursor_XY_User.o   LCD_Cursor_XY_User.c 
	@${DEP_GEN} -d ${OBJECTDIR}/LCD_Cursor_XY_User.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_Cursor_XY_User.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/LCD_Write_Register_User.o: LCD_Write_Register_User.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCD_Write_Register_User.o.d 
	@${RM} ${OBJECTDIR}/LCD_Write_Register_User.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/LCD_Write_Register_User.o   LCD_Write_Register_User.c 
	@${DEP_GEN} -d ${OBJECTDIR}/LCD_Write_Register_User.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_Write_Register_User.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/LCD_Write_Data_User.o: LCD_Write_Data_User.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCD_Write_Data_User.o.d 
	@${RM} ${OBJECTDIR}/LCD_Write_Data_User.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/LCD_Write_Data_User.o   LCD_Write_Data_User.c 
	@${DEP_GEN} -d ${OBJECTDIR}/LCD_Write_Data_User.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_Write_Data_User.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/LCD_Init_User.o: LCD_Init_User.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCD_Init_User.o.d 
	@${RM} ${OBJECTDIR}/LCD_Init_User.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/LCD_Init_User.o   LCD_Init_User.c 
	@${DEP_GEN} -d ${OBJECTDIR}/LCD_Init_User.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_Init_User.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/LCD_String_XY_User.o: LCD_String_XY_User.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCD_String_XY_User.o.d 
	@${RM} ${OBJECTDIR}/LCD_String_XY_User.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/LCD_String_XY_User.o   LCD_String_XY_User.c 
	@${DEP_GEN} -d ${OBJECTDIR}/LCD_String_XY_User.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_String_XY_User.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/LCD_Char_User.o: LCD_Char_User.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCD_Char_User.o.d 
	@${RM} ${OBJECTDIR}/LCD_Char_User.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/LCD_Char_User.o   LCD_Char_User.c 
	@${DEP_GEN} -d ${OBJECTDIR}/LCD_Char_User.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_Char_User.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/LCD_Char_XY_User.o: LCD_Char_XY_User.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCD_Char_XY_User.o.d 
	@${RM} ${OBJECTDIR}/LCD_Char_XY_User.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/LCD_Char_XY_User.o   LCD_Char_XY_User.c 
	@${DEP_GEN} -d ${OBJECTDIR}/LCD_Char_XY_User.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_Char_XY_User.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/LCD_Command_User.o: LCD_Command_User.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCD_Command_User.o.d 
	@${RM} ${OBJECTDIR}/LCD_Command_User.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/LCD_Command_User.o   LCD_Command_User.c 
	@${DEP_GEN} -d ${OBJECTDIR}/LCD_Command_User.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_Command_User.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/LCD_String_User.o: LCD_String_User.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCD_String_User.o.d 
	@${RM} ${OBJECTDIR}/LCD_String_User.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/LCD_String_User.o   LCD_String_User.c 
	@${DEP_GEN} -d ${OBJECTDIR}/LCD_String_User.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_String_User.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/LCD_Cursor_XY_User.o: LCD_Cursor_XY_User.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCD_Cursor_XY_User.o.d 
	@${RM} ${OBJECTDIR}/LCD_Cursor_XY_User.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/LCD_Cursor_XY_User.o   LCD_Cursor_XY_User.c 
	@${DEP_GEN} -d ${OBJECTDIR}/LCD_Cursor_XY_User.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_Cursor_XY_User.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/LCD_Write_Register_User.o: LCD_Write_Register_User.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCD_Write_Register_User.o.d 
	@${RM} ${OBJECTDIR}/LCD_Write_Register_User.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/LCD_Write_Register_User.o   LCD_Write_Register_User.c 
	@${DEP_GEN} -d ${OBJECTDIR}/LCD_Write_Register_User.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_Write_Register_User.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/LCD_Write_Data_User.o: LCD_Write_Data_User.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCD_Write_Data_User.o.d 
	@${RM} ${OBJECTDIR}/LCD_Write_Data_User.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/LCD_Write_Data_User.o   LCD_Write_Data_User.c 
	@${DEP_GEN} -d ${OBJECTDIR}/LCD_Write_Data_User.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_Write_Data_User.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: archive
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/LCDUser.X.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_AR} $(MP_EXTRA_AR_PRE) -c dist/${CND_CONF}/${IMAGE_TYPE}/LCDUser.X.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}  
else
dist/${CND_CONF}/${IMAGE_TYPE}/LCDUser.X.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_AR} $(MP_EXTRA_AR_PRE) -c dist/${CND_CONF}/${IMAGE_TYPE}/LCDUser.X.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}  
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
