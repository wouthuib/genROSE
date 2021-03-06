## Makefile for C++ project using Boost
#
# @author Cedric "levif" Le Dillau
#
# Some notes:
# - Using ':=' instead of '=' assign the value at Makefile parsing time,
#   others are evaluated at usage time. This discards
# - Use ':set list' in Vi/Vim to show tabs (Ctrl-v-i force tab insertion)
#

# List to '.PHONY' all fake targets, those that are neither files nor folders.
# "all" and "clean" are good candidates.
.PHONY: all, clean

# Define the final program name
PROGNAME := WorldServer

# CXXFLAGS is used for C++ compilation options.
CXXFLAGS = -std=c++11

# LDFLAGS is used for linker (-g enables debug symbols)
LDFLAGS += -g -O3 -W -Wall -pedantic -Wpointer-arith -Wwrite-strings -Wno-long-long -lssl -lcrypt $(THREADSCXXFLAGS)

# List the project' sources to compile or let the Makefile recognize
# them for you using 'wildcard' function.
#
#SOURCES = simple_ls.cpp rawr.cpp converter.cpp
SOURCES = $(wildcard *.cpp)
SOURCES += ${wildcard ../common/*.cpp}
SOURCES += ${wildcard ../common/database/*.cpp}
SOURCES += ${wildcard ./quest/*.cpp}
SOURCES += ${wildcard ./aip/*.cpp}

# List the project' headers or let the Makefile recognize
# them for you using 'wildcard' function.
#
#HEADERS = simple_ls.h 2dquicksort.h rawr.h
HEADERS = $(wildcard %.h)
HEADERS += $(wildcard %.hpp)
HEADERS += ${wildcard ../common/*.h}
HEADERS += ${wildcard ../common/*.hpp}
HEADERS += ${wildcard ../common/database/*.h}
HEADERS += ${wildcard ../common/database/*.hpp}
HEADERS += ${wildcard /usr/include/mysql/*.h}
HEADERS += ${wildcard ./quest/*.h}
HEADERS += ${wildcard ./quest/*.hpp}
HEADERS += ${wildcard ./aip/*.h}
HEADERS += ${wildcard ./aip/*.hpp}

# Construct the list of object files based on source files using
# simple extension substitution.
OBJECTS = $(SOURCES:%.cpp=%.o)

#
# Now declare the dependencies rules and targets
#
# Starting with 'all' make it  becomes the default target when none 
# is specified on 'make' command line.
all : $(PROGNAME)

# Declare that the final program depends on all objects and the Makfile
$(PROGNAME) : $(OBJECTS) Makefile
	$(CXX) -o $@ $(LDFLAGS) $(OBJECTS) `mysql_config --cflags --libs` -lcrypto -lssl

# Now the choice of using implicit rules or not (my choice)...
#
# Choice 1: use implicit rules and then we only need to add some dependencies
#           to each object.
#
## Tells make that each object file depends on all headers and this Makefile.
#$(OBJECTS) : $(HEADERS) Makefile
#
# Choice 2: don't use implicit rules and specify our will
%.o: %.cpp $(HEADERS) Makefile
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(OUTPUT_OPTION) $<

# Simple clean-up target
# notes:
# - the '@' before 'echo' informs make to hide command invocation.
# - the '-' before 'rm' command to informs make to ignore errors.
clean :
	@echo "Clean."
	-rm -f *.o $(PROGNAME)
	-rm -f ../common/*.o $(PROGNAME)
	-rm -f ../common/database/*.o $(PROGNAME)
	-rm -f quest/*.o $(PROGNAME)
	-rm -f aip/*.o $(PROGNAME)
