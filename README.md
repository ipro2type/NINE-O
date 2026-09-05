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

I would like to give a special thanks to MPK for understanding my constraints and going easy on me with the deadlines.
