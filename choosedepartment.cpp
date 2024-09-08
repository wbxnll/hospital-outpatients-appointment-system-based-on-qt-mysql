#include "choosedepartment.h"
#include "ui_choosedepartment.h"
#include "QStandardItem"
#include "QStringList"
#include "databasemanager.h"
#include <QVBoxLayout>
#include "choosetime.h"
#include <QPushButton>
#include <QLineEdit>
#include <QDateEdit>
#include <QCheckBox>

choosedepartment::choosedepartment(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::choosedepartment)
{
    ui->setupUi(this);

    QDateEdit *dateEdit = new QDateEdit(this);
    dateEdit->setCalendarPopup(true);
    dateEdit->setDisplayFormat("yyyy-MM-dd");
    dateEdit->setDate(QDate::currentDate());

    QLineEdit *searchEdit = new QLineEdit(this);
    QPushButton *searchButton = new QPushButton("Search", this);


    QCheckBox *filterByDayCheckBox = new QCheckBox("Filter by Workday", this);
    filterByDayCheckBox->setChecked(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(dateEdit);
    layout->addWidget(filterByDayCheckBox);
    layout->addWidget(searchEdit);
    layout->addWidget(searchButton);

    QTreeView *treeView = new QTreeView(this);
    layout->addWidget(treeView);
    this->setLayout(layout);

    treeView->setColumnWidth(0, 150);
    treeView->setColumnWidth(1, 100);
    treeView->setColumnWidth(2, 100);
    treeView->setColumnWidth(3, 100);
    treeView->expandAll();
    treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    updateDoctorList(dateEdit->date().dayOfWeek(), treeView, filterByDayCheckBox->isChecked());


    connect(dateEdit, &QDateEdit::dateChanged, this, [=](const QDate &date) {
        updateDoctorList(date.dayOfWeek(), treeView, filterByDayCheckBox->isChecked());
    });


    connect(filterByDayCheckBox, &QCheckBox::stateChanged, this, [=]() {
        updateDoctorList(dateEdit->date().dayOfWeek(), treeView, filterByDayCheckBox->isChecked());
    });

    connect(searchButton, &QPushButton::clicked, this, [=]() {
        onSearchClicked(searchEdit->text(), dateEdit->date().dayOfWeek(), treeView, filterByDayCheckBox->isChecked());
    });

    connect(treeView, &QTreeView::doubleClicked, this, &choosedepartment::onTreeViewDoubleClicked);
}

void choosedepartment::updateDoctorList(int dayOfWeek, QTreeView *treeView, bool filterByDay) {
    QSqlDatabase db3 = DatabaseManager::instance().getDatabase();
    QSqlQuery query3(db3);

    QString s = "SELECT name, title, department, timebegin, timeover FROM doctor ";


    if (filterByDay) {
        s += "WHERE gongzuori = :dayOfWeek ORDER BY department";
        query3.prepare(s);
        query3.bindValue(":dayOfWeek", dayOfWeek);
    } else {
        s += "ORDER BY department";
        query3.prepare(s);
    }

    query3.exec();

    QStandardItemModel *model = new QStandardItemModel(this);
    model->setColumnCount(4);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Title"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Time Begin"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Time Over"));
    QStandardItem *rootNode = model->invisibleRootItem();
    QMap<QString, QStandardItem*> departmentMap;

    while (query3.next()) {
        QString doctorTitle = query3.value(1).toString();
        QString doctorName = query3.value(0).toString();
        QString timeBegin = query3.value(3).toString();
        QString department = query3.value(2).toString();
        QString timeOver = query3.value(4).toString();

        if (!departmentMap.contains(department)) {
            QStandardItem *departmentItem = new QStandardItem(department);
            departmentMap[department] = departmentItem;
            rootNode->appendRow(departmentItem);
        }

        QList<QStandardItem *> doctorRow;
        doctorRow.append(new QStandardItem(doctorName));
        doctorRow.append(new QStandardItem(doctorTitle));
        doctorRow.append(new QStandardItem(timeBegin));
        doctorRow.append(new QStandardItem(timeOver));

        departmentMap[department]->appendRow(doctorRow);
    }

    treeView->setModel(model);
    treeView->expandAll();
}

void choosedepartment::onSearchClicked(const QString &searchTerm, int dayOfWeek, QTreeView *treeView, bool filterByDay) {
    QSqlDatabase db3 = DatabaseManager::instance().getDatabase();
    QSqlQuery query3(db3);

    QString s = "SELECT name, title, department, timebegin, timeover FROM doctor "
                "WHERE (name LIKE :searchTerm OR department LIKE :searchTerm) ";


    if (filterByDay) {
        s += "AND gongzuori = :dayOfWeek ORDER BY department";
        query3.prepare(s);
        query3.bindValue(":dayOfWeek", dayOfWeek);
    } else {
        s += "ORDER BY department";
        query3.prepare(s);
    }

    query3.bindValue(":searchTerm", "%" + searchTerm + "%");
    query3.exec();

    QStandardItemModel *model = new QStandardItemModel(this);
    model->setColumnCount(4);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Title"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Time Begin"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Time Over"));
    QStandardItem *rootNode = model->invisibleRootItem();
    QMap<QString, QStandardItem*> departmentMap;

    while (query3.next()) {
        QString doctorTitle = query3.value(1).toString();
        QString doctorName = query3.value(0).toString();
        QString timeBegin = query3.value(3).toString();
        QString department = query3.value(2).toString();
        QString timeOver = query3.value(4).toString();

        if (!departmentMap.contains(department)) {
            QStandardItem *departmentItem = new QStandardItem(department);
            departmentMap[department] = departmentItem;
            rootNode->appendRow(departmentItem);
        }

        QList<QStandardItem *> doctorRow;
        doctorRow.append(new QStandardItem(doctorName));
        doctorRow.append(new QStandardItem(doctorTitle));
        doctorRow.append(new QStandardItem(timeBegin));
        doctorRow.append(new QStandardItem(timeOver));

        departmentMap[department]->appendRow(doctorRow);
    }

    treeView->setModel(model);
    treeView->expandAll();
}

void choosedepartment::onTreeViewDoubleClicked(const QModelIndex &index) {
    if (!index.isValid()) return;

    QString doctorName = index.model()->index(index.row(), 0, index.parent()).data().toString();
    choosetime *time = new choosetime(doctorName);
    time->show();
}

choosedepartment::~choosedepartment() {
    delete ui;
}
