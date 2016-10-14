#include <ctime>
#include <iostream>

using namespace std;

int main()
{//function-main open

    // get time now
    time_t t = time(0);

    //create structure to hold localtime
    struct tm * now = localtime( & t );
    int t1;

    //print formatted date
    cout <<  now->tm_mday << '-'
         << (now->tm_mon + 1) << '-'
         << (now->tm_year + 1900)
         << endl;

    t1 = now ->tm_mday;
    cout << t1 << endl;
    cout << t << endl;

}//function-main close
