蓄水池抽样实现程序
==========================

程序由下面几个部分组成：

* random.h random.cpp
* reservoid.h reservoid.cpp
* reservoid_main.cpp

random部分
=============================

random主要实现了随机数发生器(模范RS HASH算法),
并在此基础上实现了几个封装:

* next()

产生的随机数的范围是[0-UINT32_MAX]

* uniform(n)

产生的随机数的范围是[0, n-1]

* one_in(n)

true: 1/n概率  false: other

* range(n, m)

true: m/n概率  false: other

reservoid部分
=============================

蓄水池抽样主体部分（N个员工中抽取K个员工）:

```
1: 初始化(讲编号1-K的员工装入返回集合results_中)
2: 将编号为K+1的员工以k/(k+1)的概率替换result_集合中的一个员工,
  依此类推，将第I个员工以K/I的概率替换results_集合中的一个员工
```


测试程序reservoid_main部分
=============================


```
reservoid使用示例:
1: 调用init
2: 判断valid() 
  true: 调用move_one_step继续
  false: 结束调用get_results()获取结果
```

示例程序


    uint32_t total, ret_size;
    printf("enter total and ret_size\n");
    scanf("%u%u", &total, &ret_size);
    
    if(ret_size>total){
        printf("ERROR: total should great than ret_size\n");
        exit(-1);
    }
   
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
