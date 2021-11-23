/*
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-11-15			LouYIxuan		 parkour
 */

#include <parkour.h>

void draw_pic(int posx,int posy,int row,int col,int arr[],char *shape)
{
    if(row<=8)//8è¡Œ
    {
        for(int i=0; i<col; i++)
        {
            for(int j=0; j<row; j++) //8row
            {
                if(((arr[i]>>7)&1)==1)
                {
                    vt_move_to(posx+j,posy+i);
                    rt_kprintf("%c",*shape);

                }
                else
                {
                    rt_kprintf(" ");
                }
                arr[i]=arr[i]<<1;
            }
        }
    }
    if(row>8&&row<=16)//16è¡Œ
    {
        for(int i=0; i<col; i++) //åˆ—
        {
            int x=2*i;
            int y=2*i+1;
//			vt_move_to(5+i,5+i);
//			rt_kprintf("x=%d\t\n",x);
//			rt_kprintf("y=%d\t\n",y);

            for(int j=0; j<row; j++) //è¡Œ
            {
                if(j>=0&&j<8)
                {
                    if(((arr[x]>>7)&1)==1)//å…ˆç¬¬ä¸€ä¸ª16è¿›åˆ¶
                    {
                        vt_move_to(posx+j,posy+i);
                        rt_kprintf("%c",*shape);

                    }
                    else
                    {
                        rt_kprintf(" ");
                    }
                    arr[x]=arr[x]<<1;
                }

                if(j>=8&&j<row)//å†æ‰“å°åŽ8ä½
                {
                    if(((arr[y]>>7)&1)==1)
                    {
                        vt_move_to(posx+j,posy+i);
                        rt_kprintf("%c",*shape);
                    }
                    else
                    {
                        rt_kprintf(" ");
                    }
                    arr[y]=arr[y]<<1;
                }
            }
        }


    }
}

void role(int posx,int posy)
{
    char *shape="_";
    char *shape1="=";
    char *shape2="<";
    char *shape7=">";
    char *shape3="@";
    char *shape4="|";
    char *shape5="/";
    char *shape6="\\";

    vt_move_to(posx,posy);//leg
    rt_kprintf("%c",*shape6);
    vt_move_to(posx,posy-1);
    rt_kprintf("%c",*shape5);

    vt_move_to(posx-1,posy-1);
    rt_kprintf("%c",*shape4);

    vt_move_to(posx-1,posy);
    rt_kprintf("%c",*shape4);

    vt_move_to(posx-2,posy-2);//left hand
    rt_kprintf("%c",*shape);
    vt_move_to(posx-2,posy-3);
    rt_kprintf("%c",*shape);


    vt_move_to(posx-2,posy+1);//right hand
    rt_kprintf("%c",*shape);
    vt_move_to(posx-2,posy+2);
    rt_kprintf("%c",*shape);

    vt_move_to(posx-2,posy-1);//neck
    rt_kprintf("%c",*shape2);
    vt_move_to(posx-2,posy);
    rt_kprintf("%c",*shape7);

    vt_move_to(posx-3,posy-1);//eyes
    rt_kprintf("%c",*shape3);
    vt_move_to(posx-3,posy);
    rt_kprintf("%c",*shape3);

    vt_move_to(posx-4,posy-1);//hat
    rt_kprintf("%c",*shape1);
    vt_move_to(posx-4,posy);
    rt_kprintf("%c",*shape1);

    vt_move_to(posx-4,posy+1);
    rt_kprintf("%c",*shape4);

    vt_move_to(posx-3,posy+1);
    rt_kprintf("%c",*shape4);

    vt_move_to(posx-4,posy-2);
    rt_kprintf("%c",*shape4);

    vt_move_to(posx-3,posy-2);
    rt_kprintf("%c",*shape4);
}

void role_dis(int posx,int posy)
{
    char *shape8=" ";

    vt_move_to(posx,posy);//right leg
    rt_kprintf("%c",*shape8);

    vt_move_to(posx,posy-1);
    rt_kprintf("%c",*shape8);

    vt_move_to(posx-1,posy-1);
    rt_kprintf("%c",*shape8);

    vt_move_to(posx-1,posy);
    rt_kprintf("%c",*shape8);

    vt_move_to(posx-2,posy-2);//left hand
    rt_kprintf("%c",*shape8);
    vt_move_to(posx-2,posy-3);
    rt_kprintf("%c",*shape8);


    vt_move_to(posx-2,posy+1);//right hand
    rt_kprintf("%c",*shape8);
    vt_move_to(posx-2,posy+2);
    rt_kprintf("%c",*shape8);

    vt_move_to(posx-2,posy-1);//neck
    rt_kprintf("%c",*shape8);
    vt_move_to(posx-2,posy);
    rt_kprintf("%c",*shape8);

    vt_move_to(posx-3,posy-1);//eyes
    rt_kprintf("%c",*shape8);
    vt_move_to(posx-3,posy);
    rt_kprintf("%c",*shape8);

    vt_move_to(posx-4,posy-1);//hat
    rt_kprintf("%c",*shape8);
    vt_move_to(posx-4,posy);
    rt_kprintf("%c",*shape8);

    vt_move_to(posx-4,posy+1);
    rt_kprintf("%c",*shape8);

    vt_move_to(posx-3,posy+1);
    rt_kprintf("%c",*shape8);

    vt_move_to(posx-4,posy-2);
    rt_kprintf("%c",*shape8);

    vt_move_to(posx-3,posy-2);
    rt_kprintf("%c",*shape8);
}


void key_role(void *parameter)
{
    rt_pin_mode(USER_KEY, PIN_MODE_INPUT_PULLUP);
    while (1)
    {

        if(rt_pin_read(USER_KEY)==PIN_LOW )
            rt_thread_delay(20);
        if(rt_pin_read(USER_KEY)==PIN_LOW )
        {

            /*Release dynamic semaphore*/
            rt_sem_release(dynamic_sem);

            while(rt_pin_read(USER_KEY)==PIN_LOW)
                rt_thread_delay(20);
        }

    }
}

void tree_build(int posx,int posy,char *shape)
{
    vt_move_to(posx,posy);
    rt_kprintf("%c",*shape);

    vt_move_to(posx+1,posy);
    rt_kprintf("%c",*shape);

    vt_move_to(posx+2,posy);
    rt_kprintf("%c",*shape);
}

void role_jump(void *parameter)
{
    ROLE.posx=37;
    ROLE.posy=60;
    int Role_dis;
    while(1)
    {
        /*Waiting semaphore*/
        rt_sem_take(dynamic_sem, RT_WAITING_FOREVER);
        role_dis(38,ROLE.posy);
        while(1)
        {
            Role_dis=ROLE.posx+1;
            role(ROLE.posx--,ROLE.posy);
            rt_thread_mdelay(60);//Jump speed

            role_dis(Role_dis--,ROLE.posy);
            role_dis(Role_dis--,ROLE.posy);

            if(ROLE.posx==31)//Jump height
            {
                role_dis(Role_dis--,ROLE.posy);
                while(1)
                {
                    Role_dis=ROLE.posx;
                    role(ROLE.posx++,ROLE.posy);
                    rt_thread_mdelay(120);//Falling speed
                    role_dis(Role_dis++,ROLE.posy);

                    if(ROLE.posx==39)
                    {
                        role(38,ROLE.posy);
                        ROLE.posx=37;
                        break;
                    }
                }
                break;//Jump thread
            }
        }
    }
}

void fail_pic(int posx,int posy,char *shape)
{
    vt_set_font_color(VT_F_RED);
    int a[]= {0x10,0x04,0x1F,0xFC,0x11,0x04,0x11,0x00,0x17,0xC0,0x10,0x00,0x08,0x00,0x00,0x00, //F
              0x00,0x00,0x00,0x98,0x01,0x24,0x01,0x24,0x01,0x48,0x00,0xFC,0x00,0x04,0x00,0x00,//a
              0x00,0x00,0x01,0x04,0x19,0x04,0x19,0xFC,0x00,0x04,0x00,0x04,0x00,0x00,0x00,0x00,//i
              0x00,0x00,0x08,0x04,0x08,0x04,0x1F,0xFC,0x00,0x04,0x00,0x04,0x00,0x00,0x00,0x00,//l
              0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xCC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00//!
             };
    draw_pic(10,80,16,40,a,"Â¶");
}

void tree_run(void *parameter)
{

    TREE.posx=TREE2.posx=TREE3.posx=36;
    TREE.posy=143;
    int TREE_dis,TREE2_dis,TREE3_dis;
    int score=0;
    char *shape5="/";
    char *shape6="\\";

    while(1)
    {
        vt_move_to(20,135);//Print score
        rt_kprintf("SCORE:");

        vt_move_to(38,60);
        rt_kprintf("%c"," ");
        vt_move_to(38,60);
        rt_kprintf("%c",*shape5);
        rt_thread_mdelay(50);//Leg speed
        vt_move_to(38,60);
        rt_kprintf("%c"," ");
        vt_move_to(38,60);
        rt_kprintf("%c",*shape6);
        vt_move_to(38,60);
        rt_kprintf("%c"," ");

        vt_move_to(38,59);
        rt_kprintf("%c"," ");
        vt_move_to(38,59);
        rt_kprintf("%c",*shape5);
        rt_thread_mdelay(50);//Leg speed
        vt_move_to(38,59);
        rt_kprintf("%c"," ");
        vt_move_to(38,59);
        rt_kprintf("%c",*shape6);
        vt_move_to(38,59);
        rt_kprintf("%c"," ");

        TREE_dis=TREE.posy+1;
        tree_build(TREE.posx,TREE.posy--,"¡ö");
        tree_build(TREE.posx,TREE_dis--," ");
        if(TREE.posy==120)
        {
            TREE2.posy=143;
        }
        TREE2_dis=TREE2.posy+1;
        tree_build(TREE2.posx,TREE2.posy--,"¡ö");
        tree_build(TREE2.posx,TREE2_dis--," ");
        if(TREE2.posy==100)
        {
            TREE3.posy=143;
        }
        TREE3_dis=TREE3.posy+1;
        tree_build(TREE3.posx,TREE3.posy--,"¡ö");
        tree_build(TREE3.posx,TREE3_dis--," ");
        if(TREE.posy<45)
        {
            tree_build(TREE.posx,45," ");
            TREE.posy=143;
        }
        if(TREE2.posy<45)
        {
            tree_build(TREE2.posx,45," ");
        }
        if(TREE3.posy<45)
        {
            tree_build(TREE3.posx,45," ");
        }


        if(ROLE.posy==TREE.posy||ROLE.posy==TREE2.posy||ROLE.posy==TREE3.posy)
        {
            if(ROLE.posy==TREE.posy&&ROLE.posx>=36)
            {
                fail_pic(20,95,"¡ö");
                break;
            }
            if(ROLE.posy==TREE2.posy&&ROLE.posx>=36)
            {
                fail_pic(20,95,"¡ö");
                break;
            }
            if(ROLE.posy==TREE3.posy&&ROLE.posx>=36)
            {
                fail_pic(20,95,"¡ö");
                break;
            }
            vt_move_to(20,142);
            rt_kprintf("%d",(++score)*100);
        }
    }

}

static void parkour(int argc, char *argv[])
{
    box.shape="¡ö";
    ROLE.posx=38;
    ROLE.posy=60;

    vt_set_font_color(VT_F_RED);
    vt_set_bg_color(VT_B_BLACK);

    vt_hide_cursor();
    vt_draw_hline(39,45,100,*box.shape);//Ground position

    vt_set_font_color(VT_F_WHITE);//Color of people and trees
    role(ROLE.posx,ROLE.posy);
		
		

//		int c=0xff;
//		c=c>>6;
//		vt_move_to(50,50);
//		rt_kprintf("%d",c);

    vt_move_down(28);//The cursor moves down 28

    /* Create a dynamic semaphore with an initial value of 0 */
    dynamic_sem = rt_sem_create("dsem", 0, RT_IPC_FLAG_PRIO);

    rt_thread_init(&role_jumping,
                   "role_jumping",
                   role_jump,
                   RT_NULL,
                   &role_jump_stack[0],
                   sizeof(role_jump_stack),
                   THREAD_PRIORITY, THREAD_TIMESLICE);
    rt_thread_startup(&role_jumping);

    rt_thread_init(&KEY,
                   "KEY",
                   key_role,
                   RT_NULL,
                   &KEY_stack[0],
                   sizeof(KEY_stack),
                   THREAD_PRIORITY, THREAD_TIMESLICE);
    rt_thread_startup(&KEY);

    /*Tree runs have the highest priority*/
    rt_thread_init(&tree_running,
                   "tree",
                   tree_run,
                   RT_NULL,
                   &tree_stack[0],
                   sizeof(tree_stack),
                   THREAD_PRIORITY-1, THREAD_TIMESLICE);
    rt_thread_startup(&tree_running);

}

MSH_CMD_EXPORT(parkour, steam locomotive);



