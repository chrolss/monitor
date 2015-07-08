/*
 * main.cpp
 *
 *  Created on: Jul 8, 2015
 *      Author: quad
 */

#include "communicate.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  Communicate window;

  window.setWindowTitle("Communicate");
  window.setMinimumSize(800,600);
  window.show();

  return app.exec();
}


