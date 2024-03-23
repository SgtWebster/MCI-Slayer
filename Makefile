all: prototyp3

prototyp3: main.o GameConfig.o character.o item.o inventory.o hero.o npc.o fighter.o sorcerer.o
	g++ -o prototyp3 main.o GameConfig.o character.o item.o inventory.o hero.o npc.o fighter.o sorcerer.o -Werror -Wall

main.o: main.cpp
	g++ -c -o main.o main.cpp

hero.o: hero.cpp
	g++ -c -o hero.o hero.cpp -Werror

character.o: character.cpp
	g++ -c -o character.o character.cpp -Werror

item.o: item.cpp
	g++ -c -o item.o item.cpp -Werror

GameConfig.o: GameConfig.cpp
	g++ -c -o GameConfig.o GameConfig.cpp -Werror

inventory.o: inventory.cpp
	g++ -c -o inventory.o inventory.cpp -Werror

schurke.o: npc.cpp
	g++ -c -o npc.o npc.cpp -Werror

fighter.o: fighter.cpp
	g++ -c -o fighter.o fighter.cpp -Werror

sorcerer.o: sorcerer.cpp
	g++ -c -o sorcerer.o sorcerer.cpp -Werror

clean:
	rm -f prototyp3 main.o hero.o character.o item.o GameConfig.o inventory.o npc.o fighter.o sorcerer.o