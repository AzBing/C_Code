.PHONY:all
all:udpserver udpclient

udpserver:main.cc
	g++ -o $@ $^ -std=c++11
udpclient:client.cc
	g++ -o $@ $^ -std=c++11

.PHONY:clean
clean:
	rm -f udpserver udpclient