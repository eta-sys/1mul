Using 'SetDateTime' from Example 7 you may build a smart socket to switch a consummer according to a programmed scheduler.

    ?U13 :U13{5,2,"esp","---PW----",3,7,1},P0{13,S,"TCP","192.168.4.1",2345}
    O=1,O{2}
    J1                                            # here write your scheduler
    ?D4+D5 :O1=0,HT{20 s},O1=1;                   # switsh on for 20s every round minute
    E
    J7
    ?V14*((7-D3)*3600+(7-D4)*60+(7-D5)) E					#set time at 7h7m7s
    U14{5,1," home NET"," home WiFi PW"}
    HT{5 s},P14{14,C,"TCP","ptbtime1.ptb.de",13},HT{15 s}?_$P14>0 $14=$P14;P14{14,0}
    V14=$14/4+$14/5+$14/6
    ?V14=217 D1=1:?V14=205 D1=2:?V14=224 D1=3:?V14=227 D1=4:?V14=231 D1=5:?V14=237 D1=6:?V14=235 D1=7:?V14=221 D1=8:?V14=232 D1=9:?V14=230 D1=10:?V14=243 D1=11:?V14=204 D1=12:D1=0
    ?D1 D0=$14]10,D2=$14,D3=$14]13,D4=$14]16,D5=($14]19)*4:V14=1,D3=7,D4=2;			# wait 5min ant try again
    !'"%2adD2 %2adD1 20%2adD0 %2ad{D3}:%2ad{D4}:%2ad{D5/4} day %ad{D6}\r\n",U14{0}
    E
    '0x1a

You can run a HTTP server to supervise the switch, or at last you may arrange TCP console U13 over home WiFi, 
so you will be in able to run, stop and monitoring program's work or upload a new one. If you prefer add local time correction.  
If you use ESP-07 you may attach a termistor or other analog sensor to the analog input, so you will have a feedback in real time.

