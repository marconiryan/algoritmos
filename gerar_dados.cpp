#include <ctime>
#include <iostream>
#include <unistd.h>

std::string gen_random(const int len) {
    static const char alphanum[] =
        "qtuepdpflpplfkoreofomf"
        "zxcvbnmasdfghjklasdnanisdn"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}

int main(int argc, char *argv[]) {
    srand((unsigned)time(NULL) * getpid());     
    long long i = 30000000;
    while(i--){
	std::cout << "1" << "\n";
    	std::cout << gen_random(29) << " 20/06/2022/" << " email@email" << " 99-9999999\n";
    }
    std::cout << "-1" << "\n";
    return 0;
}
