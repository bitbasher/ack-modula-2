#ifndef NORCSID
static char rcsid4[] = "$Header$";
#endif

#include "nopt.h"

OO_rotate(w,amount)
	int w, amount;
{
	long highmask, lowmask;
	highmask = (long)(-1) << amount;
	lowmask = ~highmask;
	if(OO_WSIZE!=4)
		highmask &= (OO_WSIZE==2)?0xFFFF:0xFF;
	return(((w<<amount)&highmask) | ((w >> (8*OO_WSIZE-amount))&lowmask));
}

OO_signsame(a,b)
	int a, b;
{
	return( (a ^ b) >= 0);
}

OO_sfit(val,nbits)
	int val, nbits;
{
	register long mask = 0;
	register int i;
	for(i=nbits-1;i<8*sizeof(mask);i++)
		mask |= (1<<i);
	return(((val&mask) == 0) | (val&mask)==mask);
}

OO_ufit(val, nbits)
	int val, nbits;
{
	register long mask = 0;
	register int i;
	for(i=nbits;i<8*sizeof(mask);i++)
		mask |= (1<<i);
	return((val&mask) == 0);
}

OO_extsame(a1,a2)
	register p_instr a1, a2;
{
	if (a1->em_argtype != a2->em_argtype)
		return(0);
	switch(a1->em_argtype) {
	case cst_ptyp:
		return (a1->em_cst == a2->em_cst);
	case sof_ptyp:
		if(a1->em_off != a2->em_off)
			return(0);
		return (strcmp(a1->em_dnam,a2->em_dnam)==0);
	case nof_ptyp:
		if (a1->em_off != a2->em_off)
			return(0);
		return (a1->em_dlb == a2->em_dlb);
	default:
		fatal("illegal type (%d) to sameext!",a1->em_argtype);
	}
}

OO_namsame(a1,a2)
	register p_instr a1, a2;
{
	if (a1->em_argtype != a2->em_argtype)
		return(0);
	switch(a1->em_argtype) {
	case cst_ptyp:
		return 1;
	case sof_ptyp:
		return (strcmp(a1->em_dnam,a2->em_dnam)==0);
	case nof_ptyp:
		return (a1->em_dlb == a2->em_dlb);
	default:
		fatal("illegal type (%d) to samenam!",a1->em_argtype);
	}
}

OO_offset(a)
	register p_instr a;
{
	switch(a->em_argtype) {
	case cst_ptyp:
		return a->em_cst;
	case sof_ptyp:
		return a->em_off;
	case nof_ptyp:
		return a->em_off;
	default:
		fatal("illegal type (%d) to offset!",a->em_argtype);
	}
}
