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
vex::motor  rightTopDriveMotor = vex::motor( vex:: PORT2);
vex::motor  leftBottomDriveMotor = vex::motor( vex:: PORT3);
vex::motor  rightBottomDriveMotor = vex::motor( vex:: PORT4);



//Lift
vex::motor  LeftLiftMotor = vex::motor( vex:: PORT6, true); //Change port
vex::motor  LeftBottomLiftMotor = vex::motor( vex:: PORT7, true); //Change port
vex::motor  RightLiftMotor = vex::motor( vex:: PORT5); //Change port

//Intake
vex::motor  LeftIntakeMotor = vex::motor( vex:: PORT3); //Change port
vex::motor  RightIntakeMotor = vex::motor( vex:: PORT4, true); //Change port


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
  int LiftSpeed = 75;

  //Percent speed that the intake moves at
  int intakeSpeed = 100;

  int driveSpeed = 100;
  
  
  // infinite loop for the controller binds
  while (1) {

    
//Drive Train Program
  //Left Stick  
    //When the left stick is in the 1st quadrant, the robot moves diagonally right.
    if(Yeetroller.Axis3.position() > 0 && Yeetroller.Axis4.position() > 0) {
      leftTopDriveMotor.spin(vex::directionType::fwd, driveSpeed, vex::velocityUnits::pct);
      rightBottomDriveMotor.spin(vex::directionType::fwd, driveSpeed, vex::velocityUnits::pct);
    } 
    //When the left stick is in the 2st quadrant, the robot moves diagonally left.
    if(Yeetroller.Axis3.position() > 0 && Yeetroller.Axis4.position() < 0) {
      leftBottomDriveMotor.spin(vex::directionType::fwd, driveSpeed, vex::velocityUnits::pct);
      rightTopDriveMotor.spin(vex::directionType::fwd, driveSpeed, vex::velocityUnits::pct);
    }
    //When the left stick is in the 3rd quadrant, the robot moves backwards diagonally left.
    if(Yeetroller.Axis3.position() < 0 && Yeetroller.Axis4.position() < 0) {
      leftTopDriveMotor.spin(vex::directionType::rev, driveSpeed, vex::velocityUnits::pct);
      rightBottomDriveMotor.spin(vex::directionType::rev, driveSpeed, vex::velocityUnits::pct);
    }
    //When the left stick is in the 4th quadrant, the robot moves backwards diagonally right.
    if(Yeetroller.Axis3.position() < 0 && Yeetroller.Axis4.position() > 0) {
      leftBottomDriveMotor.spin(vex::directionType::rev, driveSpeed, vex::velocityUnits::pct);
      rightTopDriveMotor.spin(vex::directionType::rev, driveSpeed, vex::velocityUnits::pct);
    }
  //Right Stick
    //If the right stick is to the right, the robot will turn right.
    if(Yeetroller.Axis1.position() > 0) {
      leftTopDriveMotor.spin(vex::directionType::fwd, driveSpeed, vex::velocityUnits::pct);
      rightBottomDriveMotor.spin(vex::directionType::rev, driveSpeed, vex::velocityUnits::pct);
    } 
    //If the right stick is to the left, the robot will turn left.
    if(Yeetroller.Axis1.position() < 0) {
      leftBottomDriveMotor.spin(vex::directionType::rev, driveSpeed, vex::velocityUnits::pct);
      rightTopDriveMotor.spin(vex::directionType::fwd, driveSpeed, vex::velocityUnits::pct);
    } 









    //Lift Program


    //If Button 1 is pressed, the lift will move up
    if (Yeetroller.ButtonR2.pressing()) {
        LeftLiftMotor.spin(vex::directionType::fwd, LiftSpeed, vex::velocityUnits::pct);
        LeftBottomLiftMotor.spin(vex::directionType::fwd, LiftSpeed, vex::velocityUnits::pct);
        RightLiftMotor.spin(vex::directionType::fwd, LiftSpeed, vex::velocityUnits::pct);
    }
    //If Button 2 is pressed, the lift will move down
    else if (Yeetroller.ButtonR1.pressing()){
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
    if (Yeetroller.ButtonL2.pressing()) {
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









