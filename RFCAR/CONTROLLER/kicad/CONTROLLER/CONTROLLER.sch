EESchema Schematic File Version 4
LIBS:CONTROLLER-cache
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
L power:PWR_FLAG #FLG01
U 1 1 5BFBDEB0
P 700 7550
F 0 "#FLG01" H 700 7625 50  0001 C CNN
F 1 "PWR_FLAG" H 700 7724 50  0000 C CNN
F 2 "" H 700 7550 50  0001 C CNN
F 3 "~" H 700 7550 50  0001 C CNN
	1    700  7550
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR01
U 1 1 5BFBDEFC
P 700 7550
F 0 "#PWR01" H 700 7400 50  0001 C CNN
F 1 "+9V" H 715 7723 50  0000 C CNN
F 2 "" H 700 7550 50  0001 C CNN
F 3 "" H 700 7550 50  0001 C CNN
	1    700  7550
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG02
U 1 1 5BFBDFD4
P 1100 7550
F 0 "#FLG02" H 1100 7625 50  0001 C CNN
F 1 "PWR_FLAG" H 1100 7724 50  0000 C CNN
F 2 "" H 1100 7550 50  0001 C CNN
F 3 "~" H 1100 7550 50  0001 C CNN
	1    1100 7550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5BFBE035
P 1100 7550
F 0 "#PWR02" H 1100 7300 50  0001 C CNN
F 1 "GND" H 1105 7377 50  0000 C CNN
F 2 "" H 1100 7550 50  0001 C CNN
F 3 "" H 1100 7550 50  0001 C CNN
	1    1100 7550
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C1
U 1 1 5BFBE174
P 5250 2250
F 0 "C1" V 4995 2250 50  0000 C CNN
F 1 "CP" V 5086 2250 50  0000 C CNN
F 2 "Capacitor_THT:C_Axial_L3.8mm_D2.6mm_P7.50mm_Horizontal" H 5288 2100 50  0001 C CNN
F 3 "~" H 5250 2250 50  0001 C CNN
	1    5250 2250
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR04
U 1 1 5BFBE32A
P 5100 2250
F 0 "#PWR04" H 5100 2000 50  0001 C CNN
F 1 "GND" H 5105 2077 50  0000 C CNN
F 2 "" H 5100 2250 50  0001 C CNN
F 3 "" H 5100 2250 50  0001 C CNN
	1    5100 2250
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:LM7805_TO220 U1
U 1 1 5BFBE3A3
P 5400 2700
F 0 "U1" V 5354 2805 50  0000 L CNN
F 1 "LM7805_TO220" V 5445 2805 50  0000 L CNN
F 2 "Converter_DCDC:Converter_DCDC_TRACO_TSR-1_THT" H 5400 2925 50  0001 C CIN
F 3 "http://www.fairchildsemi.com/ds/LM/LM7805.pdf" H 5400 2650 50  0001 C CNN
	1    5400 2700
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5BFBE43F
P 5100 2700
F 0 "#PWR05" H 5100 2450 50  0001 C CNN
F 1 "GND" H 5105 2527 50  0000 C CNN
F 2 "" H 5100 2700 50  0001 C CNN
F 3 "" H 5100 2700 50  0001 C CNN
	1    5100 2700
	1    0    0    -1  
$EndComp
$Comp
L MCU_Microchip_ATmega:ATmega328-PU U2
U 1 1 5BFBE5D5
P 6400 4500
F 0 "U2" H 5759 4546 50  0000 R CNN
F 1 "ATmega328-PU" H 5759 4455 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 6400 4500 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 6400 4500 50  0001 C CNN
	1    6400 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 3000 5800 3000
Wire Wire Line
	6400 3000 6500 3000
Connection ~ 6400 3000
$Comp
L Connector:Conn_01x01_Female nrf_V+_3.1
U 1 1 5BFBECC5
P 7550 2900
F 0 "nrf_V+_3.1" H 7578 2926 50  0000 L CNN
F 1 " " H 7578 2835 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7550 2900 50  0001 C CNN
F 3 "~" H 7550 2900 50  0001 C CNN
	1    7550 2900
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female nrf_GND1
U 1 1 5BFBED5A
P 7550 3000
F 0 "nrf_GND1" H 7578 3026 50  0000 L CNN
F 1 " " H 7578 2935 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7550 3000 50  0001 C CNN
F 3 "~" H 7550 3000 50  0001 C CNN
	1    7550 3000
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female nrf_MOSI_PB3_11D1
U 1 1 5BFBEE0C
P 7550 3600
F 0 "nrf_MOSI_PB3_11D1" H 7578 3626 50  0000 L CNN
F 1 " " H 7578 3535 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7550 3600 50  0001 C CNN
F 3 "~" H 7550 3600 50  0001 C CNN
	1    7550 3600
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female nrf_CE_PB1_09D1
U 1 1 5BFBEE74
P 7550 3400
F 0 "nrf_CE_PB1_09D1" H 7578 3426 50  0000 L CNN
F 1 " " H 7578 3335 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7550 3400 50  0001 C CNN
F 3 "~" H 7550 3400 50  0001 C CNN
	1    7550 3400
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female nrf_SCK_PB5_13D1
U 1 1 5BFBEEDE
P 7550 3800
F 0 "nrf_SCK_PB5_13D1" H 7577 3826 50  0000 L CNN
F 1 " " H 7577 3735 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7550 3800 50  0001 C CNN
F 3 "~" H 7550 3800 50  0001 C CNN
	1    7550 3800
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female nrf_MISO_PB4_12D1
U 1 1 5BFBEF8C
P 7550 3700
F 0 "nrf_MISO_PB4_12D1" H 7578 3726 50  0000 L CNN
F 1 " " H 7578 3635 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7550 3700 50  0001 C CNN
F 3 "~" H 7550 3700 50  0001 C CNN
	1    7550 3700
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female nrf_CSN_PB2_10D1
U 1 1 5BFBF508
P 7550 3500
F 0 "nrf_CSN_PB2_10D1" H 7578 3526 50  0000 L CNN
F 1 " " H 7578 3435 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7550 3500 50  0001 C CNN
F 3 "~" H 7550 3500 50  0001 C CNN
	1    7550 3500
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:LM1117-3.3 U3
U 1 1 5BFBF963
P 7050 1950
F 0 "U3" H 7050 2192 50  0000 C CNN
F 1 "LM1117-3.3" H 7050 2101 50  0000 C CNN
F 2 "Converter_DCDC:Converter_DCDC_TRACO_TSR-1_THT" H 7050 1950 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm1117.pdf" H 7050 1950 50  0001 C CNN
	1    7050 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 3000 7050 3000
Wire Wire Line
	7050 3000 7050 2650
Wire Wire Line
	7350 2900 7350 2650
$Comp
L Connector:Conn_01x01_Female _2
U 1 1 5BFBFEC4
P 7200 3300
F 0 "_2" H 7227 3326 50  0000 L CNN
F 1 " " H 7227 3235 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7200 3300 50  0001 C CNN
F 3 "~" H 7200 3300 50  0001 C CNN
	1    7200 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:Crystal Y1
U 1 1 5BFBFFE4
P 8450 3950
F 0 "Y1" V 8404 4081 50  0000 L CNN
F 1 "Crystal" V 8495 4081 50  0000 L CNN
F 2 "Crystal:Crystal_HC49-U_Vertical" H 8450 3950 50  0001 C CNN
F 3 "~" H 8450 3950 50  0001 C CNN
	1    8450 3950
	0    1    1    0   
$EndComp
$Comp
L Device:CP C3
U 1 1 5BFC0D53
P 7200 2650
F 0 "C3" V 6945 2650 50  0000 C CNN
F 1 "CP" V 7036 2650 50  0000 C CNN
F 2 "Capacitor_THT:C_Axial_L3.8mm_D2.6mm_P7.50mm_Horizontal" H 7238 2500 50  0001 C CNN
F 3 "~" H 7200 2650 50  0001 C CNN
	1    7200 2650
	0    1    1    0   
$EndComp
Connection ~ 7050 2650
$Comp
L Device:CP C2
U 1 1 5BFC0DFF
P 6200 2850
F 0 "C2" H 6082 2804 50  0000 R CNN
F 1 "CP" H 6082 2895 50  0000 R CNN
F 2 "Capacitor_THT:C_Axial_L3.8mm_D2.6mm_P7.50mm_Horizontal" H 6238 2700 50  0001 C CNN
F 3 "~" H 6200 2850 50  0001 C CNN
	1    6200 2850
	-1   0    0    1   
$EndComp
Connection ~ 6200 3000
Wire Wire Line
	6200 3000 6400 3000
$Comp
L Device:C C4
U 1 1 5BFC1019
P 9050 3800
F 0 "C4" V 8798 3800 50  0000 C CNN
F 1 "C" V 8889 3800 50  0000 C CNN
F 2 "Capacitor_THT:C_Axial_L3.8mm_D2.6mm_P7.50mm_Horizontal" H 9088 3650 50  0001 C CNN
F 3 "~" H 9050 3800 50  0001 C CNN
	1    9050 3800
	0    1    1    0   
$EndComp
$Comp
L Device:C C5
U 1 1 5BFC1256
P 9050 4100
F 0 "C5" V 8798 4100 50  0000 C CNN
F 1 "C" V 8889 4100 50  0000 C CNN
F 2 "Capacitor_THT:C_Axial_L3.8mm_D2.6mm_P7.50mm_Horizontal" H 9088 3950 50  0001 C CNN
F 3 "~" H 9050 4100 50  0001 C CNN
	1    9050 4100
	0    1    1    0   
$EndComp
Wire Wire Line
	7350 3400 7000 3400
Wire Wire Line
	7000 3500 7350 3500
Wire Wire Line
	7350 3600 7000 3600
Wire Wire Line
	7000 3700 7350 3700
Wire Wire Line
	7000 3800 7350 3800
Wire Wire Line
	7000 3900 8300 3900
Wire Wire Line
	8300 3900 8300 3800
Wire Wire Line
	8300 3800 8450 3800
Wire Wire Line
	7000 4000 8300 4000
Wire Wire Line
	8300 4000 8300 4100
Wire Wire Line
	8300 4100 8450 4100
Wire Wire Line
	8450 4100 8900 4100
Connection ~ 8450 4100
Wire Wire Line
	8450 3800 8900 3800
Connection ~ 8450 3800
Text Label 8200 2950 0    197  ~ 0
nRF2401+
$Comp
L Connector:Conn_01x01_Female JT01_X1
U 1 1 5BFC46ED
P 7450 4200
F 0 "JT01_X1" H 7478 4226 50  0000 L CNN
F 1 " " H 7478 4135 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7450 4200 50  0001 C CNN
F 3 "~" H 7450 4200 50  0001 C CNN
	1    7450 4200
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female JT01_Y1
U 1 1 5BFC4902
P 7450 4300
F 0 "JT01_Y1" H 7477 4326 50  0000 L CNN
F 1 " " H 7477 4235 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7450 4300 50  0001 C CNN
F 3 "~" H 7450 4300 50  0001 C CNN
	1    7450 4300
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female JT02_X1
U 1 1 5BFC4EF3
P 7450 4400
F 0 "JT02_X1" H 7478 4426 50  0000 L CNN
F 1 " " H 7478 4335 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7450 4400 50  0001 C CNN
F 3 "~" H 7450 4400 50  0001 C CNN
	1    7450 4400
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female JT02_Y1
U 1 1 5BFC4F2F
P 7450 4500
F 0 "JT02_Y1" H 7477 4526 50  0000 L CNN
F 1 " " H 7477 4435 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7450 4500 50  0001 C CNN
F 3 "~" H 7450 4500 50  0001 C CNN
	1    7450 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 4200 7250 4200
Wire Wire Line
	7000 4300 7250 4300
Wire Wire Line
	7000 4400 7250 4400
Wire Wire Line
	7000 4500 7250 4500
$Comp
L Connector:Conn_01x01_Female JT01_BT1
U 1 1 5BFC647F
P 7500 5200
F 0 "JT01_BT1" H 7527 5226 50  0000 L CNN
F 1 " " H 7527 5135 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7500 5200 50  0001 C CNN
F 3 "~" H 7500 5200 50  0001 C CNN
	1    7500 5200
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female JT02_BT1
U 1 1 5BFC64D9
P 7500 5300
F 0 "JT02_BT1" H 7527 5326 50  0000 L CNN
F 1 " " H 7527 5235 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7500 5300 50  0001 C CNN
F 3 "~" H 7500 5300 50  0001 C CNN
	1    7500 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 5200 7300 5200
Wire Wire Line
	7000 5300 7300 5300
$Comp
L Connector:Conn_01x01_Female _3
U 1 1 5BFC8987
P 7200 4600
F 0 "_3" H 7227 4626 50  0000 L CNN
F 1 " " H 7227 4535 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7200 4600 50  0001 C CNN
F 3 "~" H 7200 4600 50  0001 C CNN
	1    7200 4600
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female _4
U 1 1 5BFC8A01
P 7200 4700
F 0 "_4" H 7227 4726 50  0000 L CNN
F 1 " " H 7227 4635 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7200 4700 50  0001 C CNN
F 3 "~" H 7200 4700 50  0001 C CNN
	1    7200 4700
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female _5
U 1 1 5BFC8A43
P 7200 4800
F 0 "_5" H 7227 4826 50  0000 L CNN
F 1 " " H 7227 4735 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7200 4800 50  0001 C CNN
F 3 "~" H 7200 4800 50  0001 C CNN
	1    7200 4800
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female _6
U 1 1 5BFC8AA1
P 7200 5000
F 0 "_6" H 7227 5026 50  0000 L CNN
F 1 " " H 7227 4935 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7200 5000 50  0001 C CNN
F 3 "~" H 7200 5000 50  0001 C CNN
	1    7200 5000
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female _7
U 1 1 5BFC8AEB
P 7200 5100
F 0 "_7" H 7227 5126 50  0000 L CNN
F 1 " " H 7227 5035 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7200 5100 50  0001 C CNN
F 3 "~" H 7200 5100 50  0001 C CNN
	1    7200 5100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female _8
U 1 1 5BFC8C15
P 7200 5400
F 0 "_8" H 7227 5426 50  0000 L CNN
F 1 " " H 7227 5335 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7200 5400 50  0001 C CNN
F 3 "~" H 7200 5400 50  0001 C CNN
	1    7200 5400
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female _9
U 1 1 5BFC8C67
P 7200 5500
F 0 "_9" H 7227 5526 50  0000 L CNN
F 1 " " H 7227 5435 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7200 5500 50  0001 C CNN
F 3 "~" H 7200 5500 50  0001 C CNN
	1    7200 5500
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female _10
U 1 1 5BFC8CB7
P 7200 5600
F 0 "_10" H 7227 5626 50  0000 L CNN
F 1 " " H 7227 5535 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7200 5600 50  0001 C CNN
F 3 "~" H 7200 5600 50  0001 C CNN
	1    7200 5600
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female _11
U 1 1 5BFC8D05
P 7200 5700
F 0 "_11" H 7227 5726 50  0000 L CNN
F 1 " " H 7227 5635 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 7200 5700 50  0001 C CNN
F 3 "~" H 7200 5700 50  0001 C CNN
	1    7200 5700
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female JT01_5V1
U 1 1 5BFC9DFF
P 8400 4300
F 0 "JT01_5V1" H 8600 4300 50  0000 C CNN
F 1 " " H 8294 4166 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 8400 4300 50  0001 C CNN
F 3 "~" H 8400 4300 50  0001 C CNN
	1    8400 4300
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Female JT02_5V1
U 1 1 5BFCA49A
P 8400 4400
F 0 "JT02_5V1" H 8600 4400 50  0000 C CNN
F 1 " " H 8294 4266 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 8400 4400 50  0001 C CNN
F 3 "~" H 8400 4400 50  0001 C CNN
	1    8400 4400
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Female JT01_GND1
U 1 1 5BFCF4C5
P 8400 4500
F 0 "JT01_GND1" H 8600 4500 50  0000 C CNN
F 1 " " H 8294 4366 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 8400 4500 50  0001 C CNN
F 3 "~" H 8400 4500 50  0001 C CNN
	1    8400 4500
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Female JT02_GND1
U 1 1 5BFCF5B0
P 8400 4600
F 0 "JT02_GND1" H 8600 4600 50  0000 C CNN
F 1 " " H 8294 4466 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 8400 4600 50  0001 C CNN
F 3 "~" H 8400 4600 50  0001 C CNN
	1    8400 4600
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Female _1
U 1 1 5BFD30AC
P 5600 3300
F 0 "_1" H 5494 3075 50  0000 C CNN
F 1 " " H 5494 3166 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 5600 3300 50  0001 C CNN
F 3 "~" H 5600 3300 50  0001 C CNN
	1    5600 3300
	-1   0    0    1   
$EndComp
Wire Wire Line
	6200 2700 6200 2550
Wire Wire Line
	5400 3000 5400 6400
Wire Wire Line
	5400 6400 8950 6400
Wire Wire Line
	8950 6400 8950 4400
Wire Wire Line
	8950 4400 8600 4400
Connection ~ 5400 3000
Wire Wire Line
	8600 4400 8600 4300
Connection ~ 8600 4400
Wire Wire Line
	9200 3800 9200 3950
$Comp
L power:GND #PWR08
U 1 1 5BFE7B14
P 6400 6000
F 0 "#PWR08" H 6400 5750 50  0001 C CNN
F 1 "GND" H 6405 5827 50  0000 C CNN
F 2 "" H 6400 6000 50  0001 C CNN
F 3 "" H 6400 6000 50  0001 C CNN
	1    6400 6000
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery_Cell BT1
U 1 1 5BFDC488
P 5200 950
F 0 "BT1" V 4945 1000 50  0000 C CNN
F 1 "Battery_Cell" V 5036 1000 50  0000 C CNN
F 2 "" V 5200 1010 50  0001 C CNN
F 3 "~" V 5200 1010 50  0001 C CNN
	1    5200 950 
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5BFE27A5
P 5100 950
F 0 "#PWR03" H 5100 700 50  0001 C CNN
F 1 "GND" H 5105 777 50  0000 C CNN
F 2 "" H 5100 950 50  0001 C CNN
F 3 "" H 5100 950 50  0001 C CNN
	1    5100 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 2650 7050 2550
Connection ~ 7050 2550
Wire Wire Line
	6200 2550 6350 2550
$Comp
L power:GND #PWR09
U 1 1 5BFE82E6
P 6650 2550
F 0 "#PWR09" H 6650 2300 50  0001 C CNN
F 1 "GND" H 6655 2377 50  0000 C CNN
F 2 "" H 6650 2550 50  0001 C CNN
F 3 "" H 6650 2550 50  0001 C CNN
	1    6650 2550
	1    0    0    -1  
$EndComp
Connection ~ 6650 2550
Wire Wire Line
	6650 2550 7050 2550
$Comp
L power:GND #PWR011
U 1 1 5BFE8897
P 9200 3950
F 0 "#PWR011" H 9200 3700 50  0001 C CNN
F 1 "GND" H 9205 3777 50  0000 C CNN
F 2 "" H 9200 3950 50  0001 C CNN
F 3 "" H 9200 3950 50  0001 C CNN
	1    9200 3950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9200 4100 9200 3950
Connection ~ 9200 3950
$Comp
L power:GND #PWR010
U 1 1 5BFF202A
P 8600 4550
F 0 "#PWR010" H 8600 4300 50  0001 C CNN
F 1 "GND" H 8605 4377 50  0000 C CNN
F 2 "" H 8600 4550 50  0001 C CNN
F 3 "" H 8600 4550 50  0001 C CNN
	1    8600 4550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8600 4500 8600 4550
Wire Wire Line
	8600 4550 8600 4600
Connection ~ 8600 4550
$Comp
L Device:R R1
U 1 1 5BFF374F
P 6350 2400
F 0 "R1" H 6420 2446 50  0000 L CNN
F 1 "R" H 6420 2355 50  0000 L CNN
F 2 "" V 6280 2400 50  0001 C CNN
F 3 "~" H 6350 2400 50  0001 C CNN
	1    6350 2400
	1    0    0    -1  
$EndComp
Connection ~ 6350 2550
Wire Wire Line
	6350 2550 6650 2550
$Comp
L Device:LED D1
U 1 1 5BFF384D
P 6350 2100
F 0 "D1" V 6295 2178 50  0000 L CNN
F 1 "LED" V 6386 2178 50  0000 L CNN
F 2 "" H 6350 2100 50  0001 C CNN
F 3 "~" H 6350 2100 50  0001 C CNN
	1    6350 2100
	0    1    1    0   
$EndComp
Connection ~ 7350 2650
Connection ~ 5800 3000
Wire Wire Line
	5800 3000 6200 3000
Wire Wire Line
	5800 1950 6350 1950
Wire Wire Line
	5800 1950 5800 3000
Connection ~ 6350 1950
Wire Wire Line
	6350 1950 6750 1950
Wire Wire Line
	7350 1950 7350 2650
Wire Wire Line
	7050 2250 7050 2550
Wire Wire Line
	5400 950  5400 1350
Wire Wire Line
	5400 2250 5400 2400
$Comp
L power:+BATT #PWR0101
U 1 1 5C06009C
P 1550 7550
F 0 "#PWR0101" H 1550 7400 50  0001 C CNN
F 1 "+BATT" H 1565 7723 50  0000 C CNN
F 2 "" H 1550 7550 50  0001 C CNN
F 3 "" H 1550 7550 50  0001 C CNN
	1    1550 7550
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5C063F8F
P 1550 7550
F 0 "#FLG0101" H 1550 7625 50  0001 C CNN
F 1 "PWR_FLAG" H 1550 7724 50  0000 C CNN
F 2 "" H 1550 7550 50  0001 C CNN
F 3 "~" H 1550 7550 50  0001 C CNN
	1    1550 7550
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5C0667BA
P 2000 7550
F 0 "#FLG0102" H 2000 7625 50  0001 C CNN
F 1 "PWR_FLAG" H 2000 7724 50  0000 C CNN
F 2 "" H 2000 7550 50  0001 C CNN
F 3 "~" H 2000 7550 50  0001 C CNN
	1    2000 7550
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0102
U 1 1 5C0674CE
P 2000 7550
F 0 "#PWR0102" H 2000 7400 50  0001 C CNN
F 1 "+5V" H 2015 7723 50  0000 C CNN
F 2 "" H 2000 7550 50  0001 C CNN
F 3 "" H 2000 7550 50  0001 C CNN
	1    2000 7550
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG0103
U 1 1 5C067584
P 2450 7550
F 0 "#FLG0103" H 2450 7625 50  0001 C CNN
F 1 "PWR_FLAG" H 2450 7724 50  0000 C CNN
F 2 "" H 2450 7550 50  0001 C CNN
F 3 "~" H 2450 7550 50  0001 C CNN
	1    2450 7550
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0103
U 1 1 5C067682
P 2450 7550
F 0 "#PWR0103" H 2450 7400 50  0001 C CNN
F 1 "+3.3V" H 2465 7723 50  0000 C CNN
F 2 "" H 2450 7550 50  0001 C CNN
F 3 "" H 2450 7550 50  0001 C CNN
	1    2450 7550
	-1   0    0    1   
$EndComp
Wire Wire Line
	5400 2250 5400 1950
Connection ~ 5400 2250
$Comp
L power:+9V #PWR0104
U 1 1 5C05DB23
P 5400 700
F 0 "#PWR0104" H 5400 550 50  0001 C CNN
F 1 "+9V" H 5415 873 50  0000 C CNN
F 2 "" H 5400 700 50  0001 C CNN
F 3 "" H 5400 700 50  0001 C CNN
	1    5400 700 
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 950  5400 700 
Connection ~ 5400 950 
$Comp
L switch:SW_DIP_x01 SW1
U 1 1 5C081EE9
P 5400 1650
F 0 "SW1" V 5354 1780 50  0000 L CNN
F 1 "SW_DIP_x01" V 5445 1780 50  0000 L CNN
F 2 "" H 5400 1650 50  0001 C CNN
F 3 "" H 5400 1650 50  0001 C CNN
	1    5400 1650
	0    1    1    0   
$EndComp
$EndSCHEMATC
