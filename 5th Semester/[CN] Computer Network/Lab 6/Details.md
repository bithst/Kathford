# Lab 6 | Distance Vector Routing

>Date: Baiskh 28 | May 12

## CLI Commands

### Router 0

```none
Router>enable
Router#config terminal
Enter configuration commands, one per line.  End with CNTL/Z.
Router(config)#int
Router(config)#interface fas
Router(config)#int
Router(config)#interface se
Router(config)#interface serial 0/0
Router(config-if)#ip
Router(config-if)#ip add
Router(config-if)#ip address 16.0.0.1 255.0.0.0
Router(config-if)#no shutdown

Router(config-if)#
%LINK-5-CHANGED: Interface Serial0/0, changed state to up

%LINEPROTO-5-UPDOWN: Line protocol on Interface Serial0/0, changed state to up

Router(config-if)#exit
Router(config)#int
Router(config)#interface fa
Router(config)#interface fastEthernet 0/0
Router(config-if)#ip add
Router(config-if)#ip address 192.168.1.1 255.255.255.0
Router(config-if)#no shutdown

Router(config-if)#
%LINK-5-CHANGED: Interface FastEthernet0/0, changed state to up

%LINEPROTO-5-UPDOWN: Line protocol on Interface FastEthernet0/0, changed state to up
```