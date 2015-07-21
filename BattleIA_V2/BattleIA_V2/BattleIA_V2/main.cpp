#include "stdafx.h"

float Util::heigth = 100;
float Util::width = 100;

int main(void)
{
    std::srand(time(NULL));
    std::vector<Army* > champions;
    try {
        std::ifstream in("Army_10_100.save");
        Army army = Army::load(in);
        std::cout<<army<<std::endl;
        champions.push_back(new Army(army));
    } catch(...) {

    }
    Army* army = train(10,100, 20, 10, 100, champions);
    std::cout<<*army<<std::endl;
    std::ofstream out("Army_10_100.save");
    army->save(out);
    out.flush();
    out.close();
    return 0;
}