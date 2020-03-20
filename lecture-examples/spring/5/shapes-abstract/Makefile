CXX=g++

objects=shape.o \
	circle.o \
	rectangle.o \
	main.o

all: $(objects)
	$(CXX) -o shaper $(objects)

clean:
	rm $(objects) shaper

main.o: shape.h circle.h rectangle.h
shape.o: shape.h
circle.o: shape.h circle.h
rectangle.o: shape.h rectangle.h

