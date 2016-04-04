/*********************************************************************/
/*                                                                   */
/*             Optimized BLAS libraries                              */
/*                     By Kazushige Goto <kgoto@tacc.utexas.edu>     */
/*                                                                   */
/* Copyright (c) The University of Texas, 2009. All rights reserved. */
/* UNIVERSITY EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES CONCERNING  */
/* THIS SOFTWARE AND DOCUMENTATION, INCLUDING ANY WARRANTIES OF      */
/* MERCHANTABILITY, FITNESS FOR ANY PARTICULAR PURPOSE,              */
/* NON-INFRINGEMENT AND WARRANTIES OF PERFORMANCE, AND ANY WARRANTY  */
/* THAT MIGHT OTHERWISE ARISE FROM COURSE OF DEALING OR USAGE OF     */
/* TRADE. NO WARRANTY IS EITHER EXPRESS OR IMPLIED WITH RESPECT TO   */
/* THE USE OF THE SOFTWARE OR DOCUMENTATION.                         */
/* Under no circumstances shall University be liable for incidental, */
/* special, indirect, direct or consequential damages or loss of     */
/* profits, interruption of business, or related expenses which may  */
/* arise from use of Software or Documentation, including but not    */
/* limited to those resulting from defects in Software and/or        */
/* Documentation, or loss or inaccuracy of data of any kind.         */
/*********************************************************************/

#include <stdio.h>
#include "common.h"

int CNAME(BLASLONG m, BLASLONG n, FLOAT *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, FLOAT *b){

  BLASLONG i, js;
  BLASLONG X;

  FLOAT data01, data02, data03, data04, data05, data06, data07, data08;
  FLOAT data09, data10, data11, data12, data13, data14, data15, data16;
  FLOAT data17, data18, data19, data20, data21, data22, data23, data24;
  FLOAT data25, data26, data27, data28, data29, data30, data31, data32;
  FLOAT data33, data34, data35, data36, data37, data38, data39, data40;
  FLOAT data41, data42, data43, data44, data45, data46, data47, data48;
  FLOAT data49, data50, data51, data52, data53, data54, data55, data56;
  FLOAT data57, data58, data59, data60, data61, data62, data63, data64;

  FLOAT *ao1, *ao2, *ao3, *ao4, *ao5, *ao6, *ao7, *ao8;

  js = (n >> 3);

  if (js > 0){
    do {
      X = posX;

      if (posX <= posY) {
	ao1 = a + posX + (posY + 0) * lda;
	ao2 = a + posX + (posY + 1) * lda;
	ao3 = a + posX + (posY + 2) * lda;
	ao4 = a + posX + (posY + 3) * lda;
	ao5 = a + posX + (posY + 4) * lda;
	ao6 = a + posX + (posY + 5) * lda;
	ao7 = a + posX + (posY + 6) * lda;
	ao8 = a + posX + (posY + 7) * lda;
      } else {
	ao1 = a + posY + (posX + 0) * lda;
	ao2 = a + posY + (posX + 1) * lda;
	ao3 = a + posY + (posX + 2) * lda;
	ao4 = a + posY + (posX + 3) * lda;
	ao5 = a + posY + (posX + 4) * lda;
	ao6 = a + posY + (posX + 5) * lda;
	ao7 = a + posY + (posX + 6) * lda;
	ao8 = a + posY + (posX + 7) * lda;
      }
      
      i = (m >> 3);
      if (i > 0) {
	do {
	  if (X < posY) {
	    ao1 += 8;
	    ao2 += 8;
	    ao3 += 8;
	    ao4 += 8;
	    ao5 += 8;
	    ao6 += 8;
	    ao7 += 8;
	    ao8 += 8;

	    b += 64;
	  } else 
	    if (X > posY) {
	      data01 = *(ao1 + 0);
	      data02 = *(ao1 + 1);
	      data03 = *(ao1 + 2);
	      data04 = *(ao1 + 3);
	      data05 = *(ao1 + 4);
	      data06 = *(ao1 + 5);
	      data07 = *(ao1 + 6);
	      data08 = *(ao1 + 7);
	      
	      data09 = *(ao2 + 0);
	      data10 = *(ao2 + 1);
	      data11 = *(ao2 + 2);
	      data12 = *(ao2 + 3);
	      data13 = *(ao2 + 4);
	      data14 = *(ao2 + 5);
	      data15 = *(ao2 + 6);
	      data16 = *(ao2 + 7);
	      
	      data17 = *(ao3 + 0);
	      data18 = *(ao3 + 1);
	      data19 = *(ao3 + 2);
	      data20 = *(ao3 + 3);
	      data21 = *(ao3 + 4);
	      data22 = *(ao3 + 5);
	      data23 = *(ao3 + 6);
	      data24 = *(ao3 + 7);
	      
	      data25 = *(ao4 + 0);
	      data26 = *(ao4 + 1);
	      data27 = *(ao4 + 2);
	      data28 = *(ao4 + 3);
	      data29 = *(ao4 + 4);
	      data30 = *(ao4 + 5);
	      data31 = *(ao4 + 6);
	      data32 = *(ao4 + 7);
	      
	      data33 = *(ao5 + 0);
	      data34 = *(ao5 + 1);
	      data35 = *(ao5 + 2);
	      data36 = *(ao5 + 3);
	      data37 = *(ao5 + 4);
	      data38 = *(ao5 + 5);
	      data39 = *(ao5 + 6);
	      data40 = *(ao5 + 7);
	  
	      data41 = *(ao6 + 0);
	      data42 = *(ao6 + 1);
	      data43 = *(ao6 + 2);
	      data44 = *(ao6 + 3);
	      data45 = *(ao6 + 4);
	      data46 = *(ao6 + 5);
	      data47 = *(ao6 + 6);
	      data48 = *(ao6 + 7);

	      data49 = *(ao7 + 0);
	      data50 = *(ao7 + 1);
	      data51 = *(ao7 + 2);
	      data52 = *(ao7 + 3);
	      data53 = *(ao7 + 4);
	      data54 = *(ao7 + 5);
	      data55 = *(ao7 + 6);
	      data56 = *(ao7 + 7);
	      
	      data57 = *(ao8 + 0);
	      data58 = *(ao8 + 1);
	      data59 = *(ao8 + 2);
	      data60 = *(ao8 + 3);
	      data61 = *(ao8 + 4);
	      data62 = *(ao8 + 5);
	      data63 = *(ao8 + 6);
	      data64 = *(ao8 + 7);
	      
	      b[ 0] = data01;
	      b[ 1] = data02;
	      b[ 2] = data03;
	      b[ 3] = data04;
	      b[ 4] = data05;
	      b[ 5] = data06;
	      b[ 6] = data07;
	      b[ 7] = data08;
	      
	      b[ 8] = data09;
	      b[ 9] = data10;
	      b[10] = data11;
	      b[11] = data12;
	      b[12] = data13;
	      b[13] = data14;
	      b[14] = data15;
	      b[15] = data16;

	      b[16] = data17;
	      b[17] = data18;
	      b[18] = data19;
	      b[19] = data20;
	      b[20] = data21;
	      b[21] = data22;
	      b[22] = data23;
	      b[23] = data24;
	      
	      b[24] = data25;
	      b[25] = data26;
	      b[26] = data27;
	      b[27] = data28;
	      b[28] = data29;
	      b[29] = data30;
	      b[30] = data31;
	      b[31] = data32;

	      b[32] = data33;
	      b[33] = data34;
	      b[34] = data35;
	      b[35] = data36;
	      b[36] = data37;
	      b[37] = data38;
	      b[38] = data39;
	      b[39] = data40;
	      
	      b[40] = data41;
	      b[41] = data42;
	      b[42] = data43;
	      b[43] = data44;
	      b[44] = data45;
	      b[45] = data46;
	      b[46] = data47;
	      b[47] = data48;

	      b[48] = data49;
	      b[49] = data50;
	      b[50] = data51;
	      b[51] = data52;
	      b[52] = data53;
	      b[53] = data54;
	      b[54] = data55;
	      b[55] = data56;

	      b[56] = data57;
	      b[57] = data58;
	      b[58] = data59;
	      b[59] = data60;
	      b[60] = data61;
	      b[61] = data62;
	      b[62] = data63;
	      b[63] = data64;
	      
	      ao1 += 8 * lda;
	      ao2 += 8 * lda;
	      ao3 += 8 * lda;
	      ao4 += 8 * lda;
	      ao5 += 8 * lda;
	      ao6 += 8 * lda;
	      ao7 += 8 * lda;
	      ao8 += 8 * lda;
	      
	      b += 64;

	    } else {
#ifdef UNIT
	      data09 = *(ao2 + 0);
	      
	      data17 = *(ao3 + 0);
	      data18 = *(ao3 + 1);
	      
	      data25 = *(ao4 + 0);
	      data26 = *(ao4 + 1);
	      data27 = *(ao4 + 2);
	      
	      data33 = *(ao5 + 0);
	      data34 = *(ao5 + 1);
	      data35 = *(ao5 + 2);
	      data36 = *(ao5 + 3);
	  
	      data41 = *(ao6 + 0);
	      data42 = *(ao6 + 1);
	      data43 = *(ao6 + 2);
	      data44 = *(ao6 + 3);
	      data45 = *(ao6 + 4);

	      data49 = *(ao7 + 0);
	      data50 = *(ao7 + 1);
	      data51 = *(ao7 + 2);
	      data52 = *(ao7 + 3);
	      data53 = *(ao7 + 4);
	      data54 = *(ao7 + 5);
	      
	      data57 = *(ao8 + 0);
	      data58 = *(ao8 + 1);
	      data59 = *(ao8 + 2);
	      data60 = *(ao8 + 3);
	      data61 = *(ao8 + 4);
	      data62 = *(ao8 + 5);
	      data63 = *(ao8 + 6);

	      b[ 0] = ONE;
	      b[ 1] = ZERO;
	      b[ 2] = ZERO;
	      b[ 3] = ZERO;
	      b[ 4] = ZERO;
	      b[ 5] = ZERO;
	      b[ 6] = ZERO;
	      b[ 7] = ZERO;
	      
	      b[ 8] = data09;
	      b[ 9] = ONE;
	      b[10] = ZERO;
	      b[11] = ZERO;
	      b[12] = ZERO;
	      b[13] = ZERO;
	      b[14] = ZERO;
	      b[15] = ZERO;

	      b[16] = data17;
	      b[17] = data18;
	      b[18] = ONE;
	      b[19] = ZERO;
	      b[20] = ZERO;
	      b[21] = ZERO;
	      b[22] = ZERO;
	      b[23] = ZERO;
	      
	      b[24] = data25;
	      b[25] = data26;
	      b[26] = data27;
	      b[27] = ONE;
	      b[28] = ZERO;
	      b[29] = ZERO;
	      b[30] = ZERO;
	      b[31] = ZERO;

	      b[32] = data33;
	      b[33] = data34;
	      b[34] = data35;
	      b[35] = data36;
	      b[36] = ONE;
	      b[37] = ZERO;
	      b[38] = ZERO;
	      b[39] = ZERO;
	      
	      b[40] = data41;
	      b[41] = data42;
	      b[42] = data43;
	      b[43] = data44;
	      b[44] = data45;
	      b[45] = ONE;
	      b[46] = ZERO;
	      b[47] = ZERO;

	      b[48] = data49;
	      b[49] = data50;
	      b[50] = data51;
	      b[51] = data52;
	      b[52] = data53;
	      b[53] = data54;
	      b[54] = ONE;
	      b[55] = ZERO;

	      b[56] = data57;
	      b[57] = data58;
	      b[58] = data59;
	      b[59] = data60;
	      b[60] = data61;
	      b[61] = data62;
	      b[62] = data63;
	      b[63] = ONE;
#else
	      data01 = *(ao1 + 0);

	      data09 = *(ao2 + 0);
	      data10 = *(ao2 + 1);
	      
	      data17 = *(ao3 + 0);
	      data18 = *(ao3 + 1);
	      data19 = *(ao3 + 2);
	      
	      data25 = *(ao4 + 0);
	      data26 = *(ao4 + 1);
	      data27 = *(ao4 + 2);
	      data28 = *(ao4 + 3);
	      
	      data33 = *(ao5 + 0);
	      data34 = *(ao5 + 1);
	      data35 = *(ao5 + 2);
	      data36 = *(ao5 + 3);
	      data37 = *(ao5 + 4);
	  
	      data41 = *(ao6 + 0);
	      data42 = *(ao6 + 1);
	      data43 = *(ao6 + 2);
	      data44 = *(ao6 + 3);
	      data45 = *(ao6 + 4);
	      data46 = *(ao6 + 5);

	      data49 = *(ao7 + 0);
	      data50 = *(ao7 + 1);
	      data51 = *(ao7 + 2);
	      data52 = *(ao7 + 3);
	      data53 = *(ao7 + 4);
	      data54 = *(ao7 + 5);
	      data55 = *(ao7 + 6);
	      
	      data57 = *(ao8 + 0);
	      data58 = *(ao8 + 1);
	      data59 = *(ao8 + 2);
	      data60 = *(ao8 + 3);
	      data61 = *(ao8 + 4);
	      data62 = *(ao8 + 5);
	      data63 = *(ao8 + 6);
	      data64 = *(ao8 + 7);

	      b[ 0] = data01;
	      b[ 1] = ZERO;
	      b[ 2] = ZERO;
	      b[ 3] = ZERO;
	      b[ 4] = ZERO;
	      b[ 5] = ZERO;
	      b[ 6] = ZERO;
	      b[ 7] = ZERO;
	      
	      b[ 8] = data09;
	      b[ 9] = data10;
	      b[10] = ZERO;
	      b[11] = ZERO;
	      b[12] = ZERO;
	      b[13] = ZERO;
	      b[14] = ZERO;
	      b[15] = ZERO;

	      b[16] = data17;
	      b[17] = data18;
	      b[18] = data19;
	      b[19] = ZERO;
	      b[20] = ZERO;
	      b[21] = ZERO;
	      b[22] = ZERO;
	      b[23] = ZERO;
	      
	      b[24] = data25;
	      b[25] = data26;
	      b[26] = data27;
	      b[27] = data28;
	      b[28] = ZERO;
	      b[29] = ZERO;
	      b[30] = ZERO;
	      b[31] = ZERO;

	      b[32] = data33;
	      b[33] = data34;
	      b[34] = data35;
	      b[35] = data36;
	      b[36] = data37;
	      b[37] = ZERO;
	      b[38] = ZERO;
	      b[39] = ZERO;
	      
	      b[40] = data41;
	      b[41] = data42;
	      b[42] = data43;
	      b[43] = data44;
	      b[44] = data45;
	      b[45] = data46;
	      b[46] = ZERO;
	      b[47] = ZERO;

	      b[48] = data49;
	      b[49] = data50;
	      b[50] = data51;
	      b[51] = data52;
	      b[52] = data53;
	      b[53] = data54;
	      b[54] = data55;
	      b[55] = ZERO;

	      b[56] = data57;
	      b[57] = data58;
	      b[58] = data59;
	      b[59] = data60;
	      b[60] = data61;
	      b[61] = data62;
	      b[62] = data63;
	      b[63] = data64;

#endif
	      ao1 += 8 * lda;
	      ao2 += 8 * lda;
	      ao3 += 8 * lda;
	      ao4 += 8 * lda;
	      ao5 += 8 * lda;
	      ao6 += 8 * lda;
	      ao7 += 8 * lda;
	      ao8 += 8 * lda;
	      
	      b += 64;
	    }

	  X += 8;
	  i --;
	} while (i > 0);
      }

      i = (m & 7);
      if (i) {
      
	if (X < posY) {

	  if (m & 4) {
	    ao1 += 4;
	    ao2 += 4;
	    ao3 += 4;
	    ao4 += 4;
	    ao5 += 4;
	    ao6 += 4;
	    ao7 += 4;
	    ao8 += 4;
	    
	    b += 32;
	  }
	  
	  if (m & 2) {
	    ao1 += 2;
	    ao2 += 2;
	    ao3 += 2;
	    ao4 += 2;
	    ao5 += 2;
	    ao6 += 2;
	    ao7 += 2;
	    ao8 += 2;
	    
	    b += 16;
	  }
	  
	  if (m & 1) {
	    b += 8;
	  }
	} else 
	  if (X > posY) {
	    if (m & 4) {
	      data01 = *(ao1 + 0);
	      data02 = *(ao1 + 1);
	      data03 = *(ao1 + 2);
	      data04 = *(ao1 + 3);
	      data05 = *(ao1 + 4);
	      data06 = *(ao1 + 5);
	      data07 = *(ao1 + 6);
	      data08 = *(ao1 + 7);
	      
	      data09 = *(ao2 + 0);
	      data10 = *(ao2 + 1);
	      data11 = *(ao2 + 2);
	      data12 = *(ao2 + 3);
	      data13 = *(ao2 + 4);
	      data14 = *(ao2 + 5);
	      data15 = *(ao2 + 6);
	      data16 = *(ao2 + 7);
	      
	      data17 = *(ao3 + 0);
	      data18 = *(ao3 + 1);
	      data19 = *(ao3 + 2);
	      data20 = *(ao3 + 3);
	      data21 = *(ao3 + 4);
	      data22 = *(ao3 + 5);
	      data23 = *(ao3 + 6);
	      data24 = *(ao3 + 7);
	      
	      data25 = *(ao4 + 0);
	      data26 = *(ao4 + 1);
	      data27 = *(ao4 + 2);
	      data28 = *(ao4 + 3);
	      data29 = *(ao4 + 4);
	      data30 = *(ao4 + 5);
	      data31 = *(ao4 + 6);
	      data32 = *(ao4 + 7);
	      
	      b[ 0] = data01;
	      b[ 1] = data02;
	      b[ 2] = data03;
	      b[ 3] = data04;
	      b[ 4] = data05;
	      b[ 5] = data06;
	      b[ 6] = data07;
	      b[ 7] = data08;
	      
	      b[ 8] = data09;
	      b[ 9] = data10;
	      b[10] = data11;
	      b[11] = data12;
	      b[12] = data13;
	      b[13] = data14;
	      b[14] = data15;
	      b[15] = data16;
	      
	      b[16] = data17;
	      b[17] = data18;
	      b[18] = data19;
	      b[19] = data20;
	      b[20] = data21;
	      b[21] = data22;
	      b[22] = data23;
	      b[23] = data24;
	      
	      b[24] = data25;
	      b[25] = data26;
	      b[26] = data27;
	      b[27] = data28;
	      b[28] = data29;
	      b[29] = data30;
	      b[30] = data31;
	      b[31] = data32;
	      
	      ao1 += 4 * lda;
	      ao2 += 4 * lda;
	      ao3 += 4 * lda;
	      ao4 += 4 * lda;
	      
	      b += 32;
	    }
	    
	    if (m & 2) {
	      data01 = *(ao1 + 0);
	      data02 = *(ao1 + 1);
	      data03 = *(ao1 + 2);
	      data04 = *(ao1 + 3);
	      data05 = *(ao1 + 4);
	      data06 = *(ao1 + 5);
	      data07 = *(ao1 + 6);
	      data08 = *(ao1 + 7);
	      
	      data09 = *(ao2 + 0);
	      data10 = *(ao2 + 1);
	      data11 = *(ao2 + 2);
	      data12 = *(ao2 + 3);
	      data13 = *(ao2 + 4);
	      data14 = *(ao2 + 5);
	      data15 = *(ao2 + 6);
	      data16 = *(ao2 + 7);
	      
	      b[ 0] = data01;
	      b[ 1] = data02;
	      b[ 2] = data03;
	      b[ 3] = data04;
	      b[ 4] = data05;
	      b[ 5] = data06;
	      b[ 6] = data07;
	      b[ 7] = data08;
	      
	      b[ 8] = data09;
	      b[ 9] = data10;
	      b[10] = data11;
	      b[11] = data12;
	      b[12] = data13;
	      b[13] = data14;
	      b[14] = data15;
	      b[15] = data16;
	      
	      ao1 += 2 * lda;
	      b += 16;
	    }
	    
	    if (m & 1) {
	      data01 = *(ao1 + 0);
	      data02 = *(ao1 + 1);
	      data03 = *(ao1 + 2);
	      data04 = *(ao1 + 3);
	      data05 = *(ao1 + 4);
	      data06 = *(ao1 + 5);
	      data07 = *(ao1 + 6);
	      data08 = *(ao1 + 7);

	      b[ 0] = data01;
	      b[ 1] = data02;
	      b[ 2] = data03;
	      b[ 3] = data04;
	      b[ 4] = data05;
	      b[ 5] = data06;
	      b[ 6] = data07;
	      b[ 7] = data08;
	      
	      b += 8;
	    }
	  } else {

#ifndef UNIT
	    data01 = *(ao1 + 0);
#endif
	    data09 = *(ao2 + 0);
	    data17 = *(ao3 + 0);
	    data25 = *(ao4 + 0);
	    data33 = *(ao5 + 0);
	    data41 = *(ao6 + 0);
	    data49 = *(ao7 + 0);
	    data57 = *(ao8 + 0);

	    if (i >= 2) {
#ifndef UNIT
	      data10 = *(ao2 + 1);
#endif
	      data18 = *(ao3 + 1);
	      data26 = *(ao4 + 1);
	      data34 = *(ao5 + 1);
	      data42 = *(ao6 + 1);
	      data50 = *(ao7 + 1);
	      data58 = *(ao8 + 1);
	    }

	    if (i >= 3) {
#ifndef UNIT
	      data19 = *(ao3 + 2);
#endif
	      data27 = *(ao4 + 2);
	      data35 = *(ao5 + 2);
	      data43 = *(ao6 + 2);
	      data51 = *(ao7 + 2);
	      data59 = *(ao8 + 2);
	    }
	    
	    if (i >= 4) {
#ifndef UNIT
	      data28 = *(ao4 + 3);
#endif
	      data36 = *(ao5 + 3);
	      data44 = *(ao6 + 3);
	      data52 = *(ao7 + 3);
	      data60 = *(ao8 + 3);
	    }

	    if (i >= 5) {
#ifndef UNIT
	      data37 = *(ao5 + 4);
#endif
	      data45 = *(ao6 + 4);
	      data53 = *(ao7 + 4);
	      data61 = *(ao8 + 4);
	    }

	    if (i >= 6) {
#ifndef UNIT
	      data46 = *(ao6 + 5);
#endif
	      data54 = *(ao7 + 5);
	      data62 = *(ao8 + 5);
	    }

	    if (i >= 7) {
#ifndef UNIT
	      data55 = *(ao7 + 6);
#endif
	      data63 = *(ao8 + 6);
	    }

#ifdef UNIT
	    b[ 0] = ONE;
#else
	    b[ 0] = data01;
#endif
	    b[ 1] = ZERO;
	    b[ 2] = ZERO;
	    b[ 3] = ZERO;
	    b[ 4] = ZERO;
	    b[ 5] = ZERO;
	    b[ 6] = ZERO;
	    b[ 7] = ZERO;
	    b += 8;
	      
	    if(i >= 2) {
	      b[ 0] = data09;
#ifdef UNIT
	      b[ 1] = ONE;
#else
	      b[ 1] = data10;
#endif
	      b[ 2] = ZERO;
	      b[ 3] = ZERO;
	      b[ 4] = ZERO;
	      b[ 5] = ZERO;
	      b[ 6] = ZERO;
	      b[ 7] = ZERO;
	      b += 8;
	    }
	      
	    if (i >= 3) {
	      b[ 0] = data17;
	      b[ 1] = data18;
#ifdef UNIT
	      b[ 2] = ONE;
#else
	      b[ 2] = data19;
#endif
	      b[ 3] = ZERO;
	      b[ 4] = ZERO;
	      b[ 5] = ZERO;
	      b[ 6] = ZERO;
	      b[ 7] = ZERO;
	      b += 8;
	    }
			     
	    if (i >= 4) {  
	      b[ 0] = data25;
	      b[ 1] = data26;
	      b[ 2] = data27;
#ifdef UNIT
	      b[ 3] = ONE;
#else
	      b[ 3] = data28;
#endif
	      b[ 4] = ZERO;
	      b[ 5] = ZERO;
	      b[ 6] = ZERO;
	      b[ 7] = ZERO;
	      b += 8;
	    }

	    if (i >= 5) {
	      b[ 0] = data33;
	      b[ 1] = data34;
	      b[ 2] = data35;
	      b[ 3] = data36;
#ifdef UNIT
	      b[ 4] = ONE;
#else
	      b[ 4] = data37;
#endif
	      b[ 5] = ZERO;
	      b[ 6] = ZERO;
	      b[ 7] = ZERO;
	      b += 8;
	    }
	      
	    if (i >= 6) {
	      b[ 0] = data41;
	      b[ 1] = data42;
	      b[ 2] = data43;
	      b[ 3] = data44;
	      b[ 4] = data45;
#ifdef UNIT
	      b[ 5] = ONE;
#else
	      b[ 5] = data46;
#endif
	      b[ 6] = ZERO;
	      b[ 7] = ZERO;
	      b += 8;
	    }

	    if (i >= 7) {
	      b[ 0] = data49;
	      b[ 1] = data50;
	      b[ 2] = data51;
	      b[ 3] = data52;
	      b[ 4] = data53;
	      b[ 5] = data54;
#ifdef UNIT
	      b[ 6] = ONE;
#else
	      b[ 6] = data55;
#endif
	      b[ 7] = ZERO;
	      b += 8;
	    }
	  }
      }

      posY += 8;
      js --;
    } while (js > 0);
  } /* End of main loop */


  if (n & 4){
      X = posX;

      if (posX <= posY) {
	ao1 = a + posX + (posY + 0) * lda;
	ao2 = a + posX + (posY + 1) * lda;
	ao3 = a + posX + (posY + 2) * lda;
	ao4 = a + posX + (posY + 3) * lda;
      } else {
	ao1 = a + posY + (posX + 0) * lda;
	ao2 = a + posY + (posX + 1) * lda;
	ao3 = a + posY + (posX + 2) * lda;
	ao4 = a + posY + (posX + 3) * lda;
      }

      i = (m >> 2);
      if (i > 0) {
	do {
	  if (X < posY) {
	    ao1 += 4;
	    ao2 += 4;
	    ao3 += 4;
	    ao4 += 4;

	    b += 16;

	  } else 
	    if (X > posY) {
	      data01 = *(ao1 + 0);
	      data02 = *(ao1 + 1);
	      data03 = *(ao1 + 2);
	      data04 = *(ao1 + 3);

	      data09 = *(ao2 + 0);
	      data10 = *(ao2 + 1);
	      data11 = *(ao2 + 2);
	      data12 = *(ao2 + 3);

	      data17 = *(ao3 + 0);
	      data18 = *(ao3 + 1);
	      data19 = *(ao3 + 2);
	      data20 = *(ao3 + 3);

	      data25 = *(ao4 + 0);
	      data26 = *(ao4 + 1);
	      data27 = *(ao4 + 2);
	      data28 = *(ao4 + 3);

	      ao1 += 4 * lda;
	      ao2 += 4 * lda;
	      ao3 += 4 * lda;
	      ao4 += 4 * lda;
	      
	      b[ 0] = data01;
	      b[ 1] = data02;
	      b[ 2] = data03;
	      b[ 3] = data04;

	      b[ 4] = data09;
	      b[ 5] = data10;
	      b[ 6] = data11;
	      b[ 7] = data12;

	      b[ 8] = data17;
	      b[ 9] = data18;
	      b[10] = data19;
	      b[11] = data20;

	      b[12] = data25;
	      b[13] = data26;
	      b[14] = data27;
	      b[15] = data28;

	      b += 16;

	    } else {

#ifdef UNIT
	      data09 = *(ao2 + 0);

	      data17 = *(ao3 + 0);
	      data18 = *(ao3 + 1);

	      data25 = *(ao4 + 0);
	      data26 = *(ao4 + 1);
	      data27 = *(ao4 + 2);

	      b[ 0] = ONE;
	      b[ 1] = ZERO;
	      b[ 2] = ZERO;
	      b[ 3] = ZERO;

	      b[ 4] = data09;
	      b[ 5] = ONE;
	      b[ 6] = ZERO;
	      b[ 7] = ZERO;

	      b[ 8] = data17;
	      b[ 9] = data18;
	      b[10] = ONE;
	      b[11] = ZERO;

	      b[12] = data25;
	      b[13] = data26;
	      b[14] = data27;
	      b[15] = ONE;
#else
	      data01 = *(ao1 + 0);

	      data09 = *(ao2 + 0);
	      data10 = *(ao2 + 1);

	      data17 = *(ao3 + 0);
	      data18 = *(ao3 + 1);
	      data19 = *(ao3 + 2);

	      data25 = *(ao4 + 0);
	      data26 = *(ao4 + 1);
	      data27 = *(ao4 + 2);
	      data28 = *(ao4 + 3);

	      b[ 0] = data01;
	      b[ 1] = ZERO;
	      b[ 2] = ZERO;
	      b[ 3] = ZERO;

	      b[ 4] = data09;
	      b[ 5] = data10;
	      b[ 6] = ZERO;
	      b[ 7] = ZERO;

	      b[ 8] = data17;
	      b[ 9] = data18;
	      b[10] = data19;
	      b[11] = ZERO;

	      b[12] = data25;
	      b[13] = data26;
	      b[14] = data27;
	      b[15] = data28;
#endif
	      ao1 += 4 * lda;
	      ao2 += 4 * lda;
	      ao3 += 4 * lda;
	      ao4 += 4 * lda;
	      
	      b += 16;
	    }

	  X += 4;
	  i --;
	} while (i > 0);
      }

      i = (m & 3);
      if (i) {
      
	if (X < posY) {

	  if (m & 2) {
	    ao1 += 2;
	    ao2 += 2;
	    ao3 += 2;
	    ao4 += 2;
	    
	    b += 8;
	  }
	  
	  if (m & 1) {
	    b += 4;
	  }
	} else 
	  if (X > posY) {
	    if (m & 2) {
	      data01 = *(ao1 + 0);
	      data02 = *(ao1 + 1);
	      data03 = *(ao1 + 2);
	      data04 = *(ao1 + 3);

	      data09 = *(ao2 + 0);
	      data10 = *(ao2 + 1);
	      data11 = *(ao2 + 2);
	      data12 = *(ao2 + 3);
	      
	      b[ 0] = data01;
	      b[ 1] = data02;
	      b[ 2] = data03;
	      b[ 3] = data04;
	      b[ 4] = data09;
	      b[ 5] = data10;
	      b[ 6] = data11;
	      b[ 7] = data12;
	      
	      ao1 += 2 * lda;
	      b += 8;
	    }
	    
	    if (m & 1) {
	      data01 = *(ao1 + 0);
	      data02 = *(ao1 + 1);
	      data03 = *(ao1 + 2);
	      data04 = *(ao1 + 3);

	      b[ 0] = data01;
	      b[ 1] = data02;
	      b[ 2] = data03;
	      b[ 3] = data04;
	      
	      b += 4;
	    }
	  } else {

#ifndef UNIT
	    data01 = *(ao1 + 0);
#endif
	    data09 = *(ao2 + 0);
	    data17 = *(ao3 + 0);
	    data25 = *(ao4 + 0);

	    if (i >= 2) {
#ifndef UNIT
	      data10 = *(ao2 + 1);
#endif
	      data18 = *(ao3 + 1);
	      data26 = *(ao4 + 1);
	    }

	    if (i >= 3) {
#ifndef UNIT
	      data19 = *(ao3 + 2);
#endif
	      data27 = *(ao4 + 2);
	    }
	    
#ifndef UNIT
	    b[ 0] = ONE;
#else
	    b[ 0] = data01;
#endif
	    b[ 1] = ZERO;
	    b[ 2] = ZERO;
	    b[ 3] = ZERO;
	    b += 4;
	      
	    if(i >= 2) {
	      b[ 0] = data09;
#ifndef UNIT
	      b[ 1] = ONE;
#else
	      b[ 1] = data10;
#endif
	      b[ 2] = ZERO;
	      b[ 3] = ZERO;
	      b += 4;
	    }
	      
	    if (i >= 3) {
	      b[ 0] = data17;
	   
    b[ 1] = data18;
#ifndef UNIT
	      b[ 2] = ONE;
#else
	      b[ 2] = data19;
#endif
	      b[ 3] = ZERO;
	      b += 4;
	    }
	  }
      }

      posY += 4;
  }

  if (n & 2){
      X = posX;

      if (posX <= posY) {
	ao1 = a + posX + (posY + 0) * lda;
	ao2 = a + posX + (posY + 1) * lda;
      } else {
	ao1 = a + posY + (posX + 0) * lda;
	ao2 = a + posY + (posX + 1) * lda;
      }

      i = (m >> 1);
      if (i > 0) {
	do {
	  if (X < posY) {
	    ao1 += 2;
	    ao2 += 2;
	    b += 4;

	  } else 
	    if (X > posY) {
	      data01 = *(ao1 + 0);
	      data02 = *(ao1 + 1);
	      data09 = *(ao2 + 0);
	      data10 = *(ao2 + 1);

	      ao1 += 2 * lda;
	      ao2 += 2 * lda;
	      
	      b[ 0] = data01;
	      b[ 1] = data02;
	      b[ 2] = data09;
	      b[ 3] = data10;

	      b += 4;

	    } else {

#ifdef UNIT
	      data09 = *(ao2 + 0);

	      b[ 0] = ONE;
	      b[ 1] = ZERO;
	      b[ 2] = data09;
	      b[ 3] = ONE;
#else
	      data01 = *(ao1 + 0);
	      data09 = *(ao2 + 0);
	      data10 = *(ao2 + 1);

	      b[ 0] = data01;
	      b[ 1] = ZERO;
	      b[ 2] = data09;
	      b[ 3] = data10;
#endif

	      ao1 += 2 * lda;
	      ao2 += 2 * lda;

	      b += 4;
	    }

	  X += 2;
	  i --;
	} while (i > 0);
      }

      if (m & 1) {
      
	if (X < posY) {
	  b += 2;
	} else 
	  if (X > posY) {
	    data01 = *(ao1 + 0);
	    data02 = *(ao1 + 1);

	    b[ 0] = data01;
	    b[ 1] = data02;
	    b += 2;
	  } else {
#ifdef UNIT
	    data09 = *(ao2 + 0);
	    b[ 0] = ONE;
	    b[ 1] = data09;
#else
	    data01 = *(ao1 + 0);
	    data09 = *(ao2 + 0);
	    b[ 0] = data01;
	    b[ 1] = data09;
#endif
	    b += 2;
	  }
      }
      posY += 2;
  }

  if (n & 1){
      X = posX;

      if (posX <= posY) {
	ao1 = a + posX + (posY + 0) * lda;
      } else {
	ao1 = a + posY + (posX + 0) * lda;
      }

      i = m;
      if (m > 0) {
	do {
	  if (X < posY) {
	    ao1 += 1;
	    b += 1;
	  } else 
	    if (X > posY) {
	      data01 = *(ao1 + 0);
	      ao1 += lda;
	      
	      b[ 0] = data01;
	      b += 1;

	    } else {
#ifdef UNIT
	      b[ 0] = ONE;
#else
	      data01 = *(ao1 + 0);
	      b[ 0] = data01;
#endif
	      ao1 += lda;
	      b += 1;
	    }

	  X += 1;
	  i --;
	} while (i > 0);
      }
  }

  return 0;
}
