//============================================================================
// Name        : test.cpp
// Author      : wenhan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

#include <thread>

using namespace std;

void fun(const boost::system::error_code& error) {

	if (!error) {
		cout << "timeout" << endl;
	} else {
		cout << "error" << endl;
	}
}

int main() {
	boost::asio::io_service ioservice;
	boost::asio::ip::tcp::socket sock(ioservice);
	boost::asio::ip::tcp::endpoint ep(boost::asio::ip::tcp::v4(), 20000);
	boost::asio::ip::tcp::acceptor ap(ioservice, ep);

	ioservice.run();

	boost::system::error_code ec;
	ap.accept(sock, ec);

	cout << "============" << endl;

	time_t t1, t2;
	char buff[1024] = { 0 };

	boost::asio::deadline_timer deadline(ioservice);
	cout << "============" << endl;
	deadline.expires_from_now(boost::posix_time::seconds(2));
	cout << "============" << endl;
	deadline.async_wait(fun);
	cout << "============" << endl;
	time(&t1);
	size_t size = sock.read_some(boost::asio::buffer(buff, 100));
	time(&t2);

	cout << t2 - t1 << endl;

	return 0;
}
