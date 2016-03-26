#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "graph.h"
#include "graph_test.h"

#include "emprunt.h"
#include "flux.h"
#include "arbre.h"
#include "fusionneurbuilder.h"

#include <QStandardItemModel>
#include <QDirIterator>
#include "unittest.h"
#include "hanoi.h"

#include "utils.h"
#include "tuple.h"
#include "point.h"

 std::vector<temptest<QTextBrowser*>> tests;


void variatiqTemp(std::stringstream & stream)
 {

                      MyTupleContainer<std::tuple<int,char>> cont;
                      std::tuple<int,char> A(1,'j');
                      std::tuple<int,char> B(8,'y');
}

 void graphepf(std::stringstream & stream)
 {

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

     graph4.display(stream);
 }

 void HanoiTest1(std::stringstream & stream)
 {
     hanoitest(stream);
 }

 void nodePf(std::stringstream & stream)
 {
     testNode(stream);
 }

 void testPoint(std::stringstream & stream)
 {
    point p(1,2);
    stream << p;
 }

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString message= QString("program start");
    ui->textBrowser->append(message);


    std::stringstream stream;

    run_test(ui->textBrowser_3);

    stream.clear();

    Emprunt e;

    e.montant = 168275;
    e.mois = 180; //204;
    e.taux = 0.025+0.42/100;
    e.mensualité = 1155.7;
    e.build();
    e.display(stream);

    QString out = QString(stream.str().c_str());
    ui->textBrowser->append(out);

    FusionneurBuilder builder;
    Fusionneur f=builder.getFusionneur();
    std::vector<std::string> sources=f.getSources();
    //std::string destination=f.getDestination();

    QString inputs;
    for(std::vector<std::string>::iterator it=sources.begin();it!=sources.end();it++)
    {
        inputs.append("a");
    }

    QDirIterator dirIt("D:\\test_\\Chess_repertoire",QDirIterator::Subdirectories);
    while (dirIt.hasNext()) {
        dirIt.next();
        if (QFileInfo(dirIt.filePath()).isFile())
        {
            volatile int b=0;
            b++;
            QString dat(dirIt.fileName());
            QString suffix(".pgn");
            QString suffix2(".cbh");
            if(dat.contains(suffix,Qt::CaseInsensitive) || dat.contains(suffix2,Qt::CaseInsensitive))
            {
                ui->listWidget->addItem(dirIt.fileName());
                ui->listWidget->addItem(dat);
            }
        }
    }

    tests.push_back(temptest<QTextBrowser*>("heritage", NULL, ui->textBrowser_4));
    tests.push_back(temptest<QTextBrowser*>("Graphe", &graphepf, ui->textBrowser_4));
    tests.push_back(temptest<QTextBrowser*>("const", NULL, ui->textBrowser_4));
    tests.push_back(temptest<QTextBrowser*>("diamant", NULL, ui->textBrowser_4));
    tests.push_back(temptest<QTextBrowser*>("multiheritage", NULL, ui->textBrowser_4));
    tests.push_back(temptest<QTextBrowser*>("references", NULL, ui->textBrowser_4));
    tests.push_back(temptest<QTextBrowser*>("templates", NULL, ui->textBrowser_4));
    tests.push_back(temptest<QTextBrowser*>("threading", NULL, ui->textBrowser_4));
    tests.push_back(temptest<QTextBrowser*>("arbre binaire", &nodePf, ui->textBrowser_4));
    tests.push_back(temptest<QTextBrowser*>("tri", NULL, ui->textBrowser_4));
    tests.push_back(temptest<QTextBrowser*>("Exception", NULL, ui->textBrowser_4));
    tests.push_back(temptest<QTextBrowser*>("foncteur", NULL, ui->textBrowser_4));
    tests.push_back(temptest<QTextBrowser*>("lambda", NULL, ui->textBrowser_4));
    tests.push_back(temptest<QTextBrowser*>("Hanoi", &HanoiTest1, ui->textBrowser_4));
    tests.push_back(temptest<QTextBrowser*>("destructeur", NULL, ui->textBrowser_4));
    tests.push_back(temptest<QTextBrowser*>("friend", NULL, ui->textBrowser_4));
    tests.push_back(temptest<QTextBrowser*>("mutltiple parameters", NULL, ui->textBrowser_4));
    tests.push_back(temptest<QTextBrowser*>("variatiq template", NULL, ui->textBrowser_4));
    tests.push_back(temptest<QTextBrowser*>("template of template", NULL, ui->textBrowser_4));
    tests.push_back(temptest<QTextBrowser*>("surcharge opérateurs", &testPoint, ui->textBrowser_4));
    tests.push_back(temptest<QTextBrowser*>("export", NULL, ui->textBrowser_4));
    tests.push_back(temptest<QTextBrowser*>("non copiable", NULL, ui->textBrowser_4));

    for(std::vector<temptest<QTextBrowser*>>::iterator it = tests.begin(); it!=tests.end(); it++)
    {
        temptest<QTextBrowser*> current = *it;
        ui->comboBox->addItem(QString(current.nom.c_str()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    //appel au fusionnage de bases
    QString text;
   QList<QListWidgetItem *> list = ui->listWidget->selectedItems();
   int i = list.size();
   for(int j = 0; j < i; j++)
   {
       QListWidgetItem * current = list.at(j);
     text.append(current->text());
     text.append("\n");
      // it.i
   }

   ui->textBrowser_2->clear();
   ui->textBrowser_2->setText(text);

}

void MainWindow::on_pushButton_3_clicked()
{
    QString item = ui->comboBox->currentText();
    bool found = false;
    int i=0;
    int size = ui->comboBox->count();
    while(!found || i<size)
    {
        std::string s2 = item.toStdString();
        temptest<QTextBrowser*> currentTest = tests.at(i);
        if(currentTest.nom == s2)
        {
            found = true;
        currentTest.execute();
        }
        i++;
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->textBrowser->clear();

    int mois = fromQString<int>(ui->dureEdit->text());
    double montant = fromQString<double>(ui->capitalEdit->text());
    double taux= fromQString<double>(ui->tauxEdit->text())/100;
    taux += fromQString<double>(ui->assurance->text())/100;


    std::stringstream stream;
    Emprunt e;
    e.montant = montant;
    e.mois = mois; //204;
    e.taux = taux;
    e.mensualité = 1155.7;
    e.build();
    e.display(stream);

    QString out = QString(stream.str().c_str());
    ui->textBrowser->append(out);
    ui->cout->setText(toQString<double>(e.cout));
}
