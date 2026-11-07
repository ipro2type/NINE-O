# NINE-O

NINE-O is a custom designed ESP32-S3 based desk gadget / desktop dashboard and control console.

It can act as (the firmware is yet to support these): a weather forecast display, clock, pomodoro timer, stopwatch, Spotify display, GIF display, a silly pet sitting on your desk, a macro pad (2 customisable encoders), crypto price viewer, and much more (thanks to the ESP32-S3).

It uses a 2.4" display to beautifully display colourful images and UI elements.
You navigate using 2 encoders:

Encoder 1: Handles main navigation, list scrolling, mode switching, etc.
Encoder 2: Handles fine tuning, volume adjustment, or value changes. When you're using it as a macro pad or media controller, having separate knobs means you can adjust two things simultaneously (like scrubbing a timeline or changing system volume).

And for the audio side, I've added a buzzer that will work as a little mouth for the device, so that the timers you set don't go unnoticed. That's all I could write in brief about the features of NINE-O.

TL;DR

>Features
- ESP32-S3 based
- 2.4" colour SPI display
- 2 rotary encoders with push buttons
- Buzzer for notifications/timers
(see BOM Excel Sheet in Hardware folder for more details)


>Planned Software modes
- Weather info
- Clock
- Pomodoro timer
- Stopwatch
- Spotify/media display
- GIF display
- Macro pad
- Crypto price viewer
- And more


>Current firmware

I currently have a test firmware for the display, the rotary encoders, encoder buttons, and buzzer. The larger UI and planned features are future work.
(See hardware_test.ino in Firmware folder)


>Here are the final schematic and PCB layout:

<img width="1176" height="998" alt="1000072014" src="https://github.com/user-attachments/assets/58496619-4713-47cb-b009-3e9d34fa2ef2" />

the board was designed around the 2.4" display, with the 2 encoders placed along the bottom for easy access. the ESP32 is placed in the centre, with its antenna extending beyond the board for RF clearance.

<img width="1220" height="2712" alt="1000072019" src="https://github.com/user-attachments/assets/f4a13741-a2b1-463b-a472-0b5f7b1a7fe4" />  

The inspiration for this basic silkscreen art came from my ratsnest because they looked like a spider web! (kind of :p)

<img width="1220" height="2712" alt="1000072015" src="https://github.com/user-attachments/assets/32c36910-384d-404e-8ab8-4cd7248f3b39" />  

the routing took longer than I expected, after all, working on an android to make a custom pcb isn't an easy thing to do...
I couldn't get 3d view in easyEDA pro to work, it seems like its 3d viewer doesn't work on Android. so I don't have 3D screenshots to upload here, but I've included the STEP file in the Hardware folder.


## Bill of Materials

| Component | Qty | Specification | Supplier | Unit Price | Total |
|---|---:|---|---|---:|---:|
| [ESP32-S3-DevKitC-1](https://robu.in/product/weact-studio-esp32-s3-devkitc-1-development-board/) | 1 | ESP32-S3-DevKitC-1 development board | Robu India | ₹1,099.00 | ₹1,099.00 |
| [Waveshare 2.4inch LCD Module](https://robu.in/product/waveshare-240x320-general-2-4inch-lcd-display-module/) | 1 | 2.4-inch 240×320 ILI9341 SPI TFT, SKU 18366 | Robu India | ₹1,109.00 | ₹1,109.00 |
| [Rotary Encoder EC11](https://www.sunrom.com/p/rotary-encoder-ec11-flat-d-shaft-20mm) | 2 | EC11 rotary encoder with push switch | Sunrom | ₹56.35 | ₹112.70 |
| [CUI CST-931AP buzzer](https://www.digikey.in/en/products/detail/cui-devices/CST-931AP/1216850) | 1 | CST-931AP through-hole buzzer | DigiKey India | ₹152.88 | ₹152.88 |
| [2N3904S-RTK/PS (Q1)](https://www.lcsc.com/product-detail/Transistors-NPN-PNP_KEC_2n3904S-RTK-P_2n3904S-RTK-P_C18536.html) | 1 | KEC 2N3904S-RTK/PS, SOT-23 | LCSC | ₹1.19 | ₹1.19 |
| [10kΩ resistor](https://www.lcsc.com/product-detail/Chip-Resistor-Surface-Mount-UNI-ROYAL-UniOhm-1206W4F1002T5E.html) | 1 | 1206 SMD resistor, 10kΩ ±1% | LCSC | ₹0.75 | ₹0.75 |
| [LCD PCB connector](https://www.digikey.in/en/products/detail/jst-sales-america-inc/B8B-PH-K-S/926617) | 1 | JST B8B-PH-K-S, 8-position, 2.00 mm pitch | DigiKey India | ₹33.44 | ₹33.44 |
| [Custom PCB](https://cart.jlcpcb.com/quote) | 1 | 98 × 75 mm, 2-layer FR-4, 1.6 mm | JLCPCB | ₹610.16 | ₹610.16 |
| [JLCPCB shipping](https://cart.jlcpcb.com/quote) | 1 | UPS Worldwide Express, 5-board order | JLCPCB | ₹947.43 | ₹947.43 |
| [M2 × 6mm brass standoff](https://onlyscrews.in/products/m2-x-6mm-female-to-female-brass-with-nickel-plating-hex-threaded-standoff-spacer) | 4 | M2 × 6 mm, female-to-female, brass | OnlyScrews | ₹4.00 | ₹16.00 |
| [M2 × 4mm Phillips screw](https://onlyscrews.in/products/m2-x-4mm-phillips-round-head-laptop-screw) | 8 | M2 × 4 mm Phillips round-head | OnlyScrews | ₹3.80 | ₹30.40 |

**Total estimated cost: ₹4,112.95**


I would like to give a special thanks to MPK for understanding my constraints and going easy on me with the deadlines.
