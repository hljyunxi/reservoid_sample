#include <stdio.h>
#include <stdlib.h>

#include "reservoid.h"


using namespace std;

//测试程序
int main(){
    uint32_t total, ret_size;
    printf("enter total and ret_size\n");
    scanf("%u%u", &total, &ret_size);
    
    if(ret_size>total){
        printf("ERROR: total should great than ret_size\n");
        exit(-1);
    }
    //reservoid使用示例:
    //1: 调用init
    //2: 判断valid() 
    //  true: 调用move_one_step继续
    //  false: 结束调用get_results()获取结果
   
    Reservoid reservoid(total, ret_size); 
    reservoid.init();
    
    while(reservoid.valid()){
        reservoid.move_one_step();
    }

    vector<uint32_t> results = reservoid.get_results();

    printf("RESULTS:\n");
    for(int i=0; i<ret_size; i++)
        printf("%u\n", results[i]);

    return 0;
}
