#include <boost/interprocess/ipc/message_queue.hpp>
#include <iostream>

int main() {
  try {
    boost::interprocess::message_queue::remove("task-queue");
    std::cout << "Removed task-queue" << std::endl;
  } catch (boost::interprocess::interprocess_exception &ex) {
    std::cout << "Error: " << ex.what() << std::endl;
    return 1;
  }

  return 0;
}
