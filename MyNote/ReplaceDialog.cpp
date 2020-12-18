#include "ReplaceDialog.h"

ReplaceDialog::ReplaceDialog()
{
    ui.setupUi(this);
    connect(ui.buttonBox, &QDialogButtonBox::accepted, this, &ReplaceDialog::onOK);
    connect(ui.buttonBox, &QDialogButtonBox::rejected, this, [=] { hide(); });
}

void ReplaceDialog::onOK()
{
    QString what = ui.editReplaceWhat->text();
    QString to = ui.editReplaceTo->text();
    text = text.replace(what, to);
    emit textReplaced(text);
}