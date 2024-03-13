all: prototyp2

prototyp2: archive/main.o archive/hero.o archive/character.o archive/item.o
	g++ -o prototyp2 main.o hero.o character.o item.o gameconfig.o -Werror -Wall

main.o: main.cpp
	g++ -c -o main.o main.cpp

hero.o: hero.cpp
	g++ -c -o hero.o hero.cpp -Werror

character.o: character.cpp
	g++ -c -o character.o character.cpp -Werror

item.o: item.cpp
	g++ -c -o item.o item.cpp -Werror

gameconfig.o: gameconfig.cpp
	g++ -c -o gameconfig.o gameconfig.cpp -Werror

clean:
	rm -f prototyp2 main.o hero.o character.o item.o