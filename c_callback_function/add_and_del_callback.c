#include <stdio.h>
#include <stdlib.h>

//server结构体
typedef struct 
{
    char is_available;    
    int visit_count;    
}server_t;

char is_server_unavailable(server_t *server)
{
    return server->is_available == 1;
}

void init_server(server_t *server, char is_available, int visit_count)
{
    server->is_available = is_available;
    server->visit_count = visit_count;
}

void visit_server(server_t *server)
{
    server->visit_count = server->visit_count + 1;
    printf("visit count ++\n");
}

void get_visit_count(server_t *server)
{
    printf("visit count: %d\n", server->visit_count);
}

//定义回调函数类型
typedef void (*server_unavailable_callback_t)(server_t *s);

#define MAX_CALLBACKS_NUMBER    10

static server_unavailable_callback_t unavailable_callbacks[MAX_CALLBACKS_NUMBER];
static int cb_count = 0;

//注册回调函数
int monitor_add_unavailable_callback(server_unavailable_callback_t cb)
{
    if(cb_count < MAX_CALLBACKS_NUMBER)
    {
        unavailable_callbacks[cb_count++] = cb;
    }
}

//撤销回调函数
int monitor_del_unavailable_callback(server_unavailable_callback_t cb)
{
    for (int i = 0; i < cb_count; i++)
    {
        if (unavailable_callbacks[i] == cb)
        {
            unavailable_callbacks[i] = NULL;
        }
    }
}

//调用回调函数
int monitor_check_server_status(server_t *servers, int count)
{
    while(1)
    {
        for (int i = 0; i < count; i++)
        {
            if (is_server_unavailable(&servers[i]))
            {
                //servers[i].visit_count++;
                //(&servers[i])->visit_count++;
                for (int j = 0; j < cb_count; j++)
                {
                    if (unavailable_callbacks[j] != NULL)
                    {
                        unavailable_callbacks[j](&servers[i]);
                    }
                }
            }
            printf("%d\n", &servers[i]);
        }
        printf("sleep...\n");
        sleep(1);
    }
}

int main()
{
    server_t server_list[5];
    for (int i = 0; i < 5; i++)
    {
        init_server(&server_list[i], 1, 0);
        printf("%d\n", &server_list[i]);
    }
    
    //添加回调函数
    monitor_add_unavailable_callback(visit_server);
    monitor_add_unavailable_callback(get_visit_count);

    //调用回调函数
    monitor_check_server_status(server_list, 5);
}