#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    createMenu();

    createHorizontalGroup();

    createGridGroup();

    createFormGroup();

    createDialogButtons();

    createButtonsActions();

    mainLayoutConfig();

    mainWindowConfig();
}

Dialog::~Dialog()
{
}

void Dialog::showHelp()
{
    QMessageBox::about(this, "About", "This is a help message");
}

void Dialog::createMenu()
{
    menuBar = new QMenuBar;

    QMenu *fileMenu = new QMenu();
    fileMenu->setTitle("File");

    QAction *exitAction = new QAction;
    exitAction->setText("Exit");

    fileMenu->addAction(exitAction);

    menuBar->addMenu(fileMenu);

    connect(exitAction, &QAction::triggered, this, &Dialog::close);
}

void Dialog::createHorizontalGroup()
{
    horizontalGroup = new QGroupBox;

    QHBoxLayout *horizontalLayout = new QHBoxLayout;

    horizontalGroup->setTitle("Horizontal Group");

    for (int i = 0; i < numButtons; i++)
    {
        buttons[i] = new QPushButton;
        QString buttonLabel = "Button " + QString::number(i + 1);
        buttons[i]->setText(buttonLabel);
        horizontalLayout->addWidget(buttons[i]);
    }

    horizontalGroup->setLayout(horizontalLayout);
}

void Dialog::createGridGroup()
{
    gridGroup = new QGroupBox;
    gridGroup->setTitle("Grid Group");

    QGridLayout *gridLayout = new QGridLayout;

    for (int i = 0; i < numGridRows; i++)
    {
        lineLabel[i] = new QLabel;
        QString label = "Line " + QString::number(i + 1);
        lineLabel[i]->setText(label);

        lineEdit[i] = new QLineEdit;

        gridLayout->addWidget(lineLabel[i], i, 0);
        gridLayout->addWidget(lineEdit[i], i, 1);
    }

    QTextEdit *textEdit = new QTextEdit;

    gridLayout->addWidget(textEdit, 0, 2, 3, 2);

    gridGroup->setLayout(gridLayout);
}

void Dialog::createFormGroup()
{
    formGroup = new QGroupBox;
    formGroup->setTitle("Form Group");

    QFormLayout *formLayout = new QFormLayout;

    for (int i = 0; i < numGridRows; i++)
    {
        QString name = "Row " + QString::number(i + 1);
        rowLabel[i] = new QLabel;
        rowLabel[i]->setText(name);
    }

    QLineEdit *formLineEdit = new QLineEdit;

    QComboBox *formComboBox = new QComboBox;
    formComboBox->addItem("Item 01");
    formComboBox->addItem("Item 02");
    formComboBox->addItem("Item 03");

    QSpinBox *formSpinbox = new QSpinBox;
    formSpinbox->setRange(0, 100);
    formSpinbox->setValue(10);

    QTextEdit *formTextEdit = new QTextEdit;
    formTextEdit->setText("This is a long text");

    formLayout->addRow(rowLabel[0], formLineEdit);
    formLayout->addRow(rowLabel[1], formComboBox);
    formLayout->addRow(rowLabel[2], formSpinbox);
    formLayout->addRow(formTextEdit);

    formGroup->setLayout(formLayout);
}

void Dialog::createDialogButtons()
{
    dialogButtons = new QDialogButtonBox;
    dialogButtons->addButton(QDialogButtonBox::Ok);
    dialogButtons->addButton(QDialogButtonBox::Cancel);
    dialogButtons->addButton(QDialogButtonBox::Help);
}

void Dialog::createButtonsActions()
{
    connect(dialogButtons, &QDialogButtonBox::helpRequested, this, &Dialog::showHelp);
    connect(dialogButtons, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(dialogButtons, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

void Dialog::mainLayoutConfig()
{
    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(horizontalGroup);
    mainLayout->addWidget(gridGroup);
    mainLayout->addWidget(formGroup);
    mainLayout->addWidget(dialogButtons);

    mainLayout->setMenuBar(menuBar);

    setLayout(mainLayout);
}

void Dialog::mainWindowConfig()
{
    setWindowTitle("Basic Layout");
    setMinimumWidth(800);
    setMinimumHeight(600);
}