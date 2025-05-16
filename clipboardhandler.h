#ifndef CLIPBOARDHANDLER_H
#define CLIPBOARDHANDLER_H

#include <QObject>

class ClipboardHandler : public QObject {
    Q_OBJECT
public:
    explicit ClipboardHandler(QObject *parent = nullptr);
    void copyToClipboard(const QString &text);

private:
    void clearClipboard();
};

#endif // CLIPBOARDHANDLER_H
