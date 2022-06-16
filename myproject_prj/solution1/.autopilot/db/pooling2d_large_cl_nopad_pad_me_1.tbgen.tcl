set moduleName pooling2d_large_cl_nopad_pad_me_1
set isTopModule 0
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isFreeRunPipelineModule 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {pooling2d_large_cl_nopad_pad_me.1}
set C_modelType { void 0 }
set C_modelArgList {
	{ data_V_V int 32 regular {fifo 0 volatile }  }
	{ res_V_V int 32 regular {fifo 1 volatile }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "data_V_V", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "res_V_V", "interface" : "fifo", "bitwidth" : 32, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 16
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ start_full_n sc_in sc_logic 1 signal -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_continue sc_in sc_logic 1 continue -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ start_out sc_out sc_logic 1 signal -1 } 
	{ start_write sc_out sc_logic 1 signal -1 } 
	{ data_V_V_dout sc_in sc_lv 32 signal 0 } 
	{ data_V_V_empty_n sc_in sc_logic 1 signal 0 } 
	{ data_V_V_read sc_out sc_logic 1 signal 0 } 
	{ res_V_V_din sc_out sc_lv 32 signal 1 } 
	{ res_V_V_full_n sc_in sc_logic 1 signal 1 } 
	{ res_V_V_write sc_out sc_logic 1 signal 1 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "start_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "start_full_n", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_continue", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "continue", "bundle":{"name": "ap_continue", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "start_out", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "start_out", "role": "default" }} , 
 	{ "name": "start_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "start_write", "role": "default" }} , 
 	{ "name": "data_V_V_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "data_V_V", "role": "dout" }} , 
 	{ "name": "data_V_V_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "data_V_V", "role": "empty_n" }} , 
 	{ "name": "data_V_V_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "data_V_V", "role": "read" }} , 
 	{ "name": "res_V_V_din", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "res_V_V", "role": "din" }} , 
 	{ "name": "res_V_V_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "res_V_V", "role": "full_n" }} , 
 	{ "name": "res_V_V_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "res_V_V", "role": "write" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "10", "11", "12", "13", "14"],
		"CDFG" : "pooling2d_large_cl_nopad_pad_me_1",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "1", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "421", "EstimateLatencyMax" : "12895",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "1",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "data_V_V", "Type" : "Fifo", "Direction" : "I", "DependentProc" : "0", "DependentChan" : "0",
				"BlockSignal" : [
					{"Name" : "data_V_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "res_V_V", "Type" : "Fifo", "Direction" : "O", "DependentProc" : "0", "DependentChan" : "0",
				"BlockSignal" : [
					{"Name" : "res_V_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "layer_in_V_17", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "layer_in_row_Array_V_7_0_0", "Type" : "Memory", "Direction" : "X",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "call_ret_cnnshift_arr_ap_fixed_ap_fixed_32_16_5_3_0_config35_s_fu_190", "Port" : "layer_in_row_Array_V_7_0_0"}]},
			{"Name" : "layer_in_row_Array_V_7_0_1", "Type" : "Memory", "Direction" : "X",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "call_ret_cnnshift_arr_ap_fixed_ap_fixed_32_16_5_3_0_config35_s_fu_190", "Port" : "layer_in_row_Array_V_7_0_1"}]},
			{"Name" : "layer_in_row_Array_V_7_0_2", "Type" : "Memory", "Direction" : "X",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "call_ret_cnnshift_arr_ap_fixed_ap_fixed_32_16_5_3_0_config35_s_fu_190", "Port" : "layer_in_row_Array_V_7_0_2"}]},
			{"Name" : "layer_in_row_Array_V_7_0_3", "Type" : "Memory", "Direction" : "X",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "call_ret_cnnshift_arr_ap_fixed_ap_fixed_32_16_5_3_0_config35_s_fu_190", "Port" : "layer_in_row_Array_V_7_0_3"}]},
			{"Name" : "layer_in_row_Array_V_7_0_4", "Type" : "Memory", "Direction" : "X",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "call_ret_cnnshift_arr_ap_fixed_ap_fixed_32_16_5_3_0_config35_s_fu_190", "Port" : "layer_in_row_Array_V_7_0_4"}]},
			{"Name" : "layer_in_row_Array_V_7_0_5", "Type" : "Memory", "Direction" : "X",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "call_ret_cnnshift_arr_ap_fixed_ap_fixed_32_16_5_3_0_config35_s_fu_190", "Port" : "layer_in_row_Array_V_7_0_5"}]},
			{"Name" : "layer_in_row_Array_V_7_0_6", "Type" : "Memory", "Direction" : "X",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "call_ret_cnnshift_arr_ap_fixed_ap_fixed_32_16_5_3_0_config35_s_fu_190", "Port" : "layer_in_row_Array_V_7_0_6"}]},
			{"Name" : "layer_in_row_Array_V_7_0_7", "Type" : "Memory", "Direction" : "X",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "call_ret_cnnshift_arr_ap_fixed_ap_fixed_32_16_5_3_0_config35_s_fu_190", "Port" : "layer_in_row_Array_V_7_0_7"}]},
			{"Name" : "sX_5", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "sY_5", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "pY_5", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "pX_5", "Type" : "OVld", "Direction" : "IO"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.call_ret_cnnshift_arr_ap_fixed_ap_fixed_32_16_5_3_0_config35_s_fu_190", "Parent" : "0", "Child" : ["2", "3", "4", "5", "6", "7", "8", "9"],
		"CDFG" : "cnnshift_arr_ap_fixed_ap_fixed_32_16_5_3_0_config35_s",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "1",
		"VariableLatency" : "0", "ExactLatency" : "0", "EstimateLatencyMin" : "0", "EstimateLatencyMax" : "0",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "data_0_V_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "data_1_V_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "data_2_V_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "data_3_V_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "data_4_V_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "data_5_V_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "data_6_V_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "data_7_V_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "output_V_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "layer_in_row_Array_V_7_0_0", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "layer_in_row_Array_V_7_0_1", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "layer_in_row_Array_V_7_0_2", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "layer_in_row_Array_V_7_0_3", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "layer_in_row_Array_V_7_0_4", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "layer_in_row_Array_V_7_0_5", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "layer_in_row_Array_V_7_0_6", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "layer_in_row_Array_V_7_0_7", "Type" : "Memory", "Direction" : "X"}]},
	{"ID" : "2", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.call_ret_cnnshift_arr_ap_fixed_ap_fixed_32_16_5_3_0_config35_s_fu_190.layer_in_row_Array_V_7_0_0_U", "Parent" : "1"},
	{"ID" : "3", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.call_ret_cnnshift_arr_ap_fixed_ap_fixed_32_16_5_3_0_config35_s_fu_190.layer_in_row_Array_V_7_0_1_U", "Parent" : "1"},
	{"ID" : "4", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.call_ret_cnnshift_arr_ap_fixed_ap_fixed_32_16_5_3_0_config35_s_fu_190.layer_in_row_Array_V_7_0_2_U", "Parent" : "1"},
	{"ID" : "5", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.call_ret_cnnshift_arr_ap_fixed_ap_fixed_32_16_5_3_0_config35_s_fu_190.layer_in_row_Array_V_7_0_3_U", "Parent" : "1"},
	{"ID" : "6", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.call_ret_cnnshift_arr_ap_fixed_ap_fixed_32_16_5_3_0_config35_s_fu_190.layer_in_row_Array_V_7_0_4_U", "Parent" : "1"},
	{"ID" : "7", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.call_ret_cnnshift_arr_ap_fixed_ap_fixed_32_16_5_3_0_config35_s_fu_190.layer_in_row_Array_V_7_0_5_U", "Parent" : "1"},
	{"ID" : "8", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.call_ret_cnnshift_arr_ap_fixed_ap_fixed_32_16_5_3_0_config35_s_fu_190.layer_in_row_Array_V_7_0_6_U", "Parent" : "1"},
	{"ID" : "9", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.call_ret_cnnshift_arr_ap_fixed_ap_fixed_32_16_5_3_0_config35_s_fu_190.layer_in_row_Array_V_7_0_7_U", "Parent" : "1"},
	{"ID" : "10", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.myproject_axi_lshr_1024ns_11ns_1024_6_1_U155", "Parent" : "0"},
	{"ID" : "11", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.myproject_axi_lshr_1024ns_11ns_1024_6_1_U156", "Parent" : "0"},
	{"ID" : "12", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.myproject_axi_lshr_1024ns_11ns_1024_6_1_U157", "Parent" : "0"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.myproject_axi_lshr_1024ns_11ns_1024_6_1_U158", "Parent" : "0"},
	{"ID" : "14", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.myproject_axi_lshr_128ns_8ns_128_6_1_U159", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	pooling2d_large_cl_nopad_pad_me_1 {
		data_V_V {Type I LastRead 8 FirstWrite -1}
		res_V_V {Type O LastRead -1 FirstWrite 18}
		layer_in_V_17 {Type IO LastRead -1 FirstWrite -1}
		layer_in_row_Array_V_7_0_0 {Type X LastRead -1 FirstWrite -1}
		layer_in_row_Array_V_7_0_1 {Type X LastRead -1 FirstWrite -1}
		layer_in_row_Array_V_7_0_2 {Type X LastRead -1 FirstWrite -1}
		layer_in_row_Array_V_7_0_3 {Type X LastRead -1 FirstWrite -1}
		layer_in_row_Array_V_7_0_4 {Type X LastRead -1 FirstWrite -1}
		layer_in_row_Array_V_7_0_5 {Type X LastRead -1 FirstWrite -1}
		layer_in_row_Array_V_7_0_6 {Type X LastRead -1 FirstWrite -1}
		layer_in_row_Array_V_7_0_7 {Type X LastRead -1 FirstWrite -1}
		sX_5 {Type IO LastRead -1 FirstWrite -1}
		sY_5 {Type IO LastRead -1 FirstWrite -1}
		pY_5 {Type IO LastRead -1 FirstWrite -1}
		pX_5 {Type IO LastRead -1 FirstWrite -1}}
	cnnshift_arr_ap_fixed_ap_fixed_32_16_5_3_0_config35_s {
		data_0_V_read {Type I LastRead 0 FirstWrite -1}
		data_1_V_read {Type I LastRead 0 FirstWrite -1}
		data_2_V_read {Type I LastRead 0 FirstWrite -1}
		data_3_V_read {Type I LastRead 0 FirstWrite -1}
		data_4_V_read {Type I LastRead 0 FirstWrite -1}
		data_5_V_read {Type I LastRead 0 FirstWrite -1}
		data_6_V_read {Type I LastRead 0 FirstWrite -1}
		data_7_V_read {Type I LastRead 0 FirstWrite -1}
		output_V_read {Type I LastRead 0 FirstWrite -1}
		layer_in_row_Array_V_7_0_0 {Type X LastRead -1 FirstWrite -1}
		layer_in_row_Array_V_7_0_1 {Type X LastRead -1 FirstWrite -1}
		layer_in_row_Array_V_7_0_2 {Type X LastRead -1 FirstWrite -1}
		layer_in_row_Array_V_7_0_3 {Type X LastRead -1 FirstWrite -1}
		layer_in_row_Array_V_7_0_4 {Type X LastRead -1 FirstWrite -1}
		layer_in_row_Array_V_7_0_5 {Type X LastRead -1 FirstWrite -1}
		layer_in_row_Array_V_7_0_6 {Type X LastRead -1 FirstWrite -1}
		layer_in_row_Array_V_7_0_7 {Type X LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "421", "Max" : "12895"}
	, {"Name" : "Interval", "Min" : "421", "Max" : "12895"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	data_V_V { ap_fifo {  { data_V_V_dout fifo_data 0 32 }  { data_V_V_empty_n fifo_status 0 1 }  { data_V_V_read fifo_update 1 1 } } }
	res_V_V { ap_fifo {  { res_V_V_din fifo_data 1 32 }  { res_V_V_full_n fifo_status 0 1 }  { res_V_V_write fifo_update 1 1 } } }
}
