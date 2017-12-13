// author : Nathan Easton
// date : 10/16/17
// Project : 8
// Section:014
/*
Simulate circle collison.
*/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using std::ostringstream;
using std::setprecision;
using std::cout; using std::endl;using std::fixed;
#include "proj08_twod.h"
#include "proj08_ball.h"


//Construtor for Ball
Ball::Ball(double m, TwoD pos, TwoD speed, double r){
    mass=m;
    coords=pos;
    velocity=speed;
    radius=r;
}

//Takes ball returns a string using ostringstream
string Ball::to_string(){
    ostringstream oss;
    oss<<fixed<<setprecision(2)<<mass<<", "<<coords.to_string()<<", "<<velocity.to_string()<<", "<<radius;
    return oss.str();
}

//returns a bool when given a Ball 
//Checks to see if ball is in contact with other ball
bool Ball::contact_ball(Ball q){
    auto test=coords.diff(q.coords);//Gets the difference between the cords
    auto rs=(radius+q.radius)*(radius+q.radius);//Gets the radius of both circles
    if (test.magnitude_squared()<=rs){//Checks to see if the distance is less than the radius
        return true;
    }
    return false;
}

//Takes in two longs returns a bool of if the ball is in contact with a wall.
bool Ball::contact_wall(long xdim, long ydim){
    if (coords.x+radius >xdim || coords.x-radius<0){
        //Check if its touching on the x axis
        return true;
    }else if(coords.y+radius >ydim || coords.y-radius<0){
        //Checks if its touching on the y axis
        return true;
    }
    return false;
}

//Returns a TwoD of the velocity after it contacts 
TwoD Ball::update_velocity_wall(long xdim, long ydim){
    char axis;
    //Determine what axis the ball touches on.
    if (coords.x+radius >xdim || coords.x-radius<0){
        axis='x';
    }else if(coords.y+radius >ydim || coords.y-radius<0){
        axis= 'y';
    }
    //Apply direction change based on axis
    if (axis=='x'){
        return TwoD(velocity.x*-1,velocity.y);
    }else{
        return TwoD(velocity.x,velocity.y*-1);
    }

    
}
//Takes in ball returns a TwoD
TwoD Ball::update_velocity_ball(Ball q){
    //Updates ball velocity when it hits another ball.
    double newx=(velocity.x *(mass-q.mass)+(2.0*q.mass*q.velocity.x))/(mass+q.mass);
    double newy=(velocity.y *(mass-q.mass)+(2.0*q.mass*q.velocity.y))/(mass+q.mass);
    // cout<<newx<<" "<<newy;
    return TwoD(newx,newy);
    
}
