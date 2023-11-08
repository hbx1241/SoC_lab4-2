# Execute FIR code in user BRAM

## Replace files
```sh
counter_la_fir.c -> testbench/counter_la_fir
fir_control.c -> testbench/counter_la_fir
fir_control.h -> testbench/counter_la_fir

```
## Simulation for FIR
```sh
cd ~/caravel-soc_fpga-lab/lab-exmem-fir/testbench/counter_la_fir
source run_clean
source run_sim
```

