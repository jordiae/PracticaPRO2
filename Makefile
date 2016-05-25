CXX = g++
OPTIONS = -std=c++11 -O2 -DNDEBUG -D_GLIBCXX_DEBUG -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -Wshadow

program.exe: main.o *.o
	$(CXX) -o $@ $^ -I$(CURDIR) -IText -ICjt_autors -ICites

main.o: main.cc
		$(CXX) -c $^ $(OPTIONS)

Cjt_autors.o: *.cc
	cd Cjt_autors; $(CXX) -c $^ $(OPTIONS)

Cites.o: *.cc
	cd Cites; $(CXX) -c $^ $(OPTIONS)

Text.o: *.cc
	cd Text; $(CXX) -c $^ $(OPTIONS) -IText

clean:
	rm *.o
	rm *.tar
	rm *.exe