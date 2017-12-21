Run this program on ESP8266. You will gain an other remote console to your board.
Connect to AP just opened. Use 'Putty' or 'MySerial' TCP Client (set 'Raw' to IP 192.168.4.1:2345) to talk with board.
See Wiki>Manual>Examples for more info.

    U14{5,2,"esp"},P015{14,S,"TCP",2345}
    J1
    H
    E
    '0x1a'
