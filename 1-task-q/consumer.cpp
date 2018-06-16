#include <boost/interprocess/ipc/message_queue.hpp>
#include <iostream>

int main() {
  try {
    auto mq = std::make_unique<boost::interprocess::message_queue>(
        boost::interprocess::open_or_create, "task-queue", 1000, sizeof(int));

    unsigned int priority;
    boost::interprocess::message_queue::size_type recvd_size;

    int message;

    while (true) {
      mq->receive(&message, sizeof(message), recvd_size, priority);

      std::cout << "Consumed: " << message << std::endl;
    }

  } catch (boost::interprocess::interprocess_exception &ex) {
    std::cout << "Error: " << ex.what() << std::endl;
    return 1;
  }

  return 0;
}
