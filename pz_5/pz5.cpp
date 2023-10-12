#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool isValueReached = false;

void thread1()
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return isValueReached; });
        std::cout << "����� 1: �������� ��������\n";
        isValueReached = false;
        lock.unlock();
        cv.notify_one();
    }
}

void thread2()
{
    int value = 1;
    while (value < 100)
    {
        std::unique_lock<std::mutex> lock(mtx);
        if (value == 42)
        {
            std::cout << "����� 2: ���������� ����������� ��������, ��������� ����������\n";
            std::terminate();
        }
        std::cout << "����� 2: ������������ ���������� - " << value << "\n";
        value++;
        isValueReached = true;
        lock.unlock();
        cv.notify_one();
    }
}

int main()
{
    setlocale(LC_ALL, "Russian"); 
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();

    return 0;
}