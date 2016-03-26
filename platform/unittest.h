#ifndef UNITTEST_H
#define UNITTEST_H

#include<QTextBrowser>

typedef  void (PFUNCTION)(QTextBrowser* output);


typedef  void (PFUNCTIONSTREAM)(std::stringstream & s);

class unitTest
{
public:
    unitTest();
    unitTest(std::string nom, PFUNCTION * pf,QTextBrowser* output) : nom(nom), pf(pf),output(output){}

    std::string nom;
    PFUNCTION * pf;
    QTextBrowser* output;

    void execute()
    {
        this->output->clear();
        if(this->pf)
           this->pf(this->output);

        //this->pf()
    }

};

template<typename displayer> class temptest
{
public:
    std::string nom;
    PFUNCTIONSTREAM* func;
    displayer output;

    temptest(std::string nom, PFUNCTIONSTREAM* func0,displayer output)
    {
        this->nom = nom;
        this->func = func0;
        this->output = output;
    }

    void execute(){}
};

template<> void temptest<QTextBrowser *>::execute()
{
    std::stringstream s;
    this->output->clear();
    this->func(s);
    this->output->append(QString(s.str().c_str()));
}


#endif // UNITTEST_H
