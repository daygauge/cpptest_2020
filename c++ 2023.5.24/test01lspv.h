#pragma once
#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include <unordered_map>

//class pvls1
//{
//public:
//	int mutex = 0;
//	int apple = 0;
//	int orange = 0;
//	int plate = 0;
//};

/*
* int chopsticks[] = {1,1,1,1,1};
* int data = 4;
* int mutex = 1;//互斥
* p1()
* {   p(mutex);//--
*     p(chopsticks[n]);//拿左筷子--
*     p(chopsticks[(n+1)%5]);//拿右筷子--
*     v(mutex);//++
*     吃饭
*     v(chopsticks[n]);//放左筷子++
*     v(chopsticks[(n+1)%5]);//放右筷子++

* 
*     思考
* }
* 
* p2()
* {
*     p(data);//进餐人数++;
*     if(data%2)
*     p(chopsticks[n]);//拿左筷子--
*     p(chopsticks[(n+1)%5]);//拿右筷子--
*     else
*     p(chopsticks[(n+1)%5]);//拿右筷子--
*     p(chopsticks[n]);//拿左筷子--
*     吃饭
*     p(chopsticks[n]);//放左筷子
*     p(chopsticks[(n+1)%5]);//放右筷子
*     v(data);//进餐人数--;
* 
*     思考
* }
* p3()
* {
* 
* }
* p4()
* {
* 
* }
* p5()
* {
* 
* }
* p6()
* {
* 
* }
*/
