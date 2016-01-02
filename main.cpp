#include <iostream>
#include <cstdlib>
#include <climits>
#include <thread>
#include <vector>
#include <string.h>

int calcPrimes(long, long, int);
void startBench(int, long);
void startHeat();

using namespace std;

vector <std::thread*> threadsv;

int main (int argc, char* argv[]) {

    if((argc != 3) && (argc != 2)) {
        cout << "Wrong number of arguments, please call primus like this: " << endl
                  << "\tprimus <maximumNumber> <numberOfThreads>" << endl
                  << "for benchmarking, or" << endl
                  << "\tprimus heat [numberOfThreads]" << endl
                  << "for CPU heating" << endl;
        return 1;
    }
    else if (argc == 3 && strcmp(argv[1], "heat") != 0) {
	    int threads = atoi(argv[2]);
	    long totalMax = atoi(argv[1]);
        startBench(threads, totalMax);
    }
    else if (argc == 2 && strcmp(argv[1], "heat") == 0) {
        startHeat();
    }
    return 0;
}

void startBench(int threads, long maxNumber) {
    long perThread = maxNumber / threads;
    cout << "Starting with " << threads << " threads, calculating up to " <<  maxNumber << std::endl;
    for (int t = 0; t < threads; t++){
        threadsv.emplace_back(new thread(calcPrimes, perThread * (t + 1) - perThread, perThread * (t + 2) - perThread, t));
    }
    for (thread* thread : threadsv) {
        thread->join();
    }
    for (thread* thread : threadsv) {
        delete thread;
    }
    cout << "All " << threads << " threads finished, exiting" << endl;

}

void startHeat() {
    int cores = thread::hardware_concurrency();
    cout << "Starting heating with " << cores << " threads. These will caclulate up to: " << LONG_MAX << endl;
    for (int i = 0; i < cores; i++) {
        threadsv.emplace_back(new thread(calcPrimes, 4, LONG_MAX, i));
    }
    for (thread* thread : threadsv) {
        thread->join();
    }
    for (thread* thread : threadsv) {
        delete thread;
    }
    cout << "All " << cores << " threads finished, exiting" << endl;
}

int calcPrimes(long start, long finish, int threadID){
	int maxNumber = finish;
    int currentNumber = start;
    int primesFound = 0;
    while(currentNumber <= maxNumber) {
            for (int i = 2; i < currentNumber; i++){
                    if((currentNumber % i) == 0) primesFound++;
            }
            currentNumber++;
    }
    return primesFound;
}
