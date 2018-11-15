O=0,I{1,2,3,4,5},O{9,10}
V1=0,V2=I,U1{4,1}
J1,V1=V2^I
?V1=0 E
?V1&1 P1{1,SMS,"0011223344"},?I&1 P1="Z1 Alarm":P1="Restore Z1"; HT{10 s}?P1=1 
V2=I
E

