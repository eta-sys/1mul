If you have to trim your RTClock, use next program in your ESP8266 board:

HT{30 s}						#wait J7 to set time
!"J1 Start\r\n"
O=3,O{12,13},I{15}
F1=1
J1
?I1*F1 F1=0,O1=0,O2=1,T1{2 s}
?T1 T1=0,O1=1,O2=0,T2{2 s}
?T2 T2=0,O=3,F1=1
E
J7								#execute J7=1 when you want to set time
U14{5,1,"myNET","myPW"}
HT{5 s},P14{14,C,"TCP","ptbtime1.ptb.de",13},HT{15 s}?_$P14>0 $14=$P14;P14{14,0}
V14=$14/4+$14/5+$14/6
?V14=217 D1=1:?V14=205 D1=2:?V14=224 D1=3:?V14=227 D1=4:?V14=231 D1=5:?V14=237 D1=6:?V14=235 D1=7:?V14=221 D1=8:?V14=232 D1=9:?V14=230 D1=10:?V14=243 D1=11:?V14=204 D1=12:D1=0
?D1 D0=$14]10,D2=$14,D3=$14]13,D4=$14]16,D5=($14]19)*4
!"%2adD2 %2adD1 20%2adD0 %2ad{D3}:%2ad{D4}:%2ad{D5/4} day %ad{D6}\r\n",H
E


You have to write your WiFi-net for "myNET" and PW for "myPW" in order ESP to be in able to connect to the time server.
