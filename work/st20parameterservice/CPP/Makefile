VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h src/st20parameterservice.h src/st20parameterservice.cc

compile-linux:
	mkdir -p obj && cd obj && g++ -c ../src/*.cc
