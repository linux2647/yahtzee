# vi: set noexpandtab
# 
# Makefile based off of Tia Newhall's documentation on how to write a Makefile
# http://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html

TARGET=yahtzee
CC=g++
CXXFLAGS=-g -Wall -std=c++11
CFLAGS=-g -Wall
SRCS=yahtzee.cpp die.cpp numeric.cpp upper_section.cpp lower_section.cpp \
		 n_ofa_kind.cpp full_house.cpp straight.cpp yahtzee_slot.cpp chance.cpp
OBJS=$(SRCS:.c=.o)
INCLUDES=-I../include
LFLAGS=
LIBS=

.PHONY: depend clean

all: $(TARGET)

$(TARGET): $(OBJS) 
	$(CC) $(CXXFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CXXFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o $(TARGET)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
