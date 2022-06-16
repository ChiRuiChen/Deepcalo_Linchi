//
//    rfnoc-hls-neuralnet: Vivado HLS code for neural-net building blocks
//
//    Copyright (C) 2017 EJ Kreinar
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef MYPROJECT_H_
#define MYPROJECT_H_

#include "ap_int.h"
#include "ap_fixed.h"
#include "hls_stream.h"

#include "defines.h"

// Prototype of top level function for C-synthesis
void myproject(
    hls::stream<input_t> &em_barrel,
    hls::stream<result_t> &layer56_out,
    model_default_t s3[4],
    model_default_t b3[4],
    model_default_t w4[800],
    bias4_t b4[8],
    model_default_t w9[576],
    bias9_t b9[8],
    model_default_t w13[576],
    bias13_t b13[8],
    model_default_t w18[576],
    bias18_t b18[8],
    model_default_t w22[576],
    bias22_t b22[8],
    model_default_t w27[576],
    bias27_t b27[8],
    model_default_t w31[576],
    bias31_t b31[8],
    model_default_t w36[576],
    bias36_t b36[8],
    model_default_t w40[576],
    bias40_t b40[8],
    model_default_t w46[256],
    bias46_t b46[32],
    model_default_t w50[1024],
    bias50_t b50[32],
    model_default_t w54[32],
    model_default_t b54[1],
    unsigned short &const_size_in_1,
    unsigned short &const_size_out_1
);

#endif
