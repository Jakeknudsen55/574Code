#include "main.h"

void doubleShot(){
  shoot();
  ratchetAsync();
  intake(127);
  adjust();
  while(!isLoaded()){
    static int count = 0;
    count++;
    if(count > 40)
      break;
    delay(20);
  }
  shoot();
  adjustAsync();
  ratchetAsync();
}

void park(){
  driveAsync(1.6 TL);
  while(drivePos() < 1 TL) delay(20);
  drive(-1);
  reset();
}

void alliancePark(){
  intake(127);
  driveAsync(1.9 TL);
  while(drivePos() < 1.4 TL) delay(20);
  setSpeed(20);
  while(isDriving()) delay(20);
  driveAsync(.4 TL);
  setSpeed(40);
  while(isDriving()) delay(20);
}

void backToFront(){
  drive(.2 TL);
  turn(86);
  drive(2.05 TL);
  turn(-94);
  drive(-.5 TL);
}

void wallToFlag(){
  drive(.22 TL);
  turn(85);
  doubleShot();
}

void lowFlag(){
  turn(15);
  loadAndClearAsync();
  slowDrive(2.5 TL, 1.1 TL);
  turn(-5);
}

void intakeFlip(){
  intake(-80);
  driveAsync(2.5 TL);
  while(drivePos() < 1.2 TL) delay(20);
  setSpeed(60);
  while(drivePos() < 1.7 TL) delay(20);
  intakeBallAsync();
  while(isDriving()) delay(20);
}

void backCap(){
  //back cap
  intake(-80);
  slowDrive(2.2 TL, .6 TL);

  //align with wall
  drive(-1.95 TL);
  turn(24);
  drive(-.5 TL);
}
