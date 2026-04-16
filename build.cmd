g++ -c -L.\include\SFML-3.0.2\lib -I.\include\SFML-3.0.2\include lib\main.cpp -DSFML_STATIC -o lib\main.o
g++ -c -L.\include\SFML-3.0.2\lib -I.\include\SFML-3.0.2\include lib\menu.cpp -DSFML_STATIC -o lib\menu.o
g++ lib\main.o lib\menu.o -o main -L.\include\SFML-3.0.2\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32