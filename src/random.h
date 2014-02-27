#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <stdint.h>

//32位无符号随机数发生器
class Radom{
public:
    Random(uint32_t seed);

public:
    //返回下一个随机数
    uint32_t next();

    //对随机数进行格式化: 范围[0, max-1]
    uint32_t uniform(uint32_t max);

    // 1/n 概率
    bool one_in(uint32_t n);

    // n/m 概率
    bool range_in();

private:
    uint32_t seed_;
};

#endif //__RANDOM_H__
