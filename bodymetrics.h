#ifndef BODYMETRICS_H
#define BODYMETRICS_H

#include <QMainWindow>
#include <QMessageBox>
#include <QKeyEvent>

#include "personwithage.h"
#include "resultform.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class BodyMetrics;
}
QT_END_NAMESPACE

class BodyMetrics : public QMainWindow
{
    Q_OBJECT

public:
    BodyMetrics(QWidget *parent = nullptr);
    ~BodyMetrics();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void onCalculateClicked();

private:
    Ui::BodyMetrics *ui;
    ResultForm *resultForm;
};

#endif // BODYMETRICS_H
