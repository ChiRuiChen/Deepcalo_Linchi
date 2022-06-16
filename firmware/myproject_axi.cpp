#include "myproject_axi.h"

//hls-fpga-machine-learning insert bram
model_default_t s3[4];
model_default_t b3[4];
model_default_t w4[800];
bias4_t b4[8];
model_default_t w9[576];
bias9_t b9[8];
model_default_t w13[576];
bias13_t b13[8];
model_default_t w18[576];
bias18_t b18[8];
model_default_t w22[576];
bias22_t b22[8];
model_default_t w27[576];
bias27_t b27[8];
model_default_t w31[576];
bias31_t b31[8];
model_default_t w36[576];
bias36_t b36[8];
model_default_t w40[576];
bias40_t b40[8];
model_default_t w46[256];
bias46_t b46[32];
model_default_t w50[1024];
bias50_t b50[32];
model_default_t w54[32];
model_default_t b54[1];


void myproject_axi(
    input_axi_t in[N_IN],
    output_axi_t out[N_OUT]
        ){

    #pragma HLS INTERFACE axis port=in
    #pragma HLS INTERFACE axis port=out
    #pragma HLS INTERFACE ap_ctrl_none port=return
    #pragma HLS DATAFLOW

    unsigned short in_size = 0;
    unsigned short out_size = 0;

    bool is_last = false;
    hls::stream<input_t> in_local("input_1");
    hls::stream<result_t> out_local("output_1");

    #pragma HLS STREAM variable=in_local depth=N_IN
    #pragma HLS STREAM variable=out_local depth=N_OUT

    for(unsigned i = 0; i < N_IN; ++i) {
        input_t ctype;
            ctype = input_t (in[i].data);
            is_last |= (in[i].last == 1)? true : false;
        in_local.write(ctype);
    }

    myproject(in_local, out_local, s3,b3,w4,b4,w9,b9,w13,b13,w18,b18,w22,b22,w27,b27,w31,b31,w36,b36,w40,b40,w46,b46,w50,b50,w54,b54, in_size, out_size);

    for(unsigned i = 0; i < N_OUT; ++i) {
        result_t ctype = out_local.read();
            bool last = (is_last && (i == N_OUT - 1)) ? true : false;
            out[i] = output_axi_t(ctype, last);
    }
}
