#include <boost/interprocess/ipc/message_queue.hpp>
#include <chrono>
#include <iostream>
#include <thread>

int main() {
  try {
    auto mq = std::make_unique<boost::interprocess::message_queue>(
        boost::interprocess::open_or_create, "task-queue", 1000, sizeof(int));

    int counter = 0;

    while (true) {
      mq->send(&counter, sizeof(counter), 0);

      std::cout << "Published..." << counter << std::endl;

      std::this_thread::sleep_for(std::chrono::milliseconds(500));

      counter++;
    }
  } catch (boost::interprocess::interprocess_exception &ex) {
    std::cout << "Error: " << ex.what() << std::endl;
    return 1;
  }

  return 0;
}
