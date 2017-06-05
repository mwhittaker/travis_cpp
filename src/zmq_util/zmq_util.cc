#include "zmq_util/zmq_util.h"

#include <iomanip>
#include <ios>

#include "glog/logging.h"

std::string message_to_string(const zmq::message_t& message) {
  return std::string(static_cast<const char*>(message.data()), message.size());
}

zmq::message_t string_to_message(const std::string& s) {
  zmq::message_t msg(s.size());
  memcpy(msg.data(), s.c_str(), s.size());
  return msg;
}

void send_string(const std::string& s, zmq::socket_t* socket) {
  CHECK_NOTNULL(socket);
  socket->send(string_to_message(s));
}

std::string recv_string(zmq::socket_t* socket) {
  CHECK_NOTNULL(socket);
  zmq::message_t message;
  socket->recv(&message);
  return message_to_string(message);
}
