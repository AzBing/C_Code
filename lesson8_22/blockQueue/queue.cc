#include "BlockQueue.hpp"

void* Producer(void* arg)
{
	BlockQueue<Task>* bq = (BlockQueue<Task>*)arg;
	const char* arr = "+-*/%";
	//生产者不断进行生产
	while (true){
		int x = rand() % 100;
		int y = rand() % 100;
		char op = arr[rand() % 5];
		Task t(x, y, op);
		bq->Push(t); //生产数据
		std::cout << "producer task done" << std::endl;
	}
}
void* Consumer(void* arg)
{
	BlockQueue<Task>* bq = (BlockQueue<Task>*)arg;
	//消费者不断进行消费
	while (true){
		sleep(1);
		Task t;
		bq->Pop(t); //消费数据
		t.Run(); //处理数据
	}
}


// void* Producer(void* arg)
// {
// 	BlockQueue<int>* bq = (BlockQueue<int>*)arg;
// 	//生产者不断进行生产
// 	while (true){
// 		sleep(1);
// 		int data = rand() % 100 + 1;
// 		bq->Push(data); //生产数据
// 		std::cout << "Producer: " << data << std::endl;
// 	}
// }
// void* Consumer(void* arg)
// {
// 	BlockQueue<int>* bq = (BlockQueue<int>*)arg;
// 	//消费者不断进行消费
// 	while (true){
// 		int data = 0;
// 		bq->Pop(data); //消费数据
// 		std::cout << "Consumer: " << data << std::endl;
// 	}
// }

int main()
{
	srand((unsigned int)time(nullptr));
	pthread_t producer, consumer;
	BlockQueue<int>* bq = new BlockQueue<int>;
	//创建生产者线程和消费者线程
	pthread_create(&producer, nullptr, Producer, bq);
	pthread_create(&consumer, nullptr, Consumer, bq);

	//join生产者线程和消费者线程
	pthread_join(producer, nullptr);
	pthread_join(consumer, nullptr);

	delete bq;
	return 0;
}
