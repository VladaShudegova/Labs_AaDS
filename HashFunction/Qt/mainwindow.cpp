#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QString>
#include <QMessageBox>
#include <iostream>
#include <vector>
#include <QDebug>

MainWindow::MainWindow(int size, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , table(size)
{
    ui->setupUi(this);
    ui->keyEdit->setValidator(new QIntValidator {0, INT_MAX});
    ui->keyEdit->setText("0");
    ui->valueEdit->setValidator(new QIntValidator {0, INT_MAX});
    ui->valueEdit->setText("0");
    ui->keyForDelete->setValidator(new QIntValidator {0, INT_MAX});
    ui->keyForDelete->setText("0");
    ui->tableWidget->setColumnCount(1);

    ui->tableWidget->setRowCount(table.getCapacity());
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "[Key, Value]");

    //connect(toolButton, &QPushButton::clicked, this, &MainWindow::nameOfYourSlot);
    QObject::connect(ui->addValueButton, &QPushButton::clicked, this, &MainWindow::on_clicked_addValue);
    QObject::connect(ui->deleteValueButton, &QPushButton::clicked, this, &MainWindow::on_clicked_deleteValue);
//    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
}

void MainWindow::on_clicked_addValue()
{
    bool ok1;
    int key = ui->keyEdit->text().toInt(&ok1);
    bool ok2;
    int value = ui->valueEdit->text().toInt(&ok2);

    if(ok1 && ok2)
    {
        int hash = table.add(key, value); //

        std::cout << "table" << std::endl;
        table.printTable();

        QTableWidgetItem *existingItem = ui->tableWidget->item(hash, 0);


        if (existingItem) {
            QString existingData = existingItem->text();
            existingData += QString(" [%1, %2]").arg(QString::number(key), QString::number(value));
            ui->tableWidget->setItem(hash, 0, new QTableWidgetItem(existingData));
        }
        else {
            ui->tableWidget->setItem(hash, 0, new QTableWidgetItem(QString("[%1, %2]").arg(QString::number(key), QString::number(value))));
        }
    }
    else {
        displayError(QString {"addValue: invalid key value: must be an integer"});
    }
    //ui->deleteValueButton->setEnabled(true);
}

void MainWindow::on_clicked_deleteValue()
{
    bool ok;
    int keyToDelete = ui->keyForDelete->text().toInt(&ok);
    if(ok)
    {
        if(table.contains(keyToDelete))
        {

            HashFunction *hashFunction = table.getHashFunction();
            int hash = hashFunction->hash(keyToDelete, table.getCapacity());

            QTableWidgetItem *existingItem = ui->tableWidget->item(hash, 0);

            if (existingItem) {
                QString existingData = existingItem->text();
                QStringList dataList = existingData.split(" ");
                for (int i = 0; i < dataList.size(); ++i) {
                    if (dataList[i].startsWith(QString("[%1,").arg(keyToDelete))) {
                        dataList.removeAt(i+1); // Удаляем значение (пара идет [ключ, значение])
                        dataList.removeAt(i);   // Удаляем ключ
                        break;
                    }
                }
                QString updatedData = dataList.join(" ");
                ui->tableWidget->setItem(hash, 0, new QTableWidgetItem(updatedData));
            }

            table.remove(keyToDelete);
        }
        else {
            displayError("deleteValue: this key not found");
        }
    }
    else {
        displayError("deleteValue: invalid key value: must be an integer");
    }

    table.printTable();
}

void MainWindow::displayError(QString const& msg)
{
    QMessageBox::warning(this, "error", msg);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printTableInUI()
{
    ui->tableWidget->clearContents();

    HashFunction *hashFunction = table.getHashFunction();
    for(int i = 0; i < table.getCapacity(); i++){
        int key = table.getNodes()[i]->getKey();
        int value = table.getCapacity();
        int hash = hashFunction->hash(key, value);
        QTableWidgetItem *item = ui->tableWidget->item(hash, 0);
        //ui->tableWidget->setItem(hash,0, item);


        if (item) {
            QString existingData = item->text();
            existingData += QString(" [%1, %2]").arg(QString::number(key), QString::number(value));
            ui->tableWidget->setItem(hash, 0, new QTableWidgetItem(existingData));
        }
        else {
            ui->tableWidget->setItem(hash, 0, new QTableWidgetItem(QString("[%1, %2]").arg(QString::number(key), QString::number(value))));
        }

    }
}

void MainWindow::on_pushButton_clicked()
{

        // Получение значения свойства isHash у кнопки
        //bool isHash = ui->pushButton->property("isHash").toBool();
        bool isHash = table.getisFirstHash();
        // Создание новой хеш-функции в зависимости от значения isHash
        HashFunction* newHashFunction = nullptr;
        if (isHash) {
           // SecondHash sHash;
            newHashFunction = new SecondHash(); //&sHash;

            ui->pushButton->setText( "Change on First hash");
        } else {
           // FirstHash fHash;
            newHashFunction = new FirstHash(); // &fHash;//

            ui->pushButton->setText("Change on Second hash");
        }

        // Смена хеш-функции для объекта table
        table.changeHashFunction(newHashFunction);

        ui->deleteValueButton->setEnabled(false);
        table.printTable();
        // Очистка выделенной памяти после использования
        delete newHashFunction;
        printTableInUI();

}

