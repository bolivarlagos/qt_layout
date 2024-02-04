#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtWidgets>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    void showHelp();
    void createMenu();
    void createHorizontalGroup();
    void createGridGroup();
    void createFormGroup();
    void createDialogButtons();
    void createButtonsActions();
    void mainLayoutConfig();
    void mainWindowConfig();

    int numGridRows = 3;
    int numButtons = 4;

    QMenuBar *menuBar;
    QGroupBox *horizontalGroup;
    QGroupBox *gridGroup;
    QGroupBox *formGroup;
    QVBoxLayout *mainLayout;

    QPushButton *buttons[4];
    QLabel *lineLabel[3];
    QLineEdit *lineEdit[3];
    QLabel *rowLabel[3];
    QDialogButtonBox *dialogButtons;
};

#endif
