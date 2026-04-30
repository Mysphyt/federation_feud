g++ -c -L.\include\SFML-3.0.2\lib -I.\include\SFML-3.0.2\include lib\main.cpp -DSFML_STATIC -o lib\main.o
g++ -c -L.\include\SFML-3.0.2\lib -I.\include\SFML-3.0.2\include lib\menu.cpp -DSFML_STATIC -o lib\menu.o
g++ -c -L.\include\SFML-3.0.2\lib -I.\include\SFML-3.0.2\include lib\event.cpp -DSFML_STATIC -o lib\event.o
g++ -c -L.\include\SFML-3.0.2\lib -I.\include\SFML-3.0.2\include lib\log.cpp -DSFML_STATIC -o lib\log.o
g++ lib\main.o lib\menu.o lib\event.o lib\log.o -o main -L.\include\SFML-3.0.2\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32
