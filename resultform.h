#ifndef RESULTFORM_H
#define RESULTFORM_H

#include <QDialog>
#include <QKeyEvent>

namespace Ui {
class ResultForm;
}

class ResultForm : public QDialog
{
    Q_OBJECT

public:
    explicit ResultForm(float bmi, const QString& bmiCategory, float bmr, float proteins, float fats, float carbs, QWidget *parent = nullptr);
    ~ResultForm();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void onCloseClicked();

private:
    Ui::ResultForm *ui;
};

#endif // RESULTFORM_H
