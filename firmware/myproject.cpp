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
#include <iostream>

#include "myproject.h"
#include "parameters.h"

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
) {

    //hls-fpga-machine-learning insert IO
    #pragma HLS INTERFACE axis port=em_barrel,layer56_out 
    #pragma HLS DATAFLOW 

    const_size_in_1 = N_INPUT_1_1*N_INPUT_2_1*N_INPUT_3_1;
    const_size_out_1 = N_LAYER_54;

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<model_default_t, 4>(s3, "s3.txt");
        nnet::load_weights_from_txt<model_default_t, 4>(b3, "b3.txt");
        nnet::load_weights_from_txt<model_default_t, 800>(w4, "w4.txt");
        nnet::load_weights_from_txt<bias4_t, 8>(b4, "b4.txt");
        nnet::load_weights_from_txt<model_default_t, 576>(w9, "w9.txt");
        nnet::load_weights_from_txt<bias9_t, 8>(b9, "b9.txt");
        nnet::load_weights_from_txt<model_default_t, 576>(w13, "w13.txt");
        nnet::load_weights_from_txt<bias13_t, 8>(b13, "b13.txt");
        nnet::load_weights_from_txt<model_default_t, 576>(w18, "w18.txt");
        nnet::load_weights_from_txt<bias18_t, 8>(b18, "b18.txt");
        nnet::load_weights_from_txt<model_default_t, 576>(w22, "w22.txt");
        nnet::load_weights_from_txt<bias22_t, 8>(b22, "b22.txt");
        nnet::load_weights_from_txt<model_default_t, 576>(w27, "w27.txt");
        nnet::load_weights_from_txt<bias27_t, 8>(b27, "b27.txt");
        nnet::load_weights_from_txt<model_default_t, 576>(w31, "w31.txt");
        nnet::load_weights_from_txt<bias31_t, 8>(b31, "b31.txt");
        nnet::load_weights_from_txt<model_default_t, 576>(w36, "w36.txt");
        nnet::load_weights_from_txt<bias36_t, 8>(b36, "b36.txt");
        nnet::load_weights_from_txt<model_default_t, 576>(w40, "w40.txt");
        nnet::load_weights_from_txt<bias40_t, 8>(b40, "b40.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(w46, "w46.txt");
        nnet::load_weights_from_txt<bias46_t, 32>(b46, "b46.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(w50, "w50.txt");
        nnet::load_weights_from_txt<bias50_t, 32>(b50, "b50.txt");
        nnet::load_weights_from_txt<model_default_t, 32>(w54, "w54.txt");
        nnet::load_weights_from_txt<model_default_t, 1>(b54, "b54.txt");
        loaded_weights = true;
    }
#endif

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    //hls-fpga-machine-learning insert layers

std::cout<<"em_barrel"<<std::endl;
std::cout<<"up_sampling"<<std::endl;
    hls::stream<layer2_t> layer2_out("layer2_out");
    #pragma HLS STREAM variable=layer2_out depth=3080
    nnet::resize_nearest_me<input_t, config2>(em_barrel, layer2_out); // up_sampling

std::cout<<"batch_norm"<<std::endl;
    hls::stream<layer3_t> layer3_out("layer3_out");
    #pragma HLS STREAM variable=layer3_out depth=3080
    nnet::normalize_me<layer2_t, layer3_t, config3>(layer2_out, layer3_out, s3, b3); // batch_norm

std::cout<<"zp2d_conv"<<std::endl;
    hls::stream<layer57_t> layer57_out("layer57_out");
    #pragma HLS STREAM variable=layer57_out depth=3540
    nnet::zeropad2d_cl_me<layer3_t, layer57_t, config57>(layer3_out, layer57_out); // zp2d_conv

std::cout<<"conv"<<std::endl;
    hls::stream<layer4_t> layer4_out("layer4_out");
    #pragma HLS STREAM variable=layer4_out depth=3080
    nnet::conv_2d_cl_me<layer57_t, layer4_t, config4>(layer57_out, layer4_out, w4, b4); // conv

std::cout<<"leaky_relu"<<std::endl;
    hls::stream<layer7_t> layer7_out("layer7_out");
    #pragma HLS STREAM variable=layer7_out depth=3080
    nnet::leaky_relu_me<layer4_t, layer7_t, LeakyReLU_config7>(layer4_out, 0.30000001192092896, layer7_out); // leaky_relu

std::cout<<"max_pooling2D"<<std::endl;
    hls::stream<layer8_t> layer8_out("layer8_out");
    #pragma HLS STREAM variable=layer8_out depth=756
    nnet::pooling2d_large_cl_nopad_pad_me<layer7_t, layer8_t, config8>(layer7_out, layer8_out); // max_pooling2D

std::cout<<"zp2d_conv_1"<<std::endl;
    hls::stream<layer58_t> layer58_out("layer58_out");
    #pragma HLS STREAM variable=layer58_out depth=870
    nnet::zeropad2d_cl_me<layer8_t, layer58_t, config58>(layer8_out, layer58_out); // zp2d_conv_1

std::cout<<"conv_1"<<std::endl;
    hls::stream<layer9_t> layer9_out("layer9_out");
    #pragma HLS STREAM variable=layer9_out depth=756
    nnet::conv_2d_cl_me<layer58_t, layer9_t, config9>(layer58_out, layer9_out, w9, b9); // conv_1

std::cout<<"leaky_relu_1"<<std::endl;
    hls::stream<layer12_t> layer12_out("layer12_out");
    #pragma HLS STREAM variable=layer12_out depth=756
    nnet::leaky_relu_me<layer9_t, layer12_t, LeakyReLU_config12>(layer9_out, 0.30000001192092896, layer12_out); // leaky_relu_1

std::cout<<"zp2d_conv_2"<<std::endl;
    hls::stream<layer59_t> layer59_out("layer59_out");
    #pragma HLS STREAM variable=layer59_out depth=870
    nnet::zeropad2d_cl_me<layer12_t, layer59_t, config59>(layer12_out, layer59_out); // zp2d_conv_2

std::cout<<"conv_2"<<std::endl;
    hls::stream<layer13_t> layer13_out("layer13_out");
    #pragma HLS STREAM variable=layer13_out depth=756
    nnet::conv_2d_cl_me<layer59_t, layer13_t, config13>(layer59_out, layer13_out, w13, b13); // conv_2

std::cout<<"leaky_relu_2"<<std::endl;
    hls::stream<layer16_t> layer16_out("layer16_out");
    #pragma HLS STREAM variable=layer16_out depth=756
    nnet::leaky_relu_me<layer13_t, layer16_t, LeakyReLU_config16>(layer13_out, 0.30000001192092896, layer16_out); // leaky_relu_2

std::cout<<"max_pooling2D_1"<<std::endl;
    hls::stream<layer17_t> layer17_out("layer17_out");
    #pragma HLS STREAM variable=layer17_out depth=182
    nnet::pooling2d_large_cl_nopad_pad_me<layer16_t, layer17_t, config17>(layer16_out, layer17_out); // max_pooling2D_1

std::cout<<"zp2d_conv_3"<<std::endl;
    hls::stream<layer60_t> layer60_out("layer60_out");
    #pragma HLS STREAM variable=layer60_out depth=240
    nnet::zeropad2d_cl_me<layer17_t, layer60_t, config60>(layer17_out, layer60_out); // zp2d_conv_3

std::cout<<"conv_3"<<std::endl;
    hls::stream<layer18_t> layer18_out("layer18_out");
    #pragma HLS STREAM variable=layer18_out depth=182
    nnet::conv_2d_cl_me<layer60_t, layer18_t, config18>(layer60_out, layer18_out, w18, b18); // conv_3

std::cout<<"leaky_relu_3"<<std::endl;
    hls::stream<layer21_t> layer21_out("layer21_out");
    #pragma HLS STREAM variable=layer21_out depth=182
    nnet::leaky_relu_me<layer18_t, layer21_t, LeakyReLU_config21>(layer18_out, 0.30000001192092896, layer21_out); // leaky_relu_3

std::cout<<"zp2d_conv_4"<<std::endl;
    hls::stream<layer61_t> layer61_out("layer61_out");
    #pragma HLS STREAM variable=layer61_out depth=240
    nnet::zeropad2d_cl_me<layer21_t, layer61_t, config61>(layer21_out, layer61_out); // zp2d_conv_4

std::cout<<"conv_4"<<std::endl;
    hls::stream<layer22_t> layer22_out("layer22_out");
    #pragma HLS STREAM variable=layer22_out depth=182
    nnet::conv_2d_cl_me<layer61_t, layer22_t, config22>(layer61_out, layer22_out, w22, b22); // conv_4

std::cout<<"leaky_relu_4"<<std::endl;
    hls::stream<layer25_t> layer25_out("layer25_out");
    #pragma HLS STREAM variable=layer25_out depth=182
    nnet::leaky_relu_me<layer22_t, layer25_t, LeakyReLU_config25>(layer22_out, 0.30000001192092896, layer25_out); // leaky_relu_4

std::cout<<"max_pooling2D_2"<<std::endl;
    hls::stream<layer26_t> layer26_out("layer26_out");
    #pragma HLS STREAM variable=layer26_out depth=42
    nnet::pooling2d_large_cl_nopad_pad_me<layer25_t, layer26_t, config26>(layer25_out, layer26_out); // max_pooling2D_2

std::cout<<"zp2d_conv_5"<<std::endl;
    hls::stream<layer62_t> layer62_out("layer62_out");
    #pragma HLS STREAM variable=layer62_out depth=72
    nnet::zeropad2d_cl_me<layer26_t, layer62_t, config62>(layer26_out, layer62_out); // zp2d_conv_5

std::cout<<"conv_5"<<std::endl;
    hls::stream<layer27_t> layer27_out("layer27_out");
    #pragma HLS STREAM variable=layer27_out depth=42
    nnet::conv_2d_cl_me<layer62_t, layer27_t, config27>(layer62_out, layer27_out, w27, b27); // conv_5

std::cout<<"leaky_relu_5"<<std::endl;
    hls::stream<layer30_t> layer30_out("layer30_out");
    #pragma HLS STREAM variable=layer30_out depth=42
    nnet::leaky_relu_me<layer27_t, layer30_t, LeakyReLU_config30>(layer27_out, 0.30000001192092896, layer30_out); // leaky_relu_5

std::cout<<"zp2d_conv_6"<<std::endl;
    hls::stream<layer63_t> layer63_out("layer63_out");
    #pragma HLS STREAM variable=layer63_out depth=72
    nnet::zeropad2d_cl_me<layer30_t, layer63_t, config63>(layer30_out, layer63_out); // zp2d_conv_6

std::cout<<"conv_6"<<std::endl;
    hls::stream<layer31_t> layer31_out("layer31_out");
    #pragma HLS STREAM variable=layer31_out depth=42
    nnet::conv_2d_cl_me<layer63_t, layer31_t, config31>(layer63_out, layer31_out, w31, b31); // conv_6

std::cout<<"leaky_relu_6"<<std::endl;
    hls::stream<layer34_t> layer34_out("layer34_out");
    #pragma HLS STREAM variable=layer34_out depth=42
    nnet::leaky_relu_me<layer31_t, layer34_t, LeakyReLU_config34>(layer31_out, 0.30000001192092896, layer34_out); // leaky_relu_6

std::cout<<"max_pooling2D_3"<<std::endl;
    hls::stream<layer35_t> layer35_out("layer35_out");
    #pragma HLS STREAM variable=layer35_out depth=9
    nnet::pooling2d_large_cl_nopad_pad_me<layer34_t, layer35_t, config35>(layer34_out, layer35_out); // max_pooling2D_3

std::cout<<"zp2d_conv_7"<<std::endl;
    hls::stream<layer64_t> layer64_out("layer64_out");
    #pragma HLS STREAM variable=layer64_out depth=25
    nnet::zeropad2d_cl_me<layer35_t, layer64_t, config64>(layer35_out, layer64_out); // zp2d_conv_7

std::cout<<"conv_7"<<std::endl;
    hls::stream<layer36_t> layer36_out("layer36_out");
    #pragma HLS STREAM variable=layer36_out depth=9
    nnet::conv_2d_cl_me<layer64_t, layer36_t, config36>(layer64_out, layer36_out, w36, b36); // conv_7

std::cout<<"leaky_relu_7"<<std::endl;
    hls::stream<layer39_t> layer39_out("layer39_out");
    #pragma HLS STREAM variable=layer39_out depth=9
    nnet::leaky_relu_me<layer36_t, layer39_t, LeakyReLU_config39>(layer36_out, 0.30000001192092896, layer39_out); // leaky_relu_7

std::cout<<"zp2d_conv_8"<<std::endl;
    hls::stream<layer65_t> layer65_out("layer65_out");
    #pragma HLS STREAM variable=layer65_out depth=25
    nnet::zeropad2d_cl_me<layer39_t, layer65_t, config65>(layer39_out, layer65_out); // zp2d_conv_8

std::cout<<"conv_8"<<std::endl;
    hls::stream<layer40_t> layer40_out("layer40_out");
    #pragma HLS STREAM variable=layer40_out depth=9
    nnet::conv_2d_cl_me<layer65_t, layer40_t, config40>(layer65_out, layer40_out, w40, b40); // conv_8

std::cout<<"leaky_relu_8"<<std::endl;
    hls::stream<layer43_t> layer43_out("layer43_out");
    #pragma HLS STREAM variable=layer43_out depth=9
    nnet::leaky_relu_me<layer40_t, layer43_t, LeakyReLU_config43>(layer40_out, 0.30000001192092896, layer43_out); // leaky_relu_8

std::cout<<"max_pooling2D_4"<<std::endl;
    hls::stream<layer44_t> layer44_out("layer44_out");
    #pragma HLS STREAM variable=layer44_out depth=1
    nnet::pooling2d_large_cl_nopad_pad_me<layer43_t, layer44_t, config44>(layer43_out, layer44_out); // max_pooling2D_4

std::cout<<"flatten"<<std::endl;
std::cout<<"dense"<<std::endl;
    hls::stream<layer46_t> layer46_out("layer46_out");
    #pragma HLS STREAM variable=layer46_out depth=1
    nnet::dense_large_stream_me<layer44_t, layer46_t, config46>(layer44_out, layer46_out, w46, b46); // dense

std::cout<<"leaky_relu_d0"<<std::endl;
    hls::stream<layer49_t> layer49_out("layer49_out");
    #pragma HLS STREAM variable=layer49_out depth=1
    nnet::leaky_relu_me<layer46_t, layer49_t, LeakyReLU_config49>(layer46_out, 0.30000001192092896, layer49_out); // leaky_relu_d0

std::cout<<"dense_1"<<std::endl;
    hls::stream<layer50_t> layer50_out("layer50_out");
    #pragma HLS STREAM variable=layer50_out depth=1
    nnet::dense_large_stream_me<layer49_t, layer50_t, config50>(layer49_out, layer50_out, w50, b50); // dense_1

std::cout<<"leaky_relu_d1"<<std::endl;
    hls::stream<layer53_t> layer53_out("layer53_out");
    #pragma HLS STREAM variable=layer53_out depth=1
    nnet::leaky_relu_me<layer50_t, layer53_t, LeakyReLU_config53>(layer50_out, 0.30000001192092896, layer53_out); // leaky_relu_d1

std::cout<<"dense_2"<<std::endl;
    hls::stream<layer54_t> layer54_out("layer54_out");
    #pragma HLS STREAM variable=layer54_out depth=1
    nnet::dense_large_stream_me<layer53_t, layer54_t, config54>(layer53_out, layer54_out, w54, b54); // dense_2

std::cout<<"activate"<<std::endl;
    nnet::relu_me<layer54_t, result_t, relu_config56>(layer54_out, layer56_out); // activate

}
