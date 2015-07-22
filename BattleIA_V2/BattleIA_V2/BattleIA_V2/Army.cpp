#include "stdafx.h"

void Army::copyUnits_(const std::vector<std::shared_ptr<Unit>>& units)
{
    units_.clear();
    for(auto it = units.begin(); it != units.end(); ++it) {
        units_.push_back(std::shared_ptr<Unit>(new Unit(*(*it))));
    }
}

Army::Army(int size, int level)
{
    while (size--) {
        std::string iaCode = Build::BuildIACode();
        std::cout << iaCode << std::endl << std::endl;

        units_.push_back(std::shared_ptr<Unit>(new Unit(level, iaCode))); //"?C1LDOPU<C1U!ALDOPU?aDOPU<a5O!MBO!ALDOPU"
    }
}

Army::Army(std::vector<std::shared_ptr<Unit>>& units)
{
    copyUnits_(units);
}


Army::Army(const Army& army)
{
    copyUnits_(army.units_);
}

void Army::swap(Army& army)
{
    std::swap(units_, army.units_);
}

Army& Army::operator=(Army army)
{
    swap(army);
    return *this;
}


Unit& Army::getNearestUnit(const Point& p)
{
    if(units_.empty())throw std::invalid_argument("empty army");
	std::shared_ptr<Unit> result = nullptr;
    float minDist = std::numeric_limits<float>::max();
    for(auto it = units_.begin(); it != units_.end(); ++it) {
        float d = (*it)->getPosition().distance(p);
        if(d < minDist) {
            minDist = d;
            result = *it;
        }
    }
    return *result;
}

Unit& Army::getFurthestUnit(const Point& p)
{
    if(units_.empty())throw std::invalid_argument("empty army");
	std::shared_ptr<Unit> result = nullptr;
    float maxDist = -1.0f;
    for(auto it = units_.begin(); it != units_.end(); ++it) {
        float d = (*it)->getPosition().distance(p);
        if(d > maxDist) {
            maxDist = d;
            result = *it;
        }
    }
    return *result;
}

Unit& Army::getLowestUnit(int capa_index)
{
    if(units_.empty())throw std::invalid_argument("empty army");
    return **std::min_element(units_.begin(), units_.end(),
    [&capa_index](std::shared_ptr<Unit> a, std::shared_ptr<Unit> b) {
        return a->getCapacity(capa_index)->getLevel() < b->getCapacity(capa_index)->getLevel();
    });
}

Unit& Army::getHigestUnit(int capa_index)
{
    if(units_.empty())throw std::invalid_argument("empty army");
    return **std::max_element(units_.begin(), units_.end(),
    [&capa_index](std::shared_ptr<Unit> a, std::shared_ptr<Unit> b) {
        return a->getCapacity(capa_index)->getLevel() < b->getCapacity(capa_index)->getLevel();
    });
}

void Army::purge()
{
    units_.erase(std::remove_if(units_.begin(), units_.end(),[](std::shared_ptr<Unit> u) {
        return !(u->isAlive());
    }), units_.end());
}

Army Army::mutate()const
{
    if(units_.size()==0)return Army(*this);
    Army mutated(*this);
    int count = 1+std::rand()%units_.size();
    while(count--) {
        if(std::rand()%3==0 || units_.size() == 1)
            mutated.units_[std::rand()%units_.size()] = std::shared_ptr<Unit>(new Unit(units_[0]->getLevel()));
        else if(std::rand()%2) {
            int i1 = std::rand()%units_.size();
            int i2 = std::rand()%units_.size();
            while(i1 == i2)i2 = std::rand()%units_.size();
            mutated.units_[i1] = std::shared_ptr<Unit>(new Unit(*(units_[i2])));
        } else {
            int i1 = std::rand()%units_.size();
            int i2 = std::rand()%units_.size();
            while(i1 == i2)i2 = std::rand()%units_.size();
            mutated.units_[i1] = std::shared_ptr<Unit>(new Unit((*(units_[i2]))*(*(units_[i1]))));

        }
    }
    return mutated;
}


Army Army::operator*(const Army& army)const
{
    if(this->size() == 0 && army.size() == 0)return Army(*this);
    int s = std::min(this->size(),army.size());
    std::vector<std::shared_ptr<Unit>> crossing;
    for(int i = 0; i < s; i++) {
        switch(std::rand()%4) {
        case 0 :
            crossing.push_back(std::shared_ptr<Unit>(new Unit(*(units_[i]))));
            break;
        case 1 :
            crossing.push_back(std::shared_ptr<Unit>(new Unit(*(army.units_[i]))));
            break;
        case 2 :
            crossing.push_back(std::shared_ptr<Unit>(new Unit(*(units_[i])**(army.units_[std::rand()%army.units_.size()]))));
            break;
        case 3 :
            crossing.push_back(std::shared_ptr<Unit>(new Unit(*(army.units_[i])**(units_[std::rand()%units_.size()]))));
            break;
        }
    }
    return Army(crossing);
}


void Army::save(std::ostream& out)const
{
	for (auto it = units_.begin(); it != units_.end(); ++it)
		(*it)->save(out);
}

Army Army::load(std::istream& in)
{
    std::vector<std::shared_ptr<Unit>> units;

    in.exceptions(std::istream::failbit | std::istream::eofbit);
    while(in) {
        try {
            units.push_back(std::shared_ptr<Unit>(new Unit(Unit::load(in))));
        } catch(...) {}
    }
    return Army(units);
}
