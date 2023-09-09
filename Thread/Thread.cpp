#include <iostream>
#include <thread>
#include <vector>
using std::vector;
using std::thread;

void func1()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Thread1 Working!\n";
	}
}

void func2()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Thread2 working!\n";
	}
}

void func3()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Thread3 working!\n";
	}
}

void worker(vector<int>::iterator start, vector<int>::iterator end,
	int* result)
{
	int sum = 0;
	for (auto itr = start; itr < end; itr++)
	{
		sum += *itr;
	}
	
	*result = sum;
	thread::id this_id = std::this_thread::get_id();
	printf("쓰레드 %x에서 %d까지 계산한 결과: %d\n", this_id, *start, *(end - 1), sum);
}
int main()
{
	thread t1(func1);
	thread t2(func2);
	thread t3(func3);

	/*t1.join();
	t2.join();
	t3.join();*/
	
	t1.detach();
	t2.detach();
	t3.detach();

	vector<int> data(10000);
	for (int i = 0; i < 10000; i++)
	{
		data[i] = i;
	}

	vector<int> partial_sums(4);
	
	vector<thread> workers;
	for (int i = 0; i < 4; i++)
	{
		workers.push_back(thread(worker, data.begin() + i * 2500,
			data.begin() + (i + 1) * 2500, &partial_sums[i]));
	}

	for (int i = 0; i < 4; i++)
	{
		workers[i].join();
	}

	int total = 0;
	for (int i = 0; i < 4; i++)
	{
		total += partial_sums[i];
	}

	std::cout << "전체 합:  " << total << std::endl;
	
	std::cout << "main 함수 end" << std::endl;

	
		


	return 0;
}