#include <iostream>

//API
int container_each_element(void *p_container, void (*cb)(void *element, void *user_data), void *user_data);

//用户函数
void user_callback(void *element, void *user_data);

//定义一个容器
typedef struct
{
    int *p;
    int count;
}sample_container_t;

sample_container_t *sample_container_create(int size)
{
    sample_container_t *p = malloc(sizeof(sample_container_t) + size * sizeof(int));
    p->p = ((char *)p) + sizeof(sample_container_t);
    p->count = 0;
    return p;
}

//https://my.oschina.net/sundq/blog/3002471