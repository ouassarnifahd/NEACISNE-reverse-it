vlib work
vlib activehdl

vlib activehdl/xil_defaultlib
vlib activehdl/xpm
vlib activehdl/axi_infrastructure_v1_1_0
vlib activehdl/smartconnect_v1_0
vlib activehdl/axi_protocol_checker_v2_0_1
vlib activehdl/axi_vip_v1_1_1
vlib activehdl/processing_system7_vip_v1_0_3
vlib activehdl/lib_cdc_v1_0_2
vlib activehdl/proc_sys_reset_v5_0_12
vlib activehdl/blk_mem_gen_v8_4_1
vlib activehdl/generic_baseblocks_v2_1_0
vlib activehdl/fifo_generator_v13_2_1
vlib activehdl/axi_data_fifo_v2_1_14
vlib activehdl/axi_register_slice_v2_1_15
vlib activehdl/axi_protocol_converter_v2_1_15

vmap xil_defaultlib activehdl/xil_defaultlib
vmap xpm activehdl/xpm
vmap axi_infrastructure_v1_1_0 activehdl/axi_infrastructure_v1_1_0
vmap smartconnect_v1_0 activehdl/smartconnect_v1_0
vmap axi_protocol_checker_v2_0_1 activehdl/axi_protocol_checker_v2_0_1
vmap axi_vip_v1_1_1 activehdl/axi_vip_v1_1_1
vmap processing_system7_vip_v1_0_3 activehdl/processing_system7_vip_v1_0_3
vmap lib_cdc_v1_0_2 activehdl/lib_cdc_v1_0_2
vmap proc_sys_reset_v5_0_12 activehdl/proc_sys_reset_v5_0_12
vmap blk_mem_gen_v8_4_1 activehdl/blk_mem_gen_v8_4_1
vmap generic_baseblocks_v2_1_0 activehdl/generic_baseblocks_v2_1_0
vmap fifo_generator_v13_2_1 activehdl/fifo_generator_v13_2_1
vmap axi_data_fifo_v2_1_14 activehdl/axi_data_fifo_v2_1_14
vmap axi_register_slice_v2_1_15 activehdl/axi_register_slice_v2_1_15
vmap axi_protocol_converter_v2_1_15 activehdl/axi_protocol_converter_v2_1_15

vlog -work xil_defaultlib  -sv2k12 "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" \
"C:/Xilinx/Vivado/2017.4/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
"C:/Xilinx/Vivado/2017.4/data/ip/xpm/xpm_fifo/hdl/xpm_fifo.sv" \
"C:/Xilinx/Vivado/2017.4/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \

vcom -work xpm -93 \
"C:/Xilinx/Vivado/2017.4/data/ip/xpm/xpm_VCOMP.vhd" \

vlog -work axi_infrastructure_v1_1_0  -v2k5 "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" \
"../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl/axi_infrastructure_v1_1_vl_rfs.v" \

vlog -work smartconnect_v1_0  -sv2k12 "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" \
"../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/sc_util_v1_0_vl_rfs.sv" \

vlog -work axi_protocol_checker_v2_0_1  -sv2k12 "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" \
"../../../../test_A.srcs/sources_1/bd/design_1/ipshared/3b24/hdl/axi_protocol_checker_v2_0_vl_rfs.sv" \

vlog -work axi_vip_v1_1_1  -sv2k12 "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" \
"../../../../test_A.srcs/sources_1/bd/design_1/ipshared/a16a/hdl/axi_vip_v1_1_vl_rfs.sv" \

vlog -work processing_system7_vip_v1_0_3  -sv2k12 "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" \
"../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl/processing_system7_vip_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_processing_system7_0_0/sim/design_1_processing_system7_0_0.v" \

vcom -work lib_cdc_v1_0_2 -93 \
"../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ef1e/hdl/lib_cdc_v1_0_rfs.vhd" \

vcom -work proc_sys_reset_v5_0_12 -93 \
"../../../../test_A.srcs/sources_1/bd/design_1/ipshared/f86a/hdl/proc_sys_reset_v5_0_vh_rfs.vhd" \

vcom -work xil_defaultlib -93 \
"../../../bd/design_1/ip/design_1_rst_ps7_0_100M_0/sim/design_1_rst_ps7_0_100M_0.vhd" \
"../../../bd/design_1/sim/design_1.vhd" \

vlog -work blk_mem_gen_v8_4_1  -v2k5 "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" \
"../../../../test_A.srcs/sources_1/bd/design_1/ip/design_1_oled_ip2019_0_1/src/charlib/simulation/blk_mem_gen_v8_4.v" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_oled_ip2019_0_1/src/charlib/sim/charlib.v" \

vcom -work xil_defaultlib -93 \
"../../../bd/design_1/ipshared/9de1/src/SpiCtrl.vhd" \
"../../../bd/design_1/ipshared/9de1/src/delay.vhd" \
"../../../bd/design_1/ipshared/9de1/hdl/oled_ip2019_v1_0_S00_AXI.vhd" \
"../../../bd/design_1/ipshared/9de1/hdl/oled_ip2019_v1_0.vhd" \
"../../../bd/design_1/ip/design_1_oled_ip2019_0_1/sim/design_1_oled_ip2019_0_1.vhd" \

vlog -work generic_baseblocks_v2_1_0  -v2k5 "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" \
"../../../../test_A.srcs/sources_1/bd/design_1/ipshared/b752/hdl/generic_baseblocks_v2_1_vl_rfs.v" \

vlog -work fifo_generator_v13_2_1  -v2k5 "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" \
"../../../../test_A.srcs/sources_1/bd/design_1/ipshared/5c35/simulation/fifo_generator_vlog_beh.v" \

vcom -work fifo_generator_v13_2_1 -93 \
"../../../../test_A.srcs/sources_1/bd/design_1/ipshared/5c35/hdl/fifo_generator_v13_2_rfs.vhd" \

vlog -work fifo_generator_v13_2_1  -v2k5 "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" \
"../../../../test_A.srcs/sources_1/bd/design_1/ipshared/5c35/hdl/fifo_generator_v13_2_rfs.v" \

vlog -work axi_data_fifo_v2_1_14  -v2k5 "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" \
"../../../../test_A.srcs/sources_1/bd/design_1/ipshared/9909/hdl/axi_data_fifo_v2_1_vl_rfs.v" \

vlog -work axi_register_slice_v2_1_15  -v2k5 "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" \
"../../../../test_A.srcs/sources_1/bd/design_1/ipshared/3ed1/hdl/axi_register_slice_v2_1_vl_rfs.v" \

vlog -work axi_protocol_converter_v2_1_15  -v2k5 "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" \
"../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ff69/hdl/axi_protocol_converter_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/02c8/hdl/verilog" "+incdir+../../../../test_A.srcs/sources_1/bd/design_1/ipshared/1313/hdl" "+incdir+C:/Xilinx/Vivado/2017.4/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_auto_pc_0/sim/design_1_auto_pc_0.v" \

vlog -work xil_defaultlib \
"glbl.v"

