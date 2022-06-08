# PoolRobot
Paxcess HJ2052 - DIY replacement controller

Using virtually any microcontroller with three analog pins.

Fix your Paxcess / AIPER HJ2052 pool robot if the internal logic board the bot dies.

This seems to happen when the one of the motors ( usually drive motor ) siezes up and board burns out.

Arduino UNO , DFROBOT Beetle and Pi PICO tested 

*DFROBOT Beetle*
- https://www.amazon.com/dp/B01B0IQFU4?psc=1&ref=ppx_yo2ov_dt_b_product_details
- Recommend the Beetle for bare minimum. Has just enough pins to run this robot.
- Extremely small foot print.

*Pi PICO*
- https://www.amazon.com/Raspberry-Pi-Pico-RP2040-microcontroller/dp/B092S2KCV2?th=1
- Recommended if you want to add any kind of BLE / WiFi or anything else fancy that requires more pins and grunt.
- Small foot print.

*Forward and Reverse Relay Module for Motor/Linear Actuator, Reversing Relay Module (DC 24V)*
- https://www.amazon.com/dp/B0879JDWP4?ref=ppx_yo2ov_dt_b_product_details&th=1
- Recommend this as it makes it easy to power and change directions of the drive motor.
- Recommend clipping off the mounting points on each side to make extra room inside.
- DC 24v is needed for the Paxcess / AIPER HJ2052 model. If you use this for anything else, make sure right voltage!

*1 Channel Relay Module*
- https://www.amazon.com/dp/B079FJSYGY?ref=ppx_yo2ov_dt_b_product_details&th=1
- Pretty much any kind similar to this will work. 
- If can find smaller verions the better to help with the tight working space.

*Buck Converter DC-DC Step Down*
- https://www.amazon.com/PlusRoc-1-25V-35V-Converter-Efficiency-Regulator/dp/B0B2CLXGD8/ref=sr_1_25_sspa?crid=35SGBNY3END8C&keywords=arduino%2Bbuck%2Bconverter%2B24v&qid=1654655776&s=industrial&sprefix=arduino%2Bbuck%2Bconverter%2B24v%2Cindustrial%2C61&sr=1-25-spons&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEzVlU5S1ZOVzMySzhPJmVuY3J5cHRlZElkPUEwMDY5MjU2MkNMU1hESFMyNDZEViZlbmNyeXB0ZWRBZElkPUEwODAyMDU1UERaTktCM0lGR1REJndpZGdldE5hbWU9c3BfYXRmX25leHQmYWN0aW9uPWNsaWNrUmVkaXJlY3QmZG9Ob3RMb2dDbGljaz10cnVl&th=1
- Needed to convert 24v input from power box to 3.3v/5v/12v whatever your controller of choice needs as input.
- These will get pretty warm, so make sure not touching sides of casing.

*Replacement bearing*
- https://www.amazon.com/dp/B09J8BN3PF?ref=ppx_yo2ov_dt_b_product_details&th=1
- Not necessary but this is an upgrade to the steel bearing in your robot for supporting the drive motor shaft. Coated, nylon, and ceramic made, A huge step up from the factory bearing that rusts out.

Crummy video showing my ugly build, rebuilt drive motor gear reduction box and the robot working in the pool!
- https://www.youtube.com/watch?v=KBQ-W7AHP2Y

