#include <stdio.h>
#include <stdlib.h>

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

void sample_container_destory(void *p)
{
    free(p);
}

//add element
void sample_container_add(sample_container_t *p_container, int ele)
{
    p_container->p[p_container->count++] = ele;
}

//delete the last element
void sample_container_del(sample_container_t *p_container)
{
    p_container->count--;
}

//遍历
void sample_container_each_element(sample_container_t *p_container, void (*cb)(int element, void *user_data), void *user_data)
{
    for (int i = 0; i < p_container->count; i++)
    {
        cb(p_container->p[i], user_data);
    }
}

//user data
typedef struct
{
    int gt;
    int count;
}user_data_t;

//callback
void statistic_container_gt(int ele, void *user_data)
{
    user_data_t *p = (user_data_t *)user_data;
    if (ele < p->gt)
    {
        p->count++;
    }
}

int main()
{
    sample_container_t *p = sample_container_create(100);
    sample_container_add(p, 1);
    sample_container_add(p, 4);

    //利用回调函数计算大于2的个数
    user_data_t user_data = {2, 0};
    sample_container_each_element(p, statistic_container_gt, &user_data);

    printf("The count of gt 2 is: %d\n", user_data.count);
}






//https://my.oschina.net/sundq/blog/3002471