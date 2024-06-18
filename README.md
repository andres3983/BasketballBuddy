# BasketballBuddy, a basketball hoop add-on using Arduino!
Get more out of your basketbll hoop! BasketballBuddy is a project that tracks field goal % and has mini-games, such as shots made in 30 seconds. An arduino UNO 3 was used as the microcontroller. Shots are tracked by an ultrasonic distance sensor (HC-SR04) and are displayed on a LCD display. Shots are also visually and audibly displayed via a passive buzzer and a LED. Two buttons control the reset and the game browsing features.

✍️Code can be found in the basketball_buddy folder.

⚡️Schematics can be found in the BasketballBuddySchematics and the TinkercadSchematics folders.

## Build it yourself - coniderations / Challenges:
1.) If your going to build this project I`d suggest using a different microcontroller, the Arduino is limited in its ability to multitask. So, you will encontour issues with the time countdown and tracking shots. 

2.) I also suggest getting an I2C module for the LCD screen as it saves a lot of time and wires, which get tricky once the project gets bigger. 

3.) Also consider adding an accelerometer and a gyroscope to more accurately track the shots. 

4.) Finally, have fun and play around with adding different/more games!



