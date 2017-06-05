#include <iostream>
#include <string>

#include "zmq.hpp"

#include "reverse/reverse.h"
#include "zmq_util/zmq_util.h"

int main() {
  zmq::context_t context(1);
  zmq::socket_t socket(context, ZMQ_REP);
  const std::string address = "tcp://*:5555";
  socket.bind(address);
  std::cout << "Server listening on '" << address << "'." << std::endl;

  for (int i = 0; true; i++) {
    std::string request = recv_string(&socket);
    std::cout << "Received '" << request << "'." << std::endl;
    std::string reversed = Reverse(std::move(request));
    send_string(reversed, &socket);
    std::cout << "Sent '" << reversed << "'." << std::endl;
  }
}
