#include <iostream>
#include <vector>
#include <random>
#include <functional> //for std::function
#include <algorithm>  //for std::generate_n

using namespace std;

//declaration of type built from vector
typedef vector<char> char_array;

char_array charset()
{//function-charset open

    //Can be changed to suit user
    return char_array(
    {'0','1','2','3','4',
    '5','6','7','8','9',
    'A','B','C','D','E','F',
    'G','H','I','J','K',
    'L','M','N','O','P',
    'Q','R','S','T','U',
    'V','W','X','Y','Z',
    'a','b','c','d','e','f',
    'g','h','i','j','k',
    'l','m','n','o','p',
    'q','r','s','t','u',
    'v','w','x','y','z'
    });

};//function-charset closed

//function to return string of requested length by generation of random characters
string random_string( size_t length, function<char(void)> rand_char )
{//function-random_string open

    string str(length,0);
    generate_n( str.begin(), length, rand_char );
    return str;

}//function-random_string close

int main()
{//function-main open

    //0) create the character set:
    //function is used over array, to keep the code cleaner and function more flexible
    const auto ch_set = charset();

    //1) create a non-deterministic random number generator
    default_random_engine rng(random_device{}());

    //2) create a random number "shaper" that gives
    //   uniformly distribution of indices into the character set
    uniform_int_distribution<> dist(0, ch_set.size()-1);

    //3) create a function that ties 1) and 2) together, to get:
    //   a non-deterministic uniform distribution from the
    //   character set of choice.
    auto randchar = [ ch_set,&dist,&rng ](){return ch_set[ dist(rng) ];};

    //4) set length of the wanted string and
    //  set profit
    auto length = 6;
    cout<<random_string(length,randchar)<<endl;
    return 0;

}//function-main close
