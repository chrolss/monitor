/*
 * main.cpp
 *
 *  Created on: Jul 8, 2015
 *      Author: quad
 */

// Server used is located in BeagleProjects/communication
// The monitor project is always a client, never a server

#include "communicate.h"
#include "com.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  Communicate window;

  window.setWindowTitle("Communicate");
  window.setMinimumSize(800,600);
  window.show();

  return app.exec();
}


