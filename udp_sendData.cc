#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

class server
{
public:
server(boost::asio::io_service& io_service, short port)
	: socket_(io_service, udp::endpoint(udp::v4(), port))
{
	socket_.async_receive_from(
	boost::asio::buffer(data_, max_length), sender_endpoint_,
	boost::bind(&server::handle_receive_from, this,
	boost::asio::placeholders::error,
	boost::asio::placeholders::bytes_transferred));
}

void handle_receive_from(const boost::system::error_code& error,
	size_t bytes_recvd)
{
	if (!error && bytes_recvd > 0)
	{
	char data[max_length]  = "hello";
		socket_.async_send_to(
		boost::asio::buffer(data, bytes_recvd), sender_endpoint_,
		boost::bind(&server::handle_send_to, this,
		boost::asio::placeholders::error,
		boost::asio::placeholders::bytes_transferred));
		std::cout << data_ << std::endl;
	}
	else
	{
		socket_.async_receive_from(
		boost::asio::buffer(data_, max_length), sender_endpoint_,
		boost::bind(&server::handle_receive_from, this,
		boost::asio::placeholders::error,
		boost::asio::placeholders::bytes_transferred));
	}
}

void handle_send_to(const boost::system::error_code& /*error*/,
	size_t /*bytes_sent*/)
{
	char data[max_length]  = "hello";
	socket_.async_receive_from(
		boost::asio::buffer(data_, max_length), sender_endpoint_,
		boost::bind(&server::handle_receive_from, this,
		boost::asio::placeholders::error,
		boost::asio::placeholders::bytes_transferred));
}

private:
	udp::socket socket_;
	udp::endpoint sender_endpoint_;
	enum { max_length = 1024 };
	char data_[max_length];
};

int main()
{
	try
	{
		boost::asio::io_service io_service;
		using namespace std; // For atoi.
		server s(io_service, 30001);
		io_service.run();
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}
	return 0;
}
