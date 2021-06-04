VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h src/tc_handler.h src/tc_handler.cc

compile-linux:
	mkdir -p obj && cd obj && g++ -c ../src/*.cc
