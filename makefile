write:write.cc contacts.pb.cc
	g++ -o $@ $^ -std=c++11 -lpthread -lprotobuf
.PHONY:clean
clean:
	rm -rf main