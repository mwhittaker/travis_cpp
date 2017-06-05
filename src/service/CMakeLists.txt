CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_EXECUTABLE(service_client client.cc)
ADD_EXECUTABLE(service_server server.cc)
TARGET_LINK_LIBRARIES(service_client reverse zmq_util)
TARGET_LINK_LIBRARIES(service_server reverse zmq_util)
