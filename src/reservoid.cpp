#include "reservoid.h"

using namespace std;

Reservoid::Reservoid(uint32_t total, uint32_t ret_size)
        : valid_(false), random_((uint32_t)time(NULL)) {
    total_ = total;
    ret_size_ = ret_size;
    current_step_ = 0;
}

void Reservoid::init(){
    assert(valid_==false);

    for(int i=1; i<=ret_size_; i++){
        results_.push_back(i);
    }

    current_step_ = ret_size_;
    valid_ = true;
}

void Reservoid::judge_valid(){
    current_step_++;
    valid_ = current_step_<total_?true:false;
    return;
}

void Reservoid::move_one_step(){
    assert(valid());
    
    //是否通过 K/I 的先验条件
    if(!random_.range_in(current_step_+1, ret_size_)){
        judge_valid();
        return;
    }

    uint32_t replace_pos = random_.uniform(ret_size_);
    results_[replace_pos] = current_step_+1;

    judge_valid();
    return;
}
