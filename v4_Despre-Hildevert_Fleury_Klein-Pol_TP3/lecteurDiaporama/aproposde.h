#ifndef APROPOSDE_H
#define APROPOSDE_H

#include <QDialog>
#include <QObject>
#include <QShortcut>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class AProposDe; }
QT_END_NAMESPACE

class AProposDe : public QDialog
{
    Q_OBJECT

public:
    AProposDe(QWidget *parent = nullptr);
    ~AProposDe();


private:
    Ui::AProposDe *uiAProposDe;

};
#endif // APROPOSDE_H
