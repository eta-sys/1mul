This program have to be run on ESP8266 only!

As Pic has limited memory space ml-program is keeped in Flash. So you can't see it working correct on Pic.
Program finds "My old row" and replaced it to "My new row". Keep in mind that new length has to be less or equal than old one, else row pointers set at program start will be corupted.

    O=3,O{12,13},I{14}        # initial block
    $1="!\"This is my old"
    P1{15},P1+$P1/$1-_$1="!\"This is my new row!\""
    J1                        # Job1 entry point
    H?I1 O1=0,O2=1            # halt&wait I1
    HT{5 s} O1=1,O2=0         # halt for 5 sec.
    HT{5 s} O=3               # halt for 5 sec.
    !"This is my old row!"		# row for change
    E                         # End. Loop to J1
    '0x1a'


