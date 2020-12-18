#pragma once

#include <QDialog>
#include "ui_ReplaceDialog.h"

class ReplaceDialog : public QDialog
{
    Q_OBJECT

public:
    ReplaceDialog();

    void SetText(QString& text) { this->text = text; }

signals:
    void textReplaced(QString& text);

private:
    void onOK();

    Ui::ReplaceDialog ui;
    QString text;
};
