/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "%h:%h";
static const char *ng1 = "dump.vcd";
static int ng2[] = {1, 0};
static const char *ng3 = "dut";
static int ng4[] = {0, 0};
static int ng5[] = {4, 0};
static const char *ng6 = "Loading firmware from file: %s";
static int ng7[] = {778593656, 0, 1869771873, 0, 1970220912, 0, 1819238244, 0, 795370860, 0, 1650553709, 0, 1697607536, 0, 1651270010, 0, 1885954927, 0, 1668576047, 0, 1919904357, 0, 1970024304, 0, 1697608545, 0, 795373421, 0};
static const char *ng8 = "*IRQ*";



static void Always_87_0(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;

LAB0:    t1 = (t0 + 3432U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 3240);
    xsi_process_wait(t2, 15625LL);
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    t4 = (t0 + 1880);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB8;

LAB6:    if (*((unsigned int *)t7) == 0)
        goto LAB5;

LAB7:    t13 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t13) = 1;

LAB8:    t14 = (t3 + 4);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t6);
    t17 = (~(t16));
    *((unsigned int *)t3) = t17;
    *((unsigned int *)t14) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB10;

LAB9:    t22 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t22 & 1U);
    t23 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t23 & 1U);
    t24 = (t0 + 1880);
    xsi_vlogvar_assign_value(t24, t3, 0, 0, 1);
    goto LAB2;

LAB5:    *((unsigned int *)t3) = 1;
    goto LAB8;

LAB10:    t18 = *((unsigned int *)t3);
    t19 = *((unsigned int *)t15);
    *((unsigned int *)t3) = (t18 | t19);
    t20 = *((unsigned int *)t14);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t14) = (t20 | t21);
    goto LAB9;

}

static void Always_93_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;

LAB0:    t1 = (t0 + 3680U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 4496);
    *((int *)t2) = 1;
    t3 = (t0 + 3712);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    t4 = (t0 + 6112);
    t5 = *((char **)t4);
    t6 = ((((char*)(t5))) + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB5;

LAB6:
LAB7:    goto LAB2;

LAB5:
LAB8:    t14 = (t0 + 6136);
    t15 = *((char **)t14);
    t16 = ((((char*)(t15))) + 40U);
    t17 = *((char **)t16);
    t16 = (t0 + 6160);
    t18 = *((char **)t16);
    t19 = ((((char*)(t18))) + 40U);
    t20 = *((char **)t19);
    xsi_vlogfile_write(1, 0, 0, ng0, 3, t0, (char)118, t17, 10, (char)118, t20, 18);
    goto LAB7;

}

static void Initial_106_2(char *t0)
{
    char t6[8];
    char t7[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;

LAB0:
LAB2:    xsi_vcd_dumpfile(ng1);
    t1 = ((char*)((ng2)));
    xsi_vcd_dumpvars_args(*((unsigned int *)t1), t0, (char)115, ng3, (char)101);
    t1 = ((char*)((ng4)));
    t2 = (t0 + 2360);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 32);

LAB3:    t1 = (t0 + 2360);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = ((char*)((ng2)));
    t5 = ((char*)((ng5)));
    memset(t6, 0, 8);
    xsi_vlog_signed_lshift(t6, 32, t4, 32, t5, 32);
    memset(t7, 0, 8);
    xsi_vlog_signed_less(t7, 32, t3, 32, t6, 32);
    t8 = (t7 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB4;

LAB5:    t1 = ((char*)((ng7)));
    xsi_vlogfile_write(1, 0, 0, ng6, 2, t0, (char)118, t1, 448);

LAB1:    return;
LAB4:
LAB6:    t14 = ((char*)((ng4)));
    xsi_vcd_dumpvars_args(*((unsigned int *)t14), t0, (char)101);
    t1 = (t0 + 2360);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_signed_add(t6, 32, t3, 32, t4, 32);
    t5 = (t0 + 2360);
    xsi_vlogvar_assign_value(t5, t6, 0, 0, 32);
    goto LAB3;

}

static void Initial_121_3(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 4176U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:
LAB4:    t2 = ((char*)((ng4)));
    t3 = (t0 + 1880);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2040);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2200);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    t2 = (t0 + 3984);
    xsi_process_wait(t2, 62500LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    t2 = (t0 + 4512);
    *((int *)t2) = 1;
    t3 = (t0 + 4208);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    t4 = ((char*)((ng4)));
    t5 = (t0 + 2040);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    t2 = (t0 + 3984);
    xsi_process_wait(t2, 3125000LL);
    *((char **)t1) = &&LAB7;
    goto LAB1;

LAB7:    t2 = (t0 + 4528);
    *((int *)t2) = 1;
    t3 = (t0 + 4208);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB8;
    goto LAB1;

LAB8:    t4 = ((char*)((ng2)));
    t5 = (t0 + 2200);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_vlogfile_write(1, 0, 0, ng8, 1, t0);
    t2 = (t0 + 4544);
    *((int *)t2) = 1;
    t3 = (t0 + 4208);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB9;
    goto LAB1;

LAB9:    t4 = ((char*)((ng4)));
    t5 = (t0 + 2200);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    t2 = (t0 + 3984);
    xsi_process_wait(t2, 3125100000LL);
    *((char **)t1) = &&LAB10;
    goto LAB1;

LAB10:    xsi_vlog_finish(1);
    goto LAB1;

}


extern void work_m_08188226917474359845_3842355075_init()
{
	static char *pe[] = {(void *)Always_87_0,(void *)Always_93_1,(void *)Initial_106_2,(void *)Initial_121_3};
	xsi_register_didat("work_m_08188226917474359845_3842355075", "isim/bamse_tb.exe.sim/work/m_08188226917474359845_3842355075.didat");
	xsi_register_executes(pe);
}
