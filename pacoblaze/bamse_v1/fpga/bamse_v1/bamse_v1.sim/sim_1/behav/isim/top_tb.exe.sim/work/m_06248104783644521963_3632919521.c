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
static const char *ng0 = "/home/saul/projects/picoblaze/pacoblaze/bamse_v1/fpga/bamse_v1/bamse_v1.sim/sim_1/behav/pacoblaze_alu.v";
static unsigned int ng1[] = {14U, 0U};
static unsigned int ng2[] = {15U, 0U};
static unsigned int ng3[] = {10U, 0U};
static unsigned int ng4[] = {13U, 0U};
static int ng5[] = {1, 0};
static int ng6[] = {0, 0};
static unsigned int ng7[] = {2U, 0U};
static unsigned int ng8[] = {1U, 0U};
static unsigned int ng9[] = {0U, 0U};
static unsigned int ng10[] = {12U, 0U};
static unsigned int ng11[] = {5U, 0U};
static unsigned int ng12[] = {6U, 0U};
static unsigned int ng13[] = {9U, 0U};
static unsigned int ng14[] = {7U, 0U};
static unsigned int ng15[] = {16U, 0U};



static void NetDecl_79_0(char *t0)
{
    char t3[8];
    char t4[8];
    char t6[8];
    char t22[8];
    char t37[8];
    char t53[8];
    char t61[8];
    char t89[8];
    char t104[8];
    char t120[8];
    char t128[8];
    char t167[8];
    char *t1;
    char *t2;
    char *t5;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    char *t36;
    char *t38;
    char *t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    char *t52;
    char *t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    char *t60;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    char *t65;
    char *t66;
    char *t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t75;
    char *t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    char *t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    char *t96;
    char *t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    char *t102;
    char *t103;
    char *t105;
    char *t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    char *t119;
    char *t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    char *t127;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    char *t132;
    char *t133;
    char *t134;
    unsigned int t135;
    unsigned int t136;
    unsigned int t137;
    unsigned int t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    char *t142;
    char *t143;
    unsigned int t144;
    unsigned int t145;
    unsigned int t146;
    int t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    int t151;
    unsigned int t152;
    unsigned int t153;
    unsigned int t154;
    unsigned int t155;
    char *t156;
    unsigned int t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    unsigned int t161;
    char *t162;
    char *t163;
    unsigned int t164;
    unsigned int t165;
    unsigned int t166;
    char *t168;
    char *t169;
    char *t170;
    unsigned int t171;
    unsigned int t172;
    unsigned int t173;
    unsigned int t174;
    unsigned int t175;
    unsigned int t176;
    unsigned int t177;
    unsigned int t178;
    unsigned int t179;
    unsigned int t180;
    unsigned int t181;
    unsigned int t182;
    char *t183;
    char *t184;
    char *t185;
    char *t186;
    char *t187;
    char *t188;
    unsigned int t189;
    unsigned int t190;
    char *t191;
    unsigned int t192;
    unsigned int t193;
    char *t194;
    unsigned int t195;
    unsigned int t196;
    char *t197;

LAB0:    t1 = (t0 + 4576U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(79, ng0);
    t2 = (t0 + 1344U);
    t5 = *((char **)t2);
    t2 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    t8 = (t2 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB7;

LAB4:    if (t18 != 0)
        goto LAB6;

LAB5:    *((unsigned int *)t6) = 1;

LAB7:    memset(t22, 0, 8);
    t23 = (t6 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB8;

LAB9:    if (*((unsigned int *)t23) != 0)
        goto LAB10;

LAB11:    t30 = (t22 + 4);
    t31 = *((unsigned int *)t22);
    t32 = (!(t31));
    t33 = *((unsigned int *)t30);
    t34 = (t32 || t33);
    if (t34 > 0)
        goto LAB12;

LAB13:    memcpy(t61, t22, 8);

LAB14:    memset(t89, 0, 8);
    t90 = (t61 + 4);
    t91 = *((unsigned int *)t90);
    t92 = (~(t91));
    t93 = *((unsigned int *)t61);
    t94 = (t93 & t92);
    t95 = (t94 & 1U);
    if (t95 != 0)
        goto LAB26;

LAB27:    if (*((unsigned int *)t90) != 0)
        goto LAB28;

LAB29:    t97 = (t89 + 4);
    t98 = *((unsigned int *)t89);
    t99 = (!(t98));
    t100 = *((unsigned int *)t97);
    t101 = (t99 || t100);
    if (t101 > 0)
        goto LAB30;

LAB31:    memcpy(t128, t89, 8);

LAB32:    memset(t4, 0, 8);
    t156 = (t128 + 4);
    t157 = *((unsigned int *)t156);
    t158 = (~(t157));
    t159 = *((unsigned int *)t128);
    t160 = (t159 & t158);
    t161 = (t160 & 1U);
    if (t161 != 0)
        goto LAB44;

LAB45:    if (*((unsigned int *)t156) != 0)
        goto LAB46;

LAB47:    t163 = (t4 + 4);
    t164 = *((unsigned int *)t4);
    t165 = *((unsigned int *)t163);
    t166 = (t164 || t165);
    if (t166 > 0)
        goto LAB48;

LAB49:    t179 = *((unsigned int *)t4);
    t180 = (~(t179));
    t181 = *((unsigned int *)t163);
    t182 = (t180 || t181);
    if (t182 > 0)
        goto LAB50;

LAB51:    if (*((unsigned int *)t163) > 0)
        goto LAB52;

LAB53:    if (*((unsigned int *)t4) > 0)
        goto LAB54;

LAB55:    memcpy(t3, t184, 8);

LAB56:    t183 = (t0 + 6296);
    t185 = (t183 + 56U);
    t186 = *((char **)t185);
    t187 = (t186 + 56U);
    t188 = *((char **)t187);
    memset(t188, 0, 8);
    t189 = 255U;
    t190 = t189;
    t191 = (t3 + 4);
    t192 = *((unsigned int *)t3);
    t189 = (t189 & t192);
    t193 = *((unsigned int *)t191);
    t190 = (t190 & t193);
    t194 = (t188 + 4);
    t195 = *((unsigned int *)t188);
    *((unsigned int *)t188) = (t195 | t189);
    t196 = *((unsigned int *)t194);
    *((unsigned int *)t194) = (t196 | t190);
    xsi_driver_vfirst_trans(t183, 0, 7U);
    t197 = (t0 + 6136);
    *((int *)t197) = 1;

LAB1:    return;
LAB6:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB7;

LAB8:    *((unsigned int *)t22) = 1;
    goto LAB11;

LAB10:    t29 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB11;

LAB12:    t35 = (t0 + 1344U);
    t36 = *((char **)t35);
    t35 = ((char*)((ng2)));
    memset(t37, 0, 8);
    t38 = (t36 + 4);
    t39 = (t35 + 4);
    t40 = *((unsigned int *)t36);
    t41 = *((unsigned int *)t35);
    t42 = (t40 ^ t41);
    t43 = *((unsigned int *)t38);
    t44 = *((unsigned int *)t39);
    t45 = (t43 ^ t44);
    t46 = (t42 | t45);
    t47 = *((unsigned int *)t38);
    t48 = *((unsigned int *)t39);
    t49 = (t47 | t48);
    t50 = (~(t49));
    t51 = (t46 & t50);
    if (t51 != 0)
        goto LAB18;

LAB15:    if (t49 != 0)
        goto LAB17;

LAB16:    *((unsigned int *)t37) = 1;

LAB18:    memset(t53, 0, 8);
    t54 = (t37 + 4);
    t55 = *((unsigned int *)t54);
    t56 = (~(t55));
    t57 = *((unsigned int *)t37);
    t58 = (t57 & t56);
    t59 = (t58 & 1U);
    if (t59 != 0)
        goto LAB19;

LAB20:    if (*((unsigned int *)t54) != 0)
        goto LAB21;

LAB22:    t62 = *((unsigned int *)t22);
    t63 = *((unsigned int *)t53);
    t64 = (t62 | t63);
    *((unsigned int *)t61) = t64;
    t65 = (t22 + 4);
    t66 = (t53 + 4);
    t67 = (t61 + 4);
    t68 = *((unsigned int *)t65);
    t69 = *((unsigned int *)t66);
    t70 = (t68 | t69);
    *((unsigned int *)t67) = t70;
    t71 = *((unsigned int *)t67);
    t72 = (t71 != 0);
    if (t72 == 1)
        goto LAB23;

LAB24:
LAB25:    goto LAB14;

LAB17:    t52 = (t37 + 4);
    *((unsigned int *)t37) = 1;
    *((unsigned int *)t52) = 1;
    goto LAB18;

LAB19:    *((unsigned int *)t53) = 1;
    goto LAB22;

LAB21:    t60 = (t53 + 4);
    *((unsigned int *)t53) = 1;
    *((unsigned int *)t60) = 1;
    goto LAB22;

LAB23:    t73 = *((unsigned int *)t61);
    t74 = *((unsigned int *)t67);
    *((unsigned int *)t61) = (t73 | t74);
    t75 = (t22 + 4);
    t76 = (t53 + 4);
    t77 = *((unsigned int *)t75);
    t78 = (~(t77));
    t79 = *((unsigned int *)t22);
    t80 = (t79 & t78);
    t81 = *((unsigned int *)t76);
    t82 = (~(t81));
    t83 = *((unsigned int *)t53);
    t84 = (t83 & t82);
    t85 = (~(t80));
    t86 = (~(t84));
    t87 = *((unsigned int *)t67);
    *((unsigned int *)t67) = (t87 & t85);
    t88 = *((unsigned int *)t67);
    *((unsigned int *)t67) = (t88 & t86);
    goto LAB25;

LAB26:    *((unsigned int *)t89) = 1;
    goto LAB29;

LAB28:    t96 = (t89 + 4);
    *((unsigned int *)t89) = 1;
    *((unsigned int *)t96) = 1;
    goto LAB29;

LAB30:    t102 = (t0 + 1344U);
    t103 = *((char **)t102);
    t102 = ((char*)((ng3)));
    memset(t104, 0, 8);
    t105 = (t103 + 4);
    t106 = (t102 + 4);
    t107 = *((unsigned int *)t103);
    t108 = *((unsigned int *)t102);
    t109 = (t107 ^ t108);
    t110 = *((unsigned int *)t105);
    t111 = *((unsigned int *)t106);
    t112 = (t110 ^ t111);
    t113 = (t109 | t112);
    t114 = *((unsigned int *)t105);
    t115 = *((unsigned int *)t106);
    t116 = (t114 | t115);
    t117 = (~(t116));
    t118 = (t113 & t117);
    if (t118 != 0)
        goto LAB36;

LAB33:    if (t116 != 0)
        goto LAB35;

LAB34:    *((unsigned int *)t104) = 1;

LAB36:    memset(t120, 0, 8);
    t121 = (t104 + 4);
    t122 = *((unsigned int *)t121);
    t123 = (~(t122));
    t124 = *((unsigned int *)t104);
    t125 = (t124 & t123);
    t126 = (t125 & 1U);
    if (t126 != 0)
        goto LAB37;

LAB38:    if (*((unsigned int *)t121) != 0)
        goto LAB39;

LAB40:    t129 = *((unsigned int *)t89);
    t130 = *((unsigned int *)t120);
    t131 = (t129 | t130);
    *((unsigned int *)t128) = t131;
    t132 = (t89 + 4);
    t133 = (t120 + 4);
    t134 = (t128 + 4);
    t135 = *((unsigned int *)t132);
    t136 = *((unsigned int *)t133);
    t137 = (t135 | t136);
    *((unsigned int *)t134) = t137;
    t138 = *((unsigned int *)t134);
    t139 = (t138 != 0);
    if (t139 == 1)
        goto LAB41;

LAB42:
LAB43:    goto LAB32;

LAB35:    t119 = (t104 + 4);
    *((unsigned int *)t104) = 1;
    *((unsigned int *)t119) = 1;
    goto LAB36;

LAB37:    *((unsigned int *)t120) = 1;
    goto LAB40;

LAB39:    t127 = (t120 + 4);
    *((unsigned int *)t120) = 1;
    *((unsigned int *)t127) = 1;
    goto LAB40;

LAB41:    t140 = *((unsigned int *)t128);
    t141 = *((unsigned int *)t134);
    *((unsigned int *)t128) = (t140 | t141);
    t142 = (t89 + 4);
    t143 = (t120 + 4);
    t144 = *((unsigned int *)t142);
    t145 = (~(t144));
    t146 = *((unsigned int *)t89);
    t147 = (t146 & t145);
    t148 = *((unsigned int *)t143);
    t149 = (~(t148));
    t150 = *((unsigned int *)t120);
    t151 = (t150 & t149);
    t152 = (~(t147));
    t153 = (~(t151));
    t154 = *((unsigned int *)t134);
    *((unsigned int *)t134) = (t154 & t152);
    t155 = *((unsigned int *)t134);
    *((unsigned int *)t134) = (t155 & t153);
    goto LAB43;

LAB44:    *((unsigned int *)t4) = 1;
    goto LAB47;

LAB46:    t162 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t162) = 1;
    goto LAB47;

LAB48:    t168 = (t0 + 2144U);
    t169 = *((char **)t168);
    memset(t167, 0, 8);
    t168 = (t167 + 4);
    t170 = (t169 + 4);
    t171 = *((unsigned int *)t169);
    t172 = (~(t171));
    *((unsigned int *)t167) = t172;
    *((unsigned int *)t168) = 0;
    if (*((unsigned int *)t170) != 0)
        goto LAB58;

LAB57:    t177 = *((unsigned int *)t167);
    *((unsigned int *)t167) = (t177 & 255U);
    t178 = *((unsigned int *)t168);
    *((unsigned int *)t168) = (t178 & 255U);
    goto LAB49;

LAB50:    t183 = (t0 + 2144U);
    t184 = *((char **)t183);
    goto LAB51;

LAB52:    xsi_vlog_unsigned_bit_combine(t3, 8, t167, 8, t184, 8);
    goto LAB56;

LAB54:    memcpy(t3, t167, 8);
    goto LAB56;

LAB58:    t173 = *((unsigned int *)t167);
    t174 = *((unsigned int *)t170);
    *((unsigned int *)t167) = (t173 | t174);
    t175 = *((unsigned int *)t168);
    t176 = *((unsigned int *)t170);
    *((unsigned int *)t168) = (t175 | t176);
    goto LAB57;

}

static void NetDecl_95_1(char *t0)
{
    char t3[8];
    char t4[8];
    char t6[8];
    char t35[8];
    char t40[8];
    char t41[8];
    char t43[8];
    char t59[8];
    char t74[8];
    char t90[8];
    char t98[8];
    char t142[8];
    char t143[8];
    char t146[8];
    char t173[8];
    char *t1;
    char *t2;
    char *t5;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t42;
    char *t44;
    char *t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t58;
    char *t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    char *t66;
    char *t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    char *t72;
    char *t73;
    char *t75;
    char *t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    char *t89;
    char *t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    char *t97;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    char *t102;
    char *t103;
    char *t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    char *t112;
    char *t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    int t117;
    unsigned int t118;
    unsigned int t119;
    unsigned int t120;
    int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    char *t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    char *t132;
    char *t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    char *t137;
    unsigned int t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    char *t144;
    char *t145;
    char *t147;
    char *t148;
    unsigned int t149;
    unsigned int t150;
    unsigned int t151;
    unsigned int t152;
    unsigned int t153;
    unsigned int t154;
    unsigned int t155;
    unsigned int t156;
    unsigned int t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    char *t161;
    char *t162;
    unsigned int t163;
    unsigned int t164;
    unsigned int t165;
    unsigned int t166;
    unsigned int t167;
    char *t168;
    char *t169;
    unsigned int t170;
    unsigned int t171;
    unsigned int t172;
    char *t174;
    char *t175;
    unsigned int t176;
    unsigned int t177;
    unsigned int t178;
    unsigned int t179;
    unsigned int t180;
    char *t181;
    char *t182;
    char *t183;
    unsigned int t184;
    unsigned int t185;
    unsigned int t186;
    unsigned int t187;
    unsigned int t188;
    unsigned int t189;
    unsigned int t190;
    unsigned int t191;
    unsigned int t192;
    unsigned int t193;
    unsigned int t194;
    unsigned int t195;
    char *t196;
    char *t197;
    char *t198;
    char *t199;
    char *t200;
    char *t201;
    unsigned int t202;
    unsigned int t203;
    char *t204;
    unsigned int t205;
    unsigned int t206;
    char *t207;
    unsigned int t208;
    unsigned int t209;
    char *t210;

LAB0:    t1 = (t0 + 4824U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(95, ng0);
    t2 = (t0 + 1344U);
    t5 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    t8 = (t2 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB7;

LAB4:    if (t18 != 0)
        goto LAB6;

LAB5:    *((unsigned int *)t6) = 1;

LAB7:    memset(t4, 0, 8);
    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 & 1U);
    if (t27 != 0)
        goto LAB8;

LAB9:    if (*((unsigned int *)t22) != 0)
        goto LAB10;

LAB11:    t29 = (t4 + 4);
    t30 = *((unsigned int *)t4);
    t31 = *((unsigned int *)t29);
    t32 = (t30 || t31);
    if (t32 > 0)
        goto LAB12;

LAB13:    t36 = *((unsigned int *)t4);
    t37 = (~(t36));
    t38 = *((unsigned int *)t29);
    t39 = (t37 || t38);
    if (t39 > 0)
        goto LAB14;

LAB15:    if (*((unsigned int *)t29) > 0)
        goto LAB16;

LAB17:    if (*((unsigned int *)t4) > 0)
        goto LAB18;

LAB19:    memcpy(t3, t40, 8);

LAB20:    t197 = (t0 + 6360);
    t198 = (t197 + 56U);
    t199 = *((char **)t198);
    t200 = (t199 + 56U);
    t201 = *((char **)t200);
    memset(t201, 0, 8);
    t202 = 1U;
    t203 = t202;
    t204 = (t3 + 4);
    t205 = *((unsigned int *)t3);
    t202 = (t202 & t205);
    t206 = *((unsigned int *)t204);
    t203 = (t203 & t206);
    t207 = (t201 + 4);
    t208 = *((unsigned int *)t201);
    *((unsigned int *)t201) = (t208 | t202);
    t209 = *((unsigned int *)t207);
    *((unsigned int *)t207) = (t209 | t203);
    xsi_driver_vfirst_trans(t197, 0, 0U);
    t210 = (t0 + 6152);
    *((int *)t210) = 1;

LAB1:    return;
LAB6:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB7;

LAB8:    *((unsigned int *)t4) = 1;
    goto LAB11;

LAB10:    t28 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB11;

LAB12:    t33 = (t0 + 2304U);
    t34 = *((char **)t33);
    memcpy(t35, t34, 8);
    goto LAB13;

LAB14:    t33 = (t0 + 1344U);
    t42 = *((char **)t33);
    t33 = ((char*)((ng1)));
    memset(t43, 0, 8);
    t44 = (t42 + 4);
    t45 = (t33 + 4);
    t46 = *((unsigned int *)t42);
    t47 = *((unsigned int *)t33);
    t48 = (t46 ^ t47);
    t49 = *((unsigned int *)t44);
    t50 = *((unsigned int *)t45);
    t51 = (t49 ^ t50);
    t52 = (t48 | t51);
    t53 = *((unsigned int *)t44);
    t54 = *((unsigned int *)t45);
    t55 = (t53 | t54);
    t56 = (~(t55));
    t57 = (t52 & t56);
    if (t57 != 0)
        goto LAB24;

LAB21:    if (t55 != 0)
        goto LAB23;

LAB22:    *((unsigned int *)t43) = 1;

LAB24:    memset(t59, 0, 8);
    t60 = (t43 + 4);
    t61 = *((unsigned int *)t60);
    t62 = (~(t61));
    t63 = *((unsigned int *)t43);
    t64 = (t63 & t62);
    t65 = (t64 & 1U);
    if (t65 != 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t60) != 0)
        goto LAB27;

LAB28:    t67 = (t59 + 4);
    t68 = *((unsigned int *)t59);
    t69 = (!(t68));
    t70 = *((unsigned int *)t67);
    t71 = (t69 || t70);
    if (t71 > 0)
        goto LAB29;

LAB30:    memcpy(t98, t59, 8);

LAB31:    memset(t41, 0, 8);
    t126 = (t98 + 4);
    t127 = *((unsigned int *)t126);
    t128 = (~(t127));
    t129 = *((unsigned int *)t98);
    t130 = (t129 & t128);
    t131 = (t130 & 1U);
    if (t131 != 0)
        goto LAB43;

LAB44:    if (*((unsigned int *)t126) != 0)
        goto LAB45;

LAB46:    t133 = (t41 + 4);
    t134 = *((unsigned int *)t41);
    t135 = *((unsigned int *)t133);
    t136 = (t134 || t135);
    if (t136 > 0)
        goto LAB47;

LAB48:    t138 = *((unsigned int *)t41);
    t139 = (~(t138));
    t140 = *((unsigned int *)t133);
    t141 = (t139 || t140);
    if (t141 > 0)
        goto LAB49;

LAB50:    if (*((unsigned int *)t133) > 0)
        goto LAB51;

LAB52:    if (*((unsigned int *)t41) > 0)
        goto LAB53;

LAB54:    memcpy(t40, t142, 8);

LAB55:    goto LAB15;

LAB16:    xsi_vlog_unsigned_bit_combine(t3, 32, t35, 32, t40, 32);
    goto LAB20;

LAB18:    memcpy(t3, t35, 8);
    goto LAB20;

LAB23:    t58 = (t43 + 4);
    *((unsigned int *)t43) = 1;
    *((unsigned int *)t58) = 1;
    goto LAB24;

LAB25:    *((unsigned int *)t59) = 1;
    goto LAB28;

LAB27:    t66 = (t59 + 4);
    *((unsigned int *)t59) = 1;
    *((unsigned int *)t66) = 1;
    goto LAB28;

LAB29:    t72 = (t0 + 1344U);
    t73 = *((char **)t72);
    t72 = ((char*)((ng3)));
    memset(t74, 0, 8);
    t75 = (t73 + 4);
    t76 = (t72 + 4);
    t77 = *((unsigned int *)t73);
    t78 = *((unsigned int *)t72);
    t79 = (t77 ^ t78);
    t80 = *((unsigned int *)t75);
    t81 = *((unsigned int *)t76);
    t82 = (t80 ^ t81);
    t83 = (t79 | t82);
    t84 = *((unsigned int *)t75);
    t85 = *((unsigned int *)t76);
    t86 = (t84 | t85);
    t87 = (~(t86));
    t88 = (t83 & t87);
    if (t88 != 0)
        goto LAB35;

LAB32:    if (t86 != 0)
        goto LAB34;

LAB33:    *((unsigned int *)t74) = 1;

LAB35:    memset(t90, 0, 8);
    t91 = (t74 + 4);
    t92 = *((unsigned int *)t91);
    t93 = (~(t92));
    t94 = *((unsigned int *)t74);
    t95 = (t94 & t93);
    t96 = (t95 & 1U);
    if (t96 != 0)
        goto LAB36;

LAB37:    if (*((unsigned int *)t91) != 0)
        goto LAB38;

LAB39:    t99 = *((unsigned int *)t59);
    t100 = *((unsigned int *)t90);
    t101 = (t99 | t100);
    *((unsigned int *)t98) = t101;
    t102 = (t59 + 4);
    t103 = (t90 + 4);
    t104 = (t98 + 4);
    t105 = *((unsigned int *)t102);
    t106 = *((unsigned int *)t103);
    t107 = (t105 | t106);
    *((unsigned int *)t104) = t107;
    t108 = *((unsigned int *)t104);
    t109 = (t108 != 0);
    if (t109 == 1)
        goto LAB40;

LAB41:
LAB42:    goto LAB31;

LAB34:    t89 = (t74 + 4);
    *((unsigned int *)t74) = 1;
    *((unsigned int *)t89) = 1;
    goto LAB35;

LAB36:    *((unsigned int *)t90) = 1;
    goto LAB39;

LAB38:    t97 = (t90 + 4);
    *((unsigned int *)t90) = 1;
    *((unsigned int *)t97) = 1;
    goto LAB39;

LAB40:    t110 = *((unsigned int *)t98);
    t111 = *((unsigned int *)t104);
    *((unsigned int *)t98) = (t110 | t111);
    t112 = (t59 + 4);
    t113 = (t90 + 4);
    t114 = *((unsigned int *)t112);
    t115 = (~(t114));
    t116 = *((unsigned int *)t59);
    t117 = (t116 & t115);
    t118 = *((unsigned int *)t113);
    t119 = (~(t118));
    t120 = *((unsigned int *)t90);
    t121 = (t120 & t119);
    t122 = (~(t117));
    t123 = (~(t121));
    t124 = *((unsigned int *)t104);
    *((unsigned int *)t104) = (t124 & t122);
    t125 = *((unsigned int *)t104);
    *((unsigned int *)t104) = (t125 & t123);
    goto LAB42;

LAB43:    *((unsigned int *)t41) = 1;
    goto LAB46;

LAB45:    t132 = (t41 + 4);
    *((unsigned int *)t41) = 1;
    *((unsigned int *)t132) = 1;
    goto LAB46;

LAB47:    t137 = ((char*)((ng5)));
    goto LAB48;

LAB49:    t144 = (t0 + 1344U);
    t145 = *((char **)t144);
    t144 = ((char*)((ng2)));
    memset(t146, 0, 8);
    t147 = (t145 + 4);
    t148 = (t144 + 4);
    t149 = *((unsigned int *)t145);
    t150 = *((unsigned int *)t144);
    t151 = (t149 ^ t150);
    t152 = *((unsigned int *)t147);
    t153 = *((unsigned int *)t148);
    t154 = (t152 ^ t153);
    t155 = (t151 | t154);
    t156 = *((unsigned int *)t147);
    t157 = *((unsigned int *)t148);
    t158 = (t156 | t157);
    t159 = (~(t158));
    t160 = (t155 & t159);
    if (t160 != 0)
        goto LAB59;

LAB56:    if (t158 != 0)
        goto LAB58;

LAB57:    *((unsigned int *)t146) = 1;

LAB59:    memset(t143, 0, 8);
    t162 = (t146 + 4);
    t163 = *((unsigned int *)t162);
    t164 = (~(t163));
    t165 = *((unsigned int *)t146);
    t166 = (t165 & t164);
    t167 = (t166 & 1U);
    if (t167 != 0)
        goto LAB60;

LAB61:    if (*((unsigned int *)t162) != 0)
        goto LAB62;

LAB63:    t169 = (t143 + 4);
    t170 = *((unsigned int *)t143);
    t171 = *((unsigned int *)t169);
    t172 = (t170 || t171);
    if (t172 > 0)
        goto LAB64;

LAB65:    t192 = *((unsigned int *)t143);
    t193 = (~(t192));
    t194 = *((unsigned int *)t169);
    t195 = (t193 || t194);
    if (t195 > 0)
        goto LAB66;

LAB67:    if (*((unsigned int *)t169) > 0)
        goto LAB68;

LAB69:    if (*((unsigned int *)t143) > 0)
        goto LAB70;

LAB71:    memcpy(t142, t196, 8);

LAB72:    goto LAB50;

LAB51:    xsi_vlog_unsigned_bit_combine(t40, 32, t137, 32, t142, 32);
    goto LAB55;

LAB53:    memcpy(t40, t137, 8);
    goto LAB55;

LAB58:    t161 = (t146 + 4);
    *((unsigned int *)t146) = 1;
    *((unsigned int *)t161) = 1;
    goto LAB59;

LAB60:    *((unsigned int *)t143) = 1;
    goto LAB63;

LAB62:    t168 = (t143 + 4);
    *((unsigned int *)t143) = 1;
    *((unsigned int *)t168) = 1;
    goto LAB63;

LAB64:    t174 = (t0 + 2304U);
    t175 = *((char **)t174);
    memset(t173, 0, 8);
    t174 = (t175 + 4);
    t176 = *((unsigned int *)t174);
    t177 = (~(t176));
    t178 = *((unsigned int *)t175);
    t179 = (t178 & t177);
    t180 = (t179 & 1U);
    if (t180 != 0)
        goto LAB76;

LAB74:    if (*((unsigned int *)t174) == 0)
        goto LAB73;

LAB75:    t181 = (t173 + 4);
    *((unsigned int *)t173) = 1;
    *((unsigned int *)t181) = 1;

LAB76:    t182 = (t173 + 4);
    t183 = (t175 + 4);
    t184 = *((unsigned int *)t175);
    t185 = (~(t184));
    *((unsigned int *)t173) = t185;
    *((unsigned int *)t182) = 0;
    if (*((unsigned int *)t183) != 0)
        goto LAB78;

LAB77:    t190 = *((unsigned int *)t173);
    *((unsigned int *)t173) = (t190 & 4294967295U);
    t191 = *((unsigned int *)t182);
    *((unsigned int *)t182) = (t191 & 4294967295U);
    goto LAB65;

LAB66:    t196 = ((char*)((ng6)));
    goto LAB67;

LAB68:    xsi_vlog_unsigned_bit_combine(t142, 32, t173, 32, t196, 32);
    goto LAB72;

LAB70:    memcpy(t142, t173, 8);
    goto LAB72;

LAB73:    *((unsigned int *)t173) = 1;
    goto LAB76;

LAB78:    t186 = *((unsigned int *)t173);
    t187 = *((unsigned int *)t183);
    *((unsigned int *)t173) = (t186 | t187);
    t188 = *((unsigned int *)t182);
    t189 = *((unsigned int *)t183);
    *((unsigned int *)t182) = (t188 | t189);
    goto LAB77;

}

static void NetDecl_117_2(char *t0)
{
    char t5[8];
    char t7[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;

LAB0:    t1 = (t0 + 5072U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(117, ng0);
    t2 = (t0 + 1984U);
    t3 = *((char **)t2);
    t2 = (t0 + 2624U);
    t4 = *((char **)t2);
    memset(t5, 0, 8);
    xsi_vlog_unsigned_add(t5, 9, t3, 8, t4, 8);
    t2 = (t0 + 2784U);
    t6 = *((char **)t2);
    memset(t7, 0, 8);
    xsi_vlog_unsigned_add(t7, 9, t5, 9, t6, 1);
    t2 = (t0 + 6424);
    t8 = (t2 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memset(t11, 0, 8);
    t12 = 511U;
    t13 = t12;
    t14 = (t7 + 4);
    t15 = *((unsigned int *)t7);
    t12 = (t12 & t15);
    t16 = *((unsigned int *)t14);
    t13 = (t13 & t16);
    t17 = (t11 + 4);
    t18 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t18 | t12);
    t19 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t19 | t13);
    xsi_driver_vfirst_trans(t2, 0, 8U);
    t20 = (t0 + 6168);
    *((int *)t20) = 1;

LAB1:    return;
}

static void NetDecl_125_3(char *t0)
{
    char t3[8];
    char t4[8];
    char t6[8];
    char t35[8];
    char t47[8];
    char t48[8];
    char t51[8];
    char t80[8];
    char t92[8];
    char t93[8];
    char t96[8];
    char *t1;
    char *t2;
    char *t5;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    char *t49;
    char *t50;
    char *t52;
    char *t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    char *t66;
    char *t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    char *t73;
    char *t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    char *t78;
    char *t79;
    char *t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    char *t94;
    char *t95;
    char *t97;
    char *t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    char *t111;
    char *t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    char *t118;
    char *t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    char *t123;
    char *t124;
    unsigned int t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    char *t129;
    char *t130;
    char *t131;
    char *t132;
    char *t133;
    unsigned int t134;
    unsigned int t135;
    char *t136;
    unsigned int t137;
    unsigned int t138;
    char *t139;
    unsigned int t140;
    unsigned int t141;
    char *t142;

LAB0:    t1 = (t0 + 5320U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(125, ng0);
    t2 = (t0 + 1504U);
    t5 = *((char **)t2);
    t2 = ((char*)((ng7)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    t8 = (t2 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB7;

LAB4:    if (t18 != 0)
        goto LAB6;

LAB5:    *((unsigned int *)t6) = 1;

LAB7:    memset(t4, 0, 8);
    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 & 1U);
    if (t27 != 0)
        goto LAB8;

LAB9:    if (*((unsigned int *)t22) != 0)
        goto LAB10;

LAB11:    t29 = (t4 + 4);
    t30 = *((unsigned int *)t4);
    t31 = *((unsigned int *)t29);
    t32 = (t30 || t31);
    if (t32 > 0)
        goto LAB12;

LAB13:    t43 = *((unsigned int *)t4);
    t44 = (~(t43));
    t45 = *((unsigned int *)t29);
    t46 = (t44 || t45);
    if (t46 > 0)
        goto LAB14;

LAB15:    if (*((unsigned int *)t29) > 0)
        goto LAB16;

LAB17:    if (*((unsigned int *)t4) > 0)
        goto LAB18;

LAB19:    memcpy(t3, t47, 8);

LAB20:    t123 = (t0 + 6488);
    t130 = (t123 + 56U);
    t131 = *((char **)t130);
    t132 = (t131 + 56U);
    t133 = *((char **)t132);
    memset(t133, 0, 8);
    t134 = 1U;
    t135 = t134;
    t136 = (t3 + 4);
    t137 = *((unsigned int *)t3);
    t134 = (t134 & t137);
    t138 = *((unsigned int *)t136);
    t135 = (t135 & t138);
    t139 = (t133 + 4);
    t140 = *((unsigned int *)t133);
    *((unsigned int *)t133) = (t140 | t134);
    t141 = *((unsigned int *)t139);
    *((unsigned int *)t139) = (t141 | t135);
    xsi_driver_vfirst_trans(t123, 0, 0U);
    t142 = (t0 + 6184);
    *((int *)t142) = 1;

LAB1:    return;
LAB6:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB7;

LAB8:    *((unsigned int *)t4) = 1;
    goto LAB11;

LAB10:    t28 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB11;

LAB12:    t33 = (t0 + 1984U);
    t34 = *((char **)t33);
    memset(t35, 0, 8);
    t33 = (t35 + 4);
    t36 = (t34 + 4);
    t37 = *((unsigned int *)t34);
    t38 = (t37 >> 0);
    t39 = (t38 & 1);
    *((unsigned int *)t35) = t39;
    t40 = *((unsigned int *)t36);
    t41 = (t40 >> 0);
    t42 = (t41 & 1);
    *((unsigned int *)t33) = t42;
    goto LAB13;

LAB14:    t49 = (t0 + 1504U);
    t50 = *((char **)t49);
    t49 = ((char*)((ng8)));
    memset(t51, 0, 8);
    t52 = (t50 + 4);
    t53 = (t49 + 4);
    t54 = *((unsigned int *)t50);
    t55 = *((unsigned int *)t49);
    t56 = (t54 ^ t55);
    t57 = *((unsigned int *)t52);
    t58 = *((unsigned int *)t53);
    t59 = (t57 ^ t58);
    t60 = (t56 | t59);
    t61 = *((unsigned int *)t52);
    t62 = *((unsigned int *)t53);
    t63 = (t61 | t62);
    t64 = (~(t63));
    t65 = (t60 & t64);
    if (t65 != 0)
        goto LAB24;

LAB21:    if (t63 != 0)
        goto LAB23;

LAB22:    *((unsigned int *)t51) = 1;

LAB24:    memset(t48, 0, 8);
    t67 = (t51 + 4);
    t68 = *((unsigned int *)t67);
    t69 = (~(t68));
    t70 = *((unsigned int *)t51);
    t71 = (t70 & t69);
    t72 = (t71 & 1U);
    if (t72 != 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t67) != 0)
        goto LAB27;

LAB28:    t74 = (t48 + 4);
    t75 = *((unsigned int *)t48);
    t76 = *((unsigned int *)t74);
    t77 = (t75 || t76);
    if (t77 > 0)
        goto LAB29;

LAB30:    t88 = *((unsigned int *)t48);
    t89 = (~(t88));
    t90 = *((unsigned int *)t74);
    t91 = (t89 || t90);
    if (t91 > 0)
        goto LAB31;

LAB32:    if (*((unsigned int *)t74) > 0)
        goto LAB33;

LAB34:    if (*((unsigned int *)t48) > 0)
        goto LAB35;

LAB36:    memcpy(t47, t92, 8);

LAB37:    goto LAB15;

LAB16:    xsi_vlog_unsigned_bit_combine(t3, 1, t35, 1, t47, 1);
    goto LAB20;

LAB18:    memcpy(t3, t35, 8);
    goto LAB20;

LAB23:    t66 = (t51 + 4);
    *((unsigned int *)t51) = 1;
    *((unsigned int *)t66) = 1;
    goto LAB24;

LAB25:    *((unsigned int *)t48) = 1;
    goto LAB28;

LAB27:    t73 = (t48 + 4);
    *((unsigned int *)t48) = 1;
    *((unsigned int *)t73) = 1;
    goto LAB28;

LAB29:    t78 = (t0 + 1984U);
    t79 = *((char **)t78);
    memset(t80, 0, 8);
    t78 = (t80 + 4);
    t81 = (t79 + 4);
    t82 = *((unsigned int *)t79);
    t83 = (t82 >> 7);
    t84 = (t83 & 1);
    *((unsigned int *)t80) = t84;
    t85 = *((unsigned int *)t81);
    t86 = (t85 >> 7);
    t87 = (t86 & 1);
    *((unsigned int *)t78) = t87;
    goto LAB30;

LAB31:    t94 = (t0 + 1504U);
    t95 = *((char **)t94);
    t94 = ((char*)((ng9)));
    memset(t96, 0, 8);
    t97 = (t95 + 4);
    t98 = (t94 + 4);
    t99 = *((unsigned int *)t95);
    t100 = *((unsigned int *)t94);
    t101 = (t99 ^ t100);
    t102 = *((unsigned int *)t97);
    t103 = *((unsigned int *)t98);
    t104 = (t102 ^ t103);
    t105 = (t101 | t104);
    t106 = *((unsigned int *)t97);
    t107 = *((unsigned int *)t98);
    t108 = (t106 | t107);
    t109 = (~(t108));
    t110 = (t105 & t109);
    if (t110 != 0)
        goto LAB41;

LAB38:    if (t108 != 0)
        goto LAB40;

LAB39:    *((unsigned int *)t96) = 1;

LAB41:    memset(t93, 0, 8);
    t112 = (t96 + 4);
    t113 = *((unsigned int *)t112);
    t114 = (~(t113));
    t115 = *((unsigned int *)t96);
    t116 = (t115 & t114);
    t117 = (t116 & 1U);
    if (t117 != 0)
        goto LAB42;

LAB43:    if (*((unsigned int *)t112) != 0)
        goto LAB44;

LAB45:    t119 = (t93 + 4);
    t120 = *((unsigned int *)t93);
    t121 = *((unsigned int *)t119);
    t122 = (t120 || t121);
    if (t122 > 0)
        goto LAB46;

LAB47:    t125 = *((unsigned int *)t93);
    t126 = (~(t125));
    t127 = *((unsigned int *)t119);
    t128 = (t126 || t127);
    if (t128 > 0)
        goto LAB48;

LAB49:    if (*((unsigned int *)t119) > 0)
        goto LAB50;

LAB51:    if (*((unsigned int *)t93) > 0)
        goto LAB52;

LAB53:    memcpy(t92, t129, 8);

LAB54:    goto LAB32;

LAB33:    xsi_vlog_unsigned_bit_combine(t47, 1, t80, 1, t92, 1);
    goto LAB37;

LAB35:    memcpy(t47, t80, 8);
    goto LAB37;

LAB40:    t111 = (t96 + 4);
    *((unsigned int *)t96) = 1;
    *((unsigned int *)t111) = 1;
    goto LAB41;

LAB42:    *((unsigned int *)t93) = 1;
    goto LAB45;

LAB44:    t118 = (t93 + 4);
    *((unsigned int *)t93) = 1;
    *((unsigned int *)t118) = 1;
    goto LAB45;

LAB46:    t123 = (t0 + 2304U);
    t124 = *((char **)t123);
    goto LAB47;

LAB48:    t123 = (t0 + 1824U);
    t129 = *((char **)t123);
    goto LAB49;

LAB50:    xsi_vlog_unsigned_bit_combine(t92, 1, t124, 1, t129, 1);
    goto LAB54;

LAB52:    memcpy(t92, t124, 8);
    goto LAB54;

}

static void Cont_135_4(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;

LAB0:    t1 = (t0 + 5568U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(135, ng0);
    t2 = (t0 + 3504);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t3, 0, 8);
    t6 = (t5 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 255U);
    if (t11 != 0)
        goto LAB7;

LAB5:    if (*((unsigned int *)t6) == 0)
        goto LAB4;

LAB6:    t12 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t12) = 1;

LAB7:    t13 = (t0 + 6552);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    memset(t17, 0, 8);
    t18 = 1U;
    t19 = t18;
    t20 = (t3 + 4);
    t21 = *((unsigned int *)t3);
    t18 = (t18 & t21);
    t22 = *((unsigned int *)t20);
    t19 = (t19 & t22);
    t23 = (t17 + 4);
    t24 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t24 | t18);
    t25 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t25 | t19);
    xsi_driver_vfirst_trans(t13, 0, 0);
    t26 = (t0 + 6200);
    *((int *)t26) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t3) = 1;
    goto LAB7;

}

static void Always_162_5(char *t0)
{
    char t10[8];
    char t11[8];
    char t18[8];
    char t21[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    int t9;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t19;
    char *t20;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    char *t36;
    char *t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    char *t46;
    char *t47;
    int t48;
    int t49;
    int t50;

LAB0:    t1 = (t0 + 5816U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(162, ng0);
    t2 = (t0 + 6216);
    *((int *)t2) = 1;
    t3 = (t0 + 5848);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(169, ng0);

LAB5:    t4 = (t0 + 280);
    xsi_vlog_namedbase_setdisablestate(t4, &&LAB6);
    t5 = (t0 + 5624);
    xsi_vlog_namedbase_pushprocess(t4, t5);

LAB7:    xsi_set_current_line(171, ng0);
    t6 = ((char*)((ng6)));
    t7 = (t0 + 3664);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 1);
    xsi_set_current_line(180, ng0);
    t2 = (t0 + 1344U);
    t3 = *((char **)t2);

LAB8:    t2 = ((char*)((ng10)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 5, t2, 5);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng4)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 5, t2, 5);
    if (t8 == 1)
        goto LAB11;

LAB12:    t4 = ((char*)((ng3)));
    t9 = xsi_vlog_unsigned_case_compare(t3, 5, t4, 5);
    if (t9 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng1)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 5, t2, 5);
    if (t8 == 1)
        goto LAB15;

LAB16:    t4 = ((char*)((ng2)));
    t9 = xsi_vlog_unsigned_case_compare(t3, 5, t4, 5);
    if (t9 == 1)
        goto LAB17;

LAB18:    t5 = ((char*)((ng11)));
    t48 = xsi_vlog_unsigned_case_compare(t3, 5, t5, 5);
    if (t48 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng12)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 5, t2, 5);
    if (t8 == 1)
        goto LAB21;

LAB22:    t2 = ((char*)((ng13)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 5, t2, 5);
    if (t8 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng14)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 5, t2, 5);
    if (t8 == 1)
        goto LAB25;

LAB26:    t2 = ((char*)((ng15)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 5, t2, 5);
    if (t8 == 1)
        goto LAB27;

LAB28:
LAB30:
LAB29:    xsi_set_current_line(231, ng0);
    t2 = (t0 + 2144U);
    t4 = *((char **)t2);
    t2 = (t0 + 3504);
    xsi_vlogvar_assign_value(t2, t4, 0, 0, 8);

LAB31:    t2 = (t0 + 280);
    xsi_vlog_namedbase_popprocess(t2);

LAB6:    t4 = (t0 + 5624);
    xsi_vlog_dispose_process_subprogram_invocation(t4);
    goto LAB2;

LAB9:    xsi_set_current_line(185, ng0);
    t4 = (t0 + 2944U);
    t5 = *((char **)t4);
    t4 = (t0 + 3504);
    xsi_vlogvar_assign_value(t4, t5, 0, 0, 8);
    t6 = (t0 + 3664);
    xsi_vlogvar_assign_value(t6, t5, 8, 0, 1);
    goto LAB31;

LAB11:    goto LAB9;

LAB13:    xsi_set_current_line(191, ng0);

LAB32:    xsi_set_current_line(192, ng0);
    t5 = (t0 + 2944U);
    t6 = *((char **)t5);
    memset(t11, 0, 8);
    t5 = (t11 + 4);
    t7 = (t6 + 4);
    t12 = *((unsigned int *)t6);
    t13 = (t12 >> 0);
    *((unsigned int *)t11) = t13;
    t14 = *((unsigned int *)t7);
    t15 = (t14 >> 0);
    *((unsigned int *)t5) = t15;
    t16 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t16 & 255U);
    t17 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t17 & 255U);
    t19 = (t0 + 2944U);
    t20 = *((char **)t19);
    memset(t21, 0, 8);
    t19 = (t21 + 4);
    t22 = (t20 + 4);
    t23 = *((unsigned int *)t20);
    t24 = (t23 >> 8);
    t25 = (t24 & 1);
    *((unsigned int *)t21) = t25;
    t26 = *((unsigned int *)t22);
    t27 = (t26 >> 8);
    t28 = (t27 & 1);
    *((unsigned int *)t19) = t28;
    memset(t18, 0, 8);
    t29 = (t21 + 4);
    t30 = *((unsigned int *)t29);
    t31 = (~(t30));
    t32 = *((unsigned int *)t21);
    t33 = (t32 & t31);
    t34 = (t33 & 1U);
    if (t34 != 0)
        goto LAB36;

LAB34:    if (*((unsigned int *)t29) == 0)
        goto LAB33;

LAB35:    t35 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t35) = 1;

LAB36:    t36 = (t18 + 4);
    t37 = (t21 + 4);
    t38 = *((unsigned int *)t21);
    t39 = (~(t38));
    *((unsigned int *)t18) = t39;
    *((unsigned int *)t36) = 0;
    if (*((unsigned int *)t37) != 0)
        goto LAB38;

LAB37:    t44 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t44 & 1U);
    t45 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t45 & 1U);
    xsi_vlogtype_concat(t10, 9, 9, 2U, t18, 1, t11, 8);
    t46 = (t0 + 3504);
    xsi_vlogvar_assign_value(t46, t10, 0, 0, 8);
    t47 = (t0 + 3664);
    xsi_vlogvar_assign_value(t47, t10, 8, 0, 1);
    goto LAB31;

LAB15:    goto LAB13;

LAB17:    goto LAB13;

LAB19:    xsi_set_current_line(196, ng0);
    t6 = (t0 + 1984U);
    t7 = *((char **)t6);
    t6 = (t0 + 2144U);
    t19 = *((char **)t6);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t19);
    t14 = (t12 & t13);
    *((unsigned int *)t10) = t14;
    t6 = (t7 + 4);
    t20 = (t19 + 4);
    t22 = (t10 + 4);
    t15 = *((unsigned int *)t6);
    t16 = *((unsigned int *)t20);
    t17 = (t15 | t16);
    *((unsigned int *)t22) = t17;
    t23 = *((unsigned int *)t22);
    t24 = (t23 != 0);
    if (t24 == 1)
        goto LAB39;

LAB40:
LAB41:    t36 = (t0 + 3504);
    xsi_vlogvar_assign_value(t36, t10, 0, 0, 8);
    goto LAB31;

LAB21:    xsi_set_current_line(199, ng0);
    t4 = (t0 + 1984U);
    t5 = *((char **)t4);
    t4 = (t0 + 2144U);
    t6 = *((char **)t4);
    t12 = *((unsigned int *)t5);
    t13 = *((unsigned int *)t6);
    t14 = (t12 | t13);
    *((unsigned int *)t10) = t14;
    t4 = (t5 + 4);
    t7 = (t6 + 4);
    t19 = (t10 + 4);
    t15 = *((unsigned int *)t4);
    t16 = *((unsigned int *)t7);
    t17 = (t15 | t16);
    *((unsigned int *)t19) = t17;
    t23 = *((unsigned int *)t19);
    t24 = (t23 != 0);
    if (t24 == 1)
        goto LAB42;

LAB43:
LAB44:    t29 = (t0 + 3504);
    xsi_vlogvar_assign_value(t29, t10, 0, 0, 8);
    goto LAB31;

LAB23:    xsi_set_current_line(203, ng0);

LAB45:    xsi_set_current_line(203, ng0);
    t4 = (t0 + 1984U);
    t5 = *((char **)t4);
    t4 = (t0 + 2144U);
    t6 = *((char **)t4);
    t12 = *((unsigned int *)t5);
    t13 = *((unsigned int *)t6);
    t14 = (t12 & t13);
    *((unsigned int *)t10) = t14;
    t4 = (t5 + 4);
    t7 = (t6 + 4);
    t19 = (t10 + 4);
    t15 = *((unsigned int *)t4);
    t16 = *((unsigned int *)t7);
    t17 = (t15 | t16);
    *((unsigned int *)t19) = t17;
    t23 = *((unsigned int *)t19);
    t24 = (t23 != 0);
    if (t24 == 1)
        goto LAB46;

LAB47:
LAB48:    t29 = (t0 + 3504);
    xsi_vlogvar_assign_value(t29, t10, 0, 0, 8);
    xsi_set_current_line(203, ng0);
    t2 = (t0 + 3504);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t10, 0, 8);
    t6 = (t5 + 4);
    t12 = *((unsigned int *)t5);
    t13 = *((unsigned int *)t5);
    t13 = (t13 & 1);
    if (*((unsigned int *)t6) != 0)
        goto LAB49;

LAB50:    t14 = 1;

LAB52:    t15 = (t14 <= 7);
    if (t15 == 1)
        goto LAB53;

LAB54:    *((unsigned int *)t10) = t13;

LAB51:    t19 = (t0 + 3664);
    xsi_vlogvar_assign_value(t19, t10, 0, 0, 1);
    goto LAB31;

LAB25:    xsi_set_current_line(207, ng0);
    t4 = (t0 + 1984U);
    t5 = *((char **)t4);
    t4 = (t0 + 2144U);
    t6 = *((char **)t4);
    t12 = *((unsigned int *)t5);
    t13 = *((unsigned int *)t6);
    t14 = (t12 ^ t13);
    *((unsigned int *)t10) = t14;
    t4 = (t5 + 4);
    t7 = (t6 + 4);
    t19 = (t10 + 4);
    t15 = *((unsigned int *)t4);
    t16 = *((unsigned int *)t7);
    t17 = (t15 | t16);
    *((unsigned int *)t19) = t17;
    t23 = *((unsigned int *)t19);
    t24 = (t23 != 0);
    if (t24 == 1)
        goto LAB56;

LAB57:
LAB58:    t20 = (t0 + 3504);
    xsi_vlogvar_assign_value(t20, t10, 0, 0, 8);
    goto LAB31;

LAB27:    xsi_set_current_line(210, ng0);
    t4 = (t0 + 1664U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t12 = *((unsigned int *)t4);
    t13 = (~(t12));
    t14 = *((unsigned int *)t5);
    t15 = (t14 & t13);
    t16 = (t15 != 0);
    if (t16 > 0)
        goto LAB59;

LAB60:    xsi_set_current_line(213, ng0);
    t2 = (t0 + 3104U);
    t4 = *((char **)t2);
    t2 = (t0 + 1984U);
    t5 = *((char **)t2);
    xsi_vlogtype_concat(t10, 9, 9, 2U, t5, 8, t4, 1);
    t2 = (t0 + 3504);
    xsi_vlogvar_assign_value(t2, t10, 0, 0, 8);
    t6 = (t0 + 3664);
    xsi_vlogvar_assign_value(t6, t10, 8, 0, 1);

LAB61:    goto LAB31;

LAB33:    *((unsigned int *)t18) = 1;
    goto LAB36;

LAB38:    t40 = *((unsigned int *)t18);
    t41 = *((unsigned int *)t37);
    *((unsigned int *)t18) = (t40 | t41);
    t42 = *((unsigned int *)t36);
    t43 = *((unsigned int *)t37);
    *((unsigned int *)t36) = (t42 | t43);
    goto LAB37;

LAB39:    t25 = *((unsigned int *)t10);
    t26 = *((unsigned int *)t22);
    *((unsigned int *)t10) = (t25 | t26);
    t29 = (t7 + 4);
    t35 = (t19 + 4);
    t27 = *((unsigned int *)t7);
    t28 = (~(t27));
    t30 = *((unsigned int *)t29);
    t31 = (~(t30));
    t32 = *((unsigned int *)t19);
    t33 = (~(t32));
    t34 = *((unsigned int *)t35);
    t38 = (~(t34));
    t49 = (t28 & t31);
    t50 = (t33 & t38);
    t39 = (~(t49));
    t40 = (~(t50));
    t41 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t41 & t39);
    t42 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t42 & t40);
    t43 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t43 & t39);
    t44 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t44 & t40);
    goto LAB41;

LAB42:    t25 = *((unsigned int *)t10);
    t26 = *((unsigned int *)t19);
    *((unsigned int *)t10) = (t25 | t26);
    t20 = (t5 + 4);
    t22 = (t6 + 4);
    t27 = *((unsigned int *)t20);
    t28 = (~(t27));
    t30 = *((unsigned int *)t5);
    t9 = (t30 & t28);
    t31 = *((unsigned int *)t22);
    t32 = (~(t31));
    t33 = *((unsigned int *)t6);
    t48 = (t33 & t32);
    t34 = (~(t9));
    t38 = (~(t48));
    t39 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t39 & t34);
    t40 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t40 & t38);
    goto LAB44;

LAB46:    t25 = *((unsigned int *)t10);
    t26 = *((unsigned int *)t19);
    *((unsigned int *)t10) = (t25 | t26);
    t20 = (t5 + 4);
    t22 = (t6 + 4);
    t27 = *((unsigned int *)t5);
    t28 = (~(t27));
    t30 = *((unsigned int *)t20);
    t31 = (~(t30));
    t32 = *((unsigned int *)t6);
    t33 = (~(t32));
    t34 = *((unsigned int *)t22);
    t38 = (~(t34));
    t9 = (t28 & t31);
    t48 = (t33 & t38);
    t39 = (~(t9));
    t40 = (~(t48));
    t41 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t41 & t39);
    t42 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t42 & t40);
    t43 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t43 & t39);
    t44 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t44 & t40);
    goto LAB48;

LAB49:    t7 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB51;

LAB53:    t12 = (t12 >> 1);
    t16 = (t12 & 1);
    t13 = (t13 ^ t16);

LAB55:    t14 = (t14 + 1);
    goto LAB52;

LAB56:    t25 = *((unsigned int *)t10);
    t26 = *((unsigned int *)t19);
    *((unsigned int *)t10) = (t25 | t26);
    goto LAB58;

LAB59:    xsi_set_current_line(211, ng0);
    t6 = (t0 + 1984U);
    t7 = *((char **)t6);
    t6 = (t0 + 3104U);
    t19 = *((char **)t6);
    xsi_vlogtype_concat(t10, 9, 9, 2U, t19, 1, t7, 8);
    t6 = (t0 + 3664);
    xsi_vlogvar_assign_value(t6, t10, 0, 0, 1);
    t20 = (t0 + 3504);
    xsi_vlogvar_assign_value(t20, t10, 1, 0, 8);
    goto LAB61;

}


extern void work_m_06248104783644521963_3632919521_init()
{
	static char *pe[] = {(void *)NetDecl_79_0,(void *)NetDecl_95_1,(void *)NetDecl_117_2,(void *)NetDecl_125_3,(void *)Cont_135_4,(void *)Always_162_5};
	xsi_register_didat("work_m_06248104783644521963_3632919521", "isim/top_tb.exe.sim/work/m_06248104783644521963_3632919521.didat");
	xsi_register_executes(pe);
}
