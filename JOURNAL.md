title: "NINE-O"
github: https://github.com/ipro2type/NINE-O
description: *A custom ESP32-S3 desktop gadget and control console.*

This journal was written after the project was completed, using my messages, screenshots, screen-time records and project files to reconstruct what I worked on. Some of the time estimates are approximate where I didn't have an exact record.

# _August 25th-26th: the idea_

I came across Gadget Market pretty randomly and noticed that people were making their own PCBs. Even though I didn't already have some huge hardware project planned, the very first things that came to my mind where some keychain things with display/leds that i can share with my siblings/friends... but that didn't excite me that much...

so I started with a question to myself; *what would I actually want on my desk? that wouldn't get boring in a few days to look at?*

I liked the idea of something with the kind of physical interaction you get from an etch A sketch, mixed with the little interactive personality of something like Anki Vector. That turned into the first version of the project: Axiom Mini, basically a little desk pet.

After thinking about it more, I decided that a desk pet by itself wasn't really worth using the opportunity for. I wanted something i could actually use instead of something that would just sit there being cute.

So I started expanding it into a proper desktop assistant/control device. I imagined having a screen and physical controls, with different modes for things like Spotify controls, weather display, crypto stats, customisable macro-pad, and other useful stuff. The exact feature list wasn't fixed yet, but the main idea was clear: one small device in which i could keep adding features.

At this point, my biggest problem was: I had never designed a PCB before.

**Total time spent: prolly an hour or two of just thinking and browsing looking for ideas...**

*(no picture to add)*

#

# _August 27th: can I even design a PCB on my phone?_

The first thing I had to figure out was whether I could actually make the project using only my phone.

I searched around for mobile PCB design tools and eventually found EasyEDA Pro, which could work in Android browser.

I had no idea what I was doing at first, so I started by learning the basic workflow. I learned that the design starts as a schematic, where the components and electrical connections are defined, and then those components are brought into the PCB editor as footprints and physically arranged and routed.

Even just navigating the editor was something I had to learn.

I spent some time getting used to zooming, moving around the canvas and selecting things, the etc...

The first component I looked for was the ESP32-S3 I wanted to use as the brain of the project. Once I got it onto the schematic, I started with adding the two rotary encoders, a battery port (later removed it), a basic 8 pin header for a .96" display, and working with net labels.

I was doing all of this from my phone, so navigating EasyEDA with just a touchscreen was pretty frustrating. I ended up connecting a mouse through OTG, which made moving things around and working with the PCB editor much easier. It still wasn't anywhere near as easy as using a PC, but it made the project actually manageable.

*Total time spent: ~45mins-1hr*

<img width="1220" height="2606" alt="1000075661" src="https://github.com/user-attachments/assets/69b64ea5-0d9e-4de3-a1be-65e943d12537" />

<img width="1220" height="2712" alt="1000069351" src="https://github.com/user-attachments/assets/7d5664b9-5885-4c75-8559-570ad2cb344a" />

#

# _August 28th: trying to make the layout actually make sense_

As I was setting up a rough layout of the components, I ran into one of my first genuinely annoying problems.

I wanted the two rotary encoders (not the footprint but the physical component) to be properly symmetrical around the centre of the board.

EasyEDA lets you use coordinates, but the footprint origins weren't always located where I expected them to be physically.

For example, the coordinate could be based around one of the pads instead of the physical centre of the part.

That meant that putting two footprints at matching coordinates didn't necessarily make the actual encoder shafts line up symmetrically.

I tried using coordinates and then eventually resorted to using grid boxes and manually getting the physical parts as symmetrical as I could.

I even asked in the Gadget Market channel because i wasn't sure what the proper workflow was.

It was a good intro to the difference between a component's software origin and its actual physical geometry.

*Total time spent: ~2hrs approx (i struggled with the encoder's positional symmetry ALOT, tried changing anchor points, footprint/canvas origins, nothing helped... and i finally used grid boxes)*

**Before:**

<img width="1220" height="2554" alt="1000075663" src="https://github.com/user-attachments/assets/667dc6e3-daa1-4fb9-853d-3d70252fcdb8" />

**After:**

<img width="1220" height="2712" alt="1000069412" src="https://github.com/user-attachments/assets/06aa42a2-a81d-441d-8243-f80755761ba2" />

#

# _August 30th – September 2nd: building the board_

Once I got past the placement problems, I started filling out the actual circuit and PCB.

The early version was still pretty simple. I had the ESP32, two rotary encoders, a display header (for the .96" display I initially thought of using), a 3 pin RGB connection and power connections.

As I said, I also considered adding a battery connection so the device could be portable, but I realised that battery power would make the design more complicated than I was comfortable with for my first PCB, so I dropped that idea.

I also started using No Connection markers for pins that I intentionally wasn't using.

After the schematic was cleaned up, I updated the PCB from it and started arranging the actual footprints. This was where the project started feeling like a real PCB instead of just a schematic.

This is where I realized that NINE-O was lacking an audio system, so i decided to add a buzzer.

I was also working out the physical layout: where the display would sit, where the two encoders should go, where the ESP32 should be placed and how everything could fit while still looking reasonable.

By August 31 I had most of the schematic done and the PCB was coming along, but routing was still left. I ended up asking for an extension because doing all of this from Android was taking much longer than I expected.

**Total recorded proxy time: 1h 29m**

<img width="1220" height="2712" alt="1000070997" src="https://github.com/user-attachments/assets/238f14da-cb31-49e6-9ba9-b1904fea1c7b" />

#

# _September 3rd: routing gets complicated_

By September 3rd, most of the schematic and component placement was out of the way, so I could finally focus properly on routing the PCB.

Routing was easily one of the harder parts for me. I was still learning what makes a PCB layout actually good, while also doing the entire thing on a phone. There were a lot of traces to fit around the ESP32, encoders, display and everything else, and I kept having to move things around and try again.

While routing, I also realised I hadn't properly accounted for the ESP32 antenna keep-out area. Instead of trying to route around it, I decided to move the ESP32 so that the antenna and its keep-out area would sit completely outside the edge of the PCB.

This also made me realise that the two RGB LED headers were making things more difficult than they were worth. I tried routing around them for a while, but they were taking up space and creating some pretty awkward routes.

Since they weren't really important to the main idea of NINE-O, I decided to remove both of them. It made the board a lot easier to work with.

Also discovered about Ground pours which will reduce the hassle of routing GND pads... so I left them unconnected for now.

After that I just kept routing, moving components around whenever a route was getting unnecessarily long or messy and trying to figure out what actually makes a PCB layout good.

**Recorded Chrome/EasyEDA proxy time: 5h 06m**

<img width="1220" height="2583" alt="1000076782" src="https://github.com/user-attachments/assets/7a0cae25-2233-4ce1-ad72-c36247f42d14" />
Ik some people can easily make clean routes with this setup too but I couldn't :p
<img width="1199" height="2603" alt="1000076783" src="https://github.com/user-attachments/assets/c20d63f3-d2e4-47fa-846f-25d5a0184316" />



#

# _September 4th: Finalising components, routing cleanup, DRC and Copper Pour_

This was THE big leap.

Updated the header to this new ribbon cable header suitable for the waveshare display.

<img width="385" height="591" alt="1000076803" src="https://github.com/user-attachments/assets/3e66d7ca-bac4-40e1-ba3d-5a9c2ace97b7" />


With the ESP32 moved, header updated,and the RGB headers removed, I had more cleaner space to work with, but routing was still pretty annoying. I kept checking if traces could take a more direct path without crossing anything else or getting too close to pads.

At first I was mostly just trying to make everything connect, but once most of the routing was done I started going back and looking at the traces properly. I removed some unnecessary bends and tried to make the routes look more intentional instead of just accepting whatever route worked...

Saw a tutorial on copper Pours and then poured it on both the layers, the DRC errors for unconnected GND pins were now gone. and after each and every route/layout remorse, I was rebuilding the ground pour cuz I didn't like the errors.

I also started using DRC more seriously. Whenever it showed an issue, I'd go back and figure out what was actually causing it instead of just trying random changes until the warning disappeared.

<img width="2712" height="1220" alt="1000071667" src="https://github.com/user-attachments/assets/babd6880-6c84-43cd-b0ad-f3ceba814bc5" />


That reminds of how annoying it was when I couldn't figure out what's the issue was with the encoders, it kepts sound some copper region errors and highlighting that encoder's footprint, then i realized that those footprints had their own copper pour, had to edit the footprints and remove their copper pours.

By the end of the day the board was looking much more like an actual finished PCB and I was getting close to being able to submit it.

Rebuilt the Copper pour just to make sure that the DRC was clear. 

Began with the silkscreen art. I earlier Thought of making a 🤨 face on that buzzer area cuz it literally looked like it. 

<img width="302" height="309" alt="1000076805" src="https://github.com/user-attachments/assets/dcfdacf6-6f73-488b-8c94-1db11e0e126f" />

But soon realized that it's prolly not gonna look good, so i came up with something simpler, yet beautiful: a spider-web.
It seemed like the perfect target to me cuz it was simple enough to make on my android with the canvas lagging upon every pixel my cursor moved, so i went with it.
This was where I decided to change the name to Nine-O. It sounded cleaner than axiom.

what I had by the end of the day:

<img width="1085" height="784" alt="1000072241" src="https://github.com/user-attachments/assets/66b84206-8bc2-4535-9a23-78110e3a25f5" />



Next step were, setting up The repo, BOM, getting the files exported from EasyEDA, and then finally submitting on gadget-market!

**Recorded Chrome/EasyEDA proxy time: 9h 38m**


#

# _September 5th: getting everything ready for submission_
September 5th was basically about getting the actual PCB project ready to submit, not just finishing the board itself.
I went through the PCB one more time, checked the routing and DRC and made sure everything I needed for the submission was actually there.
I started putting the project repository together and organising the files. I exported the Gerber files, the EasyEDA project/archive and the other files that were required for the project. I also worked on the BOM and made sure the components and their information were listed properly.
I also exported the 3D model/STEP file so there was a proper representation of the board outside EasyEDA.
Then I put together the documentation for the project and added the hardware-test firmware to the repository. The firmware was still just a basic test for the hardware rather than the full UI I had originally imagined, but I wanted the actual project files to be complete enough to show what I had built.
The 3D case was still something I hadn't made. I had already spent a lot more time than I expected doing the PCB from Android, and trying to design a proper enclosure on top of everything else would've taken even longer, so I decided to leave that for later.
Once the repo, BOM, exported files and documentation were ready, I submitted the first version of NINE-O on September 5th.



**Time Spent in EasyEDA: 45mins-1hr of just exporting the files and binding 3d models** 

(Recorded Chrome Time: 4h 36m; not counting the rest of the chrome screentime as it's prolly me visiting the electric components sites for the BOM and GitHub to prepare the repo)


#

# _September 6th – 9th: waiting for review_
**Total time spent: 0h**

#

# _September 10th: someone actually reviewed my PCB_

After I submitted NINE-O, I waited for the review.

On September 10th, The Reviewer came back with several changes.

The main feedback was:

- The PCB seemed larger than it needed to be.
- The routing could use another pass.
- The PCB corners should be rounded.
- I needed to add a proper project journal.

This was actually pretty useful because it was the first time someone more experienced had looked at my PCB as a finished design instead of me just staring at it in EasyEDA and thinking it looked fine.

Since I was busy with school stuff, I decided that I'll look into it later.

**Total time spent: 0h — I was busy with school and exams and didn't work on the PCB this day.**

#

# _September 11th: still busy with school_

I didn't really work on the PCB this day either.

I was still busy with school and exams, so the revisions had to wait.

**Total time spent: 0h**

#

# _September 12th: making the board smaller_

The revisions took longer than I expected because I had school and exams going on at the same time.

I started by shrinking the board. The original version was bigger than it really needed to be, so I reduced it down to **98 × 75 mm**.

<img width="1220" height="928" alt="1000076806" src="https://github.com/user-attachments/assets/ff5b37c0-4adc-4541-8b8c-918f7b10f792" />


I also rounded the corners and added four mounting holes. I wanted to be able to use spacers with the board and keep it from just sitting directly on whatever surface I eventually put it on.

After that, I lowkey deleted the previous routing, and decided to start all over again as I was now familiar with the game.

<img width="1220" height="993" alt="1000076809" src="https://github.com/user-attachments/assets/6259e8b5-c38f-474e-90a0-d97d4c19f08e" />


Started with the display header first, then encoders and buzzers. It didn't take me much with routing this time. I was done within an hour. 

Rebuilt the copper pours and the DRC was clean again!


<img width="1076" height="838" alt="1000073963" src="https://github.com/user-attachments/assets/71c1195e-8090-41c0-a27b-bd8dfdc53043" />



**Recorded Chrome/EasyEDA proxy time: 1h 52m**


#

# _September 13th: routing again..._

I continued working on the routing.

I kept trying to change the traces and moving things around whenever I found a route that was longer than it needed to be.

Doing this on a phone was still pretty annoying, especially when I needed to make really small changes to traces or component positions. But at this point I was a lot more comfortable with EasyEDA than I was when I started.

**Recorded Chrome/EasyEDA proxy time: 34m**

<img width="1116" height="895" alt="1000073734" src="https://github.com/user-attachments/assets/c2d6fe24-f9d6-482f-b889-05e6feb6a816" />



#

# _September 14th: almost done... again_

By the early hours of September 14th, I had finished most of the changes MPK originally asked for.

The board was now 98 × 75 mm, the corners were rounded, the four mounting holes were there and I had redone the routing.

I told the reviewer that the PCB and routing were done and that only the journal was left.


Then he pointed out the awkward 5v line...  

<img width="1076" height="838" alt="1000073963" src="https://github.com/user-attachments/assets/6964542e-b1b9-4ce0-b508-164ff05cd1fe" />


There was a long green trace taking a pretty big detour across the board.

At first, I mistook it for the 3v3 traces, It was actually the 5V route.

So... apparently I wasn't completely done with routing yet.

So, I went all in. Trying to find the most optimal and shortest way to route the 5V line. 


It wasn't easy as the placements and Orientations of the components/footprints were not optimised for short traces.

The reviewer gave the idea of routing it from UNDER the esp32, but I just couldn't find a way. It was prolly past midnight for me at that time when I was looking for shot paths like that one "path finding" algorithm. 

All I could think of was to shorten the loop by adding vias and routing it beneath the display header-esp32 connections and eventually had this:

<img width="845" height="790" alt="1000074398" src="https://github.com/user-attachments/assets/a55912cf-933a-4814-bda2-e2fd9315d76f" />

**Recorded Chrome/EasyEDA proxy time: 3h 29m**



#

# _September 15th – 17th: the 5V trace problem_

I first tried to figure out how I could shorten the 5V trace without moving the ESP32 again or making the routing around it worse.

My first idea was to put a via near the upper-left side of the ESP32 and move only part of the route to the bottom layer.

The reviewer suggested something simpler: why not just route the entire trace on the back side, since the relevant pads were through-hole.

That made a lot more sense, so I followed that approach and rerouted the entire 5V trace to the bottom layer.

Also adjusted the layout of the Buzzer, the resistor and the transistor just to make the 5v trace just to shorten the 5v trace a bit more.

<img width="1205" height="1010" alt="1000074532" src="https://github.com/user-attachments/assets/7cc3e737-630b-4a60-a23c-9e3497894317" />


After that I checked the rest of the design and made the final cleanup changes. I also noticed that I had accidentally reduced the trace width while rerouting it, so I restored it back to **0.6 mm**.

I ran DRC again and everything was clear.

At that point I asked MPK one final time if the routing looked okay.

He said that it was good:)

So that was basically it. The PCB review was finally done.

The only thing left was the journal.

**Recorded Chrome/EasyEDA proxy time: 1h 04m on September 15th(_on 16th, I was busy with school and stuff so I uploaded the updated routing somewhere near midnight... though the final routing/review work happened during this period._)**


#

# _What I ended up building_

NINE-O ended up as a small ESP32-S3 desktop gadget and control console.

The hardware has a 2.4" colour display, two rotary encoders with push buttons and a buzzer. The idea is for the device to eventually have different modes for things like weather, clocks, timers, media controls, GIFs, macro-pad functions, crypto information and even a little digital pet.

The current firmware is only a hardware test for the display, encoders, buttons and buzzer. The bigger UI and all the different modes are planned for future development.

The whole project was designed from an Android phone, which was probably the biggest constraint throughout the build.

The first version was submitted on September 5th, then reviewed and revised afterward. The final board was reduced to 98 × 75 mm, rounded, given four mounting holes and rerouted after feedback.

There are definitely things I would do differently if I started another PCB, especially around planning the layout and routing earlier. I also probably wouldn't try doing a first PCB entirely from a phone again lol.

But considering I started this without knowing how PCB design worked at all, getting from an idea on my phone to an actual PCB that went through review was already a pretty big learning experience.

**Known Chrome/EasyEDA proxy across the dates with usable screen-time records: 27h 48m**

**Time note:** The phone screenshots give Chrome usage, not exact EasyEDA usage. I used those values as a project-time proxy only for the days where I knew I was working on NINE-O. They should not be treated as exact PCB-design timing. Days before August 30 and some days between September 6–11 do not have matching Chrome records in the screenshots I have, so I have left those times unrecovered rather than inventing them.
