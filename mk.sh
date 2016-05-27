g++ main.cc -c -std=c++11
cd Cites
g++ *.cc -c -I/$HOME/Documents/PracticaPRO2 -std=c++11
cd ..
cd Cjt_autors
g++ *.cc -c -I/$HOME/Documents/PracticaPRO2 -std=c++11
cd ..
cd Text
g++ *.cc -c -I/$HOME/Documents/PracticaPRO2 -std=c++11
cd ..
g++ -o program.x main.o $HOME/Documents/PracticaPRO2/Text/*.o $HOME/Documents/PracticaPRO2/Cites/*.o $HOME/Documents/PracticaPRO2/Cjt_autors/*.o
cd Text
rm *.o
cd ..
cd Cites
rm *.o
cd ..
cd Cjt_autors
rm *.o
cd ..
rm main.o