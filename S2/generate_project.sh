#!/bin/bash

if [[ $# != 2 ]]; then
	echo "usage: $0 <ProjectName> <ProjectPath>"
	echo "Note: if ProjectPath is set to 'current' then the project will be created in the current directory"
	exit;
fi

#General
ProjectName=$1
ProjectLanguage='French'
ProjectBrief="Une implementation des ${ProjectName}s en C"
DocMacro='_DOXYGEN_'

#Paths
curDir=`pwd`
ProjectPath=$2
SrcPath='src'
IncPath='inc'
ObjPath='obj'
BinPath='bin'
DocPath='doc'

# Making directory
if [[ $FolderName != 'current' ]]; then
	mkdir -p "$ProjectPath"
	curDir=$ProjectPath
	cd "$curDir"
fi

[ -d $SrcPath ] || mkdir -p $SrcPath
[ -d $IncPath ] || mkdir -p $IncPath

#HEADER:copying to file.h
cd $IncPath/
cat << EOF1 > "$ProjectName.h"
#ifndef _\
`echo "$ProjectName" | tr /a-z/ /A-Z/`\
_
#define _\
`echo "$ProjectName" | tr /a-z/ /A-Z/`\
_
#include"./Elements/element.h"




#endif /* end of include guard : _\
`echo "$ProjectName" | tr /a-z/ /A-Z/`\
_ */

EOF1

#Elements:
mkdir Elements; cd Elements
cat << EOF2 > "element.h"
#ifndef _ELEMENT_
#define _ELEMENT_

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/** @file element.h
*   @brief Header contenant la definition de l\'elements.
*/

#ifdef _DOXYGEN_

#define _INT_
#define _FLOAT_
#define _OTHER_

#endif /* _DOXYGEN_ */

#ifdef _OTHER_

/** @typedef TElement
*   @brief L\'element.
*/
typedef TYPE TElement;

#elif _FLOAT_

/** @typedef TElement
*   @brief L\'element.
*/
typedef float TElement;

#elif _INT_

/** @typedef TElement
*   @brief L\'element.
*/
typedef int TElement;

#endif

/** @typedef PTElement
*   @brief Pointeur vers l\'element.
*/
typedef void* PTElement;

/** @fn display_element
*   @brief Affiche l\'element.
*   @param L\'element a afficher.
*/
void display_element(const void *pElement);

/** @fn read_element
*   @brief Lecture de l\'element.
*   @param L\'element a lire.
*/
bool read_element(const void *pElement);

#endif /* end of include guard : _ELEMENT_ */

EOF2

#MAIN:copying to main.c
cd ../../$SrcPath
cat << EOF3 > main.c
#include\
"../$IncPath/$ProjectName.h"

int main(int argc, char const *argv[]){
	int choix;
	/* INDEX ?  int index */
	TElement newElt;
	printf("Creation d'une $ProjectName de nombres %s: \n", (char*)TYPE);
	/* DATA STRUCT NEW */
	printf("Faites votre choix:");
	while(1){
		printf("\n");
		printf("\t1 : Ajouter un element a $ProjectName\n");
		/* printf("\t? : Another choice ?\n"); */
		printf("\t? : Modifier la position courante\n");
		printf("\t? : Enlever l'element de $ProjectName\n");
		printf("\t? : Vider la liste\n");
		printf("\t0 : Quitter\n");
		printf("\n\tChoix: ");
		scanf("%d", &choix);
		switch(choix){
			case 1:
				do{
					printf("\t  Entrer l'element: ");
				}while(/* READ ELEMENT */);
				/* ADD ELEMENT TO DATA STRUCT */
				break;
			case ?:
				/* SOMETHING HERE ? */
				break;
			/* case ?:
				do{
					printf("\t  Entrer un nouvelle position: ");
				}while(scanf("%d",&index));
				/* CHANGE INDEX ? */
				break; */
			case ?:
				/* REMOVE ELEMENT */
				if(/* REMOVING FUNCTION */){
					printf("\t  Success!\n");
				} else {
					printf("\t  Erreur!\n");
				}
				break;
			case ?:
				/* DATA STRUCT CLEAR */
				printf("\t  Liste vidée!\n");
				break;
			case 0:
				/* DATA STRUCT DESTRUCTION */
				printf("\t  Destruction de la liste!\n");
				return EXIT_SUCCESS;
			default:
				printf("\t  Ce choix n'est pas valide!\n");
		}
		printf("\n");
		/* DISPLAY HERE */
	}
}
EOF3

#FUNCTIONS:copying to functions.c
cat << EOF4 > "$ProjectName.c"
#include<stdio.h>
#include<stdlib.h>

#include\
"../$IncPath/$ProjectName.h"
#include"../inc/Elements/element.h"

EOF4

#Elements:
mkdir Elements; cd Elements
cat << EOF5 > "element.c"
#include\
"../../$IncPath/Elements/element.h"

#ifdef _FLOAT_

void display_element(const void *pElement){
    float flottant= *(const float *)pElement;
    printf("%.2f", flottant);
}

bool read_element(const void *pElement){
    return !scanf("%f",(float *)pElement);
}

#elif _INT_

void display_element(const void *pElement){
    int entier= *(const int *)pElement;
    printf("%d", entier);
}

bool read_element(const void *pElement){
    return !scanf("%d",(int *)pElement);
}

#endif


EOF5

#MAKEFILE:copying to makefile
cd ../..

cat << EOF6 > makefile
#general
CC    		 := gcc
wFlag 		 := -Wall
srcPath		 := $SrcPath
incPath		 := $IncPath
objPath		 := $ObjPath
binPath		 := $BinPath
Project		 := $ProjectName

#Documentation
docPath		 := $DocPath
docName		 := \$(Project)_documentation

#Colors
BLACK		 := \\033[0;30m
GRAY		 := \\033[1;30m
RED			 := \\033[0;31m
LRED		 := \\033[1;31m
GREEN		 := \\033[0;32m
LGREEN		 := \\033[1;32m
BROWN		 := \\033[0;33m
YELLOW		 := \\033[1;33m
BLUE		 := \\033[0;34m
LBLUE		 := \\033[1;34m
PURPLE		 := \\033[0;35m
LPURPLE		 := \\033[1;35m
CYAN		 := \\033[0;36m
LCYAN		 := \\033[1;36m
LGRAY		 := \\033[0;37m
WHITE		 := \\033[1;37m
NOCOLOR		 := \\033[0m

#common
incProject 	  := \$(incPath)/\$(Project).h
incElement    := \$(incPath)/Elements/element.h
srcProject	  := \$(srcPath)/\$(Project).c
srcElement	  := \$(srcPath)/Elements/element.c
srcMain		  := \$(srcPath)/main.c

#int
intFlags     := \$(wFlag) -D _INT_
intBinPath	 := \$(binPath)/int
intObjPath	 := \$(objPath)/int
intObjects   := \$(intObjPath)/\$(Project).o \$(intObjPath)/element.o
intBinary	 := \$(Project).int

#float
floatFlags   := \$(wFlag) -D _FLOAT_
floatBinPath := \$(binPath)/float
floatObjPath := \$(objPath)/float
floatObjects := \$(floatObjPath)/\$(Project).o \$(floatObjPath)/element.o
floatBinary  := \$(Project).float

srcElement	 := \$(srcPath)/Elements

build: cleanEasy int float makeDoc

int: intObj
	@[ -d \${intBinPath}   ] || mkdir -p \${intBinPath}
	@\${CC} \${intFlags} -o \${intBinPath}/\${intBinary} \${srcMain} \${intObjects}
	@echo "\${GREEN}Successfuly compiled \${RED}\${intBinary} \${NOCOLOR}  : see \$\${PWD}/\${intBinPath}"

float: floatObj
	@[ -d \${floatBinPath} ] || mkdir -p \${floatBinPath}
	@\${CC} \${floatFlags} -o \${floatBinPath}/\${floatBinary} \${srcMain} \${floatObjects}
	@echo "\${GREEN}Successfuly compiled \${RED}\${floatBinary} \${NOCOLOR}: see \$\${PWD}/\${floatBinPath}"

intObj:
	@[ -d \${intObjPath}   ] || mkdir -p \${intObjPath}
	@\${CC} \${intFlags} -c \${srcElement} -o \${intObjPath}/element.o
	@\${CC} \${intFlags} -c \${srcProject} -o \${intObjPath}/\${Project}.o

floatObj:
	@[ -d \${floatObjPath} ] || mkdir -p \${floatObjPath}
	@\${CC} \${floatFlags} -c \${srcElement} -o \${floatObjPath}/element.o
	@\${CC} \${floatFlags} -c \${srcProject} -o \${floatObjPath}/\${Project}.o

makeDoc:
	@echo "Run \${PURPLE}make doc\${NOCOLOR} to create \${BLUE}documentation\${NOCOLOR}."

doc:
	@[ -d \${docPath} ] || mkdir -p \${docPath}
	@echo "\${RED}Generating latex...\${NOCOLOR}"
	@doxygen Doxyfile
	@echo "\${RED}Generating pdf...\${NOCOLOR}"
	@cd \${docPath}/latex; make refman.pdf
	@cp \${docPath}/latex/refman.pdf \${docPath}/\${docName}.pdf
	@echo "\${GREEN}Successfuly generated \${RED}\${docName}.pdf\${NOCOLOR} @ \$\${PWD}/\${docPath}"

cleanEasy:
	@[ ! -d \${intBinPath}   ] || rm -f \${intBinPath}/*
	@[ ! -d \${intObjPath}   ] || rm -f \${intObjPath}/*
	@[ ! -d \${floatBinPath} ] || rm -f \${floatBinPath}/*
	@[ ! -d \${floatObjPath} ] || rm -f \${floatObjPath}/*

clean:
	@rm -rf \${binPath} \${objPath} \${docPath}

EOF6

#Doxygen...
cat << EOF7 > Doxyfile
#---------------------------------------------------------------------------
# Project related configuration options
#---------------------------------------------------------------------------

DOXYFILE_ENCODING      = UTF-8
PROJECT_NAME           = "${ProjectName}s"
PROJECT_NUMBER         = "1.0"
PROJECT_BRIEF          = "Une implementation de $ProjectName en C"
PROJECT_LOGO           =
OUTPUT_DIRECTORY       = "doc"
CREATE_SUBDIRS         = NO
ALLOW_UNICODE_NAMES    = NO
OUTPUT_LANGUAGE        = French
BRIEF_MEMBER_DESC      = YES
REPEAT_BRIEF           = YES
ABBREVIATE_BRIEF       = "The \$name class" \\
                         "The \$name widget" \\
                         "The \$name file" \\
                         is \\
                         provides \\
                         specifies \\
                         contains \\
                         represents \\
                         a \\
                         an \\
                         the
ALWAYS_DETAILED_SEC    = NO
INLINE_INHERITED_MEMB  = NO
FULL_PATH_NAMES        = NO
STRIP_FROM_PATH        =
STRIP_FROM_INC_PATH    =
SHORT_NAMES            = NO
JAVADOC_AUTOBRIEF      = NO
QT_AUTOBRIEF           = NO
MULTILINE_CPP_IS_BRIEF = NO
INHERIT_DOCS           = YES
SEPARATE_MEMBER_PAGES  = NO
TAB_SIZE               = 4
ALIASES                =
TCL_SUBST              =
OPTIMIZE_OUTPUT_FOR_C  = YES
OPTIMIZE_OUTPUT_JAVA   = NO
OPTIMIZE_FOR_FORTRAN   = NO
OPTIMIZE_OUTPUT_VHDL   = NO
EXTENSION_MAPPING      =
MARKDOWN_SUPPORT       = YES
TOC_INCLUDE_HEADINGS   = 0
AUTOLINK_SUPPORT       = YES
BUILTIN_STL_SUPPORT    = NO
CPP_CLI_SUPPORT        = NO
SIP_SUPPORT            = NO
IDL_PROPERTY_SUPPORT   = YES
DISTRIBUTE_GROUP_DOC   = NO
GROUP_NESTED_COMPOUNDS = NO
SUBGROUPING            = YES
INLINE_GROUPED_CLASSES = NO
INLINE_SIMPLE_STRUCTS  = YES
TYPEDEF_HIDES_STRUCT   = NO
LOOKUP_CACHE_SIZE      = 0

#---------------------------------------------------------------------------
# Build related configuration options
#---------------------------------------------------------------------------

EXTRACT_ALL            = YES
EXTRACT_PRIVATE        = NO
EXTRACT_PACKAGE        = NO
EXTRACT_STATIC         = YES
EXTRACT_LOCAL_CLASSES  = YES
EXTRACT_LOCAL_METHODS  = NO
EXTRACT_ANON_NSPACES   = NO
HIDE_UNDOC_MEMBERS     = NO
HIDE_UNDOC_CLASSES     = NO
HIDE_FRIEND_COMPOUNDS  = NO
HIDE_IN_BODY_DOCS      = NO
INTERNAL_DOCS          = NO
CASE_SENSE_NAMES       = NO
HIDE_SCOPE_NAMES       = NO
HIDE_COMPOUND_REFERENCE= NO
SHOW_INCLUDE_FILES     = YES
SHOW_GROUPED_MEMB_INC  = NO
FORCE_LOCAL_INCLUDES   = NO
INLINE_INFO            = YES
SORT_MEMBER_DOCS       = NO
SORT_BRIEF_DOCS        = NO
SORT_MEMBERS_CTORS_1ST = NO
SORT_GROUP_NAMES       = NO
SORT_BY_SCOPE_NAME     = NO
STRICT_PROTO_MATCHING  = NO
GENERATE_TODOLIST      = YES
GENERATE_TESTLIST      = YES
GENERATE_BUGLIST       = YES
GENERATE_DEPRECATEDLIST= YES
ENABLED_SECTIONS       =
MAX_INITIALIZER_LINES  = 30
SHOW_USED_FILES        = YES
SHOW_FILES             = YES
SHOW_NAMESPACES        = YES
FILE_VERSION_FILTER    =
LAYOUT_FILE            =
CITE_BIB_FILES         =

#---------------------------------------------------------------------------
# Configuration options related to warning and progress messages
#---------------------------------------------------------------------------

QUIET                  = NO
WARNINGS               = YES
WARN_IF_UNDOCUMENTED   = YES
WARN_IF_DOC_ERROR      = YES
WARN_NO_PARAMDOC       = NO
WARN_AS_ERROR          = NO
WARN_FORMAT            = "\$file:\$line: \$text"
WARN_LOGFILE           =

#---------------------------------------------------------------------------
# Configuration options related to the input files
#---------------------------------------------------------------------------

INPUT                  =
INPUT_ENCODING         = UTF-8
FILE_PATTERNS          = *.c \\
                         *.cc \\
                         *.cxx \\
                         *.cpp \\
                         *.c++ \\
                         *.java \\
                         *.ii \\
                         *.ixx \\
                         *.ipp \\
                         *.i++ \\
                         *.inl \\
                         *.idl \\
                         *.ddl \\
                         *.odl \\
                         *.h \\
                         *.hh \\
                         *.hxx \\
                         *.hpp \\
                         *.h++ \\
                         *.cs \\
                         *.d \\
                         *.php \\
                         *.php4 \\
                         *.php5 \\
                         *.phtml \\
                         *.inc \\
                         *.m \\
                         *.markdown \\
                         *.md \\
                         *.mm \\
                         *.dox \\
                         *.py \\
                         *.pyw \\
                         *.f90 \\
                         *.f95 \\
                         *.f03 \\
                         *.f08 \\
                         *.f \\
                         *.for \\
                         *.tcl \\
                         *.vhd \\
                         *.vhdl \\
                         *.ucf \\
                         *.qsf
RECURSIVE              = YES
EXCLUDE                =
EXCLUDE_SYMLINKS       = NO
EXCLUDE_PATTERNS       =
EXCLUDE_SYMBOLS        =
EXAMPLE_PATH           =
EXAMPLE_PATTERNS       = *
EXAMPLE_RECURSIVE      = NO
IMAGE_PATH             =
INPUT_FILTER           =
FILTER_PATTERNS        =
FILTER_SOURCE_FILES    = NO
FILTER_SOURCE_PATTERNS =
USE_MDFILE_AS_MAINPAGE =

#---------------------------------------------------------------------------
# Configuration options related to source browsing
#---------------------------------------------------------------------------

SOURCE_BROWSER         = NO
INLINE_SOURCES         = NO
STRIP_CODE_COMMENTS    = YES
REFERENCED_BY_RELATION = NO
REFERENCES_RELATION    = NO
REFERENCES_LINK_SOURCE = YES
SOURCE_TOOLTIPS        = YES
USE_HTAGS              = NO
VERBATIM_HEADERS       = YES

#---------------------------------------------------------------------------
# Configuration options related to the alphabetical class index
#---------------------------------------------------------------------------

ALPHABETICAL_INDEX     = NO
COLS_IN_ALPHA_INDEX    = 5
IGNORE_PREFIX          =

#---------------------------------------------------------------------------
# Configuration options related to the HTML output
#---------------------------------------------------------------------------

GENERATE_HTML          = NO
HTML_OUTPUT            = html
HTML_FILE_EXTENSION    = .html
HTML_HEADER            =
HTML_FOOTER            =
HTML_STYLESHEET        =
HTML_EXTRA_STYLESHEET  =
HTML_EXTRA_FILES       =
HTML_COLORSTYLE_HUE    = 220
HTML_COLORSTYLE_SAT    = 100
HTML_COLORSTYLE_GAMMA  = 80
HTML_TIMESTAMP         = NO
HTML_DYNAMIC_SECTIONS  = NO
HTML_INDEX_NUM_ENTRIES = 100
GENERATE_DOCSET        = NO
DOCSET_FEEDNAME        = "Doxygen generated docs"
DOCSET_BUNDLE_ID       = org.doxygen.Project
DOCSET_PUBLISHER_ID    = org.doxygen.Publisher
DOCSET_PUBLISHER_NAME  = Publisher
GENERATE_HTMLHELP      = NO
CHM_FILE               =
HHC_LOCATION           =
GENERATE_CHI           = NO
CHM_INDEX_ENCODING     =
BINARY_TOC             = NO
TOC_EXPAND             = NO
GENERATE_QHP           = NO
QCH_FILE               =
QHP_NAMESPACE          = org.doxygen.Project
QHP_VIRTUAL_FOLDER     = doc
QHP_CUST_FILTER_NAME   =
QHP_CUST_FILTER_ATTRS  =
QHP_SECT_FILTER_ATTRS  =
QHG_LOCATION           =
GENERATE_ECLIPSEHELP   = NO
ECLIPSE_DOC_ID         = org.doxygen.Project
DISABLE_INDEX          = NO
GENERATE_TREEVIEW      = NO
ENUM_VALUES_PER_LINE   = 4
TREEVIEW_WIDTH         = 250
EXT_LINKS_IN_WINDOW    = NO
FORMULA_FONTSIZE       = 10
FORMULA_TRANSPARENT    = YES
USE_MATHJAX            = NO
MATHJAX_FORMAT         = HTML-CSS
MATHJAX_RELPATH        = http://cdn.mathjax.org/mathjax/latest
MATHJAX_EXTENSIONS     =
MATHJAX_CODEFILE       =
SEARCHENGINE           = YES
SERVER_BASED_SEARCH    = NO
EXTERNAL_SEARCH        = NO
SEARCHENGINE_URL       =
SEARCHDATA_FILE        = searchdata.xml
EXTERNAL_SEARCH_ID     =
EXTRA_SEARCH_MAPPINGS  =

#---------------------------------------------------------------------------
# Configuration options related to the LaTeX output
#---------------------------------------------------------------------------

GENERATE_LATEX         = YES
LATEX_OUTPUT           = latex
LATEX_CMD_NAME         = latex
MAKEINDEX_CMD_NAME     = makeindex
COMPACT_LATEX          = NO
PAPER_TYPE             = a4
EXTRA_PACKAGES         =
LATEX_HEADER           =
LATEX_FOOTER           =
LATEX_EXTRA_STYLESHEET =
LATEX_EXTRA_FILES      =
PDF_HYPERLINKS         = YES
USE_PDFLATEX           = YES
LATEX_BATCHMODE        = NO
LATEX_HIDE_INDICES     = NO
LATEX_SOURCE_CODE      = NO
LATEX_BIB_STYLE        = plain
LATEX_TIMESTAMP        = NO

#---------------------------------------------------------------------------
# Configuration options related to the RTF output
#---------------------------------------------------------------------------

GENERATE_RTF           = NO
RTF_OUTPUT             = rtf
COMPACT_RTF            = NO
RTF_HYPERLINKS         = NO
RTF_STYLESHEET_FILE    =
RTF_EXTENSIONS_FILE    =
RTF_SOURCE_CODE        = NO

#---------------------------------------------------------------------------
# Configuration options related to the man page output
#---------------------------------------------------------------------------

GENERATE_MAN           = NO
MAN_OUTPUT             = man
MAN_EXTENSION          = .3
MAN_SUBDIR             =
MAN_LINKS              = NO

#---------------------------------------------------------------------------
# Configuration options related to the XML output
#---------------------------------------------------------------------------

GENERATE_XML           = NO
XML_OUTPUT             = xml
XML_PROGRAMLISTING     = YES

#---------------------------------------------------------------------------
# Configuration options related to the DOCBOOK output
#---------------------------------------------------------------------------

GENERATE_DOCBOOK       = NO
DOCBOOK_OUTPUT         = docbook
DOCBOOK_PROGRAMLISTING = NO

#---------------------------------------------------------------------------
# Configuration options for the AutoGen Definitions output
#---------------------------------------------------------------------------

GENERATE_AUTOGEN_DEF   = NO

#---------------------------------------------------------------------------
# Configuration options related to the Perl module output
#---------------------------------------------------------------------------

GENERATE_PERLMOD       = NO
PERLMOD_LATEX          = NO
PERLMOD_PRETTY         = YES
PERLMOD_MAKEVAR_PREFIX =

#---------------------------------------------------------------------------
# Configuration options related to the preprocessor
#---------------------------------------------------------------------------

ENABLE_PREPROCESSING   = YES
MACRO_EXPANSION        = NO
EXPAND_ONLY_PREDEF     = NO
SEARCH_INCLUDES        = YES
INCLUDE_PATH           =
INCLUDE_FILE_PATTERNS  =
PREDEFINED             =
EXPAND_AS_DEFINED      =
SKIP_FUNCTION_MACROS   = YES

#---------------------------------------------------------------------------
# Configuration options related to external references
#---------------------------------------------------------------------------

TAGFILES               =
GENERATE_TAGFILE       =
ALLEXTERNALS           = NO
EXTERNAL_GROUPS        = YES
EXTERNAL_PAGES         = YES
PERL_PATH              = /usr/bin/perl

#---------------------------------------------------------------------------
# Configuration options related to the dot tool
#---------------------------------------------------------------------------

CLASS_DIAGRAMS         = YES
MSCGEN_PATH            =
DIA_PATH               =
HIDE_UNDOC_RELATIONS   = YES
HAVE_DOT               = NO
DOT_NUM_THREADS        = 0
DOT_FONTNAME           = Helvetica
DOT_FONTSIZE           = 10
DOT_FONTPATH           =
CLASS_GRAPH            = YES
COLLABORATION_GRAPH    = YES
GROUP_GRAPHS           = YES
UML_LOOK               = NO
UML_LIMIT_NUM_FIELDS   = 10
TEMPLATE_RELATIONS     = NO
INCLUDE_GRAPH          = YES
INCLUDED_BY_GRAPH      = YES
CALL_GRAPH             = NO
CALLER_GRAPH           = NO
GRAPHICAL_HIERARCHY    = YES
DIRECTORY_GRAPH        = YES
DOT_IMAGE_FORMAT       = png
INTERACTIVE_SVG        = NO
DOT_PATH               =
DOTFILE_DIRS           =
MSCFILE_DIRS           =
DIAFILE_DIRS           =
PLANTUML_JAR_PATH      =
PLANTUML_CFG_FILE      =
PLANTUML_INCLUDE_PATH  =
DOT_GRAPH_MAX_NODES    = 50
MAX_DOT_GRAPH_DEPTH    = 0
DOT_TRANSPARENT        = NO
DOT_MULTI_TARGETS      = NO
GENERATE_LEGEND        = YES
DOT_CLEANUP            = YES

EOF7
