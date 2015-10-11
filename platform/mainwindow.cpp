#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "graph.h"

#include "emprunt.h"
#include "flux.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString message= QString("program start");
    ui->textBrowser->append(message);

    Graph<int> graph4(4);
    Graph<int> graph5(5);
    Graph<int> graph6(6);
    Graph<int> graph3(3);
    Graph<int> graph2(2);
    Graph<int> graph1(1);

    graph4.add(&graph6);
    graph4.add(&graph3);
    graph3.add(&graph2);
    graph6.add(&graph5);
    graph6.add(&graph5);
    graph2.add(&graph6);
    graph2.add(&graph1);
    graph5.add(&graph1);

    std::stringstream stream;

    //graph4.display(stream);

    Emprunt e;
    e.montant = 168275;
    e.mois = 180; //204;
    e.taux = 0.025+0.42/100;
    e.mensualité = 1155.7;
    e.build();
    e.display(stream);

    QString out = QString(stream.str().c_str());
    ui->textBrowser->append(out);


}

MainWindow::~MainWindow()
{
    delete ui;
}
