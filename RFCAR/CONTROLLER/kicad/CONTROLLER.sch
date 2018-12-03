EESchema Schematic File Version 4
LIBS:CONTROLLER2-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5BFBDEB0
P 700 7550
F 0 "#FLG0101" H 700 7625 50  0001 C CNN
F 1 "PWR_FLAG" H 700 7724 50  0000 C CNN
F 2 "" H 700 7550 50  0001 C CNN
F 3 "~" H 700 7550 50  0001 C CNN
	1    700  7550
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0101
U 1 1 5BFBDEFC
P 700 7550
F 0 "#PWR0101" H 700 7400 50  0001 C CNN
F 1 "+9V" H 715 7723 50  0000 C CNN
F 2 "" H 700 7550 50  0001 C CNN
F 3 "" H 700 7550 50  0001 C CNN
	1    700  7550
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5BFBDFD4
P 1100 7550
F 0 "#FLG0102" H 1100 7625 50  0001 C CNN
F 1 "PWR_FLAG" H 1100 7724 50  0000 C CNN
F 2 "" H 1100 7550 50  0001 C CNN
F 3 "~" H 1100 7550 50  0001 C CNN
	1    1100 7550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5BFBE035
P 1100 7550
F 0 "#PWR0102" H 1100 7300 50  0001 C CNN
F 1 "GND" H 1105 7377 50  0000 C CNN
F 2 "" H 1100 7550 50  0001 C CNN
F 3 "" H 1100 7550 50  0001 C CNN
	1    1100 7550
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0103
U 1 1 5BFBE081
P 5350 850
F 0 "#PWR0103" H 5350 700 50  0001 C CNN
F 1 "+9V" H 5365 1023 50  0000 C CNN
F 2 "" H 5350 850 50  0001 C CNN
F 3 "" H 5350 850 50  0001 C CNN
	1    5350 850 
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C1
U 1 1 5BFBE174
P 5200 1200
F 0 "C1" V 4945 1200 50  0000 C CNN
F 1 "CP" V 5036 1200 50  0000 C CNN
F 2 "Capacitor_THT:C_Axial_L3.8mm_D2.6mm_P7.50mm_Horizontal" H 5238 1050 50  0001 C CNN
F 3 "~" H 5200 1200 50  0001 C CNN
	1    5200 1200
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5BFBE32A
P 5050 1200
F 0 "#PWR0104" H 5050 950 50  0001 C CNN
F 1 "GND" H 5055 1027 50  0000 C CNN
F 2 "" H 5050 1200 50  0001 C CNN
F 3 "" H 5050 1200 50  0001 C CNN
	1    5050 1200
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:LM7805_TO220 U1
U 1 1 5BFBE3A3
P 5350 1700
F 0 "U1" V 5304 1805 50  0000 L CNN
F 1 "LM7805_TO220" V 5395 1805 50  0000 L CNN
F 2 "Converter_DCDC:Converter_DCDC_TRACO_TSR-1_THT" H 5350 1925 50  0001 C CIN
F 3 "http://www.fairchildsemi.com/ds/LM/LM7805.pdf" H 5350 1650 50  0001 C CNN
	1    5350 1700
	0    1    1    0   
$EndComp
Wire Wire Line
	5350 1400 5350 1200
Connection ~ 5350 1200
$Comp
L power:GND #PWR0105
U 1 1 5BFBE43F
P 5050 1700
F 0 "#PWR0105" H 5050 1450 50  0001 C CNN
F 1 "GND" H 5055 1527 50  0000 C CNN
F 2 "" H 5050 1700 50  0001 C CNN
F 3 "" H 5050 1700 50  0001 C CNN
	1    5050 1700
	1    0    0    -1  
$EndComp
$Comp
L MCU_Microchip_ATmega:ATmega328-PU U2
U 1 1 5BFBE5D5
P 6350 3500
F 0 "U2" H 5709 3546 50  0000 R CNN
F 1 "ATmega328-PU" H 5709 3455 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 6350 3500 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 6350 3500 50  0001 C CNN
	1    6350 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 2000 5750 2000
Wire Wire Line
	6350 2000 6450 2000
Connection ~ 6350 2000
$Comp
L Connector:Conn_01x01_Female nrf_V+_3.3
U 1 1 5BFBECC5
P 7500 1900
F 0 "nrf_V+_3.3" H 7528 1926 50  0000 L CNN
F 1 " " H 7528 1835 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7500 1900 50  0001 C CNN
F 3 "~" H 7500 1900 50  0001 C CNN
	1    7500 1900
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female nrf_GND1
U 1 1 5BFBED5A
P 7500 2000
F 0 "nrf_GND1" H 7528 2026 50  0000 L CNN
F 1 " " H 7528 1935 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7500 2000 50  0001 C CNN
F 3 "~" H 7500 2000 50  0001 C CNN
	1    7500 2000
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female nrf_MOSI_PB3_11D1
U 1 1 5BFBEE0C
P 7500 2600
F 0 "nrf_MOSI_PB3_11D1" H 7528 2626 50  0000 L CNN
F 1 " " H 7528 2535 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7500 2600 50  0001 C CNN
F 3 "~" H 7500 2600 50  0001 C CNN
	1    7500 2600
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female nrf_CE_PB1_09D1
U 1 1 5BFBEE74
P 7500 2400
F 0 "nrf_CE_PB1_09D1" H 7528 2426 50  0000 L CNN
F 1 " " H 7528 2335 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7500 2400 50  0001 C CNN
F 3 "~" H 7500 2400 50  0001 C CNN
	1    7500 2400
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female nrf_SCK_PB5_13D1
U 1 1 5BFBEEDE
P 7500 2800
F 0 "nrf_SCK_PB5_13D1" H 7527 2826 50  0000 L CNN
F 1 " " H 7527 2735 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7500 2800 50  0001 C CNN
F 3 "~" H 7500 2800 50  0001 C CNN
	1    7500 2800
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female nrf_MISO_PB4_12D1
U 1 1 5BFBEF8C
P 7500 2700
F 0 "nrf_MISO_PB4_12D1" H 7528 2726 50  0000 L CNN
F 1 " " H 7528 2635 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7500 2700 50  0001 C CNN
F 3 "~" H 7500 2700 50  0001 C CNN
	1    7500 2700
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female nrf_CSN_PB2_10D1
U 1 1 5BFBF508
P 7500 2500
F 0 "nrf_CSN_PB2_10D1" H 7528 2526 50  0000 L CNN
F 1 " " H 7528 2435 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7500 2500 50  0001 C CNN
F 3 "~" H 7500 2500 50  0001 C CNN
	1    7500 2500
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:LM1117-3.3 U3
U 1 1 5BFBF963
P 7000 950
F 0 "U3" H 7000 1192 50  0000 C CNN
F 1 "LM1117-3.3" H 7000 1101 50  0000 C CNN
F 2 "Converter_DCDC:Converter_DCDC_TRACO_TSR-1_THT" H 7000 950 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm1117.pdf" H 7000 950 50  0001 C CNN
	1    7000 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 2000 7000 2000
Wire Wire Line
	7000 2000 7000 1650
Wire Wire Line
	7300 1900 7300 1650
$Comp
L Connector:Conn_01x01_Female _1
U 1 1 5BFBFEC4
P 7150 2300
F 0 "_1" H 7177 2326 50  0000 L CNN
F 1 " " H 7177 2235 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7150 2300 50  0001 C CNN
F 3 "~" H 7150 2300 50  0001 C CNN
	1    7150 2300
	1    0    0    -1  
$EndComp
$Comp
L Device:Crystal Y1
U 1 1 5BFBFFE4
P 8400 2950
F 0 "Y1" V 8354 3081 50  0000 L CNN
F 1 "Crystal" V 8445 3081 50  0000 L CNN
F 2 "Crystal:Crystal_HC49-U_Vertical" H 8400 2950 50  0001 C CNN
F 3 "~" H 8400 2950 50  0001 C CNN
	1    8400 2950
	0    1    1    0   
$EndComp
$Comp
L Device:CP C3
U 1 1 5BFC0D53
P 7150 1650
F 0 "C3" V 6895 1650 50  0000 C CNN
F 1 "CP" V 6986 1650 50  0000 C CNN
F 2 "Capacitor_THT:C_Axial_L3.8mm_D2.6mm_P7.50mm_Horizontal" H 7188 1500 50  0001 C CNN
F 3 "~" H 7150 1650 50  0001 C CNN
	1    7150 1650
	0    1    1    0   
$EndComp
Connection ~ 7000 1650
$Comp
L Device:CP C2
U 1 1 5BFC0DFF
P 6150 1850
F 0 "C2" H 6032 1804 50  0000 R CNN
F 1 "CP" H 6032 1895 50  0000 R CNN
F 2 "Capacitor_THT:C_Axial_L3.8mm_D2.6mm_P7.50mm_Horizontal" H 6188 1700 50  0001 C CNN
F 3 "~" H 6150 1850 50  0001 C CNN
	1    6150 1850
	-1   0    0    1   
$EndComp
Connection ~ 6150 2000
Wire Wire Line
	6150 2000 6350 2000
$Comp
L Device:C C4
U 1 1 5BFC1019
P 9000 2800
F 0 "C4" V 8748 2800 50  0000 C CNN
F 1 "C" V 8839 2800 50  0000 C CNN
F 2 "Capacitor_THT:C_Axial_L3.8mm_D2.6mm_P7.50mm_Horizontal" H 9038 2650 50  0001 C CNN
F 3 "~" H 9000 2800 50  0001 C CNN
	1    9000 2800
	0    1    1    0   
$EndComp
$Comp
L Device:C C5
U 1 1 5BFC1256
P 9000 3100
F 0 "C5" V 8748 3100 50  0000 C CNN
F 1 "C" V 8839 3100 50  0000 C CNN
F 2 "Capacitor_THT:C_Axial_L3.8mm_D2.6mm_P7.50mm_Horizontal" H 9038 2950 50  0001 C CNN
F 3 "~" H 9000 3100 50  0001 C CNN
	1    9000 3100
	0    1    1    0   
$EndComp
Wire Wire Line
	7300 2400 6950 2400
Wire Wire Line
	6950 2500 7300 2500
Wire Wire Line
	7300 2600 6950 2600
Wire Wire Line
	6950 2700 7300 2700
Wire Wire Line
	6950 2800 7300 2800
Wire Wire Line
	6950 2900 8250 2900
Wire Wire Line
	8250 2900 8250 2800
Wire Wire Line
	8250 2800 8400 2800
Wire Wire Line
	6950 3000 8250 3000
Wire Wire Line
	8250 3000 8250 3100
Wire Wire Line
	8250 3100 8400 3100
Wire Wire Line
	8400 3100 8850 3100
Connection ~ 8400 3100
Wire Wire Line
	8400 2800 8850 2800
Connection ~ 8400 2800
Text Label 8150 1950 0    197  ~ 0
nRF2401+
$Comp
L Connector:Conn_01x01_Female JT01_X1
U 1 1 5BFC46ED
P 7400 3200
F 0 "JT01_X1" H 7428 3226 50  0000 L CNN
F 1 " " H 7428 3135 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7400 3200 50  0001 C CNN
F 3 "~" H 7400 3200 50  0001 C CNN
	1    7400 3200
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female JT01_Y1
U 1 1 5BFC4902
P 7400 3300
F 0 "JT01_Y1" H 7427 3326 50  0000 L CNN
F 1 " " H 7427 3235 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7400 3300 50  0001 C CNN
F 3 "~" H 7400 3300 50  0001 C CNN
	1    7400 3300
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female JT02_X1
U 1 1 5BFC4EF3
P 7400 3400
F 0 "JT02_X1" H 7428 3426 50  0000 L CNN
F 1 " " H 7428 3335 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7400 3400 50  0001 C CNN
F 3 "~" H 7400 3400 50  0001 C CNN
	1    7400 3400
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female JT02_Y1
U 1 1 5BFC4F2F
P 7400 3500
F 0 "JT02_Y1" H 7427 3526 50  0000 L CNN
F 1 " " H 7427 3435 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7400 3500 50  0001 C CNN
F 3 "~" H 7400 3500 50  0001 C CNN
	1    7400 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 3200 7200 3200
Wire Wire Line
	6950 3300 7200 3300
Wire Wire Line
	6950 3400 7200 3400
Wire Wire Line
	6950 3500 7200 3500
$Comp
L Connector:Conn_01x01_Female JT01_BT1
U 1 1 5BFC647F
P 7450 4200
F 0 "JT01_BT1" H 7477 4226 50  0000 L CNN
F 1 " " H 7477 4135 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7450 4200 50  0001 C CNN
F 3 "~" H 7450 4200 50  0001 C CNN
	1    7450 4200
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female JT02_BT1
U 1 1 5BFC64D9
P 7450 4300
F 0 "JT02_BT1" H 7477 4326 50  0000 L CNN
F 1 " " H 7477 4235 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7450 4300 50  0001 C CNN
F 3 "~" H 7450 4300 50  0001 C CNN
	1    7450 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 4200 7250 4200
Wire Wire Line
	6950 4300 7250 4300
$Comp
L Connector:Conn_01x01_Female _2
U 1 1 5BFC8987
P 7150 3600
F 0 "_2" H 7177 3626 50  0000 L CNN
F 1 " " H 7177 3535 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7150 3600 50  0001 C CNN
F 3 "~" H 7150 3600 50  0001 C CNN
	1    7150 3600
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female _3
U 1 1 5BFC8A01
P 7150 3700
F 0 "_3" H 7177 3726 50  0000 L CNN
F 1 " " H 7177 3635 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7150 3700 50  0001 C CNN
F 3 "~" H 7150 3700 50  0001 C CNN
	1    7150 3700
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female _4
U 1 1 5BFC8A43
P 7150 3800
F 0 "_4" H 7177 3826 50  0000 L CNN
F 1 " " H 7177 3735 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7150 3800 50  0001 C CNN
F 3 "~" H 7150 3800 50  0001 C CNN
	1    7150 3800
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female _5
U 1 1 5BFC8AA1
P 7150 4000
F 0 "_5" H 7177 4026 50  0000 L CNN
F 1 " " H 7177 3935 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7150 4000 50  0001 C CNN
F 3 "~" H 7150 4000 50  0001 C CNN
	1    7150 4000
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female _6
U 1 1 5BFC8AEB
P 7150 4100
F 0 "_6" H 7177 4126 50  0000 L CNN
F 1 " " H 7177 4035 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7150 4100 50  0001 C CNN
F 3 "~" H 7150 4100 50  0001 C CNN
	1    7150 4100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female _7
U 1 1 5BFC8C15
P 7150 4400
F 0 "_7" H 7177 4426 50  0000 L CNN
F 1 " " H 7177 4335 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7150 4400 50  0001 C CNN
F 3 "~" H 7150 4400 50  0001 C CNN
	1    7150 4400
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female _8
U 1 1 5BFC8C67
P 7150 4500
F 0 "_8" H 7177 4526 50  0000 L CNN
F 1 " " H 7177 4435 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7150 4500 50  0001 C CNN
F 3 "~" H 7150 4500 50  0001 C CNN
	1    7150 4500
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female _9
U 1 1 5BFC8CB7
P 7150 4600
F 0 "_9" H 7177 4626 50  0000 L CNN
F 1 " " H 7177 4535 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7150 4600 50  0001 C CNN
F 3 "~" H 7150 4600 50  0001 C CNN
	1    7150 4600
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female _10
U 1 1 5BFC8D05
P 7150 4700
F 0 "_10" H 7177 4726 50  0000 L CNN
F 1 " " H 7177 4635 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7150 4700 50  0001 C CNN
F 3 "~" H 7150 4700 50  0001 C CNN
	1    7150 4700
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female JT01_5V1
U 1 1 5BFC9DFF
P 8350 3300
F 0 "JT01_5V1" H 8550 3300 50  0000 C CNN
F 1 " " H 8244 3166 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 8350 3300 50  0001 C CNN
F 3 "~" H 8350 3300 50  0001 C CNN
	1    8350 3300
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Female JT02_5V1
U 1 1 5BFCA49A
P 8350 3400
F 0 "JT02_5V1" H 8550 3400 50  0000 C CNN
F 1 " " H 8244 3266 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 8350 3400 50  0001 C CNN
F 3 "~" H 8350 3400 50  0001 C CNN
	1    8350 3400
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Female JT01_GND1
U 1 1 5BFCF4C5
P 8350 3500
F 0 "JT01_GND1" H 8550 3500 50  0000 C CNN
F 1 " " H 8244 3366 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 8350 3500 50  0001 C CNN
F 3 "~" H 8350 3500 50  0001 C CNN
	1    8350 3500
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Female JT02_GND1
U 1 1 5BFCF5B0
P 8350 3600
F 0 "JT02_GND1" H 8550 3600 50  0000 C CNN
F 1 " " H 8244 3466 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 8350 3600 50  0001 C CNN
F 3 "~" H 8350 3600 50  0001 C CNN
	1    8350 3600
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Female _11
U 1 1 5BFD30AC
P 5550 2300
F 0 "_11" H 5444 2075 50  0000 C CNN
F 1 " " H 5444 2166 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 5550 2300 50  0001 C CNN
F 3 "~" H 5550 2300 50  0001 C CNN
	1    5550 2300
	-1   0    0    1   
$EndComp
Wire Wire Line
	6150 1700 6150 1550
Wire Wire Line
	5350 2000 5350 5400
Wire Wire Line
	5350 5400 8900 5400
Wire Wire Line
	8900 5400 8900 3400
Wire Wire Line
	8900 3400 8550 3400
Connection ~ 5350 2000
Wire Wire Line
	8550 3400 8550 3300
Connection ~ 8550 3400
Wire Wire Line
	9150 2800 9150 2950
$Comp
L power:GND #PWR0106
U 1 1 5BFE7B14
P 6350 5000
F 0 "#PWR0106" H 6350 4750 50  0001 C CNN
F 1 "GND" H 6355 4827 50  0000 C CNN
F 2 "" H 6350 5000 50  0001 C CNN
F 3 "" H 6350 5000 50  0001 C CNN
	1    6350 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery_Cell BT1
U 1 1 5BFDC488
P 5150 850
F 0 "BT1" V 4895 900 50  0000 C CNN
F 1 "Battery_Cell" V 4986 900 50  0000 C CNN
F 2 "" V 5150 910 50  0001 C CNN
F 3 "~" V 5150 910 50  0001 C CNN
	1    5150 850 
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5BFE27A5
P 5050 850
F 0 "#PWR0107" H 5050 600 50  0001 C CNN
F 1 "GND" H 5055 677 50  0000 C CNN
F 2 "" H 5050 850 50  0001 C CNN
F 3 "" H 5050 850 50  0001 C CNN
	1    5050 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 1650 7000 1550
Connection ~ 7000 1550
Wire Wire Line
	6150 1550 6300 1550
Connection ~ 5350 850 
$Comp
L power:GND #PWR0108
U 1 1 5BFE82E6
P 6600 1550
F 0 "#PWR0108" H 6600 1300 50  0001 C CNN
F 1 "GND" H 6605 1377 50  0000 C CNN
F 2 "" H 6600 1550 50  0001 C CNN
F 3 "" H 6600 1550 50  0001 C CNN
	1    6600 1550
	1    0    0    -1  
$EndComp
Connection ~ 6600 1550
Wire Wire Line
	6600 1550 7000 1550
$Comp
L power:GND #PWR0109
U 1 1 5BFE8897
P 9150 2950
F 0 "#PWR0109" H 9150 2700 50  0001 C CNN
F 1 "GND" H 9155 2777 50  0000 C CNN
F 2 "" H 9150 2950 50  0001 C CNN
F 3 "" H 9150 2950 50  0001 C CNN
	1    9150 2950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9150 3100 9150 2950
Connection ~ 9150 2950
$Comp
L power:GND #PWR0110
U 1 1 5BFF202A
P 8550 3550
F 0 "#PWR0110" H 8550 3300 50  0001 C CNN
F 1 "GND" H 8555 3377 50  0000 C CNN
F 2 "" H 8550 3550 50  0001 C CNN
F 3 "" H 8550 3550 50  0001 C CNN
	1    8550 3550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8550 3500 8550 3550
Wire Wire Line
	8550 3550 8550 3600
Connection ~ 8550 3550
$Comp
L Device:R R1
U 1 1 5BFF374F
P 6300 1400
F 0 "R1" H 6370 1446 50  0000 L CNN
F 1 "R" H 6370 1355 50  0000 L CNN
F 2 "" V 6230 1400 50  0001 C CNN
F 3 "~" H 6300 1400 50  0001 C CNN
	1    6300 1400
	1    0    0    -1  
$EndComp
Connection ~ 6300 1550
Wire Wire Line
	6300 1550 6600 1550
$Comp
L Device:LED D1
U 1 1 5BFF384D
P 6300 1100
F 0 "D1" V 6245 1178 50  0000 L CNN
F 1 "LED" V 6336 1178 50  0000 L CNN
F 2 "" H 6300 1100 50  0001 C CNN
F 3 "~" H 6300 1100 50  0001 C CNN
	1    6300 1100
	0    1    1    0   
$EndComp
Connection ~ 7300 1650
Wire Wire Line
	5350 850  5350 1200
Connection ~ 5750 2000
Wire Wire Line
	5750 2000 6150 2000
Wire Wire Line
	5750 950  6300 950 
Wire Wire Line
	5750 950  5750 2000
Connection ~ 6300 950 
Wire Wire Line
	6300 950  6700 950 
Wire Wire Line
	7300 950  7300 1650
Wire Wire Line
	7000 1250 7000 1550
$EndSCHEMATC
