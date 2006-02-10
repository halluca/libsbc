#ifndef __SBC_MATH_H
#define __SBC_MATH_H

#include <stdint.h>

#define fabs(x) ((x) < 0 ?-(x) : (x))
/* C does not provide an explicit arithmetic shift right but this will
   always be correct and every compiler *should* generate optimal code */
#define ASR(val, bits) ((-2>>1==-1)? ((int32_t)(val))>>bits : ((int32_t)(val))/(1<<bits))

#define SCALE_PROTO4_TBL 15
#define SCALE_ANA4_TBL 16
#define SCALE_PROTO8_TBL 15
#define SCALE_ANA8_TBL 16
#define SCALE_SPROTO4_TBL 16
#define SCALE_SPROTO8_TBL 16
#define SCALE_NPROTO4_TBL 10
#define SCALE_NPROTO8_TBL 12
#define SCALE_SAMPLES 14
#define SCALE4_STAGE1_BITS 16
#define SCALE4_STAGE2_BITS 18
#define SCALE4_STAGED1_BITS 15
#define SCALE4_STAGED2_BITS 15
#define SCALE8_STAGE1_BITS 16
#define SCALE8_STAGE2_BITS 18
#define SCALE8_STAGED1_BITS 15
#define SCALE8_STAGED2_BITS 15

typedef int32_t sbc_fixed_t;

#define DIV2(dst, src) {dst = ASR(src, 1);}
#define SCALE4_STAGE1(src) ASR(src, SCALE4_STAGE1_BITS)
#define SCALE4_STAGE2(src) ASR(src, SCALE4_STAGE2_BITS)
#define SCALE4_STAGED1(src) ASR(src, SCALE4_STAGED1_BITS)
#define SCALE4_STAGED2(src) ASR(src, SCALE4_STAGED2_BITS)
#define SCALE8_STAGE1(src) ASR(src, SCALE8_STAGE1_BITS)
#define SCALE8_STAGE2(src) ASR(src, SCALE8_STAGE2_BITS)
#define SCALE8_STAGED1(src) ASR(src, SCALE8_STAGED1_BITS)
#define SCALE8_STAGED2(src) ASR(src, SCALE8_STAGED2_BITS)

#define SBC_FIXED_0(val) {val = 0;}
#define ADD(dst, src)  {dst += src;}
#define SUB(dst, src)  {dst -= src;}
#define MUL(dst, a, b) {dst = (sbc_fixed_t)a * b;}
#define MULA(dst, a, b)  {dst += (sbc_fixed_t)a * b;}

#endif // __SBC_MATH_H
