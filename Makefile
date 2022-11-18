all: compile-and-run

build:
	cd build && cmake .. && make -j6 && ./main

compile-and-run:
	cd build && make -j6 && ./main

clean:
	cd build && make clean
