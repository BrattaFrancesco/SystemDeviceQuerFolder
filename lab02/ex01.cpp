#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
#include <memory>

using namespace std;

struct ThreadNode{
    thread thr;
    vector<ThreadNode> children;
}