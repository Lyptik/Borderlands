//------------------------------------------------------------------------------
// BORDERLANDS:  An interactive granular sampler.  
//------------------------------------------------------------------------------
// More information is available at 
//     http::/ccrma.stanford.edu/~carlsonc/256a/Borderlands/index.html
//
//
// Copyright (C) 2011  Christopher Carlson
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 3.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.


//
//  SoundRect.h
//  Borderlands
//
//  Created by Christopher Carlson on 11/30/11.
//


#ifndef SOUNDRECT_H
#define SOUNDRECT_H

#include "theglobals.h"
//#include "pt2d.h"
//graphics includes
#ifdef __MACOSX_CORE__
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif


#include <iostream>
#include <math.h>
#include <GTime.h>
#include <algorithm>
#include <Stk.h>

using namespace std;




//id for this class, which is incremented for each instance
//static unsigned int boxId = 0;

class SoundRect
{
    
public:
    
    //destructor
    virtual ~SoundRect();
    
    //constructor (default)
    SoundRect();
    
    //other object initialization code
    void init();
    
    //display functions
    void draw();
    
    //properties
    void setWidthHeight(float width, float height);

    float getHeight();
    float getWidth();
    bool getOrientation();
    
    //process mouse drag
    void move(float xDiff,float yDiff);

    //set selection (highlight)
    void setSelectState(bool state);
    //determine if mouse click is in selection range
    bool select(float x, float y);

    void toggleWaveDisplay();
    void associateSound(double* theBuff,unsigned long buffFrames, unsigned int buffChans );
    //return id
    //unsigned int getId();
    
    //return 
   bool getNormedPosition(double * positionsX, double * positionsY, float x, float y,unsigned int idx);

    //change from vertical to horizontal
    void toggleOrientation();
    //set name
    void setName(char * name);
    

protected:
    //set upsampling for waveform display (based on rect size/orientation)
    void setUps();
    bool insideMe(float x, float y);
    void setWaveDisplayParams();
    void randColor();
    //update information used for vertices with new width and height
    void updateCorners(float width,float height);
    
    
private:
    unsigned int myId;
    unsigned int screenWidth,screenHeight;
    float rWidth,rHeight;
    float rtop,rbot,rleft,rright;
    float rX, rY,rZ;
    bool isSelected;
    float colR,colG,colB,colA;
    float minDim;
    double * myBuff;
    double startTime;
    float ups;
    unsigned long myBuffFrames;
    unsigned int myBuffChans;
    unsigned int myBuffInc;
    bool showBuff;
    bool pendingBuffState;
    float lastX,lastY;
    
    //other display params
    float aMin,aMax,aTarg,lambda,pRate;
    float aPhase;
    float buffAlphaMax;
    float buffAlpha;
    double buffMult;
    bool orientation;
    
    
};

#endif
