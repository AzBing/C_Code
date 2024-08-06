.PHONY:all
all:my_server my_client

my_server:my_server.cc
	g++ -o $@ $^ -std=c++11
my_client:my_client.cc
	g++ -o $@ $^ -std=c++11

.PHONY:clean
clean:
	rm -f my_server my_client
