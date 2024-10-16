#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {

    if(argc != 2) {
        cout << "Usage: ./parser <file>" << endl;
        exit(1);
    }

    freopen(argv[1], "r", stdin);
    string line;

    while(getline(cin, bio)) {

    }

}

