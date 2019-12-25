#pragma once

#include <iostream>
#include <assert.h>
#include <errno.h>
#include <memory>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <time.h>
#include <list>
#define ip "127.0.0.1"
#define port 12345
#define MAX_EVENT_NUMBER 1024
#define MAX_FD 63525
#define MAX_CONNECT 2500

#define DELAY_TIME 10
#include "http_req.h"
using namespace std;

class HTTP_R;
/*���ﶨʱ�����뷨��ÿ����ʱ����һ��ָ�������ָ�룬ÿ��������һ��ָ��ʱ����ָ�롣
������Ҫ�������ö�ʱ��ʱ�򣬾Ͱ�ԭ����ʱ��������ָ��ָ�գ���ԭ���Ķ�ʱ��ָ��ָ��
����һ���µ�timer��������ʱ����ʱ��û������ָ��Ķ�ʱ��ֱ��Ū���ͺ���*/

class timer{
public:

    HTTP_R* get_http() {return request;};
    bool set_http(HTTP_R*& req);
    bool set_http_n() {request=NULL;return true;};
    timer(HTTP_R* req,int delay);

    time_t get_expire() {return expire;};
private:
    HTTP_R* request;

    time_t expire;

};
class timer_list{
public:
    void push(timer* t);
    void tick(); //�Ĳ���������ʱ����
private:
    std::mutex mu;
    std::list<timer*> timer_delist;
};
