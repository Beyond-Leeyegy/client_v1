main: main.o game.o sprite.o map.o meta_data.o data_protocol.o network.o utils.o read_write_on_bit.o 
	g++ *.o -I./hsl -L./hsl  -lpthread -lhsl -lX11  -o  main -Wall -lrt
main.o:main.cpp main.hpp game.hpp linked_list.h client_structs.h network.h def.h utils.h data_protocal.h
	g++ main.cpp game.cpp network.cpp utils.cpp data_protocol.cpp  -c -Wall
sprite.o:sprite.cpp sprite.hpp
	g++ sprite.cpp -c -Wall
map.o:map.cpp map.hpp
	g++ map.cpp -c -Wall

game.o:sprite.hpp map.hpp client_structs.h data_protocal.h network.h  utils.h game.hpp 
	g++ game.cpp -c -Wall

meta_data.o:def.h meta_data.h read_write_on_bit.h
	g++ meta_data.cpp read_write_on_bit.cpp -c -Wall

data_protocol.o: utils.h game.hpp data_protocal.h meta_data.h client_structs.h
	g++ data_protocol.cpp -c -Wall

network.o: def.h client_structs.h network.h meta_data.h linked_list.h utils.h data_protocal.h
	g++ network.cpp -c -Wall

utils.o: def.h utils.h
	g++ utils.cpp -c -Wall

read_write_on_bit.o: read_write_on_bit.h read_write_on_bit.cpp
	g++ read_write_on_bit.cpp -c -Wall


clean:
	rm *.o -f
	rm *~ -f
	rm main

