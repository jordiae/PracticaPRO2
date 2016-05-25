CXX = g++
OPTIONS = -std=c++11 -O2 -DNDEBUG -D_GLIBCXX_DEBUG -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -Wshadow

program.exe: main.o Cjt_autors/*.o Cites/*.o Text/*.o
	$(CXX) -o $@ $^

main.o: main.cc
		$(CXX) -c $^ $(OPTIONS)

Cjt_autors.o: Cjt_autors/*.cc
	$(CXX) -c $^ $(OPTIONS)

Cites.o: Cites/*.cc
	$(CXX) -c $^ $(OPTIONS)

Text.o: Text/*.cc
	$(CXX) -c $^ $(OPTIONS)

clean:
	rm *.o
	rm *.tar
	rm *.exe