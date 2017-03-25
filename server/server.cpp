// server.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

void *worker(zmq::context_t& context)
{
	zmq::socket_t socket(context, ZMQ_REP);
	socket.connect("inproc://workers");
	
	while(true){
		zmq::message_t request;
		socket.recv(&request);

		std::string data((char*)request.data(), (char*)request.data() + request.size());
		std::cout << "Recv request :[" << data << "]" << std::endl;

		boost::this_thread::sleep_for(boost::chrono::milliseconds(1000));

		zmq::message_t reply(data.length());
		memcpy((void*)reply.data(), "world", 6);
		socket.send(reply);
	}

	return (NULL);
}

int main(int argc, char** argv)
{
	boost::thread_group threads; // 1

	zmq::context_t context(1);
	zmq::socket_t clients(context, ZMQ_ROUTER);
	clients.bind("tcp://*:5555");

	zmq::socket_t workers(context, ZMQ_DEALER);
	workers.bind("inproc://workers");

	for (int thread_nbr = 0; thread_nbr != 5; thread_nbr++) {
		threads.create_thread(boost::bind(&worker, boost::ref(context)));
	}

	zmq::proxy(clients, workers, NULL);
	threads.join_all(); // 6
}