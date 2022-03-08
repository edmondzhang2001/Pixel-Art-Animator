CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = a4q3
OBJECTS = studio.o asciiart.o decorator.o boxes.o blank.o main.o addtext.o subject.o observer.o addgraphics.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
