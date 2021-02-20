// DRIVER CODE POG
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
vex::motor  leftTopDriveMotor = vex::motor( vex:: PORT3);
vex::motor  rightTopDriveMotor = vex::motor( vex:: PORT18,true);
vex::motor  leftBottomDriveMotor = vex::motor( vex:: PORT19,true);
vex::motor  rightBottomDriveMotor = vex::motor( vex:: PORT20);



//VCB
vex::motor  vcb = vex::motor( vex:: PORT5,true);

//Shell
vex::motor shell = vex::motor( vex:: PORT6, true);

//Intakes
vex::motor  LeftIntake = vex::motor( vex:: PORT9); //Change port
vex::motor  RightIntake = vex::motor( vex:: PORT10, true); //Change port


//Setting up the controller

vex::controller Yeetroller = vex::controller();

//Stuff like calibrating sensors, positioning lift, etc.
void setup (void) {


}



int runoff(int parameter) {
  if (parameter > 100){
    parameter = 100;
  }
  else if (parameter < -100){
    parameter = -100;
  }
  return parameter;
}





int overFlow(int input){
  if (input < 30 && input > 0){
    input = 0;
  } else if (input > -30 && input < 0){
    input = 0;
  }
  return input;
}




int average(int input1, int input2){
  return (input1+input2)/2;
}



//User control period (and general)
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  //variables

  //Percent speed that the each part moves at
  int vcbSpeed = 100;

  int intakeSpeed = 100;

  
  
  // infinite loop for the controller binds
  while (1) {



//Drive Train Program
  //Left Stick  
    int leftForward = Yeetroller.Axis3.position();
    int leftSideways = Yeetroller.Axis4.position();
    int rightSideways = Yeetroller.Axis1.position();  



    int LT = leftForward + leftSideways + rightSideways;
    LT = runoff(LT);
    LT = overFlow(LT);
    int RT = leftForward - leftSideways - rightSideways;
    RT = runoff(RT);
    RT = overFlow(RT);
    int LB = leftForward - leftSideways + rightSideways;
    LB = runoff(LB);
    LB = overFlow(LB);
    int RB = leftForward + leftSideways - rightSideways;
    RB = runoff(RB);
    RB = overFlow(RB);
    






    
    leftTopDriveMotor.spin(vex::directionType::fwd, LT, vex::velocityUnits::pct);
    rightBottomDriveMotor.spin(vex::directionType::rev, RB, vex::velocityUnits::pct);
    leftBottomDriveMotor.spin(vex::directionType::rev, LB, vex::velocityUnits::pct);
    rightTopDriveMotor.spin(vex::directionType::fwd, RT, vex::velocityUnits::pct);

  
    
    
  
  
  
  
  
  
  
  
  
  
  
  


    //Intakes Program


    //If Button 1 is pressed, the Intakes will move inwards
    if (Yeetroller.ButtonR1.pressing() || Yeetroller.ButtonL1.pressing()) {
        LeftIntake.spin(vex::directionType::fwd, intakeSpeed, vex::velocityUnits::pct);
        RightIntake.spin(vex::directionType::fwd, intakeSpeed, vex::velocityUnits::pct);
        vcb.spin(vex::directionType::rev, intakeSpeed, vex::velocityUnits::pct);
        shell.spin(vex::directionType::rev, intakeSpeed, vex::velocityUnits::pct);
    }
    //If Button 2 is pressed, the intakes will move outwards
    else if (Yeetroller.ButtonR2.pressing() || Yeetroller.ButtonL2.pressing()){
      LeftIntake.spin(vex::directionType::rev, intakeSpeed, vex::velocityUnits::pct);
      RightIntake.spin(vex::directionType::rev, intakeSpeed, vex::velocityUnits::pct);
      vcb.spin(vex::directionType::fwd, intakeSpeed, vex::velocityUnits::pct);
      shell.spin(vex::directionType::fwd, intakeSpeed, vex::velocityUnits::pct);
    }
    //If nothing is pressed, the intakes will stay stationary
    else {
      LeftIntake.stop(vex::brakeType::brake);
      RightIntake.stop(vex::brakeType::brake);
      vcb.stop(vex::brakeType::brake);
      shell.stop(vex::brakeType::brake);
    }


    //VCB Program:


    //shell Program:

    //If Button 3 is pressed, the vcb will move forward
    if (Yeetroller.ButtonA.pressing()) {
        shell.spin(vex::directionType::rev, vcbSpeed, vex::velocityUnits::pct);
    }
    //If Button 3 is pressed, the vcb will move in the opposite direction
    else if (Yeetroller.ButtonX.pressing()) {
        shell.spin(vex::directionType::fwd, vcbSpeed, vex::velocityUnits::pct);
    }
    //If nothing is pressed, the vcb will stay stationary
    else {
      shell.stop(vex::brakeType::brake);
    }


    vex::task::sleep(20); //Apparently prevents wasted resources yeah idk the tutorial had it so I kept it

  }
  
}
