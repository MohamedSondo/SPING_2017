//------------------------------------------------------------------------
// Filename: 
//    Smoker.h
// PROGRAM DESCRIPTION
//    class definition file for Smokerthread and Agentthread class
//------------------------------------------------------------------------

#ifndef _SMOKER_H
#define _SMOKER_H

#include "ThreadClass.h"

#define NUM_OF_SMOKERS      3        // number of Smoker 

//------------------------------------------------------------------------
// Smokerthread class definition
//------------------------------------------------------------------------

class Smokerthread: public Thread 
{
     public:
          Smokerthread(int Number);  // constructor
     private:
          void ThreadFunc();
          int No;
};

//------------------------------------------------------------------------
// Agentthread class definition
//------------------------------------------------------------------------

class Agentthread: public Thread 
{
     public:
          Agentthread(char *ThreadName, int iter);  // constructor
     private:
          void ThreadFunc();
          int Iterations;
};

#endif