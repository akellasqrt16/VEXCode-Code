/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       pranavakella                                              */
/*    Created:      Mon Aug 10 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----


//Before running this code, make sure the ports for the motors are identical to the ports mentioned in the code
//To move the left motor, move the left stick, while to move the right motor, move the right stick


//NOTE: CURRENTLY, THIS CODE ONLY WORKS FOR THE DRIVE TRAIN, NOT THE LIFT OR ANY OTHER MOTORS/SENSORS








#include "vex.h"

using namespace vex;
// idk why i'm including this stuff but the tutorial I watched had this
vex::brain    Brain;
vex::competition    Competition;

//Setting up the motors we are going to use

//Make sure to CHANGE THE PORT NUMBER TO THE PORT THAT THE CORRESPONDING MOTOR IS PLUGGED INTO
vex::motor  LeftDriveMotor = vex::motor( vex:: PORT1, true);
vex::motor  RightDriveMotor = vex::motor( vex:: PORT10);

//Setting up the controller

vex::controller Yeetroller = vex::controller();

//Stuff like calibrating sensors, positioning lift, etc.
void setup (void) {


}

//The code for the autonomous period (when we get around to doing that)
void auton (void) {


}

//User control period (and general)
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // infinite loop for the controller binds
  while (1) {

    //The code tying the right drive train motor to the controller
    RightDriveMotor.spin(vex::directionType::fwd, 
    //Defines what part of the controller the action is bound to
    Yeetroller.Axis2.position(), 
    //Sets the units that you might put in the position() function in percent at least I think
    vex::velocityUnits::pct );

    //Literally the same thing, but for the left motor
    LeftDriveMotor.spin(vex::directionType::fwd, Yeetroller.Axis3.position(), vex::velocityUnits::pct );






    vex::task::sleep(20); //Apparently prevents wasted resources yeah idk the tutorial had it so I kept it

  }
  
}
