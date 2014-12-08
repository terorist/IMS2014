kravin: bin/kravin
	echo "Build complete"

ucebna: bin/ucebna
	echo "Build complete"

run:
	bin/kravin
	bin/ucebna

bin/kravin: kravin.cpp bin
	g++ kravin.cpp -pedantic -g -Wall -Wextra -o bin/kravin
	
bin/ucebna: ucebna.cpp bin
	g++ ucebna.cpp -pedantic -Wall -Wextra -o bin/ucebna

bin:
	mkdir bin
