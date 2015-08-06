/*
 * communicate.h
 *
 *  Created on: Jul 8, 2015
 *      Author: quad
 */

#ifndef COMMUNICATE_H_
#define COMMUNICATE_H_

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include "stdio.h"
#include <string>
#include <iostream>
#include "com.h"

class Communicate : public QWidget
{
  Q_OBJECT

  public:
    Communicate(QWidget *parent = 0);


  private slots:
    void OnPlus();
    void OnMinus();
    void OnPeppu();
    void OnConnect();
    void sendMsg();
    void readMsg();

  private:
    bool contact = false;
    QLabel *label;
    QLineEdit *IPbar;
    QLineEdit *sender;
    QLineEdit *portBar;
    QTextEdit *dialog;

};



#endif /* COMMUNICATE_H_ */
