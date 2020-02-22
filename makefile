SOURCES := $(wildcard *.c)
OBJECTS := $(patsubst %.c,%.o,$(SOURCES))
DEPENDS := $(patsubst %.c,%.d,$(SOURCES))
CCFLAGS := -Tlinker.ld

# ADD MORE WARNINGS!
WARNING := -Wall -Wextra -Wno-ignored-qualifiers

# .PHONY means these rules get executed even if
# files of those names exist.
.PHONY: all clean

# The first rule is the default, ie. "make",
# "make all" and "make parking" mean the same
all: main 

clean: 
	$(RM) $(OBJECTS) $(DEPENDS) main 

# Linking the executable from the object files
main: $(OBJECTS)
	$(CC) $(WARNING) $(CCFLAGS) $^ -o $@

-include $(DEPENDS)

%.o: %.c makefile 
	$(CC) $(WARNING) $(CCFLAGS) -MMD -MP -c $< -o $@
