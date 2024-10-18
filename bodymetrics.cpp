#include "bodymetrics.h"
#include "ui_bodymetrics.h"

BodyMetrics::BodyMetrics(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BodyMetrics)
{
    ui->setupUi(this);
    ui->heightInput->setFocus();
    setFixedSize(510, 510);

    connect(ui->calculateButton, SIGNAL(clicked()), this, SLOT(onCalculateClicked()));
}

void BodyMetrics::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Escape)
    {
        close();
    }
    else if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
    {
        onCalculateClicked();
    }
}

void BodyMetrics::onCalculateClicked()
{
    try
    {
        bool heightOk;
        bool weightOk;
        bool ageOk;

        float height = ui->heightInput->text().toFloat(&heightOk);
        float weight = ui->weightInput->text().toFloat(&weightOk);
        int age = ui->ageInput->text().toInt(&ageOk);

        if (!heightOk || !weightOk || !ageOk)
        {
            throw "Некорректные данные.";
        }

        PersonWithAge person(height, weight, age);

        float bmi = person.calculateBMI();
        QString bmiCategory = person.getBMICategory();

        float bmr = person.calculateBMR();
        float proteins;
        float fats;
        float carbs;
        person.calculateMacronutrients(proteins, fats, carbs);

        resultForm = new ResultForm(bmi, bmiCategory, bmr, proteins, fats, carbs, this);
        resultForm->exec();

        ui->heightInput->clear();
        ui->weightInput->clear();
        ui->ageInput->clear();
    }
    catch (const char* errorMessage)
    {
        QMessageBox::warning(this, "Предупреждение", errorMessage);

        ui->heightInput->clear();
        ui->weightInput->clear();
        ui->ageInput->clear();
    }
}

BodyMetrics::~BodyMetrics()
{
    delete ui;
}
