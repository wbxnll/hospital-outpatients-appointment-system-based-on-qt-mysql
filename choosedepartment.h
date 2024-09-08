#ifndef CHOOSEDEPARTMENT_H
#define CHOOSEDEPARTMENT_H

#include <QDialog>
#include <QTreeView>
#include <QSqlDatabase>

namespace Ui {
class choosedepartment;
}

class choosedepartment : public QDialog
{
    Q_OBJECT

public:
    explicit choosedepartment(QWidget *parent = nullptr);
    ~choosedepartment();

private slots:

    void updateDoctorList(int dayOfWeek, QTreeView *treeView, bool filterByDay);


    void onSearchClicked(const QString &searchTerm, int dayOfWeek, QTreeView *treeView, bool filterByDay);

    void onTreeViewDoubleClicked(const QModelIndex &index);

private:
    Ui::choosedepartment *ui;
};

#endif // CHOOSEDEPARTMENT_H
