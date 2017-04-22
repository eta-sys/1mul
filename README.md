# 1mul
### A try to write an universal language to all the micro devices.  

1. Do you write programs for microprocessors? Then you know what costs to write programs for different processors or to migrate an old program to a new processor, even same family. You have to learn all the processor's interfaces with their registers and flags as your pocket simply to open a Com-port or set one output.    
Why? This job has to be done from those, who invent or develop the processor.

2. Suppose your 10 years old son wants to learn processors. Can you imagine how you will give him a start push? You will start explane him 'C' or LUA, or Assembler? Does one evening be enough to teach him to run a 'blinker' to let him fill the delight of success?  

1mul is one idea to change situation. I'm not sure it will be the right tool, but this will be the future. More over I can't see any problems to extend it for other micro-devices as CPLD and FPGA.  
Presented 1mul works as interpreter over user program written in mul, but this can be changed (see Appendix D in Manual).  All the commands are one-letter long and easy to remember. For example 'O' goes for 'Output', and   
  O1=1 means exactly what you mean - 'Make Output1=1'.   
No registers, nor bits.  
1mul is written in C so one can with litle effort convert it to a different processor. 
1mul is provided under [GNU GPL-3.0](https://opensource.org/licenses/GPL-3.0) license, while user's mul programs - under [MIT](https://opensource.org/licenses/MIT) license. The last one should not be included in user's programs, as this will waste processor memory, rather quoted separately or in user's program support documentation.  

Want to see mul in action? Watch the short avi presenting same 'blink' program running at different processors.  
Want to download and test 1mul? Go to [Releases](https://github.com/eta-sys/1mul/releases).  
Want to learn 1mul? Go to [Manual](https://github.com/eta-sys/1mul/wiki/mul-Manual).  
Want to participate the project? Go to [Developer's notes](https://github.com/eta-sys/1mul/wiki/Developer's-Notes).  
Want to leave a comment or make a proposition? Use this page or join 1mul@googlegroups.com in Google. 

If you want to use [MySerial](https://github.com/eta-sys/MySerial-TCP-UDP) as a terminal program fill free to get it.
