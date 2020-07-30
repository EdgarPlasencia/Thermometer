#ifndef TEMPERATURA_H
#define TEMPERATURA_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Temperatura; }
QT_END_NAMESPACE

class Temperatura : public QDialog
{
    Q_OBJECT

public:
    Temperatura(QWidget *parent = nullptr);
    ~Temperatura();
public slots:

    void cent2Far(int);
    void cent2Cent(int);
    void cent2Kel(int);

private:
    Ui::Temperatura *ui;
};
#endif // TEMPERATURA_H
