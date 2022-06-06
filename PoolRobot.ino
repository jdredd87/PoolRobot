// PoolRobot 2022
// Steven Chesser
// Steven.Chesser@twc.com
// v1.2

const int jetPIN = 16;    // Relay trigger to relay for JET motor ground wire.

const int drvPwrPIN = 17; // Relay trigger to relay for OONO Forward and Reverse Relay Module Relay.
                          // We want to cut power to the drive motor via this relay.
                          // Then once it is off, we can change the direction of this relay.
                          // Then let the relay have power again.
                            
const int drvDirPIN = 18; // Relay trigger to OONO Forward and Reverse Relay Module Relay for direction.

const int testDrive = 3000; // Move 3 seconds

const unsigned long driveTime = 60000; // 60 seconds to drive in either direction.
                                       // This could be increased or decreased for your pool size to optimize it.
                               
const int dropTime = 15000; // 15 seconds to drop to bottom of pool.
                            // Add more time if got A deep pool.
                            // Remove time if is it not.

const int stopTime = 3000; // 3 seconds to move after a STOP.
                           // Just A small delay of time when shutting off motors.
                           // These cheap relays most use, try to give it a little time if going to lower it.
                           // Don't just set it to zero.
                           
const int startupDelay = 15000; // 15 second delay on startup to allow drop into water to sink to bottom.
                                // If your bot likes to float for A while before fully sinking, increase this.


// Turn on JET to push robot down and/or against wall
void jetON() {
  digitalWrite(LED_BUILTIN, HIGH);   
  Serial.println("jetON");
  digitalWrite (jetPIN, HIGH);
  delay(stopTime);
  digitalWrite(LED_BUILTIN, LOW);  
}

// Turn off JET to let robot drop to bottom off pool and/or switch direciton
void jetOFF() {
  digitalWrite(LED_BUILTIN, HIGH); 
  Serial.println("jetOFF");
  digitalWrite (jetPIN, LOW);
  delay(stopTime);
  digitalWrite(LED_BUILTIN, LOW);  
}

void driveDirection(int moveTime, int dir) {
  digitalWrite(LED_BUILTIN, HIGH);   
  digitalWrite(drvPwrPIN, LOW); // TURN MOTOR OFF
  delay(1000);
  digitalWrite(drvDirPIN, dir); // Trigger relay to move in forward or reverse
  delay(1000);
  digitalWrite(drvPwrPIN, HIGH); // TURN MOTOR ON
  delay(moveTime); 
  digitalWrite(drvPwrPIN, LOW); // TURN MOTOR OFF
  digitalWrite(LED_BUILTIN, LOW);    
}

// Simple test of JET and Drive Motor
// Currently does not do much testing in way of things 
// but could possibly use aid of some of extra sensors added
// to insure robot is moving and such? 

bool testRun() {
  Serial.println("testRun Started");
  Serial.println("");
  Serial.println("Waiting 10 seconds....");
  Serial.println("");
  delay(startupDelay); 
  jetON();
  delay(stopTime);
  driveDirection(testDrive, LOW); 
  delay(stopTime);
  driveDirection(testDrive, HIGH); 
  Serial.println("testRun Ended");
  return true;
}

// Stage up Microcontroller and relays
void setup() {
  Serial.begin(9600);
  Serial.println("Starting pool robot");
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(jetPIN, OUTPUT);
  pinMode(drvPwrPIN, OUTPUT);
  pinMode(drvDirPIN, OUTPUT);
  digitalWrite (jetPIN, LOW); // OFF
  digitalWrite (drvPwrPIN, LOW); // OFF
  digitalWrite (drvDirPIN, LOW); // OFF
  testRun(); 
}

// The robots controller box is providing 24 volts
// and this loop will just run until the controller box shuts off the 24 volts
// So we don't have to do anything special as once voltage is cut, the microcontroller turns off.

void loop() {
    jetON();  // Turn JET ON 
    driveDirection(driveTime,LOW); // Drive forward for "driveTime" milliseconds
    jetOFF(); // Turn JET OFF to Drop/Change directions
    delay(dropTime); // Now wait for "dropTime" milliseconds
    jetON(); // Turn JET ON
    driveDirection(driveTime,HIGH); // Drive backwards for "driveTime" milliseconds
    jetOFF(); // Turn JET OFF to Drop/Change directions
    delay(dropTime); // Now wait for "dropTime" milliseconds
}
