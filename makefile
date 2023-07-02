all:write read

write:write.cc contacts.pb.cc
	g++ -o $@ $^ -std=c++11 -lpthread -lprotobuf

read:read.cc contacts.pb.cc
	g++ -o $@ $^ -std=c++11 -lpthread -lprotobuf

.PHONY:clean
clean:
	rm -rf read write