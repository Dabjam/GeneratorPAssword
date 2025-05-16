#include "ClipboardHandler.h"
#include <QClipboard>
#include <QGuiApplication>
#include <QTimer>

ClipboardHandler::ClipboardHandler(QObject *parent) : QObject(parent) {}

void ClipboardHandler::copyToClipboard(const QString &text) {
    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setText(text);
    QTimer::singleShot(30000, this, &ClipboardHandler::clearClipboard);
}

void ClipboardHandler::clearClipboard() {
    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->clear();
}
