# MicroPython

[MicroPython](https://micropython.org), [docs](https://docs.micropython.org/), [firmware esp32 GENERIC](https://micropython.org/download/esp32/), [firmware sem þarf fyrir esp-now](https://github.com/glenn20/micropython-espnow-images/tree/main/20230427-v1.20.0-espnow-2-gcc4c716f6)

## Umhverfi

Thonny virðist virka vel og er einfaldur í notkun. Er með innbyggt tól til að keyra micropython firmware-ið á ESP32-inn (*Run->Configure interpreter...*). Hægt er að ræsa upp mörg tilvik af Thonny en það þarf að opna fyrir það í *Preferences* með því að taka hakið úr *Allow only single Thonny instance* (á Mac þarf að ræsa tilvik nr. 2 frá terminal með `open -n -a Thonny.app`). 

## Python skrárnar á ESP32

- `boot.py` Keyrir fyrst þegar ESP32 er ræstur, skráin er notuð fyrir stillingar ef einhverjar eru (eru það almennt ekki).
- `main.py` Keyrir sjálfkrafa þegar `boot.py` hefur lokið keyrslu, skráin inniheldur forritið sem á að keyra.

## ESP-NOW

Kóðadæmi, grunnur [héðan](https://micropython-glenn20.readthedocs.io/en/latest/library/espnow.html): stýripinni tengdur við sendi. Ef x gildið fer yfir 4000 kveikir mótttakarinn á led peru. 

Til að finna mac addressuna, [héðan](https://stackoverflow.com/questions/71902740/how-to-retrieve-and-format-wifi-mac-address-in-micropython-on-esp32):

```python
import network

wlan_sta = network.WLAN(network.STA_IF)
wlan_sta.active(True)

wlan_mac = wlan_sta.config('mac')
print("MAC Address:", wlan_mac)  # Show MAC for peering
```

Það er víst nóg að gera eftirfarandi í REPL til að fá MAC-addressuna:
```python
import machine
machine.unique_id()
```

### Sendir

```python
import network
import espnow
from machine import ADC, Pin

# A WLAN interface must be active to send()/recv()
sta = network.WLAN(network.STA_IF)  # Or network.AP_IF
sta.active(True)

e = espnow.ESPNow()
e.active(True)
peer = b'\x0c\xb8\x15\xc4\x9dl'   # MAC address of peer's wifi interface
e.add_peer(peer)

# ADC pinnarnir verða að vera úr ADCBlock 1 vegna ESP-NOW
x_pinni = ADC(Pin(32), atten=ADC.ATTN_11DB)
y_pinni = ADC(Pin(33), atten=ADC.ATTN_11DB)
takki = Pin(25, Pin.IN, Pin.PULL_DOWN)

while True:
    x_hreyfing = x_pinni.read()
    y_hreyfing = y_pinni.read()
    takki_stada = takki.value()
    sending = f"{x_hreyfing} {y_hreyfing} {takki_stada}"
    print(sending)
    e.send(peer, sending, True)  
```

### Móttakari

```python
import network
import espnow
from machine import Pin

# A WLAN interface must be active to send()/recv()
sta = network.WLAN(network.STA_IF)
sta.active(True)

e = espnow.ESPNow()
e.active(True)
peer = b'\xacg\xb26\xd0\xc8'   # MAC address of peer's wifi interface
e.add_peer(peer)

led1 = Pin(2, Pin.OUT)

while True:
    host, msg = e.recv()
    if msg:             # msg == None if timeout in recv()
        x, y, takki = msg.split()
        print(f"X: {int(x)}, Y: {int(y)}, Takki: {bool(int(takki))}")
        if int(x) > 4000:
            led1.on()
        else:
            led1.off()
```
