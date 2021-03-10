#include "art.hpp"
#include "zipf.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <unordered_map>
#include <chrono>
#include <thread>
#include <sys/time.h>

using namespace std;

art::art<int> m;

#define TESTNUM 1000000
string key[TESTNUM];
int value[TESTNUM] = {0};

void speedTest() {
    srand(time(0));
    for (int i = 0; i < TESTNUM; ++i) {
        key[i] = to_string(rand());
    }

    timeval start, ends;
    gettimeofday(&start, NULL);
    for (int i = 0; i < TESTNUM; ++i) {
        m.set(key[i].c_str(), &(value[i]));
    }
    gettimeofday(&ends, NULL);
    double timeCost = (ends.tv_sec - start.tv_sec) * 1000000 + ends.tv_usec - start.tv_usec;
    double throughPut = (double) TESTNUM / timeCost;
    cout << "Total Put " << TESTNUM << " kv pais in " << timeCost / 1000000 << " s" << endl;
    cout << "Total Put ThroughPut: " << throughPut << " Mops" << endl;
//    cout << throughPut << endl;
}

int main() {
    speedTest();
    return 0;
}
