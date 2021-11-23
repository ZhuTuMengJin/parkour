#ifndef __SL_H__
#define __SL_H__

#include <rtthread.h>
#include <vt100.h>
#include <board.h>

typedef struct box
{
    char *shape;
    int width;
    int height;
    int posx;
    int posy;
} box_map;

typedef struct tree
{
    char *shape;
    int width;
    int height;
    int posx;
    int posy;
} tree;

typedef struct human
{
    char *shape;
    int width;
    int height;
    int posx;
    int posy;
} human;


box_map box;
human ROLE;
tree TREE,TREE2,TREE3;

#define USER_KEY    GET_PIN(H, 4)

#define THREAD_PRIORITY         25
#define THREAD_TIMESLICE        5

/* Pointer to semaphore */
static rt_sem_t dynamic_sem = RT_NULL;


ALIGN(RT_ALIGN_SIZE)
static char KEY_stack[1024];
static struct rt_thread KEY;

ALIGN(RT_ALIGN_SIZE)
static char role_jump_stack[1024];
static struct rt_thread role_jumping;

ALIGN(RT_ALIGN_SIZE)
static char tree_stack[1024];
static struct rt_thread tree_running;

#endif

