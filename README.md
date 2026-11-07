# NINE-O

NINE-O is a custom-designed ESP32-S3 based desk gadget, desktop dashboard, and control console.

The idea is to have a small device sitting on your desk that can do a bunch of useful (and some not-so-useful) things, all accessible through a small colour display and two rotary encoders.

It is planned to support a weather display, clock, Pomodoro timer, stopwatch, Spotify/media display, GIF display, a little desk pet, a macro pad, a crypto price viewer, and much more.

> **Development status:** These are planned software modes. The current firmware is still in the hardware-testing stage and does not implement these modes yet. The hardware has not been physically assembled or tested yet.

---

## Features & Hardware

| Component | Details |
|:---|:---|
| Microcontroller | ESP32-S3 development board |
| Display | 2.4-inch colour SPI TFT display |
| Resolution | 240 × 320 pixels |
| Input | 2 rotary encoders with push buttons |
| Audio | Buzzer for notifications and timers |
| Custom PCB | 98 × 75 mm, 2-layer FR-4, 1.6 mm thickness |

The 2.4-inch display will be used to show colourful images and UI elements.

### Controls

NINE-O uses two rotary encoders for navigation and control:

- **Encoder 1:** Handles main navigation, list scrolling, and mode switching.
- **Encoder 2:** Handles fine adjustments, volume, and changing values. Having two separate knobs also means you can control two things simultaneously, such as scrubbing through a timeline while adjusting system volume.

For the audio side, I've added a buzzer that will work like a little mouth for the device, making sure timers and notifications don't go unnoticed.

---

## Planned Software Modes

Here are some of the things I want NINE-O to eventually do:

- Weather information
- Clock
- Pomodoro timer
- Stopwatch
- Spotify / media display
- GIF display
- Macro pad
- Crypto price viewer
- And more!

Thanks to the ESP32-S3, there's plenty of room to experiment with more ideas later.

---

## Hardware Design

The PCB was designed around the 2.4-inch display, with the two encoders placed along the bottom for easy access. The ESP32 is placed in the centre, with its antenna extending beyond the board for RF clearance.

### Schematic and PCB Layout

<img width="1176" height="998" alt="1000091701" src="https://github.com/user-attachments/assets/e1f9ddc9-1821-4f3c-95da-9010dabfc20b" />


The board was designed around the display, with the two encoders placed along the bottom and the ESP32 positioned centrally.

<img width="1220" height="1039" alt="1000091710" src="https://github.com/user-attachments/assets/006515ff-3f0d-4882-a986-1e4918ff1974" />


The inspiration for this basic silkscreen art came from my ratsnest because it looked like a spider web! (kind of :p)

<img width="1046" height="858" alt="1000091711" src="https://github.com/user-attachments/assets/4b35feb7-a2df-45f6-b8aa-e695a95a3e0e" />


The routing took longer than I expected. After all, working on an Android device to make a custom PCB isn't exactly easy...

I couldn't get the 3D view in EasyEDA Pro to work. It seems like its 3D viewer doesn't work on Android, so I don't have 3D screenshots to upload here. However, I've included the STEP file in the Hardware folder.

---

## Bill of Materials

Here's everything required to build NINE-O, along with the suppliers and estimated prices.

| Component | Qty | Specification | Supplier | Unit Price | Line Total |
|:---|---:|:---|:---|---:|---:|
| [ESP32-S3-DevKitC-1](https://robu.in/product/weact-studio-esp32-s3-devkitc-1-development-board/) | 1 | ESP32-S3-DevKitC-1 development board | Robu India | ₹1,099.00 | ₹1,099.00 |
| [Waveshare 2.4-inch LCD Module](https://robu.in/product/waveshare-240x320-general-2-4inch-lcd-display-module/) | 1 | 2.4-inch 240 × 320 ILI9341 SPI TFT, SKU 18366 | Robu India | ₹1,109.00 | ₹1,109.00 |
| [Rotary Encoder EC11](https://www.sunrom.com/p/rotary-encoder-ec11-flat-d-shaft-20mm) | 2 | EC11 rotary encoder with push switch | Sunrom | ₹56.35 | ₹112.70 |
| [CUI CST-931AP buzzer](https://www.digikey.in/en/products/detail/cui-devices/CST-931AP/1216850) | 1 | CST-931AP through-hole buzzer | DigiKey India | ₹152.88 | ₹152.88 |
| [2N3904S-RTK/PS transistor](https://www.lcsc.com/product-detail/Transistors-NPN-PNP_KEC_2n3904S-RTK-P_2n3904S-RTK-P_C18536.html) | 1 | KEC 2N3904S-RTK/PS, SOT-23 | LCSC | ₹1.19 | ₹1.19 |
| [10 kΩ resistor](https://www.lcsc.com/product-detail/Chip-Resistor-Surface-Mount-UNI-ROYAL-UniOhm-1206W4F1002T5E.html) | 1 | 1206 SMD resistor, 10 kΩ ±1% | LCSC | ₹0.75 | ₹0.75 |
| [LCD PCB connector](https://www.digikey.in/en/products/detail/jst-sales-america-inc/B8B-PH-K-S/926617) | 1 | JST B8B-PH-K-S, 8-position, 2.00 mm pitch | DigiKey India | ₹33.44 | ₹33.44 |
| [Custom PCB](https://cart.jlcpcb.com/quote) | 1 order (5 boards) | 98 × 75 mm, 2-layer FR-4, 1.6 mm | JLCPCB | ₹610.16 | ₹610.16 |
| [JLCPCB shipping](https://cart.jlcpcb.com/quote) | 1 | UPS Worldwide Express, for the 5-board order | JLCPCB | ₹947.43 | ₹947.43 |
| [M2 × 6 mm brass standoff](https://onlyscrews.in/products/m2-x-6mm-female-to-female-brass-with-nickel-plating-hex-threaded-standoff-spacer) | 4 | M2 × 6 mm, female-to-female, brass | OnlyScrews | ₹4.00 | ₹16.00 |
| [M2 × 4 mm Phillips screw](https://onlyscrews.in/products/m2-x-4mm-phillips-round-head-laptop-screw) | 8 | M2 × 4 mm Phillips round-head | OnlyScrews | ₹3.80 | ₹30.40 |

**Total estimated cost: ₹4,112.95**

The PCB price represents the five-board order, not the cost of a single board. Shipping is listed separately.

*Prices are based on the BOM at the time of preparation and may change.*

A downloadable CSV version of the BOM is also available: [NINE-O_BOM.csv](Hardware/NINE-O_BOM.csv).

---

## Firmware

I currently have a test firmware for the display, the rotary encoders, encoder buttons, and buzzer.

The larger UI and planned features are future work. I want to get the underlying hardware working properly before moving on to the actual dashboard and its different modes.

You can find the test firmware here:

[`hardware_test.ino`](Firmware/hardware_test.ino)

---

## Project Files

The repository contains the files related to the hardware design, PCB, and firmware.

- **Hardware:** PCB-related files, BOM, STEP model, and Gerber files.
- **Hardware/Project:** EasyEDA project files.
- **Firmware:** Test firmware for the display, encoders, encoder buttons, and buzzer.

The EasyEDA project file is included so the hardware design can be inspected and worked on further.

- [EasyEDA project file](Hardware/Project/Axiom-Mini.epru)
- [3D STEP model](Hardware/3D_NINE-O.step)
- [Gerber archive](Hardware/NINE-O_GERBER%20(1).zip)

---

And that's NINE-O!
