#include "resultform.h"
#include "ui_resultform.h"

ResultForm::ResultForm(float bmi, const QString& bmiCategory, float bmr, float proteins, float fats, float carbs, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ResultForm)
{
    ui->setupUi(this);
    setFixedSize(660, 340);

    connect(ui->closeButton, SIGNAL(clicked()), this, SLOT(onCloseClicked()));

    ui->bmiOutput->setText(QString::number(bmi, 'f', 2) + " (" + bmiCategory + ")");
    ui->bmrOutput->setText(QString::number(static_cast<int>(std::round(bmr))) + " ккал");
    ui->proteinsOutput->setText(QString::number(proteins, 'f', 2) + " г");
    ui->fatsOutput->setText(QString::number(fats, 'f', 2) + " г");
    ui->carbsOutput->setText(QString::number(carbs, 'f', 2) + " г");
}

void ResultForm::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        close();
    }
}

void ResultForm::onCloseClicked()
{
    close();
}

ResultForm::~ResultForm()
{
    delete ui;
}
