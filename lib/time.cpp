#include <ctime>
#include <iostream>
using namespace std;

int main() {
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );

    cout << now->tm_hour << endl
        << now->tm_min << endl
        << now->tm_sec
        << endl;

        int t1 = now->tm_min;
        cout << t1 << endl;
}
