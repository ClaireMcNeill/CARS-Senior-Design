void setup() {
  isError();
  while(!atHeight() && !atPressure()) {
    delay(500);
  }
  antennaSetup();
  while(!isMessageRecieved()) {
    delay(500);
  }
  antennaShutdown();
  shutdown();

}

bool atHeight() {
  // Checks the height of the tower consistantly until it is at the correct height
  while(height != 12ft) { // Will check the value of the height sensor
    delay(500)
  }
  return True
}

bool atPressure() {
  // Checks the pressure of the bladder via the pressure sensor
  // Manually open and close the valve to let air out
  while(pressure != ) { // Will check the value of the pressure sensor
    delay(500)
  }
  if(pressure > ) {
    // Release some air to get it back to correct pressure
  }
  return True

}

void isError() {
  // Checks for errors, are sensors all on and connected
  isErrorCritical(error);

}

void isErrorCritical(error) {
  // Checks for critical errors

}

void antennaSetup() {
  // Deploys antenna itself, opens connection and sends a message

}

void antennaShutdown() {
  // Once message is recieved, antenna is shut off

}

bool isMessageRecieved() {
  // Checks if the message was recieved
}

void shutdown() {
  // Brings tower down and shuts it off while checking height and pressure

}
