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
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/projet.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/projet.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.c lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.S lib/FreeRTOS/Source/croutine.c lib/FreeRTOS/Source/list.c lib/FreeRTOS/Source/queue.c lib/FreeRTOS/Source/tasks.c lib/FreeRTOS/Source/timers.c src/tsk_io.c src/tsk_network.c src/tsk_time.c src/tsk_sensor.c src/tsk_console.c src/tsk_led.c lib/peripherals/kuart/pic32maxiweb/src/kuart.c src/ktrap.c src/main.c src/utask.c lib/FreeRTOS/Source/portable/MemMang/heap_4.c lib/peripherals/adc/pic32maxiweb/src/adc.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.o ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.o ${OBJECTDIR}/lib/FreeRTOS/Source/croutine.o ${OBJECTDIR}/lib/FreeRTOS/Source/list.o ${OBJECTDIR}/lib/FreeRTOS/Source/queue.o ${OBJECTDIR}/lib/FreeRTOS/Source/tasks.o ${OBJECTDIR}/lib/FreeRTOS/Source/timers.o ${OBJECTDIR}/src/tsk_io.o ${OBJECTDIR}/src/tsk_network.o ${OBJECTDIR}/src/tsk_time.o ${OBJECTDIR}/src/tsk_sensor.o ${OBJECTDIR}/src/tsk_console.o ${OBJECTDIR}/src/tsk_led.o ${OBJECTDIR}/lib/peripherals/kuart/pic32maxiweb/src/kuart.o ${OBJECTDIR}/src/ktrap.o ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/utask.o ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MemMang/heap_4.o ${OBJECTDIR}/lib/peripherals/adc/pic32maxiweb/src/adc.o
POSSIBLE_DEPFILES=${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.o.d ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.o.d ${OBJECTDIR}/lib/FreeRTOS/Source/croutine.o.d ${OBJECTDIR}/lib/FreeRTOS/Source/list.o.d ${OBJECTDIR}/lib/FreeRTOS/Source/queue.o.d ${OBJECTDIR}/lib/FreeRTOS/Source/tasks.o.d ${OBJECTDIR}/lib/FreeRTOS/Source/timers.o.d ${OBJECTDIR}/src/tsk_io.o.d ${OBJECTDIR}/src/tsk_network.o.d ${OBJECTDIR}/src/tsk_time.o.d ${OBJECTDIR}/src/tsk_sensor.o.d ${OBJECTDIR}/src/tsk_console.o.d ${OBJECTDIR}/src/tsk_led.o.d ${OBJECTDIR}/lib/peripherals/kuart/pic32maxiweb/src/kuart.o.d ${OBJECTDIR}/src/ktrap.o.d ${OBJECTDIR}/src/main.o.d ${OBJECTDIR}/src/utask.o.d ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MemMang/heap_4.o.d ${OBJECTDIR}/lib/peripherals/adc/pic32maxiweb/src/adc.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.o ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.o ${OBJECTDIR}/lib/FreeRTOS/Source/croutine.o ${OBJECTDIR}/lib/FreeRTOS/Source/list.o ${OBJECTDIR}/lib/FreeRTOS/Source/queue.o ${OBJECTDIR}/lib/FreeRTOS/Source/tasks.o ${OBJECTDIR}/lib/FreeRTOS/Source/timers.o ${OBJECTDIR}/src/tsk_io.o ${OBJECTDIR}/src/tsk_network.o ${OBJECTDIR}/src/tsk_time.o ${OBJECTDIR}/src/tsk_sensor.o ${OBJECTDIR}/src/tsk_console.o ${OBJECTDIR}/src/tsk_led.o ${OBJECTDIR}/lib/peripherals/kuart/pic32maxiweb/src/kuart.o ${OBJECTDIR}/src/ktrap.o ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/utask.o ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MemMang/heap_4.o ${OBJECTDIR}/lib/peripherals/adc/pic32maxiweb/src/adc.o

# Source Files
SOURCEFILES=lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.c lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.S lib/FreeRTOS/Source/croutine.c lib/FreeRTOS/Source/list.c lib/FreeRTOS/Source/queue.c lib/FreeRTOS/Source/tasks.c lib/FreeRTOS/Source/timers.c src/tsk_io.c src/tsk_network.c src/tsk_time.c src/tsk_sensor.c src/tsk_console.c src/tsk_led.c lib/peripherals/kuart/pic32maxiweb/src/kuart.c src/ktrap.c src/main.c src/utask.c lib/FreeRTOS/Source/portable/MemMang/heap_4.c lib/peripherals/adc/pic32maxiweb/src/adc.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/projet.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX795F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.o: lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.o.d 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.o 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.o.ok ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.o.err 
	@${FIXDEPS} "${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.o.d" "${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -DPICkit3PlatformTool=1 -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.o.d"  -o ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.o lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.S  -DXPRJ_default=$(CND_CONF)    -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=PICkit3PlatformTool=1 -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h"
	
else
${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.o: lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.o.d 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.o 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.o.ok ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.o.err 
	@${FIXDEPS} "${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.o.d" "${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.o.d"  -o ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.o lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.S  -DXPRJ_default=$(CND_CONF)    -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.o.asm.d",--gdwarf-2 -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.o: lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.o.d 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.o.d" -o ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.o lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/lib/FreeRTOS/Source/croutine.o: lib/FreeRTOS/Source/croutine.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/FreeRTOS/Source" 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/croutine.o.d 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/croutine.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/FreeRTOS/Source/croutine.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/lib/FreeRTOS/Source/croutine.o.d" -o ${OBJECTDIR}/lib/FreeRTOS/Source/croutine.o lib/FreeRTOS/Source/croutine.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/lib/FreeRTOS/Source/list.o: lib/FreeRTOS/Source/list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/FreeRTOS/Source" 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/list.o.d 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/list.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/FreeRTOS/Source/list.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/lib/FreeRTOS/Source/list.o.d" -o ${OBJECTDIR}/lib/FreeRTOS/Source/list.o lib/FreeRTOS/Source/list.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/lib/FreeRTOS/Source/queue.o: lib/FreeRTOS/Source/queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/FreeRTOS/Source" 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/queue.o.d 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/queue.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/FreeRTOS/Source/queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/lib/FreeRTOS/Source/queue.o.d" -o ${OBJECTDIR}/lib/FreeRTOS/Source/queue.o lib/FreeRTOS/Source/queue.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/lib/FreeRTOS/Source/tasks.o: lib/FreeRTOS/Source/tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/FreeRTOS/Source" 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/tasks.o.d 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/FreeRTOS/Source/tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/lib/FreeRTOS/Source/tasks.o.d" -o ${OBJECTDIR}/lib/FreeRTOS/Source/tasks.o lib/FreeRTOS/Source/tasks.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/lib/FreeRTOS/Source/timers.o: lib/FreeRTOS/Source/timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/FreeRTOS/Source" 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/timers.o.d 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/timers.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/FreeRTOS/Source/timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/lib/FreeRTOS/Source/timers.o.d" -o ${OBJECTDIR}/lib/FreeRTOS/Source/timers.o lib/FreeRTOS/Source/timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/tsk_io.o: src/tsk_io.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/tsk_io.o.d 
	@${RM} ${OBJECTDIR}/src/tsk_io.o 
	@${FIXDEPS} "${OBJECTDIR}/src/tsk_io.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/src/tsk_io.o.d" -o ${OBJECTDIR}/src/tsk_io.o src/tsk_io.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/tsk_network.o: src/tsk_network.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/tsk_network.o.d 
	@${RM} ${OBJECTDIR}/src/tsk_network.o 
	@${FIXDEPS} "${OBJECTDIR}/src/tsk_network.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/src/tsk_network.o.d" -o ${OBJECTDIR}/src/tsk_network.o src/tsk_network.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/tsk_time.o: src/tsk_time.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/tsk_time.o.d 
	@${RM} ${OBJECTDIR}/src/tsk_time.o 
	@${FIXDEPS} "${OBJECTDIR}/src/tsk_time.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/src/tsk_time.o.d" -o ${OBJECTDIR}/src/tsk_time.o src/tsk_time.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/tsk_sensor.o: src/tsk_sensor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/tsk_sensor.o.d 
	@${RM} ${OBJECTDIR}/src/tsk_sensor.o 
	@${FIXDEPS} "${OBJECTDIR}/src/tsk_sensor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/src/tsk_sensor.o.d" -o ${OBJECTDIR}/src/tsk_sensor.o src/tsk_sensor.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/tsk_console.o: src/tsk_console.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/tsk_console.o.d 
	@${RM} ${OBJECTDIR}/src/tsk_console.o 
	@${FIXDEPS} "${OBJECTDIR}/src/tsk_console.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/src/tsk_console.o.d" -o ${OBJECTDIR}/src/tsk_console.o src/tsk_console.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/tsk_led.o: src/tsk_led.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/tsk_led.o.d 
	@${RM} ${OBJECTDIR}/src/tsk_led.o 
	@${FIXDEPS} "${OBJECTDIR}/src/tsk_led.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/src/tsk_led.o.d" -o ${OBJECTDIR}/src/tsk_led.o src/tsk_led.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/lib/peripherals/kuart/pic32maxiweb/src/kuart.o: lib/peripherals/kuart/pic32maxiweb/src/kuart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/peripherals/kuart/pic32maxiweb/src" 
	@${RM} ${OBJECTDIR}/lib/peripherals/kuart/pic32maxiweb/src/kuart.o.d 
	@${RM} ${OBJECTDIR}/lib/peripherals/kuart/pic32maxiweb/src/kuart.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/peripherals/kuart/pic32maxiweb/src/kuart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/lib/peripherals/kuart/pic32maxiweb/src/kuart.o.d" -o ${OBJECTDIR}/lib/peripherals/kuart/pic32maxiweb/src/kuart.o lib/peripherals/kuart/pic32maxiweb/src/kuart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/ktrap.o: src/ktrap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/ktrap.o.d 
	@${RM} ${OBJECTDIR}/src/ktrap.o 
	@${FIXDEPS} "${OBJECTDIR}/src/ktrap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/src/ktrap.o.d" -o ${OBJECTDIR}/src/ktrap.o src/ktrap.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/main.o: src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	@${FIXDEPS} "${OBJECTDIR}/src/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/src/main.o.d" -o ${OBJECTDIR}/src/main.o src/main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/utask.o: src/utask.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/utask.o.d 
	@${RM} ${OBJECTDIR}/src/utask.o 
	@${FIXDEPS} "${OBJECTDIR}/src/utask.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/src/utask.o.d" -o ${OBJECTDIR}/src/utask.o src/utask.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/lib/FreeRTOS/Source/portable/MemMang/heap_4.o: lib/FreeRTOS/Source/portable/MemMang/heap_4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/FreeRTOS/Source/portable/MemMang" 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MemMang/heap_4.o.d 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MemMang/heap_4.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/FreeRTOS/Source/portable/MemMang/heap_4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/lib/FreeRTOS/Source/portable/MemMang/heap_4.o.d" -o ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MemMang/heap_4.o lib/FreeRTOS/Source/portable/MemMang/heap_4.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/lib/peripherals/adc/pic32maxiweb/src/adc.o: lib/peripherals/adc/pic32maxiweb/src/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/peripherals/adc/pic32maxiweb/src" 
	@${RM} ${OBJECTDIR}/lib/peripherals/adc/pic32maxiweb/src/adc.o.d 
	@${RM} ${OBJECTDIR}/lib/peripherals/adc/pic32maxiweb/src/adc.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/peripherals/adc/pic32maxiweb/src/adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/lib/peripherals/adc/pic32maxiweb/src/adc.o.d" -o ${OBJECTDIR}/lib/peripherals/adc/pic32maxiweb/src/adc.o lib/peripherals/adc/pic32maxiweb/src/adc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.o: lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.o.d 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.o.d" -o ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.o lib/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/lib/FreeRTOS/Source/croutine.o: lib/FreeRTOS/Source/croutine.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/FreeRTOS/Source" 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/croutine.o.d 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/croutine.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/FreeRTOS/Source/croutine.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/lib/FreeRTOS/Source/croutine.o.d" -o ${OBJECTDIR}/lib/FreeRTOS/Source/croutine.o lib/FreeRTOS/Source/croutine.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/lib/FreeRTOS/Source/list.o: lib/FreeRTOS/Source/list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/FreeRTOS/Source" 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/list.o.d 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/list.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/FreeRTOS/Source/list.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/lib/FreeRTOS/Source/list.o.d" -o ${OBJECTDIR}/lib/FreeRTOS/Source/list.o lib/FreeRTOS/Source/list.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/lib/FreeRTOS/Source/queue.o: lib/FreeRTOS/Source/queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/FreeRTOS/Source" 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/queue.o.d 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/queue.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/FreeRTOS/Source/queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/lib/FreeRTOS/Source/queue.o.d" -o ${OBJECTDIR}/lib/FreeRTOS/Source/queue.o lib/FreeRTOS/Source/queue.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/lib/FreeRTOS/Source/tasks.o: lib/FreeRTOS/Source/tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/FreeRTOS/Source" 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/tasks.o.d 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/FreeRTOS/Source/tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/lib/FreeRTOS/Source/tasks.o.d" -o ${OBJECTDIR}/lib/FreeRTOS/Source/tasks.o lib/FreeRTOS/Source/tasks.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/lib/FreeRTOS/Source/timers.o: lib/FreeRTOS/Source/timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/FreeRTOS/Source" 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/timers.o.d 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/timers.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/FreeRTOS/Source/timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/lib/FreeRTOS/Source/timers.o.d" -o ${OBJECTDIR}/lib/FreeRTOS/Source/timers.o lib/FreeRTOS/Source/timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/tsk_io.o: src/tsk_io.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/tsk_io.o.d 
	@${RM} ${OBJECTDIR}/src/tsk_io.o 
	@${FIXDEPS} "${OBJECTDIR}/src/tsk_io.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/src/tsk_io.o.d" -o ${OBJECTDIR}/src/tsk_io.o src/tsk_io.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/tsk_network.o: src/tsk_network.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/tsk_network.o.d 
	@${RM} ${OBJECTDIR}/src/tsk_network.o 
	@${FIXDEPS} "${OBJECTDIR}/src/tsk_network.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/src/tsk_network.o.d" -o ${OBJECTDIR}/src/tsk_network.o src/tsk_network.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/tsk_time.o: src/tsk_time.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/tsk_time.o.d 
	@${RM} ${OBJECTDIR}/src/tsk_time.o 
	@${FIXDEPS} "${OBJECTDIR}/src/tsk_time.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/src/tsk_time.o.d" -o ${OBJECTDIR}/src/tsk_time.o src/tsk_time.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/tsk_sensor.o: src/tsk_sensor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/tsk_sensor.o.d 
	@${RM} ${OBJECTDIR}/src/tsk_sensor.o 
	@${FIXDEPS} "${OBJECTDIR}/src/tsk_sensor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/src/tsk_sensor.o.d" -o ${OBJECTDIR}/src/tsk_sensor.o src/tsk_sensor.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/tsk_console.o: src/tsk_console.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/tsk_console.o.d 
	@${RM} ${OBJECTDIR}/src/tsk_console.o 
	@${FIXDEPS} "${OBJECTDIR}/src/tsk_console.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/src/tsk_console.o.d" -o ${OBJECTDIR}/src/tsk_console.o src/tsk_console.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/tsk_led.o: src/tsk_led.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/tsk_led.o.d 
	@${RM} ${OBJECTDIR}/src/tsk_led.o 
	@${FIXDEPS} "${OBJECTDIR}/src/tsk_led.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/src/tsk_led.o.d" -o ${OBJECTDIR}/src/tsk_led.o src/tsk_led.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/lib/peripherals/kuart/pic32maxiweb/src/kuart.o: lib/peripherals/kuart/pic32maxiweb/src/kuart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/peripherals/kuart/pic32maxiweb/src" 
	@${RM} ${OBJECTDIR}/lib/peripherals/kuart/pic32maxiweb/src/kuart.o.d 
	@${RM} ${OBJECTDIR}/lib/peripherals/kuart/pic32maxiweb/src/kuart.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/peripherals/kuart/pic32maxiweb/src/kuart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/lib/peripherals/kuart/pic32maxiweb/src/kuart.o.d" -o ${OBJECTDIR}/lib/peripherals/kuart/pic32maxiweb/src/kuart.o lib/peripherals/kuart/pic32maxiweb/src/kuart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/ktrap.o: src/ktrap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/ktrap.o.d 
	@${RM} ${OBJECTDIR}/src/ktrap.o 
	@${FIXDEPS} "${OBJECTDIR}/src/ktrap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/src/ktrap.o.d" -o ${OBJECTDIR}/src/ktrap.o src/ktrap.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/main.o: src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	@${FIXDEPS} "${OBJECTDIR}/src/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/src/main.o.d" -o ${OBJECTDIR}/src/main.o src/main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/utask.o: src/utask.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/utask.o.d 
	@${RM} ${OBJECTDIR}/src/utask.o 
	@${FIXDEPS} "${OBJECTDIR}/src/utask.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/src/utask.o.d" -o ${OBJECTDIR}/src/utask.o src/utask.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/lib/FreeRTOS/Source/portable/MemMang/heap_4.o: lib/FreeRTOS/Source/portable/MemMang/heap_4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/FreeRTOS/Source/portable/MemMang" 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MemMang/heap_4.o.d 
	@${RM} ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MemMang/heap_4.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/FreeRTOS/Source/portable/MemMang/heap_4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/lib/FreeRTOS/Source/portable/MemMang/heap_4.o.d" -o ${OBJECTDIR}/lib/FreeRTOS/Source/portable/MemMang/heap_4.o lib/FreeRTOS/Source/portable/MemMang/heap_4.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/lib/peripherals/adc/pic32maxiweb/src/adc.o: lib/peripherals/adc/pic32maxiweb/src/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/peripherals/adc/pic32maxiweb/src" 
	@${RM} ${OBJECTDIR}/lib/peripherals/adc/pic32maxiweb/src/adc.o.d 
	@${RM} ${OBJECTDIR}/lib/peripherals/adc/pic32maxiweb/src/adc.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/peripherals/adc/pic32maxiweb/src/adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"inc" -I"lib/FreeRTOS/Source/include" -I"lib/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"lib/peripherals/kuart/pic32maxiweb/h" -I"lib/peripherals/adc/pic32maxiweb/h" -MMD -MF "${OBJECTDIR}/lib/peripherals/adc/pic32maxiweb/src/adc.o.d" -o ${OBJECTDIR}/lib/peripherals/adc/pic32maxiweb/src/adc.o lib/peripherals/adc/pic32maxiweb/src/adc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/projet.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -DPICkit3PlatformTool=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/projet.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=PICkit3PlatformTool=1,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/projet.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/projet.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	${MP_CC_DIR}/xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/projet.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
