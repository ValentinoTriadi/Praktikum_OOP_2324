#include "Weed.hpp"
using namespace std;

Weed::Weed() {
    many = 1;
}

Weed::Weed(int n) {
    many = n;
}

Weed::Weed(const Weed &b) {
    this->many = b.many;
}

Weed::~Weed() {
}

void Weed::step() {
    for (int i = 0; i < many; i++) {
        cout << "kresek...";
    }
    cout << endl;
}