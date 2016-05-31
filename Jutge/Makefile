CXX = g++
OPTIONS = -std=c++11 -O2 -DNDEBUG -D_GLIBCXX_DEBUG -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -Wshadow

program.exe: Cites.o Cjt_autors.o program.o Text.o
	$(CXX) -o $@ $^

program.o: program.cc
		$(CXX) -c $^ $(OPTIONS)

Cites.o: Cites.cc
	$(CXX) -c $^ $(OPTIONS)

Cjt_autors.o: Cjt_autors.cc
	$(CXX) -c $^ $(OPTIONS)

Text.o: Text.cc
	$(CXX) -c $^ $(OPTIONS)

tar: 
	tar -cvf practica.tar *.cc *.hh Makefile

clean:
	rm *.o
	rm *.tar
	rm *.exe