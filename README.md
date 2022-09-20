## the pingy robot
A controller application for Pingy using Arduino

INSTRUCTIONS

Connect the following pins with a 4-wire ribbon cable:

Pingy      <->   Arduino Nano Every
-----              -------
V                  A0
Cl                 A5
Da                 A4
G                  GND

Then compile the `behavior.ino` file to the Arduino. Tested with a Nano Every. With Pingy powered off, use the Arduino Serial Monitor or otherwise connect to the Arduino with the source application at 115200 baud. The C++ source is in the `src` folder.

Turn on your Pingy.  With luck, you should receive a "Pingy detected" message.
  
Allowable commands (the closing semicolon is required):
    SOUND PLAY <0...63>;
    SOUND REPEAT <0...63>;
    SOUND DELAY <msec>;
    SOUND STOP;
    SPEED [PAN, TILT, PONSIDE] <0...255>;
    MOVE PAN <-100...100>;
    MOVE TILT <-100...100>;
    MOVE SIDE [CYCLE, CENTERFROMLEFT, RIGHT, CENTERFROMRIGHT, LEFT];
    MOVE PON [UP, HALFDOWN, DOWN, HALFUP];
    MOVE STOP;
    MODE [DANCE, TOUCH];
    MODE TEMPO;
    MODE SLEEP;

Strings that the Arduino can send back to you:
    BUTTON [DANCE, TOUCH] [OFF, ON]
    BUTTON [HEAD, FRONT, BACK, RIGHT, LEFT] [OFF, ON]
    MOTOR [PAN, TILT, SIDE, PON] FINISHED
    MOTOR [PAN, TILT, SIDE, PON] STALLED
    ENCODER TILT [NOREACH, FORWARD, BACK, UP]
    ENCODER PON [HALFDOWN, UP, DOWN, HALFUP]
    ENCODER SIDE [CENTER, RIGHT, LEFT]
    ENCODER PAN [BACK, RIGHT, LEFT, CENTER]
    EMF [PAN, TILT, PONSIDE] [-127...127]
    POSITION [PAN, TILT, PONSIDE] [VAL]
    AUDIO TEMPO [67, 80, 100, 133, 200] (if BPM cannot be detected, this is estimated from power spectral density response)
    AUDIO MEAN [0...64] (the mean of the envelope over a 1.28sec window, max around 64 for very loud music, not updated when motors are moving)
    AUDIO RANGE [0...64] (dynamic range, max 64 for shouting, not updated when motors moving)
    AUDIO ENVELOPE [0...127] (near instantaneous log of the audio amplitude; commented out in code for reduction of data transfer)
    AUDIO BPM [VAL] (estimated beat interval in multiples of 5msec)
