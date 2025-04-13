#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>


void fillVec(std::vector<int>& vec, int size)
{
    for (int i = 0; i < size; ++i)
    {
        vec[i] = 100;
    }
}

int vectorSumViaOneThread(std::vector<int>& vec)
{
    int sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        sum += vec[i];
    }
    return sum;
}

void sumPart(std::vector<int>& vec, int start, int end, int& sum)
{
    sum = 0;
    for (int i = start; i < end; ++i) 
    {
        sum += vec[i];
    }
}

int vectorSumViaTwoThreads(std::vector<int>& vec)
{
    int sum1 = 0;
    int sum2 = 0;

    std::thread t1(sumPart, std::ref(vec), 0, vec.size() / 2, std::ref(sum1));
    std::thread t2(sumPart, std::ref(vec), vec.size() / 2, vec.size(), std::ref(sum2));

    t1.join();
    t2.join();

    return sum1 + sum2;
}


int vectorSumViaSixThreads(std::vector<int>& vec)
{
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    int sum4 = 0;
    int sum5 = 0;
    int sum6 = 0;

    int partSize = vec.size() / 6;

    std::thread t1(sumPart, std::ref(vec), 0, partSize, std::ref(sum1));
    std::thread t2(sumPart, std::ref(vec), partSize, 2 * partSize, std::ref(sum2));
    std::thread t3(sumPart, std::ref(vec), 2 * partSize, 3 * partSize, std::ref(sum3));
    std::thread t4(sumPart, std::ref(vec), 3 * partSize, 4 * partSize, std::ref(sum4));
    std::thread t5(sumPart, std::ref(vec), 4 * partSize, 5 * partSize, std::ref(sum5));
    std::thread t6(sumPart, std::ref(vec), 5 * partSize, vec.size(), std::ref(sum6));

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();

    return sum1 + sum2 + sum3 + sum4 + sum5 + sum6;
}

int vectorSumViaTwelveThreads(std::vector<int>& vec) 
{
    int sum[12] = { 0 }; 

    int partSize = vec.size() / 12;

    std::thread t1(sumPart, std::ref(vec), 0, partSize, std::ref(sum[0]));
    std::thread t2(sumPart, std::ref(vec), partSize, 2 * partSize, std::ref(sum[1]));
    std::thread t3(sumPart, std::ref(vec), 2 * partSize, 3 * partSize, std::ref(sum[2]));
    std::thread t4(sumPart, std::ref(vec), 3 * partSize, 4 * partSize, std::ref(sum[3]));
    std::thread t5(sumPart, std::ref(vec), 4 * partSize, 5 * partSize, std::ref(sum[4]));
    std::thread t6(sumPart, std::ref(vec), 5 * partSize, 6 * partSize, std::ref(sum[5]));
    std::thread t7(sumPart, std::ref(vec), 6 * partSize, 7 * partSize, std::ref(sum[6]));
    std::thread t8(sumPart, std::ref(vec), 7 * partSize, 8 * partSize, std::ref(sum[7]));
    std::thread t9(sumPart, std::ref(vec), 8 * partSize, 9 * partSize, std::ref(sum[8]));
    std::thread t10(sumPart, std::ref(vec), 9 * partSize, 10 * partSize, std::ref(sum[9]));
    std::thread t11(sumPart, std::ref(vec), 10 * partSize, 11 * partSize, std::ref(sum[10]));
    std::thread t12(sumPart, std::ref(vec), 11 * partSize, vec.size(), std::ref(sum[11]));

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();
    t10.join();
    t11.join();
    t12.join();

    int totalSum = 0;
    for (int i = 0; i < 12; ++i) {
        totalSum += sum[i];
    }

    return totalSum;
}

int main() 
{
    long int SIZE = 1000000000;
    std::vector<int> vec(SIZE);
    fillVec(vec, SIZE);


    // 1 thread
    auto start = std::chrono::high_resolution_clock::now();
    vectorSumViaOneThread(vec);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time via 1 thread: " << duration.count() << " seconds" << std::endl;


    // 2 thread
    auto start1 = std::chrono::high_resolution_clock::now();
    vectorSumViaTwoThreads(vec);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration1 = end1 - start1;
    std::cout << "Time via 2 thread's: " << duration1.count() << " seconds" << std::endl;


    //6 Threads --------> std::thread::hardware_concurrency();
 
    auto start3 = std::chrono::high_resolution_clock::now();
    vectorSumViaSixThreads(vec);
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration3 = end3 - start3;
    std::cout << "Time via 6 thread's: " << duration3.count() << " seconds" << std::endl;


    //12 Threads ------- std::thread::hardware_concurrency();
    auto start4 = std::chrono::high_resolution_clock::now();
    vectorSumViaTwelveThreads(vec);
    auto end4 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration4 = end4 - start4;
    std::cout << "Time via 12 thread's: " << duration4.count() << " seconds" << std::endl;
}