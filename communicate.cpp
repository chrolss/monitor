/*
 * communicate.cpp
 *
 *  Created on: Jul 8, 2015
 *      Author: quad
 */

#include "communicate.h"

Communicate::Communicate(QWidget *parent)
    : QWidget(parent)
{

  QPushButton *plus = new QPushButton("+", this);
  plus->setGeometry(50, 40, 75, 30);

  QPushButton *minus = new QPushButton("-", this);
  minus->setGeometry(50, 100, 75, 30);

  QPushButton *BBBconnect = new QPushButton("Connect",this);
  BBBconnect->setGeometry(700,40,75,30);

  QPushButton *sendMSG = new QPushButton("Send",this);
  sendMSG->setGeometry(400,560,60,30);

  QTextEdit *dialog = new QTextEdit("BBB Dialog Field",this);
  dialog->setGeometry(10,350,380,200);
  dialog->show();

  IPbar = new QLineEdit("IP to BBB",this);
  IPbar->setGeometry(500,40,200,30);

  sender = new QLineEdit("Transmit Messages to the BBB",this);
  sender->setGeometry(10,560,380,30);
  sender->show();

  label = new QLabel("0", this);
  label->setGeometry(190, 80, 20, 30);

  connect(plus, SIGNAL(clicked()), this, SLOT(OnPeppu()));
  connect(minus, SIGNAL(clicked()), this, SLOT(OnMinus()));
  connect(BBBconnect, SIGNAL(released()), this, SLOT(OnConnect()));
  connect(sendMSG, SIGNAL(released()), this, SLOT(sendMsg()));
}

void Communicate::sendMsg()
{
	std::string str = sender->text().toUtf8().constData();
	printf("Sending a message to BBB: ");
	std::cout << str << std::endl;
}

void Communicate::OnPlus()
{
  int val = label->text().toInt();
  val++;
  label->setText(QString::number(val));
}

void Communicate::OnMinus()
{
  int val = label->text().toInt();
  val--;
  label->setText(QString::number(val));
}

void Communicate::OnPeppu()
{
	printf("Peppusar\n");
}

void Communicate::OnConnect()
{
	std::string str2 = IPbar->text().toUtf8().constData();
	printf("Connecting to Beaglebone on IP: ");
	std::cout << str2 << std::endl;

}

