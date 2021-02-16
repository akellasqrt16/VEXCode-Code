/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Ramya                                                     */
/*    Created:      Mon Feb 15 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;


//Drivetrain
vex::motor  leftTopDriveMotor = vex::motor( vex:: PORT3);
vex::motor  rightTopDriveMotor = vex::motor( vex:: PORT1,true);
vex::motor  leftBottomDriveMotor = vex::motor( vex:: PORT19,true);
vex::motor  rightBottomDriveMotor = vex::motor( vex:: PORT20);



//VCB
vex::motor  vcb = vex::motor( vex:: PORT5, true);

//Shell
vex::motor shell = vex::motor( vex:: PORT6, true);

//Intakes
vex::motor  LeftIntake = vex::motor( vex:: PORT9); //Change port
vex::motor  RightIntake = vex::motor( vex:: PORT10, true); //Change port


//Setting up the controller

vex::controller Yeetroller = vex::controller();


void moveForward(int rotations){
  int degrees = rotations*360;
  leftTopDriveMotor.startRotateFor(vex::directionType::fwd, degrees, vex::rotationUnits::deg);
  rightTopDriveMotor.startRotateFor(vex::directionType::fwd, degrees, vex::rotationUnits::deg);
  leftBottomDriveMotor.startRotateFor(vex::directionType::fwd, degrees, vex::rotationUnits::deg);
  rightBottomDriveMotor.rotateFor(vex::directionType::fwd, degrees, vex::rotationUnits::deg);
}

void turnRight(){
  int degrees = 0;
  leftTopDriveMotor.startRotateFor(vex::directionType::fwd, degrees, vex::rotationUnits::deg);
  rightTopDriveMotor.startRotateFor(vex::directionType::rev, degrees, vex::rotationUnits::deg);
  leftBottomDriveMotor.startRotateFor(vex::directionType::fwd, degrees, vex::rotationUnits::deg);
  rightBottomDriveMotor.rotateFor(vex::directionType::rev, degrees, vex::rotationUnits::deg);

}

void turnLeft(){
  int degrees = 0;
  leftTopDriveMotor.startRotateFor(vex::directionType::rev, degrees, vex::rotationUnits::deg);
  rightTopDriveMotor.startRotateFor(vex::directionType::fwd, degrees, vex::rotationUnits::deg);
  leftBottomDriveMotor.startRotateFor(vex::directionType::rev, degrees, vex::rotationUnits::deg);
  rightBottomDriveMotor.rotateFor(vex::directionType::fwd, degrees, vex::rotationUnits::deg);

}



void auton() {
  // Initializing Robot Configuration. DO NOT REMOVE!

  


}
