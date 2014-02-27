#include "random.h"

Random::Random(uint32_t seed): seed_(seed&0x7fffffff){
}

//模仿RS hash, 作为内部实现
uint32_t Random::next(){
    static uint32_t b = 378551;
    static uint32_t a = 63689;

    seed_ = (uint32_t)(seed_*a + b);

    return seed_;
}
