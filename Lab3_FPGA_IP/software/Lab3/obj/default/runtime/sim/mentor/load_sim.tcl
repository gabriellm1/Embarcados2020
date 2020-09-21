# ------------------------------------------------------------------------------
# Top Level Simulation Script to source msim_setup.tcl
# ------------------------------------------------------------------------------
set QSYS_SIMDIR obj/default/runtime/sim
source msim_setup.tcl
# Copy generated memory initialization hex and dat file(s) to current directory
file copy -force /home/labarqcomp/Desktop/Embarcados2020/Lab3_FPGA_IP/software/Lab3/mem_init/hdl_sim/niosLab2_onchip_memory2_0.dat ./ 
file copy -force /home/labarqcomp/Desktop/Embarcados2020/Lab3_FPGA_IP/software/Lab3/mem_init/niosLab2_onchip_memory2_0.hex ./ 
