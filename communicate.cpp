/*
 * communicate.cpp
 *
 *  Created on: Jul 8, 2015
 *      Author: quad
 */

#include "communicate.h"
#include "com.h"

com comLink;

Communicate::Communicate(QWidget *parent)
    : QWidget(parent)
{


  QPushButton *plus = new QPushButton("+", this);
  plus->setGeometry(50, 40, 75, 30);

  QPushButton *minus = new QPushButton("-", this);
  minus->setGeometry(50, 100, 75, 30);

  QPushButton *BBBconnect = new QPushButton("Connect",this);
  BBBconnect->setGeometry(600,40,75,30);

  QPushButton *sendMSG = new QPushButton("Send",this);
  sendMSG->setGeometry(400,560,60,30);

  //QTextEdit *dialog = new QTextEdit("BBB Dialog Field",this);
  //dialog->setGeometry(10,350,380,200);
  //dialog->show();

  dialog = new QTextEdit("BBB Dialog Field",this);
  dialog->setGeometry(10,360,380,200);
  dialog->show();
  dialog->setReadOnly(true);

  IPbar = new QLineEdit("IP to BBB",this);
  IPbar->setGeometry(450,40,100,30);

  portBar = new QLineEdit("Port",this);
  portBar->setGeometry(550,40,50,30);

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
	char *msg = new char[str.size()+1];
	std::copy(str.begin(), str.end(),msg);
	msg[str.size()] = '\0';
	comLink.sendBBB(msg);
	printf("Sending a message to BBB: %s \n", msg);
	delete[] msg;
	sender->clear();
	readMsg();
}

void Communicate::readMsg()
{
	// Here we read what the server/beaglebone has to say
	char *trans = comLink.readBBB();
	std::string sline(trans);
	std::cout << sline << std::endl;
	QString qstr = QString::fromStdString(sline);
	QString old = dialog->toPlainText();
	dialog->setPlainText(old + '\n' + qstr);
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
	std::string address = IPbar->text().toUtf8().constData();
	int portNo = portBar->text().toInt();

	char *add = new char[address.size()+1];
	std::copy(address.begin(), address.end(),add);
	add[address.size()] = '\0';

	comLink.setAddress(add);	//should be a char *
	comLink.setPort(portNo); 		//should be an int
	comLink.callBBB();

	contact = true;
	printf("Connecting to Beaglebone on IP: %s", address.c_str());
	QString Qadd = QString::fromStdString(address);
	dialog->setPlainText("Connected to BBB on: " + Qadd);
	std::cout << address << std::endl;
	delete[] add;
}

