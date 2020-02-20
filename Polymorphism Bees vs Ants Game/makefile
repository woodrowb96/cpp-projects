CC = g++
exe_file = game_exe
$(exe_file):driver.o Game.o Insect.o Bee.o Harvester.o Thrower.o Fire.o Long.o Short.o Wall.o Ninja.o Bodyguard.o helper_functions.o
	$(CC) driver.o Game.o Insect.o Bee.o Harvester.o Thrower.o Fire.o Long.o Short.o Wall.o Ninja.o Bodyguard.o helper_functions.o -o $(exe_file)
driver.o:driver.cpp Game.h 
	$(CC) -c driver.cpp
Game.o: Game.cpp Game.h Insect.h
	$(CC) -c Game.cpp
Insect.o:Insect.cpp Insect.h
	$(CC) -c Insect.cpp
Bee.o: Bee.cpp Bee.h Insect.h
	$(CC) -c Bee.cpp
Harvester.o: Harvester.cpp Harvester.h Insect.h
	$(CC) -c Harvester.cpp
Thrower.o: Thrower.cpp Thrower.h Insect.h
	$(CC) -c Thrower.cpp
Fire.o: Fire.cpp Fire.h Insect.h
	$(CC) -c Fire.cpp
Long.o: Long.cpp Long.h Insect.h
	$(CC) -c Long.cpp
Short.o: Short.cpp Short.h Insect.h
	$(CC) -c Short.cpp
Wall.o: Wall.cpp Wall.h Insect.h
	$(CC) -c Wall.cpp
Ninja.o: Ninja.cpp Ninja.h Insect.h 
	$(CC) -c Ninja.cpp
Bodyguard.o: Bodyguard.cpp Bodyguard.h Insect.h 
	$(CC) -c Bodyguard.cpp
helper_functions.o: helper_functions.cpp helper_functions.h
	$(CC) -c helper_functions.cpp
clean:
	rm -f *.out *.o $(exe_file)
