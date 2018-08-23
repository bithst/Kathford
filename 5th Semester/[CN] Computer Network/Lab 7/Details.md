# Lab 7 | Virtual LAN

>Date: Jestha 1 | May 15

| Values    | 192.168.0.129/28 - LAN10   | 192.168.0.145/28 - LAN20  |
| --------- | -------------------------- | ------------------------- |
| Address   | 192.168.0.129              | 192.168.0.145             |
| Netmask   | 255.255.255.240 = 28       | 255.255.255.240 = 28      |
| Wildcard  | 0.0.0.15                   | 0.0.0.15                  |
| Network   | 192.168.0.128/28 (Class C) | 192.168.0.144/28(Class C) |
| Broadcast | 192.168.0.143              | 192.168.0.159             |
| HostMin   | 192.168.0.129              | 192.168.0.145             |
| HostMax   | 192.168.0.142              | 192.168.0.158             |
| Hosts/Net | 14                         | 14                        |

## Switch Configurations

```none
Switch>enable
Switch#config terminal
Enter configuration commands, one per line.  End with CNTL/Z.
Switch(config)#vlan 10
Switch(config-vlan)#name CSIT
Switch(config-vlan)#vlan 20
Switch(config-vlan)#name BBA
Switch(config-vlan)#vlan 30
Switch(config-vlan)#name IT
Switch(config-vlan)#do show
show
% Incomplete command.
Switch(config-vlan)#do show vlan

VLAN Name                             Status    Ports
---- -------------------------------- --------- -------------------------------
1    default                          active    Fa0/1, Fa0/2, Fa0/3, Fa0/4
                                                Fa0/5, Fa0/6, Fa0/7, Fa0/8
                                                Fa0/9, Fa0/10, Fa0/11, Fa0/12
                                                Fa0/13, Fa0/14, Fa0/15, Fa0/16
                                                Fa0/17, Fa0/18, Fa0/19, Fa0/20
                                                Fa0/21, Fa0/22, Fa0/23, Fa0/24
                                                Gig0/1, Gig0/2
10   CSIT                             active
20   BBA                              active
30   IT                               active
1002 fddi-default                     active
1003 token-ring-default               active
1004 fddinet-default                  active
1005 trnet-default                    active

VLAN Type  SAID       MTU   Parent RingNo BridgeNo Stp  BrdgMode Trans1 Trans2
---- ----- ---------- ----- ------ ------ -------- ---- -------- ------ ------
1    enet  100001     1500  -      -      -        -    -        0      0
10   enet  100010     1500  -      -      -        -    -        0      0

Switch(config-vlan)#do show vlan

VLAN Name                             Status    Ports
---- -------------------------------- --------- -------------------------------
1    default                          active    Fa0/1, Fa0/2, Fa0/3, Fa0/4
                                                Fa0/5, Fa0/6, Fa0/7, Fa0/8
                                                Fa0/9, Fa0/10, Fa0/11, Fa0/12
                                                Fa0/13, Fa0/14, Fa0/15, Fa0/16
                                                Fa0/17, Fa0/18, Fa0/19, Fa0/20
                                                Fa0/21, Fa0/22, Fa0/23, Fa0/24
                                                Gig0/1, Gig0/2
10   CSIT                             active
20   BBA                              active
30   IT                               active
1002 fddi-default                     active
1003 token-ring-default               active
1004 fddinet-default                  active
1005 trnet-default                    active

VLAN Type  SAID       MTU   Parent RingNo BridgeNo Stp  BrdgMode Trans1 Trans2
---- ----- ---------- ----- ------ ------ -------- ---- -------- ------ ------
1    enet  100001     1500  -      -      -        -    -        0      0
10   enet  100010     1500  -      -      -        -    -        0      0
20   enet  100020     1500  -      -      -        -    -        0      0
30   enet  100030     1500  -      -      -        -    -        0      0
1002 fddi  101002     1500  -      -      -        -    -        0      0
1003 tr    101003     1500  -      -      -        -    -        0      0
1004 fdnet 101004     1500  -      -      -        ieee -        0      0
1005 trnet 101005     1500  -      -      -        ibm  -        0      0

VLAN Type  SAID       MTU   Parent RingNo BridgeNo Stp  BrdgMode Trans1 Trans2
---- ----- ---------- ----- ------ ------ -------- ---- -------- ------ ------

Remote SPAN VLANs
------------------------------------------------------------------------------

Primary Secondary Type              Ports
------- --------- ----------------- ------------------------------------------

Switch(config-vlan)#int range fa 0/1-5
Switch(config-if-range)#switchport access vlan 10
Switch(config-if-range)#switch mode access
Switch(config-if-range)#spanning-tree portfast

Switch(config)#int range fa 0/6-10
Switch(config-if-range)#switchport access vlan 20
Switch(config-if-range)#switch mode access
Switch(config-if-range)#spanning-tree portfast

Switch(config-if-range)#int range fa 0/11-14
Switch(config-if-range)#switchport access vlan 30
Switch(config-if-range)#switch mode access
Switch(config-if-range)#spanning-tree portfast

Switch(vlan)#
Switch(vlan)#exit

Switch(config)#interface fastEthernet 0/20
Switch(config-if)#switchport mode trunk
Switch(config-if)#spanning-tree portfast
```

## Router Configuration

Router 0

```none
Router>enable
Router#config terminal
Router(config)#interface fastEthernet 0/0.1
Router(config-subif)#encapsulation dot1Q 10
Router(config-subif)#ip address 192.168.0.142 255.255.255.240
Router(config-subif)#exit

Router(config)#int
Router(config)#interface fastEthernet 0/0.2
Router(config-subif)#encapsulation dot1Q 20

Router(config-subif)#ip address 192.168.0.158 255.255.255.240
```

## Checking connection

```none
Packet Tracer PC Command Line 1.0
C:\>ping 192.168.0.147

Pinging 192.168.0.147 with 32 bytes of data:

Reply from 192.168.0.147: bytes=32 time=11ms TTL=128
Reply from 192.168.0.147: bytes=32 time=1ms TTL=128
Reply from 192.168.0.147: bytes=32 time<1ms TTL=128
Reply from 192.168.0.147: bytes=32 time=1ms TTL=128

Ping statistics for 192.168.0.147:
    Packets: Sent = 4, Received = 4, Lost = 0 (0% loss),
Approximate round trip times in milli-seconds:
    Minimum = 0ms, Maximum = 11ms, Average = 3ms
```