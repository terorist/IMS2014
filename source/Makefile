test1: main.cpp mkbin
	g++ main.cpp -pedantic -Wall -Wextra -o bin/test1
	
test2: testStore.cpp mkbin
	g++ testStore.cpp -pedantic -Wall -Wextra -Werror -o bin/test2
mkbin:
	mkdir bin 2>/dev/null || echo "Slozka bin vytvorena"
