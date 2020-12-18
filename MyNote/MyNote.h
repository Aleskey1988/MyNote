#pragma once

#include <QtWidgets/QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include "ui_MyNote.h"
#include "ReplaceDialog.h"

class MyNote : public QMainWindow
{
    Q_OBJECT

public:
    MyNote(QWidget *parent = Q_NULLPTR);

private:
    void onLoad();
    void onSave();
    void onReplace();
    void onFont();
    void onExit();
    void onAbout();

    void onTextReplaced(QString& text);

    Ui::MyNoteClass ui;
    ReplaceDialog replaceDlg;
};
