#ifndef RESIZINGTEXTEDIT_H
#define RESIZINGTEXTEDIT_H

#include <QTextEdit>

class ResizingTextEdit : public QTextEdit
{
public:
    ResizingTextEdit()
    {
        auto sizePolicy = this->sizePolicy();
        sizePolicy.setHeightForWidth(true);
        sizePolicy.setVerticalPolicy(QSizePolicy::Preferred);
        this->setSizePolicy(sizePolicy);

        QObject::connect(this, &QTextEdit::textChanged, this,
                         &QWidget::updateGeometry);
    }

    QSize
    sizeHint() const override
    {
        return QSize(this->width(), this->heightForWidth(this->width()));
    }

    bool
    hasHeightForWidth() const override
    {
        return true;
    }

protected:
    int
    heightForWidth(int) const override
    {
        auto margins = this->contentsMargins();

        return margins.top() + document()->size().height() + margins.bottom() +
               5;
    }
};

#endif  // RESIZINGTEXTEDIT_H
