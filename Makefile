CC = gcc -Wall -Wextra
LINKS = -lm
SANITIZERS = -g -fsanitize=address -fsanitize=leak
LIBS = -lSDL2

galaxy_exe: galaxy_main.o galaxy.o vector.o gfx.o molecules.o
	$(CC) $^ -o $@ $(LINKS) $(SANITIZERS) $(LIBS)

galaxy_main.o: galaxy_main.c
	$(CC) $^ -c $<

galaxy.o: galaxy.c
	$(CC) $^ -c $<

vector.o: libs/vector.c
	$(CC) $^ -c $<

gfx.o: libs/gfx.c
	$(CC) $^ -c $< 

molecules.o: libs/molecules.c 
	$(CC) $^ -c $<

clean:
	rm -f *.o 
	rm -f *.gch
	rm -f galaxy_exe

rebuild: 
	clean galaxy_exe

exe: 
	make
	./galaxy_exe &