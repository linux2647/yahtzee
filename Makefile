# vi: set noexpandtab
# 
# Makefile based off of Tia Newhall's documentation on how to write a Makefile
# http://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html

TARGET=yahtzee

.PHONY: depend clean

all: $(TARGET)

$(TARGET): 
	cd src && $(MAKE) && mv $(TARGET) ..

clean:
	$(RM) $(TARGET) && cd src && $(MAKE) clean

depend: 
	cd src && $(MAKE) depend

# DO NOT DELETE THIS LINE -- make depend needs it
