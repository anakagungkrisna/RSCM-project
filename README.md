# RSCM-project
sending arrays of data using HC12 RF module
Data is from the VL53L0/1XV2 laser range sensor.
The schematic of the transmitter looks like

<img src = "Transmitter/Transmitter schematic.jpg">     
<img src = "Transmitter/Transmitter PCB.jpg">

We use 3 laser sensor with an laser diode to pinpoint the measured distance and an arduino nano for the microcontroller. We use HC12 RF module because after comparing with the NRF24L01 RF module, it provide more range and can easily pass through glass and thin wall. 

The schematic for the receiver looks like

<img src = "Receiver/Receiver schematic.jpg">
<img src = "Receiver/Receiver PCB.jpg">
  
We use an arduino nano for the microcontroller, and two led to indicate wether it receives data or not. although in the code it is not provided yet. just simply turn on the led when the data is 1, and turn off the led when the data is 0.

You can get the PCB design in the Transmitter and Receiver folder. i use altium designer to design those PCB.
