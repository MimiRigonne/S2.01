#include "aproposde.h"
#include "ui_aProposDe.h"
#include <QPushButton>
#include <QCoreApplication>
#include "lecteurvue.h"


AProposDe::AProposDe(QWidget *parent)
    : QDialog(parent)
    , uiAProposDe(new Ui::AProposDe)
{
    uiAProposDe->setupUi(this);

    QObject::connect(uiAProposDe->btnOK,SIGNAL(clicked()),this,SLOT(close()));

}


AProposDe::~AProposDe()
{
    delete uiAProposDe;
}
