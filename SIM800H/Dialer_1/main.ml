HD: add a switch between BLUE TERMINALS Z1 and +12V
SW: replace string "0011223344" with your phone number
Switching switch On/Off you'll receive a SMS.
Use code as template to create you own alarm system.

    O=0,I{1,2,3,4,5},O{9,10}
    V1=0,V2=I,U1{4,1}
    J1,V1=V2^I
    ?V1=0 E
    ?V1&1 P1{1,SMS,"0011223344"},?I&1 P1="Z1 Alarm":P1="Restore Z1"; HT{10 s}?P1=1 
    V2=I
    E

