all: prototyp

prototyp: main.o hero.o character.o item.o
	g++ -o prototyp main.o hero.o character.o item.o -Werror -Wall

main.o: main.cpp
	g++ -c -o main.o main.cpp

hero.o: hero.cpp
	g++ -c -o hero.o hero.cpp -Werror

character.o: character.cpp
	g++ -c -o character.o character.cpp -Werror

item.o: item.cpp
	g++ -c -o item.o item.cpp -Werror

clean:
	rm -f prototyp main.o hero.o character.o item.o