CXX=g++

objects=class_A.o \
	class_B.o \
	class_C.o \
	main.o

all: $(objects)
	$(CXX) -o inherit $(objects)

clean:
	rm $(objects) inherit

main.o: class_A.h class_B.h class_C.h
class_A.o: class_A.h
class_B.o: class_B.h
class_C.o: class_C.h
