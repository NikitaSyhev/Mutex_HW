//Этот проект создан с помощью классического шаблона
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

template <class T>
class Queqe {
public:
	T pop(const T &var){
		std::lock_guard<std::mutex> lock(_mutex);
		return _queue.pop(var);
	};

	T  push(const T &var){
		std::lock_guard<std::mutex> lock(_mutex);
		return _queue.push(var);
	};

	 void front(const T &var) {
		_mutex.lock();
		 _queue.front(var);
	};

 bool empty(const int element) {
	 std::lock_guard<std::mutex> lock(_mutex);
	 return _queue.empty(element);
	};
private:
	std::mutex _mutex;
	std::queue <T> _queue;
};


int main() {

	Queqe <int> queue;

	//queue.pop(5);
	//queue.push(55);
	//queue.empty(1);


	std::thread t1 = std::thread([&queue]() {
		std::string threadName = "t1";
		queue.front(1);
		});

	std::thread t2 = std::thread([&queue]() {
		std::string threadName = "t2";
		queue.front(1);
		});


	t1.join(); t2.join();
















	return 0;
}