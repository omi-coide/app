#include "minusplus.hpp"
#include <QGridLayout>
MinusPlus::MinusPlus(QWidget *parent): QWidget(parent){
  this-> counter =0;
  auto *plus = new QPushButton("+",this);
  auto *minus= new QPushButton("-", this);
  this->label = new QLabel("0",this);
  auto *grid = new QGridLayout(this);
  grid->addWidget(plus,0,0);
  grid->addWidget(minus,0,1);
  grid->addWidget(label,1,1);
  this->setLayout(grid);
  connect(plus,&QPushButton::clicked,this,&MinusPlus::OnPlus);
  connect(minus, &QPushButton::clicked, this, &MinusPlus::OnMinus);
}


void MinusPlus::OnPlus(){
  this->counter++;
  this->label->setText(QString::number(counter));
}

void MinusPlus::OnMinus() {
  this->counter--;
  this->label->setText(QString::number(counter));
}
