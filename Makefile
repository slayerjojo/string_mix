PROGRAM := mix
OBJDIR	:= obj
SRCEXTS := .c
CPPFLAGS := -g -Wall -fno-strict-aliasing
CFLAGS :=
CFLAGS +=
LDFLAGS := -lrt
LDFLAGS += -lm
LDFLAGS += -Wl,-Map,mapfile
CXX = LANG=C gcc
RM = rm -rf

SHELL = /bin/sh
SOURCES = $(shell find ./ -name "*.c")
OBJS = $(foreach x,$(SRCEXTS), $(patsubst ./%$(x),$(OBJDIR)/%.o,$(filter %$(x),$(SOURCES))))
OBJDIRS	= $(sort $(dir $(OBJS)))
DEPS = $(patsubst %.o,%.d,$(OBJS))

.PHONY : all clean debug data install doc

all : $(PROGRAM)

include $(DEPS)
$(OBJDIR)/%.d : %.c
	mkdir -p $(OBJDIR)
	$(CXX) -o $@  $(CPPFLAGS) -MM -MD -MT '$(OBJDIR)/$(patsubst %.cpp,%.o,$<)' $<
$(OBJDIR)/%.o : %.c
	$(CXX) -o $@ -c $(CPPFLAGS) $<
$(PROGRAM) : $(OBJS)
	$(CXX) -o $(PROGRAM) $(OBJS) $(LDFLAGS)


clean :
	$(RM) $(OBJDIR)/* $(PROGRAM) mapfile
doc:
	doxygen dox
debug:
	gdb $(PROGRAM)
