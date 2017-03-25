// client.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

void* worker(zmq::context_t& context)
{

	zmq::socket_t socket(context, ZMQ_REQ);
	std::cout << "Connecting to hello world server..." << std::endl;
	socket.connect("tcp://localhost:5555");

	//  Do 10 requests, waiting each time for a response
	for (int request_nbr = 0; request_nbr != 10; request_nbr++) {
		zmq::message_t request(5);
		memcpy(request.data(), "Hello", 5);
		std::cout << "Sending Hello " << request_nbr << "..." << std::endl;
		socket.send(request);

		//  Get the reply.
		zmq::message_t reply;
		socket.recv(&reply);
		std::cout << "Received World " << request_nbr << std::endl;
	}

}

int main()
{
	boost::thread_group threads; // 1

	zmq::context_t context(1);

	for (int thread_nbr = 0; thread_nbr != 5; thread_nbr++) {
		threads.create_thread(boost::bind(&worker, boost::ref(context)));
	}

	threads.join_all();
}

