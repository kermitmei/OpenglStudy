INCLUDE = -I/usr/include/
LIBDIR  = -L/usr/X11R6/lib 

COMPILERFLAGS = -Wall -g
CC   = x86_64-pc-linux-gnu-gcc
CXX  = x86_64-pc-linux-gnu-g++
LINK = x86_64-pc-linux-gnu-g++
LFLAGS = -Wl,-O2 -Wl,-rpath,$(LIBDIR)

CXXFLAGS = $(COMPILERFLAGS) $(INCLUDE)
LIBRARIES = -lX11 -lXi -lXmu -lglut -lGL -lGLU -lm 


TARGET        = myBall

SOURCES       = glm.cpp main.cpp 
OBJECTS       = glm.o 	main.o

all: $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) $(INCPATH) -o $(TARGET) $(OBJECTS)  $(LIBRARIES)

glm.o: glm.cpp glm.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o glm.o glm.cpp

main.o: main.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

clean:
	rm $(TARGET) *.o
