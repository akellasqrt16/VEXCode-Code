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










#include "vex.h"

using namespace vex;
// idk why i'm including this stuff but the tutorial I watched had this
vex::brain    Brain;
vex::competition    Competition;

//Setting up the motors we are going to use

//Make sure to CHANGE THE PORT NUMBER TO THE PORT THAT THE CORRESPONDING MOTOR IS PLUGGED INTO

//Drivetrain
vex::motor  leftTopDriveMotor = vex::motor( vex:: PORT1);
vex::motor  rightTopDriveMotor = vex::motor( vex:: PORT10);
vex::motor  leftBottomDriveMotor = vex::motor( vex:: PORT10);
vex::motor  rightBottomDriveMotor = vex::motor( vex:: PORT10);



//Lift
vex::motor  LeftLiftMotor = vex::motor( vex:: PORT6, true); //Change port
vex::motor  LeftBottomLiftMotor = vex::motor( vex:: PORT7, true); //Change port
vex::motor  RightLiftMotor = vex::motor( vex:: PORT5); //Change port

//Intake
vex::motor  LeftIntakeMotor = vex::motor( vex:: PORT3); //Change port
vex::motor  RightIntakeMotor = vex::motor( vex:: PORT4, true); //Change port


//Setting up the controller

vex::controller Controller = vex::controller();

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
  int LiftSpeed = 75;

  //Percent speed that the intake moves at
  int intakeSpeed = 100;
  
  
  // infinite loop for the controller binds
  while (1) {

    
    //Drive Train Program
    //Tank controls
    
    //The code tying the left top drive train motor to the controller
    leftTopDriveMotor.spin(vex::directionType::fwd, 
    //Defines what part of the controller the action is bound to
    Controller.Axis2.position(), 
    //Sets the units that you might put in the position() function in percent at least I think
    vex::velocityUnits::pct );

    //Literally the same thing, but for the other motors
    rightTopDriveMotor.spin(vex::directionType::fwd, Controller.Axis3.position(), vex::velocityUnits::pct );
    leftBottomDriveMotor.spin(vex::directionType::fwd, Controller.Axis2.position(), vex::velocityUnits::pct );
    rightBottomDriveMotor.spin(vex::directionType::fwd, Controller.Axis3.position(), vex::velocityUnits::pct );

    if(Controller.Axis2.position() > 0 && Controller.Axis1.position() > 0) {
      leftTopDriveMotor.spin(vex::directionType::fwd, LiftSpeed, vex::velocityUnits::pct);
      rightBottomDriveMotor.spin(vex::directionType::fwd, LiftSpeed, vex::velocityUnits::pct);

    }


    //Lift Program


    //If Button 1 is pressed, the lift will move up
    if (Controller.ButtonR2.pressing()) {
        LeftLiftMotor.spin(vex::directionType::fwd, LiftSpeed, vex::velocityUnits::pct);
        LeftBottomLiftMotor.spin(vex::directionType::fwd, LiftSpeed, vex::velocityUnits::pct);
        RightLiftMotor.spin(vex::directionType::fwd, LiftSpeed, vex::velocityUnits::pct);
    }
    //If Button 2 is pressed, the lift will move down
    else if (Controller.ButtonR1.pressing()){
      LeftLiftMotor.spin(vex::directionType::rev, LiftSpeed, vex::velocityUnits::pct);
      LeftBottomLiftMotor.spin(vex::directionType::rev, LiftSpeed, vex::velocityUnits::pct);
      RightLiftMotor.spin(vex::directionType::rev, LiftSpeed, vex::velocityUnits::pct);
    }
    //If nothing is pressed, the lift will stay stationary
    else {
      LeftLiftMotor.stop(vex::brakeType::brake);
      LeftBottomLiftMotor.stop(vex::brakeType::brake);
      RightLiftMotor.stop(vex::brakeType::brake);
    }


    //Intake Program:

    //If Button 3 is pressed, the lift will move up
    if (Controller.ButtonL2.pressing()) {
        LeftIntakeMotor.spin(vex::directionType::fwd, intakeSpeed, vex::velocityUnits::pct);
        RightIntakeMotor.spin(vex::directionType::fwd, intakeSpeed, vex::velocityUnits::pct);
    }
    //If nothing is pressed, the intake will stay stationary
    else {
      LeftIntakeMotor.stop(vex::brakeType::brake);
      RightIntakeMotor.stop(vex::brakeType::brake);
    }
 






    vex::task::sleep(20); //Apparently prevents wasted resources yeah idk the tutorial had it so I kept it

  }
  
}





