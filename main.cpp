#include <iostream>
#include <cstdlib>
#include <thread>
#include <vector>

void calcPrimes(long, long, int);

using namespace std;

int main (int argc, char* argv[]) {
    vector <std::thread*> threadsv;

    if(!(argc == 3)) {
        cout << "Wrong number of arguments, please call primus like this: " << endl
                  << "\tprimus <maximumNumber> <numberOfThreads>" << endl;
        return 1;
    }
    else {
	    int threads = atoi(argv[2]);
	    long totalMax = atoi(argv[1]);
	    long perThread = totalMax / threads;
	    cout << "Starting with " << threads << " threads, calculating up to " <<  totalMax << std::endl;
	    for (int t = 0; t < threads; t++){
		    threadsv.emplace_back(new thread(calcPrimes, perThread * (t + 1) - perThread, perThread * (t + 2) - perThread, t));
	    }
	    for (std::thread* thread : threadsv) {
		    thread->join();
	    }
	    for (std::thread* thread : threadsv) {
		    delete thread;
	    }
	    cout << "All " << threads << " threads finished, exiting" << endl;
	    return 0;
    }
}

void calcPrimes(long start, long finish, int threadID){
	int maxNumber = finish;
    int currentNumber = start;
    while(currentNumber <= maxNumber) {
            bool isPrime = true;
            for (int i = 2; i < currentNumber; i++){
                    if((currentNumber % i) == 0) isPrime = false;
            }         
            currentNumber++;
    }
}
