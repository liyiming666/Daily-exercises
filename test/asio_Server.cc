#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

using namespace std;

using boost::asio::ip::tcp;

class Connection: public boost::enable_shared_from_this<Connection> {
public:
    Connection(boost::asio::io_service& service) :
        sock(service) {
    }

    void start() {
        //        sock.async_read_some(boost::asio::buffer(buf), boost::bind(
        //                &Connection::handleRead, // ＃1
        //                shared_from_this(), boost::asio::placeholders::error));
        boost::asio::async_read(sock, boost::asio::buffer(buf),
                boost::asio::transfer_at_least(1), boost::bind(
                        &Connection::handleRead, // ＃1
                        shared_from_this(), boost::asio::placeholders::error));
    }

    tcp::socket& getSocket() {
        return sock;
    }

private:
    void handleRead(const boost::system::error_code& error) {
        if (!error) {
            cout << "recv from: " << sock.remote_endpoint().address() << ":" << sock.remote_endpoint().port() << endl;
            //            boost::asio::async_write(sock, boost::asio::buffer(buf),
            //                    boost::bind(
            //                            &Connection::handleWrite, // ＃2
            //                            shared_from_this(),
            //                            boost::asio::placeholders::error));
            sock.async_write_some(boost::asio::buffer(buf),
                    boost::bind(
                            &Connection::handleWrite, // ＃2
                            shared_from_this(),
                            boost::asio::placeholders::error));
        }
    }

    void handleWrite(const boost::system::error_code& error) {
        if (!error) {
            memset(buf, 0, 512); // 注意：重置buf
            sock.async_read_some(boost::asio::buffer(buf), boost::bind(
                    &Connection::handleRead, // ＃3
                    shared_from_this(), boost::asio::placeholders::error));
        }
    }

private:
    tcp::socket sock;
    char buf[512];
};

typedef boost::shared_ptr<Connection> ConnectionPtr;

class Server {
public:
    Server(boost::asio::io_service& service) :
        acceptor(service, tcp::endpoint(tcp::v4(), 30001)) {
        start();
    }

private:
    void start() {
        ConnectionPtr conn(new Connection(acceptor.get_io_service()));
        acceptor.async_accept(conn->getSocket(), boost::bind(
                &Server::handleAccept, this, conn,
                boost::asio::placeholders::error));
    }

    void handleAccept(ConnectionPtr con, const boost::system::error_code& error) {
        if (!error) {
            con->start();
            start();
        }
    }

private:
    tcp::acceptor acceptor;
};

int main() {
    try {
        boost::asio::io_service service;
        Server server(service);
        service.run(); // 注意：与同步I/O不同，异步I/O需要调用run()
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
