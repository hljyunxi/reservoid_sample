#ifndef __RESERVOID_H__
#define __RESERVOID_H__

#include <stdint.h>
#include <time.h>
#include <vector>

#include "random.h"

using namespace std;

//蓄水池抽样步骤(N个员工中抽取K个员工):
//1: 初始化(讲编号1-K的员工装入返回集合results_中)
//2: 将编号为K+1的员工以k/(k+1)的概率替换result_集合中的一个员工,
//  依此类推，将第I个员工以K/I的概率替换results_集合中的一个员工
class Reservoid {
public:
    Reservoid(uint32_t total, uint32_t ret_size);

public:
    //初始化results_集合
    void init();

    bool valid(){
        return valid_ ;
    }
    
    void move_one_step();

    vector<uint32_t> get_results(){
        return results_;
    }

private:
    //每一轮结束后，做善后工作:
    //1: current_step+1
    //2: 判断valid_标志
    void judge_valid(); 

private:
    //标示蓄水池是否初始化
    bool valid_;

    uint32_t total_;

    uint32_t ret_size_;

    vector<uint32_t> results_;
    
    uint32_t current_step_;

    Random random_;
};

#endif // __RESERVOID_H__
