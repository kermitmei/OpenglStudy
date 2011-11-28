INCLUDE = -I/usr/include/
LIBDIR  = -L/usr/X11R6/lib 

COMPILERFLAGS = -Wall -g
CC = x86_64-pc-linux-gnu-gcc
CFLAGS = $(COMPILERFLAGS) $(INCLUDE)
LIBRARIES = -lX11 -lXi -lXmu -lglut -lGL -lGLU -lm 

# for all, set the targets to be every main1.c-main13.c 
# file, removing the .c extension.  That is, at this point,
# it would produce main1, main2, main3,...,main13 targets.
#
all: $(basename $(wildcard main[1-9].c main1[0-3].c))

# same as for all, except set the targets to be 
# mainX.tar.gz from mainX.c.  This is really
# only used to build smaller tutorial .tar.gz files
# to send to nehe.
#
dist: $(foreach file,$(basename $(wildcard main[1-9].c main1[0-3].c)),$(file).tar.gz)

# to produce, say, main1.tar.gz:
#
# 1. remove main1.tar.gz
# 2. build main1.tar containing README, makefile, main1.c, Data/main1/*.
# 3. gzip main1.tar.
#
main%.tar.gz : 
	tar cvf $(subst .tar.gz,.tar,$@) README makefile $(subst .tar.gz,.c,$@) $(wildcard Data/$(subst .tar.gz,,$@)/*); \
	gzip $(subst .tar.gz,.tar,$@);

# to produce, say, main1:
#
# 1. compile the thing.  uses the variables defined above.
# 
main% : main%.o
	$(CC) $(CFLAGS) -o $@ $(LIBDIR) $< $(LIBRARIES)  

# to clean up:
# delete all of the mainX files.
clean:
	rm $(wildcard main[1-9] main1[0-3])

# to clean up the distributions:
# delete all of the mainX.tar.gz files.
distclean:
	rm $(wildcard main[1-9].tar.gz main1[0-3].tar.gz)

