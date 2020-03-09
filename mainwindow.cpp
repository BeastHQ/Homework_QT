#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->textEdit->setHtml("<font color='red'>Hello</font>");
}

MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::on_calculate_clicked()
{
  double a = ui->line_a->text().toDouble();
  double b = ui->line_b->text().toDouble();
  double c = ui->line_c->text().toDouble();

  if(a == 0 && b != 0){
      double ans = -c / b;
      ui->first_root->setText(QString::number(ans));
      ui->second_root->setText(QString::number(ans));
    }
  else if(c == 0){
      ui->first_root->setText("0");
      ui->second_root->setText("0");
    }
  else{
      double D = (b * b) - (4 * a * c);

      if(D < 0){
          ui->first_root->setText("*No roots*");
          ui->second_root->setText("*No roots*");
        }
      else if(D == 0){
          double x0 = -b / (2 * a);
          ui->first_root->setText(QString::number(x0));
          ui->second_root->setText(QString::number(x0));
        }
      else{
          double x1 = (-b + qSqrt(D)) / (2 * a);
          double x2 = (-b - qSqrt(D)) / (2 * a);
          ui->first_root->setText(QString::number(x1));
          ui->second_root->setText(QString::number(x2));
        }
    }

}

void MainWindow::on_calculate2_clicked()
{
  qreal a = ui->line2_a->text().toDouble();
  qreal b = ui->line2_b->text().toDouble();
  qreal degree = ui->line2_degree->text().toDouble();
  qreal ans = 0;

  if(ui->radioButton_radians->isChecked()){
      degree = degree * 180 / M_PI;
    }
  ans = qSqrt(b * b + a * a - 2 * b * a * qCos(degree));
  ui->label2_answer->setText(QString::number(ans));
}


void MainWindow::on_pushButton_add_clicked()
{
    ui->plainTextEdit->appendHtml(ui->textEdit->toHtml());
}

void MainWindow::on_pushButton_replace_clicked()
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendHtml(ui->textEdit->toHtml());
}

void MainWindow::on_pushButton_clicked()
{
    QTextDocument* doc = ui->textEdit_2->document();
    ui->textEdit_3->setDocument(doc);
}
