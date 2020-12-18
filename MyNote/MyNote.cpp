#include "MyNote.h"

MyNote::MyNote(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.actionOpen, &QAction::triggered, this, &MyNote::onLoad);
    connect(ui.actionSave, &QAction::triggered, this, &MyNote::onSave);
    connect(ui.actionReplace, &QAction::triggered, this, &MyNote::onReplace);
    connect(ui.actionFont, &QAction::triggered, this, &MyNote::onFont);
    connect(ui.actionAbout, &QAction::triggered, this, &MyNote::onAbout);

    connect(&replaceDlg, &ReplaceDialog::textReplaced, this, &MyNote::onTextReplaced);
}

void MyNote::onLoad()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select text file", "", "*.txt");
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QString str(file.readAll());
    ui.plainTextEdit->setPlainText(str);
}
void MyNote::onSave()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save text file", "", "*.txt");
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    QTextStream stream(&file);
    QString str = ui.plainTextEdit->toPlainText();
    stream << str;
    file.close();
}
void MyNote::onReplace()
{
    replaceDlg.SetText(ui.plainTextEdit->toPlainText());
    replaceDlg.show();
}
void MyNote::onFont()
{

}
void MyNote::onExit()
{

}
void MyNote::onAbout()
{
    QMessageBox::information(nullptr, "MyNote", "This is MyNote text editor");
}
void MyNote::onTextReplaced(QString& text)
{
    ui.plainTextEdit->setPlainText(text);
}