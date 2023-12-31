all: compile link

compile:
	g++ -c main.cpp Momo.cpp Ground.cpp -ID:\Programmazione\SFML\SFML-2.6.1\include -DSFML_STATIC

link:
	g++ main.o Momo.o Ground.o -o main -LD:/Programmazione/SFML/SFML-2.6.1/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main

clear:
	rm -f main.exe *.o