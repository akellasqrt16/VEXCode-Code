#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;
// idk why i'm including this stuff but the tutorial I watched had this

vex::competition    Competition;

//Setting up the motors we are going to use

//Make sure to CHANGE THE PORT NUMBER TO THE PORT THAT THE CORRESPONDING MOTOR IS PLUGGED INTO
vex::motor  LeftDriveMotor = vex::motor( vex:: PORT2, true);
vex::motor  RightDriveMotor = vex::motor( vex:: PORT1);
vex::motor  LeftLiftMotor = vex::motor( vex:: PORT6); //Change port
vex::motor  RightLiftMotor = vex::motor( vex:: PORT5, true); //Change port
vex::motor  LeftIntakeMotor = vex::motor( vex:: PORT9); //Change port
vex::motor  RightIntakeMotor = vex::motor( vex:: PORT10, true); //Change port
vex::motor  TopIntakeMotor = vex::motor( vex:: PORT10, true); //Change port



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
  
  //variables

  //Percent speed that the lift moves at
  int LiftSpeed = 25;

  //Percent speed that the intake moves at
  int bottomIntakeSpeed = 70;

  int topIntakeSpeed = 70;
  
  
  // infinite loop for the controller binds
  while (1) {

    
    //Drive Train Program
    //Tank controls
    
    //The code tying the right drive train motor to the controller
    RightDriveMotor.spin(vex::directionType::rev, 
    //Defines what part of the controller the action is bound to
    Yeetroller.Axis2.position(), 
    //Sets the units that you might put in the position() function in percent at least I think
    vex::velocityUnits::pct );

    //Literally the same thing, but for the left motor
    LeftDriveMotor.spin(vex::directionType::rev, Yeetroller.Axis3.position(), vex::velocityUnits::pct );



    //Lift Program


    //If Button R2 is pressed, the lift will move up
    if (Yeetroller.ButtonR2.pressing()){
        LeftLiftMotor.spin(vex::directionType::fwd, LiftSpeed, vex::velocityUnits::pct);
        RightLiftMotor.spin(vex::directionType::fwd, LiftSpeed, vex::velocityUnits::pct);
    }
    //If Button R1 is pressed, the lift will move down
    else if (Yeetroller.ButtonR1.pressing()){
      LeftLiftMotor.spin(vex::directionType::rev, LiftSpeed, vex::velocityUnits::pct);
      RightLiftMotor.spin(vex::directionType::rev, LiftSpeed, vex::velocityUnits::pct);
    }
    //If nothing is pressed, the lift will stay stationary
    else {
      LeftLiftMotor.stop(vex::brakeType::brake);
      RightLiftMotor.stop(vex::brakeType::brake);
    }


    //Intake Program:


    //If Button L2 is pressed, the bottom intakes will suck the ball in: 
    if (Yeetroller.ButtonL2.pressing()) {
        LeftIntakeMotor.spin(vex::directionType::fwd, bottomIntakeSpeed, vex::velocityUnits::pct);
        RightIntakeMotor.spin(vex::directionType::rev, bottomIntakeSpeed, vex::velocityUnits::pct);
    }
    // If Button L1 is pressed, the bottom intakes will spit the ball out:
    else if(Yeetroller.ButtonL1.pressing()){
        LeftIntakeMotor.spin(vex::directionType::rev, bottomIntakeSpeed, vex::velocityUnits::pct);
        RightIntakeMotor.spin(vex::directionType::fwd, bottomIntakeSpeed, vex::velocityUnits::pct);
 
    }
    //If nothing is pressed, the bottom intakes will stay stationary:
    else {
      LeftIntakeMotor.stop(vex::brakeType::brake);
      RightIntakeMotor.stop(vex::brakeType::brake);
    }


    // Top Intake:


    //If Button X is pressed, the top intake will suck the ball in: 
    if (Yeetroller.ButtonX.pressing()) {
        TopIntakeMotor.spin(vex::directionType::fwd, topIntakeSpeed, vex::velocityUnits::pct);
        
    }
    // If Button A is pressed, the top intake will spit the ball out:
    else if(Yeetroller.ButtonA.pressing()){
        TopIntakeMotor.spin(vex::directionType::rev, topIntakeSpeed, vex::velocityUnits::pct);
     
 
    }
    //If nothing is pressed, the top intake will stay stationary:
    else {
      TopIntakeMotor.stop(vex::brakeType::brake);
      
    }





    vex::task::sleep(20); //Apparently prevents wasted resources yeah idk the tutorial had it so I kept it

  }
  
}
