esphome:
  name: smartswitch
  friendly_name: SmartSwitch 

esp8266:
  board: nodemcuv2

# Enable logging
logger:

# Enable Home Assistant API
api:
  encryption:
    key: "LC7R3n3Y7QuWIF3HbxLR6bqhaah33v4YgpvDMMXyf3I="

ota:
  - platform: esphome
    password: "70dc608e95566662d60e00e9f3284a16"

wifi:
  ssid: !secret wifi_ssid
  password: !secret wifi_password

  # Enable fallback hotspot (captive portal) in case wifi connection fails
  ap:
    ssid: "Smartswitch Fallback Hotspot"
    password: "KzX5Cm9kNAOx"

captive_portal:

switch:
  - platform: gpio
    pin: D3  #Enter pin for Relay 1
    name: Relay1
    id: relay1
    inverted: true
  - platform: gpio
    pin: D2 #Enter pin for Relay 2
    name: Relay2
    id: relay2
    inverted: true  
  - platform: gpio
    pin: D1 #Enter pin for Relay 3
    name: relay3
    id: relay
    inverted: true
  - platform: gpio
    pin: GPIO10 #Enter pin for Relay 4 
    name: Relay4
    id: relay4
    inverted: true          

binary_sensor:
    - platform: gpio
      pin: D6 # Enter Touch Sensor 1 pin
      name: touch_1
      device_class: window
      on_press:
      - switch.toggle: relay1
    - platform: gpio
      pin: D5  # Enter Touch Sensor 2 pin
      name: touch_2
      on_press:
      - switch.toggle: relay2       
      device_class: window
    - platform: gpio
      pin: D0 # Enter Touch Sensor 3 pin
      name: touch_3
      device_class: window
      on_press:
      - switch.toggle: relay       
    - platform: gpio
      pin: D7 # Enter Touch Sensor 4 pin
      name: touch_4
      device_class: window      
      on_press:
      - switch.toggle: relay4 
light:
  - platform: neopixelbus
    type: GRB
    variant: ws2811
    pin: D8 #Enter LedStrips pin
    num_leds: 16
    name: "NeoPixel Light"
    effects: 
      - pulse:
      - pulse:
          name: "Fast Pulse"
          transition_length: 0.5s
          update_interval: 0.5s
          min_brightness: 0%
          max_brightness: 100%
      
      - addressable_rainbow:
      - addressable_rainbow:
          name: Rainbow Effect (Cv)
          speed: 10
          width: 50    

      - addressable_fireworks:
      - addressable_fireworks:
          name: Fireworks Effect (Random Color)
          update_interval: 32ms
          spark_probability: 10%
          use_random_color: True
          fade_out_rate: 120
      
      - addressable_scan:
          name: Scan Effect (cV)
          move_interval: 100ms
          scan_width: 1  
      - addressable_color_wipe:
      - addressable_color_wipe:
          name: Color Wipe Effect (CV)
          colors:
            - red: 100%
              green: 100%
              blue: 100%
              num_leds: 1
            - red: 0%
              green: 0%
              blue: 0%
              num_leds: 1
          add_led_interval: 100ms
          reverse: false    
